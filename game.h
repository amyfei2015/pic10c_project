#ifndef GAME_H
#define GAME_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsTextItem>

using std::vector;

/* player class
 *
 * the player class inherits from the  QGraphicsRectItem class, and it's a square whos shape is decided in the gameboard.pp instead of by a constructor
 * the player can move according to keyboard directions and respond to collision with soldiers and treasures
 */
class player: public QGraphicsRectItem{
public:
    void keyPressEvent(QKeyEvent * event);

};


/* soldier1 class
 *
 * the psoldier1 class inherits from the  QGraphicsRectItem class, and it's a unmoving rectangle, whos position is generated randomly
 */
class soldier1:public QGraphicsRectItem{
public:
    soldier1();

};

/* soldier2 class
 *
 * the soldier2 class inherits from the  QGraphicsRectItem class, and it's a moving rectangle, whos initial position is generated randomly
 */
class soldier2: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    soldier2();
public slots:
    void random_move();
};


/* soldier2 class
 *
 * the treasure class inherits from the  QGraphicsRectItem class, whos initial position is also generated randomly
 */
class treasure:public QGraphicsRectItem{
public:
    treasure();

};

/* treasure_collected
 *
 * It's meant to show the treasure collected, but I haven't be able to increment the number yet
 */
class treasure_collected: public QGraphicsTextItem{
public:
    treasure_collected(QGraphicsTextItem * parent = 0);
    void shownewcount();
    int get_treasure();
    static int treasure_count ;
    };


/* Army1
 *
 * It's a collection of soldier1
 * I use vector to store pointers to the soldier1s created.
 */
class  Army1{
private:
    vector<soldier1*> army1;
public:
    Army1 (int number);
    soldier1* operator [](int index) const;
    vector<soldier1*>::iterator begin();
    vector<soldier1*>::iterator end();

};



//in fact, I can make a template class so that I dont need to write it three times...
//but haven't succeed yet
template <typename Object>
class  group{
private:
    vector<Object*> g;
public:
    group<Object> (int number);
    Object* operator [](int index) const;

};

//template class group<soldier1>;
//template class group<soldier2>;
//template class group<treasure>;

#endif // GAME_H





