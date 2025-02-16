#include "health.h"
#include "game.h"

extern Game * game;

Health::Health()
{

}

Health::Health(QGraphicsTextItem *parent): QGraphicsTextItem(parent)
{
    health =game->numChances;
    setPlainText(QString("Score: ")+QString::number(score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));//sets the desired font style with the integer size given
}

void Health::dereaseHealth()
{
   health--;
}

int Health::getHealth()
{
   return health;
}

void Health::sethealth(int health)
{
    this->health= health;
}
