#include "breakout.h"
#include "paddle.h"
#include "brick.h"
#include "ball.h"
#include "QPainter"
#include <QKeyEvent>

using namespace std;

Breakout::Breakout(QWidget *parent)//В конструкторе класса Breakout мы
    : QWidget(parent)
{
    x = 0;
    resize(340, 440);
    gameOver = false;
    gameWon = false;
    paused = false;
    gameStarted = false;
    ball = new Ball();
    paddle = new Paddle();

    int k = 0;
    for (int i=0; i<5; i++)//создаем экземпляр тридцати Кирпичей
    {
        for (int j=0; j<6; j++)
        {
            bricks[k] = new Brick(j*40+50, i*10+50);
            k++;
        }
    }
}

void Breakout::paintEvent(QPaintEvent *e)//В зависимости от переменных gameOver и gameWon мы
{
    Q_UNUSED(e);
    QPainter painter(this);

    //либо заканчиваем игру, выдавая соответствующие сообщения:
    if (gameOver)
    {
        finishGame(&painter, str);  // Выводим изменённое значение переменной str
    }
    else if(gameWon)//
    {
        finishGame(&painter, "Victory");
    }
    else//либо продолжаем отрисовывать в окне игровые объекты
    {
        drawObjects(&painter);
    }
}

void Breakout::finishGame(QPainter *painter, QString message)//Метод finishGame() отображает завершающее сообщение в центре окна.
{                                                            // Это либо "Game over" ("Игра проиграна"), либо "Victory" ("Победа").
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);//Метод QFontMetrics::width() используется для вычисления ширины строки соответствующего сообщениям
    int textWidth = 0;

    painter->setFont(font);
    int h = height();
    int w = width();

    painter->translate(QPoint(w/2, h/2));
    painter->drawText(-textWidth/2, 0, message);
}

void Breakout::drawObjects(QPainter *painter)//Метод drawObjects() отрисовывает в окне все объекты игры: Мяч, Ракетку и Кирпичи
{
    painter->drawRect(20, 20, 300, 400); //Рисует прямоугольник-рамку
    painter->drawImage(ball->getRect(), ball->getImage());//А так как данные объекты представлены изображениями, то
    painter->drawImage(paddle->getRect(), paddle->getImage());//при помощи метода drawImage() мы отображаем и их изображения

    for (int i=0; i<N_OF_BRICKS; i++)
    {
        if (!bricks[i]->isDestroyed())
        {
            painter->drawImage(bricks[i]->getRect(), bricks[i]->getImage());
        }
    }
}

void Breakout::timerEvent(QTimerEvent *e)//В теле метода timerEvent() мы
{
    Q_UNUSED(e);

    moveObjects();//сначала перемещаем объекты,
    checkCollision();//а затем проверяем, не столкнулся ли Мяч с Ракеткой или Кирпичом.
    repaint();//В конце генерируем событие отрисовки
}

void Breakout::moveObjects()//Метод moveObjects() отвечает за перемещения объектов Мяч и Ракетка.
{
    ball->autoMove();//В нем вызываются их собственные методы перемещения
    paddle->move();
}

void Breakout::keyReleaseEvent(QKeyEvent *e)//
{
    int dx = 0;

    switch (e->key())
    {
        case Qt::Key_Left://Когда игрок отпускает кнопку ← или →
            dx = 0;//то мы присваиваем переменной dx Ракетки значение 0
            paddle->setDx(dx);//В результате Ракетка перестает двигаться
            break;

        case Qt::Key_Right:
            dx = 0;
            paddle->setDx(dx);
            break;
    }
}

void Breakout::keyPressEvent(QKeyEvent *e)//В методе keyPressEvent() мы отслеживаем события нажатия клавиш, относящиеся к нашей игре
{

    int dx = 0;

    switch (e->key())
    {
    case Qt::Key_Left://Кнопка ← перемещает объект Ракетки.
        dx = -1;//Она влияет на значение переменной dx,
        paddle->setDx(dx);//которое затем будет добавлено к координате х самой Ракетки
        break;

    case Qt::Key_Right://Кнопка → перемещает объект Ракетки.
        dx = 1;
        paddle->setDx(dx);
        break;

    case Qt::Key_P://Кнопка P ставит игру на паузу
        pauseGame();
        break;

    case Qt::Key_Space://кнопка "Пробел" запускает игру
        startGame();
        break;

    //case Qt::Key_Escape://а кнопка Esc завершает работу приложения
        //qApp->exit();
        //break;

    default:
        QWidget::keyPressEvent(e);
    }
}

