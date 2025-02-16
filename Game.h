#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include "Player.h"
#include <QGraphicsView>
#include "ScoreObj.h"
//#include "healthbar.h"
#include "User.h"
#include "Enemy.h"
#include <QObject>
#include <QTimer>
#include "EnemyCreator.h"
#include <QTime>
#include <QVector>
#include"Stat.h"
#include <QString>
#include <QGraphicsTextItem>


class Game:public QObject
{
    Q_OBJECT
public slots:
    void decreaseTime();
private:

public:
    QGraphicsTextItem* playerText;
    QGraphicsTextItem* levelText;
    Stat* lvlStat;
    User* player1;
    User* player2;
    Stat* gameStat;
    QString roundWinner = "";
    bool isGameOver();
    void gameOver();
    QTime time;
    QTimer* enemyTimer;
    QTimer* gameTimer;
    int difficulty,numChances, enemiesCreated, enemiesDestroyed, escaped,initTime, numKeyboardPressed,negative;
    int count=0;
    Player * playerRect;
    QGraphicsScene * scene;
    ScoreObj * score;
    ScoreObj * healthBar;
    ScoreObj * timerDisplay;
    EnemyCreator* creator;
    QVector<Enemy*>* enemies;
    void increaseDifficulty();
    bool isLevelOver();
    void levelOver();
    void nextLevel();
    void replayLevel();
    void setUpLevel();
    void doMultiplayer();
    Game();
    ~Game();

};

#endif // GAME_H
