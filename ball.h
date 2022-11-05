#ifndef BALL_H
#define BALL_H

#include <QWidget>
#include <QRect>
#include <QPixmap>
#include <QPainter>

class Ball : public QWidget
{
    Q_OBJECT
public:
    explicit Ball(QWidget *parent = nullptr);
    ~Ball();
public slots:
  void resetState();
  void autoMove();
  void setXDir(int);
  void setYDir(int);
  int getXDir();
  int getYDir();
  QRect getRect();
  QImage & getImage();
private:
  int xdir;
  int ydir;
  QImage image;
  QRect rect;
  static const int INITIAL_X = 150;
  static const int INITIAL_Y = 230;
  static const int RIGHT_EDGE = 320;
};

#endif // BALL_H

