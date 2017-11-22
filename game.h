#ifndef GAME_H
#define GAME_H
#include <QGraphicsRectItem>
#include <QObject>


class player: public QGraphicsRectItem{

private:
    //int treasure_collected;
    //int score;
public:
    //constructers not done
    void keyPressEvent(QKeyEvent * event);

};

class soldier1:public QGraphicsRectItem{
public:
    soldier1();

};


class treasure:public QGraphicsRectItem{
public:
    treasure();

};





class soldier2: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    soldier2();
public slots:
    void random_move();
};




//void add_soldier1 (int number);





#endif // GAME_H





