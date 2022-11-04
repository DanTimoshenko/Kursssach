#include "paddle.h"

#include <QRect>
#include <QPixmap>
#include <QPainter>
#include <iostream>

using namespace std;

Paddle::Paddle(QWidget *parent)
    : QWidget{parent}//В конструкторе класса Paddle мы:
{
    dx = 0;//инициируем переменную dx

    image.load(":paddle.png");//загружаем изображение Ракетки.

    rect = image.rect();//получаем прямоугольник, ограничивающий загруженное изображение Ракетки, и
    resetState();       //устанавливаем его в исходное положение
}

void Paddle::setDx(int x)
{
    dx = x;
}

void Paddle::move()//Метод move() перемещает прямоугольник с изображением Ракетки
{
    //Если paddle касается левой границы и двигается влево, то он не может двигатся влево
    //Или если paddle касается правой границы и двигается вправо, то он не может двигатся вправо
    if((rect.left()<=20 && dx==-1) || (rect.right()>=RIGHT_EDGE && dx==1))
    {
        dx = 0;
    }
    rect.translate(dx, 0);//перемещаем прямоугольник с изображением Ракетки

    /*int x = rect.x() + dx;//Направление движения задается переменной dx (см. breakout.cpp, строка 124):
    int y = rect.top();
    rect.moveTo(x, y);//перемещаем прямоугольник с изображением Ракетки*/
}

void Paddle::resetState()//Функция resetState() устанавливает Ракетку в исходное положение
{
    rect.moveTo(INITIAL_X, INITIAL_Y);
}

QRect Paddle::getRect()
{
    return rect;
}

QImage & Paddle::getImage()
{
    return image;
}

Paddle::~Paddle()
{
    cout << ("Paddle deleted") << endl;
}
