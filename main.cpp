#include "game.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <cstdlib>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    srand(time(NULL));
    // Create a scene
    QGraphicsScene * scene = new QGraphicsScene();


   //add a player
    player* plr = new player();
    plr -> setRect(0,0,20,20); //the first two is the xy coordinate of its upper left corner, and the following two are for the right lower coner

    //add item to the scene
    scene -> addItem(plr);




    // add a soldier 1
     int number_1 = 0;
     std::vector<soldier1*> soldier1s;
     for (size_t i = 0;i<number_1;i++){
         soldier1s.push_back(new soldier1());
         scene -> addItem (soldier1s[i]);
     }



     //add soldier 2
     int number_2 = 3;
     std::vector<soldier2*> soldier2s;
     for (size_t i = 0;i<number_2;i++){
         soldier2s.push_back(new soldier2());
         scene -> addItem (soldier2s[i]);
     }



    //add treasure
     int number_t = 1;
     std::vector<treasure*> treasures;
     for (size_t i = 0;i<number_t;i++){
         treasures.push_back(new treasure());
         scene -> addItem (treasures[i]);
     }

    //make rect focusable
    plr-> setFlag(QGraphicsItem::ItemIsFocusable);
    plr -> setFocus();



    //add treasures
    //add a door



    //add a view
    QGraphicsView *view = new QGraphicsView(scene);


    //set size of the screen
    view -> show();
    view-> setFixedSize(600,600);
    scene ->setSceneRect(0,0,600,600);

    //set the position of the player at the middle of the scene
    plr->setPos(view->width()/2-10,view->height()/2-10);


    return a.exec();
}
