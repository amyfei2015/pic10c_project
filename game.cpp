#include "game.h"
#include <QKeyEvent>
#include <cstdlib>
#include <QGraphicsScene>
#include <Qtimer>
#include <QObject>
#include <QList>

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
