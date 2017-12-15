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
            ++ treasure_collected::treasure_count;
            //game->tc->shownewcount();//need to be fixed


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

    //draw the text
    setPlainText(QString("Treasure collected:") + QString::number(treasure_count));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));

}

int treasure_collected :: treasure_count = 0;

void treasure_collected::shownewcount()
{

    setPlainText(QString("Treasure collected:") + QString::number(treasure_collected::treasure_count));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));


    qDebug()<<"wrong?";
}



int treasure_collected::get_treasure()
{
    return treasure_count;
}


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
