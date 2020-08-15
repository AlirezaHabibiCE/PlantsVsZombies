#include "Sun.h"
#include <cstdlib>

Sun::Sun(QGraphicsScene *sunScene, Score *sunScore,
         QGraphicsItem *parent ,QTimer *timer)
    : QObject () , QGraphicsPixmapItem (parent) ,
     sunScene(sunScene) , sunScore(sunScore), timeIntervals{0}
{
   setPixmap(QPixmap(":/images/sun-1.png"));

   //add to sunScene
   sunScene->addItem(this);
   setPos(rand()%725 , 0);

   //connect timer to move
   connect (timer , SIGNAL(timeout()) , this , SLOT (move()));
}



void Sun::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // add score
    sunScore->addToScore(25);

    //play sound of click
    sunScore->scorePlayer->play();

    //remove and delete
    sunScene->removeItem(this);
    delete this;
}

void Sun::move()
{   //increament timeIntervals
    ++timeIntervals;

    //move downward
    setPos(x() , y()+3);

    //remove nad delete
    if(timeIntervals == 50 || y()>700){
        sunScene->removeItem(this);
        delete this;
    }
}
