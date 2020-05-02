#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>



class Player: public QGraphicsPixmapItem
{
public:
    Player();


    int getScore() { return score_; }
    int getHealth() { return health_; }
    bool getSugarRush() { return sugar_rush_; }

public slots:
    void decreaseHealth();
    void increaseScore();
    void sugarRush();

private:
    int score_;
    int health_;
    bool sugar_rush_;

};

#endif // PLAYER_H
