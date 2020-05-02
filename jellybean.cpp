#include "jellybean.h"
#include <QTimer>

extern Game * game; // there is an external global object called game

JellyBean::JellyBean()
{
    // draw the bean
    setPixmap(QPixmap(":/sprites/smallJellyBean.png"));

    // connect

    connect(game->timer, SIGNAL(timeout()), this, SLOT(move()));


}

void JellyBean::move()
{

    QList<QGraphicsItem*> colliding_items = collidingItems();
    // if one of the colliding items is a Player, increase Player score
    for (int i = 0, n = colliding_items.size(); i < n; i++)
    {
        qDebug() << typeid(*(colliding_items[i])).name();
        qDebug() << typeid(Blue).name();
        if (typeid(*(colliding_items[i])) == typeid(Red))
        {
            game->red->decreaseHealth();
            game->health->decrease();
            game->blue->increaseScore();
            game->score->increase();
            qDebug() << "PEW PEW! Red takes a hit!";
        }
        else if (typeid (*(colliding_items[i])) == typeid(Blue))
        {
            game->blue->decreaseHealth();
            game->health->decrease();
            game->red->increaseScore();
            game->score->increase();
            qDebug() << "PEW PEW! Blue takes a hit!";
        }

        scene()->removeItem(this);
        delete this;

        return;
    }
    // move
    //qDebug() << "Direction is " << this->direction_;
    setPos(x(), y() + this->direction_);//change this to follow other player

    /* delete bean bullets when they're off the scene */
    if(pos().y() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
