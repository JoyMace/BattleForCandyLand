#include "healthtext.h"
#include <QtDebug>
#include "game.h"
extern Game * game; // there is an external global object called game

HealthText::HealthText(QGraphicsItem *parent)
{
    //initialize scores
    redHealth = game->red->getHealth();
    blueHealth = game->blue->getHealth();
    // draw the score text
    setPlainText(QString("Red Health: ") + QString::number(redHealth) + "\n" +
                 QString("Blue Health: ") + QString::number(blueHealth));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

void HealthText::decrease()
{
    qDebug() << "Inside Score.Increase";

    redHealth = game->red->getHealth();
    qDebug() << "Red Health: " << redHealth;


    blueHealth = game->blue->getHealth();
    qDebug() << "Blue Health: " << blueHealth;

    // draw the score text
    setPlainText(QString("Red Health: ") + QString::number(redHealth) + "\n" +
                 QString("Blue Health: ") + QString::number(blueHealth));
}
