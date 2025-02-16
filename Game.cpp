#include "Game.h"
#include <QImage>
#include <QBrush>
#include<QDebug>
#include<gameover.h>
#include<leveldialog.h>
#include<swapturndialog.h>
#include<levelovermulti.h>

extern int length;
extern int breadth;
extern bool multiplayer;
void Game::decreaseTime()
{
    if (isLevelOver()) {
        levelOver();
        return;
    }

    if (isGameOver()) {
        gameOver();
        return;
    }

    initTime--;
    timerDisplay->setValue(initTime);
  //increaseDifficulty();

}
bool Game::isLevelOver()
{
    if((initTime==0&&difficulty<4)||healthBar->getValue()==0)
        return true;
    return false;
}


bool Game::isGameOver()
{
    if((initTime==0&&difficulty==4)||healthBar->getValue() ==0)
        return true;
    return false;
}
void Game::levelOver()
{
    gameTimer->stop();
    enemyTimer->stop();
    for (int i = 0; i < enemies->size(); ++i) {
        scene->removeItem(enemies->at(i));
        delete enemies->at(i);
    }

    if (multiplayer) {
        doMultiplayer();
    } else {
        negative = numKeyboardPressed-enemiesDestroyed;
        lvlStat = new Stat();
        lvlStat->score = score->getValue();
        lvlStat->accuracy = 100*(double(lvlStat->score-(negative))/double(numKeyboardPressed));
        lvlStat->grade = ((enemiesDestroyed-(negative+2*difficulty-healthBar->getValue()))/double(enemiesCreated))*100;

        gameStat->accuracy+=lvlStat->score;
        gameStat->grade+=lvlStat->grade;
        LevelDialog lvlOver;
        lvlOver.setModal(true);
        lvlOver.exec();
    }


}

void Game::setUpLevel()
{
    enemiesCreated = 0;
    enemiesDestroyed = 0;
    score->setValue(0);
    healthBar->setValue(2*difficulty);
    levelText->setPlainText(QString("LEVEL ")+QString::number(difficulty));
    escaped = 0;
    numKeyboardPressed = 0;
    negative = 0;
    initTime = 30 ;
        switch (difficulty) {
        case 1:
            enemyTimer->setInterval(2000);
            break;
        case 2:
            enemyTimer->setInterval(1500);
            break;
        case 3:
            enemyTimer->setInterval(1000);
            break;
        default:
            enemyTimer->setInterval(500);
            break;
        }
        gameTimer->start();
        enemyTimer->start();
}

void Game::doMultiplayer()
{
    negative = numKeyboardPressed-enemiesDestroyed;
    if (player1->getTurn()) {
        //capture player1 stats and storing them in player1 stats vector
        player1->stats->push_back(new Stat());
        player1->stats->at(difficulty-1)->score= score->getValue();
        player1->stats->at(difficulty-1)->accuracy= 100*(double(score->getValue()-(negative))/double(numKeyboardPressed));
        player1->stats->at(difficulty-1)->grade= ((enemiesDestroyed-(negative+2*difficulty-healthBar->getValue()))/double(enemiesCreated))*100;

        //swap turns to player2
        player2->setTurn(true);
        playerText->setPlainText(QString("PLAYER 2"));
        player1->setTurn(false);

        SwapTurnDialog swaper;
        swaper.setModal(true);
        swaper.exec();

    } else {
        if (player2->getTurn()) {
            //capture player2 stats and storing them in player2 stats vector
            player2->stats->push_back(new Stat());
            player2->stats->at(difficulty-1)->score= score->getValue();
            player2->stats->at(difficulty-1)->accuracy= 100*(double(score->getValue()-(negative))/double(numKeyboardPressed));
            player2->stats->at(difficulty-1)->grade= ((enemiesDestroyed-(negative+2*difficulty-healthBar->getValue()))/double(enemiesCreated))*100;

            //swap turns to player1
            player1->setTurn(true);
            playerText->setPlainText(QString("PLAYER 1"));
            player2->setTurn(false);

            //compute winner of round
//            if (player1->stats->at(difficulty-1)->compareTo(*(player2->stats->at(difficulty-1)))>0) {
//                roundWinner = "PLAYER1";

//            } else {
//                roundWinner = "PLAYER2";
//            }
            if (player1->stats->at(difficulty-1)->grade>player2->stats->at(difficulty-1)->grade) {
                roundWinner = "PLAYER1";
            } else {
                if (player2->stats->at(difficulty-1)->grade>player1->stats->at(difficulty-1)->grade) {
                    roundWinner = "PLAYER2";
            }
            }

            LevelOverMulti lOMulti;
            lOMulti.setModal(true);
            lOMulti.exec();

        }
    }
}

