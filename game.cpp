#include "game.h"
#include <QImage>
// TO DO: The players need to be 2 objects on the same view they can't both be controlled
// by the game, or else only one can move at a time
// so you need to fix that
Game::Game(QWidget *parent)
{
    //get rid of scroll bars
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setFixedSize(1024, 768);

    // set up the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,768);
    setBackgroundBrush(QBrush(QImage(":/sprites/background.png")));
    setScene(scene);


    qDebug() << "GAME MADE";


}
/* Need to know if P1 or P2 presse the key, then move as appropriate */
void Game::keyPressEvent(QKeyEvent *event)
{
    /* Player 1 uses Arrows and Enter */
    if (event->key() == Qt::Key_Left)
    {
        if (red->pos().x() > 0)
        {
            red->setPos(red->x() - 10, red->y());
        }

    }
    else if (event->key() == Qt::Key_Right)
    {
        if (red->pos().x() + 100 < 1024)
        {
            red->setPos(red->x() + 10, red->y());
        }
    }
    else if (event->key() == Qt::Key_Up) //to do: add checks for top and bottom boundaries
    {
        red->setPos(red->x(), red->y() - 10);
    }
    else if (event->key() == Qt::Key_Down)
    {
        red->setPos(red->x(), red->y() + 10);
    }
    else if (event->key() == Qt::Key_Enter) //p1 shoot
    {
        JellyBean * bean = new JellyBean();
        bean->setPos(red->x(), red->y()-51);
        bean->setDirection(-10);
        qDebug() << "BANG!";
        scene->addItem(bean);
    }

    /* Player 2 uses WADS and Shift */
    else if (event->key() == Qt::Key_A) // move left
    {
        if (blue->pos().x() > 0)
        {
            blue->setPos(blue->x() - 10, blue->y());
        }

    }
    else if (event->key() == Qt::Key_D) // move right
    {
        if (blue->pos().x() + 100 < 1024)
        {
            blue->setPos(blue->x() + 10, blue->y());
        }
    }
    else if (event->key() == Qt::Key_W) // move up
    {
        blue->setPos(blue->x(), blue->y() - 10);
    }
    else if (event->key() == Qt::Key_S) // move down
    {
        blue->setPos(blue->x(), blue->y() + 10);
    }
    else if (event->key() == Qt::Key_Shift) //p2 shoot
    {
        JellyBean * bean = new JellyBean();
        bean->setPos(blue->x(), blue->y()+101);
        bean->setDirection(10);
        qDebug() << "BANG!";
        scene->addItem(bean);
    }
}

void Game::start()
{
    // set Players on board
    red->setPos(900, 600); // bottom right corner
    blue->setPos(100, 100); // top left corner


    // add players to scene
    scene->addItem(red);
    scene->addItem(blue);

    // make players focusable
    red->setFlag(QGraphicsItem::ItemIsFocusable);
    red->setFocus(); //this item is in focus and respond to events

    blue->setFlag(QGraphicsItem::ItemIsFocusable);
    //p2->setFocus(); //this item is in focus and respond to events

    // make score item
    score = new Score();
    scene->addItem(score);

    health = new HealthText();
    health->setPos(health->x() + 300, health->y());
    scene->addItem(health);


    Sprinkles * sprinkles = new Sprinkles();
    Sprinkles * sprinkles2 = new Sprinkles();
    Sprinkles * sprinkles3 = new Sprinkles();

    ChocolateSyrup * chocSyrup = new ChocolateSyrup();
    ChocolateSyrup * chocSyrup2 = new ChocolateSyrup();

    CaramelSyrup * carSyrup = new CaramelSyrup();
    CaramelSyrup * carSyrup2 = new CaramelSyrup();

    Cherries * cherries = new Cherries();
    Cherries * cherries2 = new Cherries();


    items.append(sprinkles);
    items.append(chocSyrup);
    items.append(sprinkles2);
    items.append(carSyrup);
    items.append(cherries);
    items.append(chocSyrup2);
    items.append(cherries2);
    items.append(sprinkles3);
    items.append(carSyrup2);


    QPoint p(30,415);
    QPoint p1(190,340);
    QPoint p2(270, 200);
    QPoint p3(270, 490);
    QPoint p4(505, 275);
    QPoint p5(740, 200);
    QPoint p6(740, 640);
    QPoint p7(660, 710);
    QPoint p8(885, 490);
    positions = { p, p1, p2, p3, p4, p5, p6, p7, p8 };
    for (int i = 0; i < items.size(); i++)
    {
        scene->addItem(items[i]);
        items[i]->setPos(positions[i]);

    }




    timer->start(50);

    qDebug() << "GAME STARTED";
}
