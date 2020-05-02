#include <QApplication>
#include <QGraphicsScene>
#include "player.h"
#include "game.h"
#include <QGraphicsView>
#include <QDebug>

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show();
    game->start();

    return a.exec();
}
