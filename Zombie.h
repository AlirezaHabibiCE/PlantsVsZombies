#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QMediaPlayer>

class Zombie : public QObject , public QGraphicsPixmapItem
{
     Q_OBJECT

private:
    int lives;
    int pixPer40MiliSec;// 25x = pixle per second
    QMediaPlayer *zombieplayer;

public:
    Zombie( const int& pixPer40MiliSec , QTimer * timer
            ,QGraphicsItem * parent);
    ~Zombie();
public slots:
    void moveToLeft ();

};

#endif // ZOMBIE_H
