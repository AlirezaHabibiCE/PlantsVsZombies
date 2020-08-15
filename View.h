#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QTimer>
#include "Controller.h"
#include <QMediaPlayer>

class View :  public QGraphicsView
{
    Q_OBJECT
private:
    QTimer * viewTimer;
    int seconds;
    Controller *viewController;
    QMediaPlayer * viewplayer;

public:
    explicit View();
    ~View();

public slots:
    void schedule();

signals:

public slots:
};

#endif // VIEW_H
