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
    void setName(QString s);
    ~Breakout();
protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *);//Ракетка управляется с помощью клавиш-стрелок на клавиатуре.
    void keyReleaseEvent(QKeyEvent *);//В игре мы следим за событиями нажатия клавиш клавиатуры с помощью методов keyPressEvent() и keyReleaseEvent()
    void drawObjects(QPainter *);
    void finishGame(QPainter *, QString);
    void moveObjects();

    void startGame();//
    void pauseGame();//
    void stopGame();//
    void victory();//
    void checkCollision();
private:
    QString str;
    int x;//В переменной x хранится текущее положение Ракетки по оси ОX.
    int timerId;//Переменная timerId используется для идентификации объекта timer. Это необходимо в тех моментах, когда мы приостанавливаем игру
    static const int N_OF_BRICKS = 30;//Константа N_OF_BRICKS задает количество Кирпичей в игре.
    static const int DELAY = 10;//Константа DELAY управляет скоростью игры
    static const int BOTTOM_EDGE = 400;//Когда Мяч пересекает нижний край окна, то игра заканчивается
    Ball *ball;//Переменные-указатели на объекты Мяча
    Paddle *paddle;//Ракетки
    Brick *bricks[N_OF_BRICKS];//и массива Кирпичей
    /*Следующие 4 переменные отвечают за различные состояния игры:  */
    bool gameOver;//Проигрыш
    bool gameWon;//Победа
    bool gameStarted;//Старт
    bool paused;//Пауза
};

#endif // BREAKOUT_H
