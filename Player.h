#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>
#include <QTimer>
#include "Bullet.h"

//Create a player class that will inherit from QGraphicsRectItem
class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public slots:
    void moveLeft();
    void moveRight();
public:
    Player(QGraphicsItem* parent = 0);
    void keyPressEvent(QKeyEvent* event);
    void timedMoveLeft();
    void timedMoveRight();
    void tester();
    void shoot();

private:
    QTimer* timer;
};

#endif // PLAYER_H
