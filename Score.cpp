#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent)
    :  QGraphicsTextItem (parent), playerscore{0}
{
    setPlainText(QString::number(playerscore));
    setDefaultTextColor(Qt::gray);
    setFont(QFont("times" , 13 ));
}

Score::~Score()
{
    delete scorePlayer;
}

void Score::addToScore(int s)
{
    playerscore += s;
    setPlainText(QString::number(playerscore));

    //create score player mediaplayer
    scorePlayer = new QMediaPlayer();
    scorePlayer->setMedia(QUrl("qrc:/Music/buzzer.mp3"));

}
