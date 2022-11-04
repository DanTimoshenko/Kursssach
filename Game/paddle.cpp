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
    int x = rect.x() + dx;
    int y = rect.top();

    rect.moveTo(x, y);
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
