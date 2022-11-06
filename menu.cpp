#include "menu.h"
#include <QGridLayout>

Menu::Menu(QWidget *parent)
    : QWidget{parent}
{
    //QGridLayout *grid=new QGridLayout (this);

    this->resize(600, 600);
    this->setWindowTitle("menu");

    label = new QLabel("Enter your name: ", this);
    label->move(width()/2-50, 90);
    //grid->addWidget(label,1,0);

    //QRegularExpressionValidator valid;
    //valid.setRegularExpression("^[A-Za-z0-9]");


    nickname = new QLineEdit (this);
    nickname->setFixedSize(150, 50);
    nickname->move(width()/2-50, 110);
    nickname->setValidator(new QRegularExpressionValidator(QRegularExpression("[A-Za-zа-яА-Я0-9]{1,10}")));
    //grid->addWidget(nickname,3,0);

    button = new QPushButton("Snake", this);
    button->setFixedSize(100, 50);
    button->move(width()/2-50, 260);
    //grid->addWidget(button,5,0);

    button2 = new QPushButton("Breakout", this);
    button2->setFixedSize(100, 50);
    button2->move(width()/2-50, 410);
    //grid->addWidget(button2,7,0);

    this->setStyleSheet("QPushButton{background-color: green;"
                          "color: white;"
                          "border-style: outset;"
                          "border-width: 2px;"
                          "border-radius: 10px;"
                          "font: bold;"
                          "border-color: white;}");

    connect(nickname, SIGNAL(textChanged(QString)), this, SLOT(setName())); // При изменении ЛайнЭдита вызываем метод setName()
    connect(button, SIGNAL(clicked(bool)), this, SLOT(snake()));
    connect(button2, SIGNAL(clicked(bool)), this, SLOT(breakout()));
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
    connect(game_breakout, SIGNAL(closed()), this, SLOT(show())); //Коннект сигнала змейки и открытия меню
}
