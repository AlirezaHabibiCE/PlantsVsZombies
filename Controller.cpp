#include "Controller.h"

Controller::Controller(QObject *parent) : QObject(parent)
{
    // create scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0 , 0 , 800 , 600);

    //create holder
    holder = new QGraphicsRectItem();
    holder->setRect(0,0,800,600);

    //create and start ctimer
    ctimer = new QTimer();
    ctimer->start(40);

    //add score
    controllerscore = new Score(holder);
    scene->addItem(controllerscore);
    controllerscore->setPos(32, 55);
}

Controller::~Controller(){
     delete holder;
     delete scene;
    delete ctimer;
}

void Controller::addZombie( int velocity )
{   //add zombie to list
    zombielist.push_back(new Zombie{velocity , ctimer , holder});
    // add zombie to scene
    scene->addItem(zombielist.last());
    zombielist.last()->setPos(800 , 400);
}

void Controller::addSun()
{
    sunList.push_back(new Sun{scene, controllerscore, holder, ctimer});
}
