#include "menu.h"
#include <QGridLayout>

Menu::Menu(QWidget *parent)
    : QWidget{parent}
{
    this->resize(400, 600);
    this->setWindowTitle("menu");

    label = new QLabel("Enter your name: ", this);
    label->setFont(QFont("Courier", 15));//шрифт и размер букв лейбла
    label->move(width()/2-95, 90);

    nickname = new QLineEdit (this);
    nickname->setFixedSize(200, 50);//размер лайнэдита
    nickname->move(width()/2-95, 110);//раположение лайнэдита
    nickname->setValidator(new QRegularExpressionValidator(QRegularExpression("[A-Za-zа-яА-Я0-9]{1,10}")));//Используем валидатор регулярных выражений.
    //Создаем валидатор,(в котором (параметром указываем регулярные выражения, (которые можно использовать("[такие символы]{кол-во символов в строке}")))
    nickname->setFont(QFont("Courier", 15));//шрифт и размер букв в лайнэдите

    button = new QPushButton("Snake", this);
    button->setFixedSize(150, 80);//Если менять размер, то змейка вроде работает, но не при всех значениях
    button->move(width()/2-70, 250);

    button2 = new QPushButton("Breakout", this);
    button2->setFixedSize(150, 80);
    button2->move(width()/2-70, 400);

    this->setStyleSheet("QPushButton{background-color: green;"//заливка кнопки
                          "color: white;"//цвет букв кнопки
                          "border-style: outset;"
                          "border-width: 3px;"
                          "border-radius: 10px;"
                          "font: bold;"
                          "font-family: Courier;"//шрифт кнопки
                          "font-size: 20px;"//размер шрифта кнопки
                          "border-color: white;}"//границы кнопки
                          "QPushButton::hover {background-color : lightgreen;}"
                        "QLineEdit{background-color: green;"//цвет фона лайнэдита
                          "color: white;}"//цвет шрифта лайнэдита
                        "QLabel{color: white;}");//цвет лэйбла

    /*QPalette pal("#6D9844"); //цвет фона
    this->setAutoFillBackground(true);
    setPalette(pal); //устанавливаем фон*/

    connect(nickname, SIGNAL(textChanged(QString)), this, SLOT(setName())); // При изменении ЛайнЭдита вызываем метод setName()
    connect(button, SIGNAL(clicked(bool)), this, SLOT(snake()));
    connect(button2, SIGNAL(clicked(bool)), this, SLOT(breakout()));

    snake_frame = new QRect(button->x()-20, button->y()-20, button->rect().width()+31, button->rect().height()+31); //рамка для движения змейки. +31, потому что там теряется еденичка, но я не знаю почему
    //змейка ползает сверху и слева по внутренней стороне рамки, а снизу и справа - по внешней. Почему так я не знаю, но это фиксится не ровной рамкой относительно кнопки
    m_dots.resize(5); // это скопированный кусок из кода игры
    for(int i=0; i<m_dots.size();++i)//заповнюємо початкове положення змійки. У нулі знаходиться голова змійки
    {
        m_dots[i].rx()=snake_frame->x()+20;//m_dots.size()-i; //rx повертає вказівних на х
        m_dots[i].ry()=snake_frame->y();//rу повертає вказівних на х. таким чином вказуємо початкові координати
    }
    timerId = startTimer(100); //ставим таймер
}

void Menu::setName() // Сохраняем значение поля для ввода (QLineEdit) в переменную str
{
    str = nickname->text();
}

void Menu::snake()
{
    game_snake = new Snake;
    game_snake->setName(str);
    game_snake->show();
    this->hide(); //Прячем виджет, но не закрываем
    connect(game_snake, SIGNAL(closed()), this, SLOT(show())); //Коннект сигнала змейки и открытия меню
}

void Menu::breakout()
{
    game_breakout = new Breakout;
    game_breakout->setName(str); // Передаём переменную str в Breakout
    game_breakout->show();
    this->hide();
    connect(game_breakout, SIGNAL(closed()), this, SLOT(show())); //Коннект сигнала брейкаута  и открытия меню
}

void Menu::paintEvent(QPaintEvent *)
{
    //опять кусок кода игры
    QPainter qp(this);//за допомогою цього класу виконуєтсья уся отрисовка

    qp.drawImage(0, 0, QImage("D:/KhPI/Lessons/Course work/Game/menu_backgroung.jpg").scaled(400, 600));//Подгружаем на фон картинку.

    qp.setRenderHint(QPainter::Antialiasing, true);//сглаживание
    qp.setBrush(Qt::yellow);//задаємо колір прямокутника
    //qp.drawRect(*snake_frame); //если раскоментировать, то можно посмотреть как выглядит рамка для змейки
    for (int i=0; i<5; ++i)//малюємо змійку
    {
        if(i == 0)//якщо це голова
        {
            qp.setBrush(Qt::white);//колір та еліпс дял малювання голови
            qp.drawEllipse(m_dots[i].x(), m_dots[i].y(), 15, 15);
        }
        else
        {
            QLinearGradient lgrad;//линейный градиент
            lgrad.setStart(200,200);//стартовая точка
            lgrad.setFinalStop(300, 300);//точка, где отрисовка смены цветов градиента заканчивается
            lgrad.setColorAt(0.0, Qt::darkRed);
            lgrad.setColorAt(0.1, Qt::red);
            lgrad.setColorAt(0.2, Qt::yellow);
            lgrad.setColorAt(0.3, Qt::green);
            lgrad.setColorAt(0.4, Qt::cyan);
            lgrad.setColorAt(0.5, Qt::blue);
            lgrad.setColorAt(0.6, Qt::darkBlue);
            lgrad.setColorAt(0.7, Qt::magenta);
            lgrad.setColorAt(0.8, Qt::darkMagenta);
            lgrad.setColorAt(0.9, Qt::darkCyan);
            lgrad.setColorAt(1.0, Qt::black);
            qp.setBrush(lgrad);//колір та еліпс для малювання інших частин змійки
            qp.drawEllipse(m_dots[i].x(), m_dots[i].y(), 14, 14);
        }
    }

}

void Menu::timerEvent(QTimerEvent *)
{
    snake_move(); //двигаем змейку
    update();
}

void Menu::snake_move()
{
    for (int i = m_dots.size()-1; i>0; --i)
    {
        m_dots[i]=m_dots[i-1]; // движение из кода игры
    }

    if(m_dots[0].rx()<=snake_frame->right() && m_dots[0].ry()==snake_frame->top()){m_dots[0].rx() += 10;} //если у = верхней границе рамки и х < правой границы, то змейка двигается вправо
    if(m_dots[0].rx()==snake_frame->right() && m_dots[0].ry()<=snake_frame->bottom()){m_dots[0].ry() += 10;} //если х = правой границе рамки и у < нижней границы, то змейка двигается вниз
    if(m_dots[0].rx()>=snake_frame->left() && m_dots[0].ry()==snake_frame->bottom()){m_dots[0].rx() += -10;} //если у = нижней границе рамки и х < левой границы, то змейка двигается влево
    if(m_dots[0].rx()==snake_frame->left() && m_dots[0].ry()>=snake_frame->top()){m_dots[0].ry() += -10;} //если х = левой границе рамки и у < верхней границы, то змейка двигается вверх
    qDebug()<<m_dots[0].rx()<<m_dots[0].ry()<<snake_frame->bottom();
}
