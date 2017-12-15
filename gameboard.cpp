#include "gameboard.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <algorithm>



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
    //we can also define that by writing a constructor as we do for the other soldiers and treasure

    //add item to the scene
    scene -> addItem(plr);

    //make rect focusable
   plr-> setFlag(QGraphicsItem::ItemIsFocusable);
   plr -> setFocus();

   //set the position of the player at the middle of the scene
   plr->setPos(600/2-10,600/2-10);


    group<soldier1>  am1(3);
//I tried to capture[scene] or [&scece] and It shows that 'scene' cannot be captured, so we probably cannot do the for_each and lambda function instead of using "scene -> addItem..."
    for (int i = 0;i<3;++i)
        scene -> addItem (am1[i]);
    //[ scene](soldier1* s){scene -> addItem(s);}(am1[i]);


   group<soldier2> am2(5);
   for (int i = 0;i<5;++i)
        scene -> addItem (am2[i]);

   //add treasure
   group<treasure> trea(5);
   for (int i = 0;i<5;++i)
        scene -> addItem (trea[i]);


     /* need to be fixed
     treasure_collected* tc = new treasure_collected();
     scene -> addItem(tc);
*/




}
