#ifndef ITEM_H
#define ITEM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QList>
#include "player.h"

class Item: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Item();

public slots:
    void pickedUp();
};

#endif // ITEM_H
