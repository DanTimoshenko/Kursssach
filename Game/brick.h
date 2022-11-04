#ifndef BRICK_H
#define BRICK_H

#include <QWidget>
#include <QImage>
#include <QRect>
#include <iostream>

class Brick : public QWidget
{
    Q_OBJECT
public:
    explicit Brick(QWidget *parent = nullptr);
    Brick(int, int);
    ~Brick();
public slots:
    bool isDestroyed();
    void setDestroyed(bool);
    QRect getRect();
    void setRect(QRect);
    QImage & getImage();
private:
    QImage image;
    QRect rect;
    bool destroyed;
};
#endif // BRICK_H
