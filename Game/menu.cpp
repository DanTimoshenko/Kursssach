#include "menu.h"

Menu::Menu(QWidget *parent)
    : QWidget{parent}
{
    this->setWindowTitle("menu");

    //auth = new Authorization;
    button = new QPushButton("Snake", this);
    button->setFixedSize(100, 50);
    button->move(width()/2, 10);

    button2 = new QPushButton("Breakout", this);
    button2->setFixedSize(100, 50);
    button2->move(width()/2, 110);

    button3 = new QPushButton("Authorization", this);
    button3->setFixedSize(100, 50);
    button3->move(width()/2, 210);

    this->setStyleSheet("QPushButton{background-color: green;"
                          "color: white;"
                          "border-style: outset;"
                          "border-width: 2px;"
                          "border-radius: 10px;"
                          "font: bold;"
                          "border-color: white;}");

    connect(button, SIGNAL(clicked(bool)), this, SLOT(snake()));
    connect(button2, SIGNAL(clicked(bool)), this, SLOT(breakout()));
    connect(button3, SIGNAL(clicked(bool)), this, SLOT(author()));
}

void Menu::snake()
{
    game_snake = new Snake;
    game_snake->show();
    this->close();
}

void Menu::breakout()
{
    game_breakout = new Breakout;
    game_breakout->show();
    this->close();
}

void Menu::author()
{
    auth = new Authorization;
    auth->show();
    this->close();
}

