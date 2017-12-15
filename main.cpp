#include "gameboard.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <cstdlib>
#include <QDebug>

Game * game; //so that it can be accest by other classes
treasure_collected*  tc;

int main(int argc, char *argv[])
{
   qDebug()<<"position 4";
   QApplication a(argc, argv);

   game = new Game();
   game->show();

qDebug()<<"position 4";
    return a.exec();
}
