#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include "Game.h"

class Health :public QGraphicsTextItem{
public:
    Health(QGraphicsTextItem* parent = 0);
    void dereaseHealth();
    int getHealth();
    void sethealth(int health);

private:
     int health;
};

#endif // HEALTH_H
