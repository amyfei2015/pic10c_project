#include "gameboard.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <cstdlib>

Game * game;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   Game *  game = new Game();
        game->show();
    return a.exec();
}
