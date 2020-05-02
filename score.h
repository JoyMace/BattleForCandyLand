#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include "player.h"

class Score : public QGraphicsTextItem
{
public:
    Score(QGraphicsItem * parent=0);
    void increase();
    int getScore();

    int redScore;
    int blueScore;

private:
    int score_;
};

#endif // SCORE_H
