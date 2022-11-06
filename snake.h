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

class Snake : public QWidget //наслідуємо, щоб можна було відобразити як вікно
{
    Q_OBJECT
public:
    explicit Snake(QWidget *parent = nullptr); 
protected:
   void timerEvent(QTimerEvent*) override;
   void keyPressEvent(QKeyEvent *event) override;
   void paintEvent(QPaintEvent *event) override;
  //void gameOver(QPainter *painter, QString message) override;
private:
   static const int DOT_WIDTH = 20; //static, так як немає прив'язки до даного об'єкту 
   static const int DOT_HEIGHT = 20; //условно поля в змійці розбиті на клітинки, тому задаємо ширину і висоту для них (розміри точок)
   static const int FEILD_WIDTH = 20; //кількість точок
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
   QPoint m_apple;
   enum Directions
   {
       left,
       right,
       up,
       down
   };
Directions m_dir;
   bool m_inGame; //функція, щоб зберігати стан (у грі або ні). локальні змінні починаємо з m, щоб зручно було орієнтуватися у великому коді
   QVector<QPoint> m_dots;
   void initGame(); //ініціалізує гру
   QLabel *score_counter;
};

#endif // SNAKE_H
