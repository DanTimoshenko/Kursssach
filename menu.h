#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QDebug>
#include <QRegularExpressionValidator>

#include <snake.h>
#include <breakout.h>

class Menu : public QWidget
{
    Q_OBJECT
public:
    explicit Menu(QWidget *parent = nullptr);
    QLineEdit *nickname;
protected:
    QPushButton *button, *button2;
private:
    QString str;
    Snake *game_snake;
    Breakout *game_breakout;
    QLabel *label;
    QRect *snake_frame; // рамка змейки
    QImage *ball, *paddle;
    QRect *rect_ball, *rect_paddle;
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void snake_move(); // метод движения змейки
    void breakout_move(); // метод движения брэйкаута
    void animation_init(); //метод для создания и перемещения всех объектов анимации
    QVector<QPoint> m_dots; //вектор змейки из кода игры
    int timerId;//таймер
    int y_move = -5;
public slots:
    void snake();
    void breakout();
    void setName();
};
#endif // MENU_H



// [[:alnum:]]
