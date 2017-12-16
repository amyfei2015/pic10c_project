#include "gameboard.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <cstdlib>
#include <QDebug>

Game * game; //so that it can be accest by other classes
extern clock_t startTime;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   game = new Game();
   game->show();




   double secondsPassed;
   bool flag = true;


   while(flag)
   {

       secondsPassed = (clock() - startTime) / (double)CLOCKS_PER_SEC;

       if(secondsPassed >= 10)
       {
           flag =  false;
       }
   }
    qDebug() <<"10 secs" ;
    QString result;

    if (treasure_collected::treasure_count == 5)
        result = "Yes, you have collected all treasures! ";
    else
        result =QString("Sorry, you still have ")+QString::number(5 - treasure_collected::treasure_count) +QString(" more treasures to collect but tie's up!");

     qDebug()<<result<<"gameboard";

    return a.exec();

}
