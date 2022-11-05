#include "ball.h"

#include <QRect>
#include <QPixmap>
#include <QPainter>
#include <iostream>

using namespace std;

Ball::Ball(QWidget *parent)
    : QWidget{parent}
{
    xdir = 0;
    ydir = -1;

    image.load(":ball.png");

    rect = image.rect();
    resetState();
}

void Ball::autoMove()
{
    rect.translate(xdir, ydir);

    if (rect.left() == 20)
    {
        xdir = 1;
    }
    if (rect.right() == RIGHT_EDGE)
    {
        xdir = -1;
    }

    if (rect.top() == 20)
    {
        ydir = 1;
    }
}

void Ball::resetState()
{
    rect.moveTo(INITIAL_X, INITIAL_Y);
}

void Ball::setXDir(int x)
{
    xdir = x;
}

void Ball::setYDir(int y)
{
    ydir = y;
}

int Ball::getXDir()
{
    return xdir;
}

int Ball::getYDir()
{
    return ydir;
}

QRect Ball::getRect()
{
    return rect;
}

QImage & Ball::getImage()
{
    return image;
}

Ball::~Ball()
{
    cout << ("Ball deleted") << endl;
}
