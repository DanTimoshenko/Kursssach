#include "paddle.h"

#include <QRect>
#include <QPixmap>
#include <QPainter>
#include <iostream>

using namespace std;

Paddle::Paddle(QWidget *parent)
    : QWidget{parent}
{
    dx = 0;

    image.load(":paddle.png");

    rect = image.rect();
    resetState();
}

void Paddle::setDx(int x)
{
    dx = x;
}

void Paddle::move()
{
    //Если paddle касается левой границы и двигается влево, то он не может двигатся влево
    //Или если paddle касается правой границы и двигается вправо, то он не может двигатся вправо
    if((rect.left()<=20 && dx==-1) || (rect.right()>=RIGHT_EDGE && dx==1))
        dx = 0;
    rect.translate(dx, 0);
}

void Paddle::resetState()
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
