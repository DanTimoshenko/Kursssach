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
Brick::Brick(int x, int y)//Конструктор класса Brick
{
    image.load(":brickie.png");//загружает изображение Кирпича,

    destroyed = false;//инициирует переменную-флаг destroyed
    rect = image.rect();
    rect.translate(x, y);//устанавливает изображение в исходную позицию
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

bool Brick::isDestroyed()//У объектов класса Brick есть переменная-флаг destroyed. Если её значение установлено как true,
{                        // то Кирпич считается разрушенным, и не отображается в окне
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
