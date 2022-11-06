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
    void setName(QString s);
protected:
   void timerEvent(QTimerEvent*) override;
   void keyPressEvent(QKeyEvent *event) override;
   void paintEvent(QPaintEvent *event) override;
  //void gameOver(QPainter *painter, QString message) override;
private:
   static const int DOT_WIDTH = 20;
   static const int DOT_HEIGHT = 20;
   static const int FEILD_WIDTH = 20;
   static const int FEILD_HEIGHT = 20;
   int score = 0;
   int FRAME_WIDTH;
   int FRAME_HEIGHT;
   static const int DELAY = 150;
   void doDrawing();
   void localApple();
   void move();
   void check_field();
   void gameOver(QPainter *painter, QString message);
   void checkApple();
   void setTitle(const QString &text);
   int timerId;
   QString str;
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
signals:
   void closed(); //Сигнал, который срабатывает, когда пользователь проигрывает и нажимает на Esc
};

#endif // SNAKE_H
