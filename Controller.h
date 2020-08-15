#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <Zombie.h>
#include <QGraphicsRectItem>
#include <Score.h>
#include <Sun.h>

class Controller : public QObject
{
    Q_OBJECT
    friend class View;

private:
    QGraphicsScene *scene;
    QList<Zombie* > zombielist;
    QList<Sun* > sunList;
    QTimer *ctimer;
    QGraphicsRectItem *holder;
    Score *controllerscore;


public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();
    void addZombie(int velocity );
    void addSun();

signals:

public slots:
};

#endif // CONTROLLER_H
