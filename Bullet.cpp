#include "Bullet.h"
#include <QGraphicsScene>

Bullet::Bullet(QTimer *bulletTimer, const int &velocity,
               QGraphicsItem *parent):
    QObject (), QGraphicsPixmapItem (parent), velocity(velocity)
{
    //set picture
    setPixmap(QPixmap(":/images/bullet.png"));

    //connect move to right
    connect (bulletTimer , SIGNAL(timeout()) , this , SLOT(moveToRight()));
}

void Bullet::moveToRight()
{
    //move to right
    setPos(x()+velocity , y());

    //delete if bullet is out of stream
    if(x() > 850){
        scene()->removeItem(this);
        delete this;
    }
}
