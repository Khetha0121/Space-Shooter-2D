#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>
#include "Location.h"
#include <QTimer>
#include <QStack>


class Bullet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    int xTar,yTar,dx,dy ;
    double length = 0;
    double angle;
    double SINE, COSINE;
    QTimer* timer;
    Location* target;
    QStack<int> hardTarget;
    int targetX, targetY;
    double getAngle();
    void setAngle(double kurt);
    Bullet(Location& targeted, QStack<int> &tgtstk, QGraphicsItem* parent=0);
    ~Bullet();
public slots:
    void move();
};
#endif // BULLET_H
