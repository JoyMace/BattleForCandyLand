#ifndef GAME_H
#define GAME_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <player.h>
#include <jellybean.h>
#include <item.h>
#include <QTimer>
#include <QDebug>
#include "score.h"
#include "red.h"
#include "blue.h"
#include "healthtext.h"
#include <QList>
#include "sprinkles.h"
#include "caramelsyrup.h"
#include "chocolatesyrup.h"
#include "cherries.h"
#include <QTimer>

/* Main Game Object handles all keyPressEvents and game logic */
class Game: public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget * parent=NULL);

    void keyPressEvent(QKeyEvent * event);
    Red * red = new Red(); // p1
    Blue * blue = new Blue(); // p2
    Score * score;
    HealthText * health;
    QGraphicsScene * scene;

    QList<Item *> items; //items like sprinkles etc
    QList<QPoint> positions; //valid places to put items

    QTimer * timer = new QTimer(); //timer for all things

public slots:
    void start();
private:



};

#endif // GAME_H
