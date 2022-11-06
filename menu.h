#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QDebug>
//#include <QValidator>
#include <QRegularExpressionValidator>
//#include <QRegularExpression>

#include <snake.h>
#include <breakout.h>

class Menu : public QWidget
{
    Q_OBJECT
public:
    //QRegularExpressionValidator valid;
    explicit Menu(QWidget *parent = nullptr);
    QLineEdit *nickname;
protected:
    QPushButton *button, *button2;
private:
    QString str;
    Snake *game_snake;
    Breakout *game_breakout;
    QLabel *label;
public slots:
    void snake();
    void breakout();
    void setName();
};
#endif // MENU_H



// [[:alnum:]]
