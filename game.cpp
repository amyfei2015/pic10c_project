#include "game.h"
#include <QKeyEvent>
#include <cstdlib>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>
#include <QList>
#include <QFont>

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
            //increase treasure_collected

            //how to call an object in abother class> how to conect these two?
            //first try:
            /*
            tc -> increase(); // it doesn't work
            */
            //second try: in fact, I can/should make it a static int



            delete colliding_items[i];
        }

        if (typeid(*(colliding_items[i])) == typeid(soldier1)){
            //move back player to center, lives lost one
            setPos(600/2-10,600/2-10);
        }

        if (typeid(*(colliding_items[i])) == typeid(soldier2)){
            //remove treasure and treasure_count ++1;
            //move back player to center, lives lost one
            setPos(600/2-10,600/2-10);
        }

    }


}


soldier1::soldier1()
{
   setRect(0,0,15,25);

}



soldier2::soldier2()
{

    setRect(0,0,20,25);


    //keep it moving
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(random_move()));
    timer -> start(200);

}


void soldier2::random_move(){
    setPos(x(),y()-10);
    if (y() <0)
        setPos(x(),590);
}


/*
void add_soldier1(int number)
{
    std::vector<soldier1*> soldier1s;
    for (size_t i = 0;i<number;i++){
        soldier1s.push_back(new soldier1());
        scene() -> addItem (soldier1s[i]);
    }

}

*/

treasure::treasure()
{
    setRect(0,0,10,10);
}

treasure_collected::treasure_collected(QGraphicsTextItem *parent):QGraphicsTextItem(parent){
    //initialize the number to 0
    tc = 0;

    //draw the text
    setPlainText(QString("Treasure collected:") + QString::number(tc));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));

}

void treasure_collected::increase()
{
    ++tc;
}

int treasure_collected::get_treasure()
{
    return tc;
}
