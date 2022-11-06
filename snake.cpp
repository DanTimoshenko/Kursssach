#include "snake.h"
#include <QDebug>
#include <QTime>
#include <QMessageBox>

Snake::Snake(QWidget *parent)
    : QWidget{parent}
{
    this->resize(DOT_WIDTH * FEILD_WIDTH,DOT_HEIGHT * FEILD_HEIGHT ); // задаємо розміри поля
    score_counter = new QLabel("score: 0", this); //лічильник ігрового рахунку
    score_counter->move(20, 0);
    FRAME_WIDTH = width()-40; 
    FRAME_HEIGHT = height()-40;
    this->setWindowTitle("snake"); 
    initGame(); // функція, що ініціалізує гру
}

void Snake::timerEvent(QTimerEvent *e) //спрацьовує кожен раз, після визивання функцій нижче
{
    if (m_inGame) 
    {
        checkApple(); 
        move();
        check_field(); 
    }
    this->update(); //оновлення даних після перевірок 
}

void Snake::keyPressEvent(QKeyEvent *e) //відпрацьовує натискання клавіш
{
    int key = e->key(); //потрібно дізнатися, яка подія прийшла від клавіши 
    if(key==Qt::Key_Left && m_dir != Directions::right){m_dir = Directions::left;} //щоб сама на себе не почала повзати перевіряємо кожний напрямок
    if(key==Qt::Key_Right && m_dir != Directions::left){m_dir = Directions::right;}
    if(key==Qt::Key_Up && m_dir != Directions::down){m_dir = Directions::up;}
    if(key==Qt::Key_Down && m_dir != Directions::up){m_dir = Directions::down;}
}

void Snake::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e); //не потрібно її ініціалізувати
    doDrawing(); //визиваємо функцію для отрисовки
}

void Snake::doDrawing(){
    QPainter qp(this); //за допомогою цього класу виконуєтсья уся отрисовка
    if (m_inGame)
    {
        qp.drawRect(20, 20, FRAME_WIDTH, FRAME_HEIGHT); //відрисовує прямокутник
        qp.setBrush(Qt::yellow); //задаємо колір прямокутника 
        qp.drawEllipse(m_apple.x() * DOT_WIDTH, m_apple.y() * DOT_HEIGHT, DOT_WIDTH, DOT_HEIGHT); //малюємо яблуко 
        for (int i=0; i<m_dots.size();++i) //малюємо змійку
        {
            if(i == 0) //якщо це голова
            {
                qp.setBrush(Qt::red); //колір та еліпс дял малювання голови
                qp.drawEllipse(m_dots[i].x() * DOT_WIDTH, m_dots[i].y() * DOT_HEIGHT, DOT_WIDTH, DOT_HEIGHT);
            }
            else
            {
                qp.setBrush(Qt::green); //колір та еліпс для малювання інших частин змійки 
                qp.drawEllipse(m_dots[i].x() * DOT_WIDTH, m_dots[i].y() * DOT_HEIGHT, DOT_WIDTH, DOT_HEIGHT);
            }
        }
    }
    else
    {
        qp.end();
        QPainter painter(this);
        gameOver(&painter, "Game over, ");
    }
}

void Snake::localApple()
{
    QTime time= QTime::currentTime(); //щоб кожен раз значення положення яблука змінювалось рандомно
    srand((uint)time.msec());

    m_apple.rx()= rand() % (DOT_WIDTH-2)+1; //щоб ограничити поля, робимо залишок від висоти та ширини клітинок
    m_apple.ry()= rand() % (DOT_HEIGHT-2)+1; //генерується рандомне положення яблука на ігровому полі
}

void Snake::move() //рух змійки 
{
    for (int i = m_dots.size()-1; i>0; --i) //щоб рухалося уся змійка, а не тільки її голова 
    {                                       
        m_dots[i]=m_dots[i-1]; // Масив рухає хвіст по предостанньому елементу, усі елементи
    }
    switch (m_dir){
    case left: {m_dots[0].rx() -= 1; break;} //якщо рухається вліво від нуля, то х щменшується на 1
    case right: {m_dots[0].rx() += 1; break;} // х збільшується на 1
    case up: {m_dots[0].ry() -= 1; break;} //у зменшується на 1
    case down: {m_dots[0].ry() += 1; break;} //у збільшується на 1
}
}

void Snake::check_field() //перевіряє чи не вийшла за поля, або не врізалась сама у себе
{
    if(m_dots.size()>4) //якщо б точок = або < 4, то врізатися в себе неможливо, тому перевіряємо більше
   {

        for (int i=1; i<m_dots.size(); ++i) //пропускаємо 0, бо голову з головой можна не порівнювати 
        {
            if(m_dots[0] == m_dots[i]) //голова врізалась у будь-яку точку тіла, поразка
            {
               m_inGame= false;
            }
        }
    }
    if(m_dots[0].x() >= FEILD_WIDTH-1) //перевірка виходу за поля
    {
        m_inGame=false;
    }
    if(m_dots[0].x() < 1)
    {
        m_inGame=false;
    }
    if(m_dots[0].y() >= FEILD_HEIGHT-1)
    {
        m_inGame=false;
    }
    if(m_dots[0].y() < 1)
    {
        m_inGame=false;
    }
    if(!m_inGame) //якщо ми не у грі, то таймер перестає працьувати 
    {
        killTimer(timerId);
    }
}

void Snake::gameOver(QPainter *painter, QString message) //гра закінчена
{
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = 0;

    painter->setFont(font);
    int h = height();
    int w = width();

    painter->translate(QPoint(w/2, h/2));
    painter->drawText(-textWidth/2, 0, message);

    score_counter->setText(tr("score: %1").arg(score));

    /*score=0;
    score_counter->setText(tr("score: %1").arg(score));
    initGame();*/
}

void Snake::checkApple() //перевіяємо чи з'їла яблуко
{
    if (m_apple== m_dots[0]) //координата яблука збігається з координатою голови
    {
        m_dots.push_back(QPoint(0,0)); //змійка збільшується на одну клітинку в тілі
        localApple(); //яблуко знов рандомно з'являється на полі
        //QMessageBox msgr;
        //msgr.setText("вы получили очко!");
        //msgr.exec();
        score++; //кількість ігрових балів збільшується на один
        score_counter->setText(tr("score: %1").arg(score));
    }
}

void Snake::initGame(){
    m_inGame=true; //якщо в ігрі, то true
    m_dots.resize(3); //спочатку у змійці буде усього три частини (клітинки)
    for(int i=0; i<m_dots.size();++i){ //заповнюємо початкове положення змійки. У нулі знаходиться голова змійки
        m_dots[i].rx()=10;//m_dots.size()-i; //rx повертає вказівних на х
        m_dots[i].ry()=10; //rу повертає вказівних на х. таким чином вказуємо початкові координати
    }
   localApple(); //положення яблука в рандомному місті поля
   timerId = startTimer(DELAY); //по ініціалізації гри запускаєтсья таймер. Через кожен деякий період будуе визивати функцію обробчика 

}
