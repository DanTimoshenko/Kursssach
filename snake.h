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
   void timerEvent(QTimerEvent*) override; //визивається, якщо відпрацював таймер
   void keyPressEvent(QKeyEvent *event) override; //при натисканні клавіш
   void paintEvent(QPaintEvent *event) override; //отрисовка змійки
  //void gameOver(QPainter *painter, QString message) override;
private:
   static const int DOT_WIDTH = 20; //static, так як немає прив'язки до даного об'єкту 
   static const int DOT_HEIGHT = 20; //условно поля в змійці розбиті на клітинки, тому задаємо ширину і висоту для них (розміри точок)
   static const int FEILD_WIDTH = 20; //кількість точок
   static const int FEILD_HEIGHT = 20;
   int score = 0;
   int FRAME_WIDTH;
   int FRAME_HEIGHT;
   static const int DELAY = 150; //усі дії виконувати за таймером
   void doDrawing();
   void localApple();
   void move();
   void check_field();
   void gameOver(QPainter *painter, QString message);
   void checkApple();
   void setTitle(const QString &text);
   int timerId;
   QPoint m_apple; //зберігається інфа про яблуко
   enum Directions //усі можливі напрямки руху змійки
   {
       left,
       right,
       up,
       down
   };
Directions m_dir; //запом'ятовує, куди рухається змійка
   bool m_inGame; //функція, щоб зберігати стан (у грі або ні). локальні змінні починаємо з m, щоб зручно було орієнтуватися у великому коді
   QVector<QPoint> m_dots; //зберігає інфу з усі точок змійки. Гра двухмірна, тому інфа точок зберігається у двух змінних (за допомогою QPoint, щоб не ускладнювати)
   void initGame(); //ініціалізує гру
   QLabel *score_counter;
};

#endif // SNAKE_H
