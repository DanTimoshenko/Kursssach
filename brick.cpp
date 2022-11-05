#include "brick.h"

#include <QRect>
#include <QPixmap>
#include <QPainter>
#include <iostream>

using namespace std;

Brick::Brick(QWidget *parent)
    : QWidget{parent}
{
}
Brick::Brick(int x, int y)
{
    image.load(":brickie.png");

    destroyed = false;
    rect = image.rect();
    rect.translate(x, y);
}

QRect Brick::getRect()
{
    return rect;
}

void Brick::setRect(QRect rct)
{
    rect = rct;
}

QImage & Brick::getImage()
{
    return image;
}

bool Brick::isDestroyed()
{
    return destroyed;
}

void Brick::setDestroyed(bool destr)
{
    destroyed = destr;
}

Brick::~Brick()
{
    cout << ("Brick deleted") << endl;
}
