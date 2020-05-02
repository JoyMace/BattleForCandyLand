#ifndef JELLYBEAN_H
#define JELLYBEAN_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include "game.h"
#include "player.h"

class JellyBean: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    JellyBean();
    void setDirection(int direction) { direction_ = direction; }
    int getDirection() { return direction_; }
    int direction_; // 10 for down, -10 for up

public slots:
    void move();
};

#endif // JELLYBEAN_H
