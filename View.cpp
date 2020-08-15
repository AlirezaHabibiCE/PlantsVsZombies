#include "View.h"

View::View() : QGraphicsView()
{
    //create view controller
    viewController = new Controller();

    //implement scene
    setScene(viewController->scene);
    setFixedSize(800,600);
    setBackgroundBrush(QBrush(QImage(":/images/background1.png")));

    //set scrolls bar off
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //set background music
    viewplayer = new QMediaPlayer();
    viewplayer->setMedia(QUrl("qrc:/Music/MainMenuPvZ1.mp3"));
    viewplayer->play();

    seconds = 0;//initialize second to zero

    //start timer
    viewTimer = new QTimer();
    viewTimer->start(1000);

    connect(viewTimer , SIGNAL(timeout()) , this , SLOT(schedule()));
}

void View::schedule(){
    ++seconds;

    if( seconds == 20 || seconds == 23 ){
        viewController->addZombie(3);
    }

    if( seconds%2 == 0){
        viewController->addSun();
    }
}

View::~View(){
    delete viewTimer;
    delete viewplayer;
    delete viewController;
}
