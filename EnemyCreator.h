#ifndef ENEMYCREATOR_H
#define ENEMYCREATOR_H

#include <QObject>
#include "Enemy.h"
#include <QVector>
#include<QStack>
#include <QQueue>

class EnemyCreator: public QObject
{
    Q_OBJECT
public slots:
    void spawnEnemy();
public:
    void letterGenerator();
    EnemyCreator();
    //QVector <int> * randNumCollector;
    QQueue <int> * randNumCollector;

};

#endif // ENEMYCREATOR_H
