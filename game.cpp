#include "game.h"
#include <QKeyEvent>
#include <cstdlib>
#include <QGraphicsScene>
#include <Qtimer>
#include <QObject>

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


}


soldier1::soldier1()
{
    //we need two random numbers to set its location
    int s1 = rand() % 570 + 5 ;//we dont want soldiers to be at corners
    int  s2 = rand() % 570 + 5 ;
    setRect(s1,s2,20,20);

}



soldier2::soldier2()
{

    // create the soldier
    //we need two random numbers to set its location
    int s1 = rand() % 570 + 5 ;//we dont want soldiers to be at corners
    int  s2 = rand() % 570 + 5 ;
    setRect(s1,s2,20,20);


    //keep it moving
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(random_move()));
    timer -> start(100);

}



void soldier2::random_move(){
    setPos(x(),y()-10);
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
    int s1 = rand() % 570 + 5 ;//we dont want soldiers to be at corners
    int  s2 = rand() % 570 + 5 ;
    setRect(s1,s2,20,20);
}