void Breakout::startGame()//Метод startGame() сбрасывает состояния объектов ball и paddle;
{
    if (!gameStarted)
    {
        ball->resetState();//ball и paddle перемещаются в исходное положение.
        paddle->resetState();
        for (int i=0; i<N_OF_BRICKS; i++)//В цикле for мы
        {
            bricks[i]->setDestroyed(false);//устанавливаем значение флага destroyed равным false для каждого Кирпича, таким образом отображая их в окне.
        }
        gameOver = false;//Переменные gameOver, gameWon и gameStarted получают свои начальные логические значения
        gameWon = false;
        gameStarted = true;
        timerId = startTimer(DELAY);//Наконец, с помощью метода startTimer() мы запускаем таймер
     }
}

void Breakout::pauseGame()//Функция pauseGame() используется для приостановки и запуска уже остановленной игры.
{                         //Данное состояние игры управляется с помощью переменной paused
    if (paused)
    { //Также мы храним и идентификатор таймера
        timerId = startTimer(DELAY);
        paused = false;
    }
    else// Чтобы приостановить игру, мы «убиваем» таймер с помощью метода killTimer(). Чтобы перезапустить его, мы вызываем метод startTimer()
    {
        paused = true;
        killTimer(timerId);
    }
}

void Breakout::stopGame()//В методе stopGame() мы
{
    killTimer(timerId);//«убиваем» таймер и
    gameOver = true;//устанавливаем соответствующие флаги
    gameStarted = false;
}

void Breakout::victory()
{
    killTimer(timerId);
    gameWon = true;
    gameStarted = false;
}

void Breakout::checkCollision()//В методе checkCollision() мы делаем проверку столкновения Мяча с игровыми объектами.
{
    if (ball->getRect().bottom() > BOTTOM_EDGE)//Игра заканчивается, если Мяч попадает в нижний край окна
    {
        stopGame();
    }

    for (int i=0, j=0; i<N_OF_BRICKS; i++)
    {
        if (bricks[i]->isDestroyed())//Проверяем количество разрушенных Кирпичей.
        {
            j++;
        }
        if (j == N_OF_BRICKS)//Если все Кирпичи уничтожены, то мы выиграли
        {
            victory();
        }
     }

     if ((ball->getRect()).intersects(paddle->getRect()))
     {
         int paddleLPos = paddle->getRect().left();
         int ballLPos = ball->getRect().left();

         int first = paddleLPos + 8;
         int second = paddleLPos + 16;
         int third = paddleLPos + 24;
         int fourth = paddleLPos + 32;

         if (ballLPos < first)//Если Мяч попадает в верхнюю часть Ракетки,
         {
             ball->setXDir(-1);//то меняем направление полета Мяча (в зависимости от движения Ракетки в момент столкновения), например, на влево-вверх
             ball->setYDir(-1);
         }
         if (ballLPos >= first && ballLPos < second)
         {
             ball->setXDir(-1);
             ball->setYDir(-1*ball->getYDir());
         }
         if (ballLPos >= second && ballLPos < third)
         {
             ball->setXDir(0);
             ball->setYDir(-1);
         }
         if (ballLPos >= third && ballLPos < fourth)
         {
             ball->setXDir(1);
             ball->setYDir(-1*ball->getYDir());
         }
         if (ballLPos > fourth)
         {
             ball->setXDir(1);
             ball->setYDir(-1);
         }
     }

     for (int i=0; i<N_OF_BRICKS; i++)
     {
         if ((ball->getRect()).intersects(bricks[i]->getRect()))
         {
             int ballLeft = ball->getRect().left();
             int ballHeight = ball->getRect().height();
             int ballWidth = ball->getRect().width();
             int ballTop = ball->getRect().top();

             QPoint pointRight(ballLeft + ballWidth + 1, ballTop);
             QPoint pointLeft(ballLeft - 1, ballTop);
             QPoint pointTop(ballLeft, ballTop -1);
             QPoint pointBottom(ballLeft, ballTop + ballHeight + 1);

             if (!bricks[i]->isDestroyed())
             {
                 if(bricks[i]->getRect().contains(pointRight))
                 {
                     ball->setXDir(-1);
                 }
                 else if(bricks[i]->getRect().contains(pointLeft))
                 {
                     ball->setXDir(1);
                 }

                 if(bricks[i]->getRect().contains(pointTop))
                 {
                     ball->setYDir(1);
                 }
                 else if(bricks[i]->getRect().contains(pointBottom))//Если Мяч ударяется о нижнюю часть Кирпича,
                 {
                     ball->setYDir(-1);//то мы меняем направление y Мяча — он идет вниз
                 }

                 bricks[i]->setDestroyed(true);
             }
         }
     }
}

void Breakout::setName(QString s)
{
    str = s; // Сохраняем значение переменной из menu
    str = "Game over, " + str; // Перестраиваем его под сообщение проигрыша
}

Breakout::~Breakout()
{
    delete ball;
    delete paddle;
    for (int i=0; i<N_OF_BRICKS; i++)
    {
        delete bricks[i];
    }
}
