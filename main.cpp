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
    scene ->setSceneRect(0,0,600,600);

   //add a player
    player* plr = new player();
    plr -> setRect(0,0,20,20); //the first two is the xy coordinate of its upper left corner, and the following two are for the right lower coner

    //add item to the scene
    scene -> addItem(plr);




    // add a soldier 1
     int number_1 = 5;
     std::vector<soldier1*> soldier1s;
     for (int i = 0;i<number_1;i++){
         soldier1s.push_back(new soldier1());
         int s1 = rand() % 570 + 5 ;//we dont want soldiers to be at corners
         int  s2 = rand() % 570 + 5 ;
         soldier1s[i] -> setPos(s1,s2);
         scene -> addItem (soldier1s[i]);
     }



     //add soldier 2
     int number_2 = 3;
     std::vector<soldier2*> soldier2s;
     for (int i = 0;i<number_2;i++){
         soldier2s.push_back(new soldier2());
         int s1 = rand() % 570 + 5 ;//we dont want soldiers to be at corners
         int  s2 = rand() % 570 + 5 ;
         soldier2s[i]->setPos(s1,s2);
         scene -> addItem (soldier2s[i]);
     }



    //add treasure
     int number_t = 3;
     std::vector<treasure*> treasures;
     for (int i = 0;i<number_t;i++){
         treasures.push_back(new treasure());
         int s1 = rand() % 570 + 5 ;//we dont want soldiers to be at corners
         int  s2 = rand() % 570 + 5 ;
         treasures[i]->setPos(s1,s2);
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


    //set the position of the player at the middle of the scene
    plr->setPos(view->width()/2-10,view->height()/2-10);


    return a.exec();
}
