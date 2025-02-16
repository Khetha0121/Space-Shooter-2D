#include "Bullet.h"
#include <QGraphicsScene>
#include <QDebug>
//#include "Enemy.h"
#include <QList>
#include <QGraphicsItem>
#include "Game.h"
#include <QtMath>

extern Game * game;//There is an external global variable called game

//We want the bullet to move upwards continually upon pressing spaceBar only once


double Bullet::getAngle()
{
    return angle;
}

void Bullet::setAngle(double kurt)
{
    angle = kurt;
}

Bullet::Bullet(Location& targeted,QStack<int>&tgtstk, QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent)
{
    //set dimensions and instantiation of bullet
     setPixmap(QPixmap(":/images/coolgreen2.png"));

    // qDebug() << "no problem";
     //target = new Location();
     target = &targeted;
     //hardTarget = tgtstk;


     //timer that will be used to cound periodic intervals at which the bullet will move
     timer = new QTimer();
     // connet is a method that is used to connect the timer to the method move thus allow us
     //to call the method "move" of the bullet at evry interval as set by "timer"

     connect(timer,SIGNAL(timeout()),this,SLOT(move()));
     //timer will start and after every 50 milliseconds, "timeout" signal will be emmitted and everytime it does emit,
     //bullet "move" method is called

     timer->start(50);

}

Bullet::~Bullet()
{
    delete timer;
    //delete target;
}

void Bullet::move()
{
    //get list of all items colliding with this bullet
    QList <QGraphicsItem *> items = collidingItems();
    //Iterate this list and check if any of these is an enemy, and if so delete both bullet and enemy
    for (int i = 0; i < items.size(); ++i) {
        if(typeid(*items[i])==typeid(Enemy))
        {
            game->score->increase();
            game->enemiesDestroyed++;
            //qDebug()<<"enemiesdestroyed "<<game->enemiesDestroyed;
            scene()->removeItem(items[i]);
            scene()->removeItem(this);
            //game->enemies.removeOne(items[i]);  //remove the enemy from vector of enemies

            delete items[i];
            delete this;

            return;
        }
    }

    if(y()+boundingRect().height()<0)
    {
     scene()->removeItem(this);
     delete this;
    }
    //We want the bullet to move in along the vector between the centre of the enemy and itself, so we construct the vector
    xTar = target->getX(); //target's x location
    yTar = target->getY();// target's y location
    dx = xTar-x();// difference between bullet and target along x
    dy = yTar-y() ;// difference between bullet and target along y
    length = sqrt(pow(dx+0.0,2.0)+pow(dy+0.0,2.0));//magnitude of the vector
    setTransformOriginPoint(boundingRect().width()/4,boundingRect().height()/4);
    SINE = qRadiansToDegrees(asin(dy/length));
    COSINE = qRadiansToDegrees(acos(dx/length));
    angle = qRadiansToDegrees(atan(SINE/COSINE));
    //qDebug()<< angle;
    if (dy<0) {
        if (dx>=0) {
            //angle = qRadiansToDegrees(atan2(-dy+0.0,dx+0.0));
            //qDebug()<< angle;
            angle = -angle;
            setRotation(angle);
            //transform().rotateRadians(atan(-dy+0.0/dx+0.0));
           // qDebug()<<qRadiansToDegrees(atan2(dy+0.0,dx+0.0));//<< "in radians is "<<atan(dy+0.0/dx+0.0);

        } else {
            //angle = 180.0-qRadiansToDegrees(atan2(dy+0.0,dx+0.0));
            setRotation(angle);
            //qDebug()<< angle;
            //transform().rotateRadians(atan(22/7-dy+0.0/dx+0.0));
           // qDebug()<<qRadiansToDegrees(atan2(dy+0.0,dx+0.0));//"in radians is "<<atan(dy+0.0/dx+0.0);
        }
        setPos(x()+100*dx/length,y()+100*dy/length);//now move the bullet 5 units along the unit vector which is along bullet and target centre

    } else {
        delete this;
        return;
        if (dx>=0) {
            angle = qRadiansToDegrees(atan2(-dy+0.0,dx+0.0));
            setRotation(-angle);
            //qDebug()<< angle;
            //transform().rotateRadians(atan(-dy+0.0/dx+0.0));
           // qDebug()<<qRadiansToDegrees(atan2(dy+0.0,dx+0.0));//<< "in radians is "<<atan(dy+0.0/dx+0.0);

        } else {
            angle = 180.0-qRadiansToDegrees(atan2(dy+0.0,dx+0.0));
            setRotation(-angle);
            //qDebug()<< angle;
            //transform().rotateRadians(atan(22/7-dy+0.0/dx+0.0));
           // qDebug()<<qRadiansToDegrees(atan2(dy+0.0,dx+0.0));//"in radians is "<<atan(dy+0.0/dx+0.0);
        }
        setPos(x()+100*dx/length,y()-100*dy/length);//now move the bullet 5 units along the unit vector which is along bullet and target centre
    }



   // qDebug()<< "new bullet x is "<< x()<<" new bullet y is "<<y();
    //setPos(x()+10,y()-10);
}
