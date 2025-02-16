#include "healthbar.h"
#include "game.h"

extern Game * game;


HealthBar::HealthBar(QGraphicsTextItem *parent): QGraphicsTextItem(parent)
{
    health =game->numChances;
    setPlainText(QString("Health: ")+QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));//sets the desired font style with the integer size given
}

void HealthBar::dereaseHealth()
{
   health--;
}

int HealthBar::getHealth()
{
   return health;
}

void HealthBar::sethealth(int health)
{
    this->health= health;
}
