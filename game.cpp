#include "game.h"
#include "gameboard.h"
#include <QKeyEvent>
#include <cstdlib>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>
#include <QList>
#include <QFont>

#include <QDebug>//for debuging

extern Game* game;

/* The player responds to directions
 * When it confronts a soldier, it's sent back to its initial position;
 * When it confronts a treasurem it picks the trasure so that the treasure is removed from scene and the count increments
 */
void player::keyPressEvent(QKeyEvent *event)
{


    //write the codes for player to move; make sure the player doesn't go out of screen
    if (event -> key() == Qt::Key_Left){
        if (pos().x() > 0)
            setPos(x()-10,y());
    }
    else if (event -> key() == Qt::Key_Right)
    {
        if (pos().x() <580)
            setPos(x()+10,y());
    }

    else if (event -> key() == Qt::Key_Up){
        if (pos().y() > 0)
            setPos(x(),y()-10);
    }
    else if (event -> key() == Qt::Key_Down){
        if (pos().y() < 580)
            setPos(x(),y()+10);
    }

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0,n = colliding_items.size();i<n;++i){
        if (typeid(*(colliding_items[i])) == typeid(treasure)){
            //remove treasure and treasure_count ++1;
            scene() -> removeItem(colliding_items[i]);


            {//work needs t be done here
            //increase treasure_collected
            //how to call an object in abother class> how to conect these two?
            //first try:
            /*
            tc -> increase(); // it doesn't work
            */
            //second try: in fact, I can/should make it a static int
            ++ treasure_collected::treasure_count;
            //game->tc->shownewcount();//need to be fixed

            }

            delete colliding_items[i];

        }

        if (typeid(*(colliding_items[i])) == typeid(soldier1) || typeid(*(colliding_items[i])) == typeid(soldier2)){
            //move back player to center, lives lost one
            setPos(600/2-10,600/2-10);
        }

    }
}


soldier1::soldier1()
{
   setRect(0,0,15,25);
}


//soldier2 keeps moving upwards after being generated and returns from the bottom of the scene after it leaves from the top of the scene
soldier2::soldier2()
{

    setRect(0,0,20,25);

    //keep it moving
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(random_move()));
    timer -> start(200);

}

//helper function to define move
void soldier2::random_move(){
    setPos(x(),y()-10);
    if (y() <0)
        setPos(x(),590);
}



treasure::treasure()
{
    setRect(0,0,10,10);
}



treasure_collected::treasure_collected(QGraphicsTextItem *parent):QGraphicsTextItem(parent){
    //initialize the number to 0

    //draw the text
    setPlainText(QString("Treasure collected:") + QString::number(treasure_count));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));

}

//static variable defined outside function
int treasure_collected :: treasure_count = 0;


/*This is the part to be fixed
 * it it's turned to a static function, the codes do not work
 * but if it's an object, how do Irefer to it before it's created?
 * probably whole thing should be made into the player class?
 *
 */
void treasure_collected::shownewcount()
{

    setPlainText(QString("Treasure collected:") + QString::number(treasure_collected::treasure_count));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));


    qDebug()<<"wrong?";
}


//it's not used yet and may be deleted later
int treasure_collected::get_treasure()
{
    return treasure_count;
}


//here we genrate a group of soldiers and assign their positions randomly
//Note that the positions cannot be decided in constructor as different scales are used there
Army1::Army1(int number)
{
    for (int i = 0; i< number; ++i){
        try{
            army1.push_back(new soldier1());
        }catch(std::exception &e)
        {
            for (int j = i;j>=0;--j){
                delete army1[j];
                army1[j] = nullptr;
                throw;
            }
        }
        int s1 = rand() % 570 + 5 ;//we dont want soldiers to be at corners
        int  s2 = rand() % 570 + 5 ;
        army1[i] -> setPos(s1,s2);


    }
}

//the three operators below are similar to how they work for a std::vector
soldier1 * Army1::operator [](int index) const
{
    return army1[index];
}

vector<soldier1*>::iterator Army1::begin()
{
    return army1.begin();
}

vector<soldier1*>::iterator Army1::end()
{
    return army1.end();
}




/*
template<typename Object>
group<Object>::group(int number)
{
    for (int i = 0; i< number; ++i){
        try{
            g.push_back(new Object());
        }catch(std::exception &e)
        {
            for (int j = i;j>=0;--j){
                delete g[j];
                g[j] = nullptr;
                throw;
            }
        }
        int s1 = rand() % 570 + 5 ;//we dont want soldiers to be at corners
        int  s2 = rand() % 570 + 5 ;
        g[i] -> setPos(s1,s2);


    }
}

template<typename Object>
Object *group<Object>::operator [](int index) const
{
    return g[index];
}
*/
