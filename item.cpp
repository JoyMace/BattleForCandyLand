#include "item.h"
#include "game.h"
extern Game * game; // there is an external global object called game

Item::Item()
{
    connect(game->timer, SIGNAL(timeout()), this, SLOT(pickedUp()));
}

void Item::pickedUp()
{
    //check for collisions with Player
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if (typeid(*(colliding_items[i])) == typeid(Red))
        {
            //remove item from scene
            scene()->removeItem(this);
            // add item.score to player
            game->red->increaseScore();
            game->score->increase();
            //delete item
            delete this;
            return;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Blue))
        {
            //remove item from scene
            scene()->removeItem(this);
            // add item.score to player
            game->blue->increaseScore();
            game->score->increase();
            //delete item
            delete this;
            return;
        }
    }


}
