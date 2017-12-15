#include "gameboard.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>



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
     int number_1 = 3;
     std::vector<soldier1*> soldier1s;
     for (int i = 0;i<number_1;i++){
         soldier1s.push_back(new soldier1());
         int s1 = rand() % 570 + 5 ;//we dont want soldiers to be at corners
         int  s2 = rand() % 570 + 5 ;
         soldier1s[i] -> setPos(s1,s2);
         scene -> addItem (soldier1s[i]);
     }
*/

    //add army 1
    int number_soldier1 = 3;
    Army1 army1(3);
    //qDebug()<< "position 1\n";
    for (int i = 0;i<number_soldier1;++i)
        scene -> addItem (army1[i]);
    //qDebug()<< "position 2\n";




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


     //add a counter for trasure collected

     //treasure_collected* tc = new treasure_collected();
     //tc = new treasure_collected();
     //scene -> addItem(tc);


     //make rect focusable
    plr-> setFlag(QGraphicsItem::ItemIsFocusable);
    plr -> setFocus();





    //set the position of the player at the middle of the scene
    plr->setPos(600/2-10,600/2-10);

    //qDebug()<<"position 3\n";
}


// I could probablydo it, but before that, I should solve the memory leak
template<typename object>
vector<object*> make_object (int x);

