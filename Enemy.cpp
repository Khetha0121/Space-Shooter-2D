#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>//library contains a rand() function which return a really large integer
#include "Game.h"
#include <QString>
#include <QFont>
#include <cmath>

//We want the bullet to move upwards continually upon pressing spaceBar only once

extern Game * game;
extern int length;


Enemy::Enemy(QChar letter)
{
    ch = letter;
    //set dimensions and instantiation of enemy at a random position along the x
     setPixmap(QPixmap(":/images/spiked_ship_3_small_green.PNG"));
     setTransformOriginPoint(boundingRect().width()/2,boundingRect().height()/2);
     setRotation(180);
     int randNum = qrand() % (int)(length-boundingRect().width());
    //qDebug() << randNum;
     setPos(randNum,0);
     //yValues = new QStack<int>();

     name = new QGraphicsTextItem();
     game->count++;
     name->setPlainText(QString(letter) +QString(""));
     //name->setPos();
     name->setDefaultTextColor(Qt::yellow);
     name->setFont(QFont("times",20));//takes params which dictate the type of font and the size of said font

     //timer that will be used to cound periodic intervals at which the bullet will move
     timer = new QTimer();
     // connet is a method that is used to connect the timer to the method move thus allow us
     //to call the method "move" of the bullet at evry interval as set by "timer"

     connect(timer,SIGNAL(timeout()),this,SLOT(move()));
     //timer will start and after every 50 milliseconds, "timeout" signal will be emmitted and everytime it does emit,
     //bullet "move" method is called

     timer->start(100);
     location = new Location(x()+boundingRect().width()/4,y()+boundingRect().height()/4);
     // qDebug()<< "initial value of enemy x is "<<location->getX()<<" initial value for y is "<<location->getY();
     yValues =  new QStack<int>();
     yValues->push(y()-boundingRect().height()/2);

}

Enemy::~Enemy()
{
    game->enemies->removeOne(this);
    delete name;
    delete timer;
    delete location;
}

void Enemy::makeName()
{
    //Now to add the name of the enemy to the scene of the enemy
    name->setPos(x()+boundingRect().width()/2-15,y()+boundingRect().height()-15);
    scene()->addItem(name);
}

void Enemy::setMark(bool mark)
{
    marked = mark;
}

void Enemy::move()
{

    if(marked)
        return;
    if(y()+boundingRect().height()>scene()->height())
    {
     game->healthBar->decrease();
     scene()->removeItem(name);
     scene()->removeItem(this);
     delete this;
    // qDebug() <<"Enemy was deleted";
     return;
    }
    //moves the enemy down by 5 units along the y
    switch (game->difficulty) {
    case 1:
        setPos(x(),y()+5);
        location->setY(y()+boundingRect().height()/4);
        name->setPos(name->x(),name->y()+5);
        break;
    case 2:
        setPos(x(),y()+7.5);
        location->setY(y()+boundingRect().height()/4);
        name->setPos(name->x(),name->y()+7.5);
        break;
    case3:
        setPos(x(),y()+10);
        location->setY(y()+boundingRect().height()/4);
        name->setPos(name->x(),name->y()+10);
        break;
    default:
        setPos(x(),y()+11);
        location->setY(y()+boundingRect().height()/4);
        name->setPos(name->x(),name->y()+11);
        break;
    }
//    setPos(x(),y()+15);
//    location->setY(y()+boundingRect().height()/4);
//    name->setPos(name->x(),name->y()+15);


      //location->setY(y()-boundingRect().height()/2);

      yValues->push(y()-boundingRect().height()/2);

}
