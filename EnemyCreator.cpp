#include "EnemyCreator.h"
#include "Game.h"
#include <QChar>
#include <QDebug>
#include "Enemy.h"

extern Game* game;
void EnemyCreator::spawnEnemy()
{
    //member function to create an  enemy
    letterGenerator();
    QChar ch = QChar(randNumCollector->at(0));
    //QChar ch = 'A';

    randNumCollector->removeAt(0);
    Enemy* enemy = new Enemy(ch);
    game->enemiesCreated++;
    //qDebug() << "Enemies Created "<< game->enemiesCreated;
    game->scene->addItem(enemy);
    enemy->makeName();
    game->enemies->append(enemy);
}

void EnemyCreator::letterGenerator()
{
    int randnum = qrand()%(91-65)+ 65;
    while(randNumCollector->contains(randnum))
    {
        randnum = qrand()%(91-65)+ 65;
    }
    randNumCollector->append(randnum);

}

EnemyCreator::EnemyCreator()
{
    //randNumCollector = new QVector<int>;
    randNumCollector= new QQueue<int>;
}
