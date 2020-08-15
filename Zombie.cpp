#include "Zombie.h"
#include <QMediaPlayer>

Zombie::Zombie(const int& pixPer40MiliSec , QTimer * timer , QGraphicsItem * parent)
    : QObject () , QGraphicsPixmapItem (parent) , pixPer40MiliSec{pixPer40MiliSec}
{
    setPixmap(QPixmap(":/images/zombies-1.png"));    //set picture for zombie

    //implement zombie move to left
    connect(timer , SIGNAL(timeout()), this , SLOT(moveToLeft()) );

    //zombie sound!!!
    zombieplayer = new QMediaPlayer();
    zombieplayer->setMedia(QUrl("qrc:/Music/sukhbir.mp3"));
    zombieplayer->play();
}

Zombie::~Zombie()
{
    delete zombieplayer;
}

void Zombie::moveToLeft(){
    setPos( x()-pixPer40MiliSec , y());
    int x = this->pos().x();

    if (x % 90 == 2){
        setPixmap(QPixmap(":/images/zombies-1.png"));
    }
    else if (x % 90 == 74){
        setPixmap(QPixmap(":/images/zombies-2.png"));
    }
    else if (x % 90 == 56){
        setPixmap(QPixmap(":/images/zombies-3.png"));
    }
    else if (x % 90 == 38){
        setPixmap(QPixmap(":/images/zombies-4.png"));
    }
    else if (x % 90 == 20){
        setPixmap(QPixmap(":/images/zombies-3.png"));
    }

    if( x == 2 ){
        exit(1);
    }
}
