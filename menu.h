#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QPushButton>

#include <snake.h>
#include <breakout.h>
#include <authorization.h>

class Menu : public QWidget
{
    Q_OBJECT
public:
    explicit Menu(QWidget *parent = nullptr);
protected:
    QPushButton *button, *button2, *button3;
private:
    Snake *game_snake;
    Breakout *game_breakout;
    Authorization *auth;
public slots:
    void snake();
    void breakout();
    void author();
};
#endif // MENU_H
