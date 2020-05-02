#include "score.h"
#include <QFont>
#include "game.h"

extern Game * game; // there is an external global object called game

Score::Score(QGraphicsItem * parent): QGraphicsTextItem(parent)
{
    //initialize scores
    redScore = game->red->getScore();
    blueScore = game->blue->getScore();
    // draw the score text
    setPlainText(QString("Red Score: ") + QString::number(redScore) + "\n" +
                 QString("Blue Score: ") + QString::number(blueScore));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times", 16));
}

void Score::increase()
{
    qDebug() << "Inside Score.Increase";

    redScore = game->red->getScore();
    qDebug() << "Red score: " << redScore;


    blueScore = game->blue->getScore();
    qDebug() << "Blue score: " << blueScore;

    // draw the score text
    setPlainText(QString("Red Score: ") + QString::number(redScore) + "\n" +
                 QString("Blue Score: ") + QString::number(blueScore));

}

int Score::getScore()
{
    return score_;
}
