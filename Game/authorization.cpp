#include "authorization.h"

Authorization::Authorization(QWidget *parent)
    : QWidget(parent)
{
    this->resize(600, 600);

    Nickname = new QLineEdit (this);
    Nickname->move(230,280);
}

Authorization::~Authorization()
{

}
