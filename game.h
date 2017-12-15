#ifndef GAME_H
#define GAME_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsTextItem>

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



class  Army1{
private:
    vector<soldier1*> army1;
public:
    Army1 (int number);
    soldier1* operator [](int index) const;

};



//in fact, I can make a template class so that I dont need to write it three times...
template <typename Object>
class  group{
private:
    vector<Object*> g;
public:
    group<Object> (int number);
    Object* operator [](int index) const;

};



#endif // GAME_H





