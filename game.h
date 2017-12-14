#ifndef GAME_H
#define GAME_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsTextItem>

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


class soldier2: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    soldier2();
public slots:
    void random_move();
};



class treasure:public QGraphicsRectItem{
public:
    treasure();

};


class treasure_collected: public QGraphicsTextItem{
public:
    treasure_collected(QGraphicsTextItem * parent = 0);
    void increase();
    int get_treasure();
private:
    int tc;
};

//int treasure_collected::tc = 0;

//void add_soldier1 (int number);





#endif // GAME_H





