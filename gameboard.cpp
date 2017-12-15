#include "gameboard.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <functional> //is foreach here??



Game::Game(QWidget *parent){
    srand(time(NULL));
    // Create a scene
    scene = new QGraphicsScene();
    scene ->setSceneRect(0,0,600,600);

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
       // it can be used to visualize scenes)
       setScene(scene);
       setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//as we have fixed the size of scene
       setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
       setFixedSize(600,600);



   //add a player
    player* plr = new player();
    plr -> setRect(0,0,20,20); //the first two is the xy coordinate of its upper left corner, and the following two are for the right lower coner

    //add item to the scene
    scene -> addItem(plr);



/*
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


    int number_1 = 5;
    std::vector<soldier1*> soldier1s;
    for (int i = 0;i<number_1;i++){
        soldier1s.push_back(new soldier1());
        int s1 = rand() % 570 + 5 ;//we dont want soldiers to be at corners
        int  s2 = rand() % 570 + 5 ;
        soldier1s[i] -> setPos(s1,s2);
    }
     Assume we have
    group<soldier1> group_s1(3);
    replacing vector... then we need

    for (int i = 0;i<number_1;++i){
         scene -> addItem (soldier1s[i]);
    }

    //if we got group setup, we could use a lambd function to avoid loops!
*/
    Army1 am1(3);
/*so now we can try generic algorithm to avoid for loop
 *so we need to use begin() and end() to return pointers at the start and end of the vector storing the values
 *Then the iterators of vectors would take care of this
 */


    for (int i = 0;i<3;++i){
         scene -> addItem (am1[i]);
    }

    //foreach (am1.begin(),am1.end(),
      //      [](soldier1* s){scene -> addItem(s);});

//forget which library for each is in, so try lambda  function first
 //   for (int i = 0;i<3;++i){
   //          [](soldier1* s){scene -> addItem(s);}(am1[i]);
     //   }




     //add soldier 2
     int number_2 = 5;
     std::vector<soldier2*> soldier2s;
     for (int i = 0;i<number_2;i++){
         soldier2s.push_back(new soldier2());
         int s1 = rand() % 570 + 5 ;//we dont want soldiers to be at corners
         int  s2 = rand() % 570 + 5 ;
         soldier2s[i]->setPos(s1,s2);
         //scene -> addItem (soldier2s[i]);
     }

     //well, showing that 'this' cannot be implicitly captured in this contect
     for (int i = 0;i<3;++i){
              [](soldier2* s){scene -> addItem(s);}(soldier2s[i]);
         }



    //add treasure
     int number_t = 5;
     std::vector<treasure*> treasures;
     for (int i = 0;i<number_t;i++){
         treasures.push_back(new treasure());
         int s1 = rand() % 570 + 5 ;//we dont want soldiers to be at corners
         int  s2 = rand() % 570 + 5 ;
         treasures[i]->setPos(s1,s2);
         scene -> addItem (treasures[i]);
     }


     //add a counter for trasure collected

     /* need to be fixed
     treasure_collected* tc = new treasure_collected();
     scene -> addItem(tc);
*/

     //make rect focusable
    plr-> setFlag(QGraphicsItem::ItemIsFocusable);
    plr -> setFocus();





    //set the position of the player at the middle of the scene
    plr->setPos(600/2-10,600/2-10);



}
