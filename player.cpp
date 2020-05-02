#include "player.h"
#include <QDebug>

#include "jellybean.h"
#include "item.h"

Player::Player()
{
    score_ = 0;
    health_ = 100;
    sugar_rush_ = false;

}

void Player::decreaseHealth()
{
    if (sugar_rush_)
    {
        health_ += 0;
    }
    else
    {
        health_ -= 10;
    }

}

void Player::increaseScore()
{
    score_ += 10;
}

void Player::sugarRush()
{
    score_ += 10;
    sugar_rush_ = true;
}

