#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QChar>
#include <QGraphicsTextItem>
#include "Location.h"
#include <QTimer>
#include <QStack>
#include <QPixmap>


class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    QChar ch;
    bool marked= false;
    QStack <int>* yValues;
    QTimer* timer;
    QGraphicsTextItem* name;
    Location* location;
    Enemy(QChar letter);
    ~Enemy();
    void makeName();
    void setMark(bool mark);

public slots:
    void move();
};

#endif // ENEMY_H
