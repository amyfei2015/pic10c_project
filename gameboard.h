#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "game.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;

};

#endif // GAMEBOARD_H



