#include "snake.h"
#include <QDebug>
#include <QTime>
#include <QMessageBox>

Snake::Snake(QWidget *parent)
    : QWidget{parent}
{
    this->resize(DOT_WIDTH * FEILD_WIDTH,DOT_HEIGHT * FEILD_HEIGHT );
    score_counter = new QLabel("score: 0", this);
    score_counter->move(20, 0);
    FRAME_WIDTH = width()-40;
    FRAME_HEIGHT = height()-40;
    this->setWindowTitle("snake");
    initGame();
}

void Snake::timerEvent(QTimerEvent *e)
{
    if (m_inGame)
    {
        checkApple();
        move();
        check_field();
    }
    this->update();
}

void Snake::keyPressEvent(QKeyEvent *e)
{
    int key = e->key();
    if(key==Qt::Key_Left && m_dir != Directions::right){m_dir = Directions::left;}
    if(key==Qt::Key_Right && m_dir != Directions::left){m_dir = Directions::right;}
    if(key==Qt::Key_Up && m_dir != Directions::down){m_dir = Directions::up;}
    if(key==Qt::Key_Down && m_dir != Directions::up){m_dir = Directions::down;}
}

void Snake::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    doDrawing();
}

void Snake::doDrawing(){
    QPainter qp(this);
    if (m_inGame)
    {
        qp.drawRect(20, 20, FRAME_WIDTH, FRAME_HEIGHT);
        qp.setBrush(Qt::yellow);
        qp.drawEllipse(m_apple.x() * DOT_WIDTH, m_apple.y() * DOT_HEIGHT, DOT_WIDTH, DOT_HEIGHT);
        for (int i=0; i<m_dots.size();++i)
        {
            if(i == 0)
            {
                qp.setBrush(Qt::red);
                qp.drawEllipse(m_dots[i].x() * DOT_WIDTH, m_dots[i].y() * DOT_HEIGHT, DOT_WIDTH, DOT_HEIGHT);
            }
            else
            {
                qp.setBrush(Qt::green);
                qp.drawEllipse(m_dots[i].x() * DOT_WIDTH, m_dots[i].y() * DOT_HEIGHT, DOT_WIDTH, DOT_HEIGHT);
            }
        }
    }
    else
    {
        qp.end();
        QPainter painter(this);
        gameOver(&painter, "Game over, ");
    }
}

void Snake::localApple()
{
    QTime time= QTime::currentTime();
    srand((uint)time.msec());

    m_apple.rx()= rand() % (DOT_WIDTH-2)+1;
    m_apple.ry()= rand() % (DOT_HEIGHT-2)+1;
}

void Snake::move()
{
    for (int i = m_dots.size()-1; i>0; --i)
    {
        m_dots[i]=m_dots[i-1];
    }
    switch (m_dir){
    case left: {m_dots[0].rx() -= 1; break;}
    case right: {m_dots[0].rx() += 1; break;}
    case up: {m_dots[0].ry() -= 1; break;}
    case down: {m_dots[0].ry() += 1; break;}
}
}

void Snake::check_field()
{
    if(m_dots.size()>4)
   {

        for (int i=1; i<m_dots.size(); ++i)
        {
            if(m_dots[0] == m_dots[i])
            {
               m_inGame= false;
            }
        }
    }
    if(m_dots[0].x() >= FEILD_WIDTH-1)
    {
        m_inGame=false;
    }
    if(m_dots[0].x() < 1)
    {
        m_inGame=false;
    }
    if(m_dots[0].y() >= FEILD_HEIGHT-1)
    {
        m_inGame=false;
    }
    if(m_dots[0].y() < 1)
    {
        m_inGame=false;
    }
    if(!m_inGame)
    {
        killTimer(timerId);
    }
}

void Snake::gameOver(QPainter *painter, QString message)
{
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = 0;

    painter->setFont(font);
    int h = height();
    int w = width();

    painter->translate(QPoint(w/2, h/2));
    painter->drawText(-textWidth/2, 0, message);

    score_counter->setText(tr("score: %1").arg(score));

    /*score=0;
    score_counter->setText(tr("score: %1").arg(score));
    initGame();*/
}

void Snake::checkApple()
{
    if (m_apple== m_dots[0])
    {
        m_dots.push_back(QPoint(0,0));
        localApple();
        //QMessageBox msgr;
        //msgr.setText("вы получили очко!");
        //msgr.exec();
        score++;
        score_counter->setText(tr("score: %1").arg(score));
    }
}

void Snake::initGame(){
    m_inGame=true;
    m_dots.resize(3);
    for(int i=0; i<m_dots.size();++i){
        m_dots[i].rx()=10;//m_dots.size()-i;
        m_dots[i].ry()=10;
    }
   localApple();
   timerId = startTimer(DELAY);

}
