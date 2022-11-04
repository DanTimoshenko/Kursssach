#ifndef SNAKE_H
#define SNAKE_H

#include <QWidget>
#include <QVector>
#include <QPoint>
#include <QKeyEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QRectF>
#include <QLabel>

class Snake : public QWidget
{
    Q_OBJECT
public:
    explicit Snake(QWidget *parent = nullptr);
protected:
   void timerEvent(QTimerEvent*) override;
   void keyPressEvent(QKeyEvent *event) override;
   void paintEvent(QPaintEvent *event) override;
   void resizeEvent(QResizeEvent *event) override;
  //void gameOver(QPainter *painter, QString message) override;
private:
   static const int DOT_WIDTH = 20;//размер яблока и точек-частей тела змеи
   static const int DOT_HEIGHT = 20;
   int FEILD_WIDTH = 20;//размер игрового поля
   int FEILD_HEIGHT = 20;
   int score = 0;//счет съеденных яблок
   int FRAME_WIDTH;//размеры рамки
   int FRAME_HEIGHT;
   static const int DELAY = 150;//задержка таймера - скорость игры
   void doDrawing();
   void localApple();
   void move();
   void check_field();
   void gameOver(QPainter *painter, QString message);
   void checkApple();
   void setTitle(const QString &text);
   int timerId;
   QPoint m_apple;
   enum Directions
   {
       left,
       right,
       up,
       down
   };
Directions m_dir;
   bool m_inGame;
   QVector<QPoint> m_dots;
   void initGame();
   QLabel *score_counter;
};

#endif // SNAKE_H
