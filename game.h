﻿#ifndef GAME_H
#define GAME_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsTextItem>
#include <QDebug>

/*
 * @ The Player class
 * The player class is inherited from QGraphicsRectItem class,responding to keyboard directions
 */

using std::vector;

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
    void shownewcount();
    int get_treasure();
    static int treasure_count ;
    };



//void add_soldier1 (int number);

class Army1 {
private:
    vector<soldier1*> army1;
public:
    Army1(int number);
    ~Army1() ;
    soldier1* operator[](int index) const;



};




#endif // GAME_H





