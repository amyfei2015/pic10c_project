#include "gameboard.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <cstdlib>

Game * game; //so that it can be accest by other classes
treasure_collected*  tc;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   game = new Game();
   game->show();
    return a.exec();
}
