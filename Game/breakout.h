#ifndef BREAKOUT_H
#define BREAKOUT_H

#include "paddle.h"
#include "brick.h"
#include "ball.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Breakout; }
QT_END_NAMESPACE

class Breakout : public QWidget
{
    Q_OBJECT

public:
    Breakout(QWidget *parent = nullptr);
    ~Breakout();
protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
    void drawObjects(QPainter *);
    void finishGame(QPainter *, QString);
    void moveObjects();

    void startGame();
    void pauseGame();
    void stopGame();
    void victory();
    void checkCollision();
private:
    int x;
    int timerId;
    static const int N_OF_BRICKS = 30;
    static const int DELAY = 10;
    static const int BOTTOM_EDGE = 400;
    Ball *ball;
    Paddle *paddle;
    Brick *bricks[N_OF_BRICKS];
    bool gameOver;
    bool gameWon;
    bool gameStarted;
    bool paused;
};

#endif // BREAKOUT_H
