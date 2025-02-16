#ifndef HEALTHBAR_H
#define HEALTHBAR_H
#include <QGraphicsTextItem>
#include "Game.h"

class HealthBar :public QGraphicsTextItem{
public:
    HealthBar(QGraphicsTextItem* parent = 0);
    void dereaseHealth();
    int getHealth();
    void sethealth(int health);

private:
     int health;
};
#endif // HEALTHBAR_H
