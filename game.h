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



/* Group
 *
 * It's a template class which can be used to generate groups of objects,eg.soldier1;
 * I use vector to store pointers to the objects saved here.
 */
template <typename Object>
class  group{
private:
    vector<Object*> g;
public:
    group<Object> (int number);
    Object* operator [](int index) const;

};










/* treasure_collected
 *
 * It's meant to show the treasure collected, but I haven't be able to show the incremented umber yet
*/
class treasure_collected: public QGraphicsTextItem{
public:
    treasure_collected(QGraphicsTextItem * parent = 0);
    //void shownewcount();
    //int get_treasure();
    static int treasure_count ;
    };

#endif // GAME_H





