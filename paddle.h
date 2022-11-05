#ifndef PADDLE_H
#define PADDLE_H

#include <QWidget>
#include <QImage>
#include <QRect>
#include <iostream>

class Paddle : public QWidget
{
    Q_OBJECT
public:
    explicit Paddle(QWidget *parent = nullptr);
    ~Paddle();
public slots:
    void resetState();
    void move();
    void setDx(int);
    QRect getRect();
    QImage & getImage();
private:
    QImage image;
    QRect rect;
    int dx;
    static const int RIGHT_EDGE = 320;
    static const int INITIAL_X = 150;
    static const int INITIAL_Y = 360;
};

#endif // PADDLE_H