void Game::gameOver()
{
    gameTimer->stop();
    enemyTimer->stop();
    GameOver gameover;
    gameover.setModal(true);
    gameover.exec();
}

void Game::increaseDifficulty()
{
        difficulty++;
        numChances+=2;
}

void Game::nextLevel()
{
    increaseDifficulty();
    setUpLevel();
}

void Game::replayLevel()
{
  setUpLevel();
}

Game::Game()
{
    /*Random seed generator to generate different random numbers everytime a random number is generated
     * rather the same sequence of random numbers, ensuring randomness
    */
    player1 = new User();
    player1->setTurn(true);
    player2 = new User();
    difficulty=1;

    enemiesCreated = 0;
    enemiesDestroyed = 0;
    escaped = 0;
    numKeyboardPressed = 0;
    negative = 0;
    initTime = 30 ;
    gameStat = new Stat();
    time = QTime::currentTime();
    qsrand((uint)time.msec());

    // 1]Create an item to be put into a scene, in this case the player a rectangle
    playerRect = new Player();
    playerText= new QGraphicsTextItem();
    playerText->setPlainText(QString("PLAYER 1"));
    playerText->setDefaultTextColor(Qt::darkMagenta);
    playerText->setFont(QFont("times",16));

    levelText= new QGraphicsTextItem();
    levelText->setPlainText(QString("LEVEL ")+QString::number(difficulty));
    levelText->setDefaultTextColor(Qt::darkCyan);
    levelText->setFont(QFont("times",16));

    score = new ScoreObj("SCORE ");
    score->setScoreColour();
    healthBar = new ScoreObj("LIVES ");
    healthBar->setHealthColour();
    healthBar->setValue(2*difficulty);
    timerDisplay = new ScoreObj("TIME LEFT ");
    timerDisplay->setDefaultTextColor(Qt::darkCyan);


    // 2]Create a Scene to store or contain all the game objects(game items in this case)
    scene = new QGraphicsScene();
    //scene->setBackgroundBrush(QBrush(QImage(":/images/130-1303740_background-overlay-space-galaxy-planets-stars-fantasy-space.png")));
    scene->setBackgroundBrush(QBrush(QImage(":/images/space-planet-background-planets-surface-with-craters-stars-comets-dark-space_53562-8705.jpg")));

    //Now to add an item into our scene
    scene->addItem(playerRect);
    scene->addItem(playerText);
    scene->addItem(score);
    score->setPos(0,25);
    scene->addItem(healthBar);
    healthBar->setPos(0,50);
    scene->addItem(levelText);
    levelText->setPos(length-100,0);
    scene->addItem(timerDisplay);
    timerDisplay->setPos(length-145,25);
    timerDisplay->setValue(initTime);


    //To make our player(rectangle )reponsive to keyboard events, we have to make it "Focusable"
    // then set the focus to the player
    playerRect->setFlag(QGraphicsItem::ItemIsFocusable);
    playerRect->setFocus();

   // view = new QGraphicsView();
    //now this view, yes you guessed it is empty so to add a scene to the view we do the following
//    view->setScene(scene);

    //Now a quick fix to ensure the Scene doesnt always get large when bullets are shot is to disable the scrollbar
    //Later we will look into destroying bullet once its completely out of sight
    //view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //now to make the view visisble

//    view->show();
//    view->setFixedSize(1000,700);
    scene->setSceneRect(0,0,length,breadth);
    playerRect->setPos((length-playerRect->boundingRect().width())/2,breadth-playerRect->boundingRect().height());

    //QGraphicsScene scene;
    /*QLabel *gif_anim = new QLabel();
    QMovie *movie = new QMovie(":/images/Spacebackground6.gif");
    gif_anim->setMovie(movie);
    movie->start();
    QGraphicsProxyWidget *proxy = scene->addWidget(gif_anim);
    */

    //playerRect->setPos(scene->width()/2-playerRect->rect().width()/2, scene->height()-playerRect->rect().height());
    //now to spawn some enemies
    enemies = new QVector<Enemy*>();
    creator = new EnemyCreator();
    //creator->spawnEnemy();
    enemyTimer = new QTimer();
    gameTimer = new QTimer();

    connect(enemyTimer,SIGNAL(timeout()),creator,SLOT(spawnEnemy()));
    connect(gameTimer,SIGNAL(timeout()),this,SLOT(decreaseTime()));
    enemyTimer->start(2000);
    gameTimer->start(1000);

}

Game::~Game()
{

}

