#include "Player.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QPixmap>
#include "Game.h"

extern Game * game;
void Player::moveRight()
{
    if (this->x()>=650) {
        qDebug() << "We are here";
        timer->stop();
        delete timer;
        return;
    }
    setPos(x()+10,y());
}

Player::Player(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent)
{
    //Now this is by default a rectangle with 0 length and 0 breatdth so to change that we use
    setPixmap(QPixmap(":/images/fighter_Sized.png"));
    //setPixmap(QPixmap(":/images/Basehip11_Sized.png"));
}

void Player::moveLeft()
{

    if (this->x()<=10) {
        qDebug() << "We are here";
        timer->stop();
        delete timer;
        return;
    }
    setPos(x()-10,y());
}

void Player::timedMoveLeft()
{
    if(timer->remainingTime()!=0)
        return;
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moveLeft()));
    timer->start(50);

}

void Player::timedMoveRight()
{
    if(timer->remainingTime()!=0)
        return;
     timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moveRight()));
    timer->start(50);
}

void Player::tester()
{
    qDebug() << "Hello";
}

/*void Player::shoot()
{
    Bullet* bull = new Bullet();
    bull->setPos(x()+boundingRect().width()/2,y()-boundingRect().height());
    //now this bullet will be created upon hitting spacebar, but will not be added to
    //the scene therefore we must add bullet to the same scene that our player
    //exists in using the RectItem member function "scene" as every item has one
    //returns a reference to this items current scene
    scene()->addItem(bull);

}
*/

void Player::keyPressEvent(QKeyEvent* event)
{
    game->numKeyboardPressed++;
    //qDebug()<<"number of times keyboard is pressed "<<game->numKeyboardPressed;

    switch (event->key()) {
    case Qt::Key_A :
        for (int i = 0; i < game->enemies->size(); i++) {
            if (game->enemies->at(i)->ch=='A') {
                //game->enemies->at(i)->setMark(true);
                Bullet* bull = new Bullet(*game->enemies->at(i)->location,*game->enemies->at(i)->yValues);
                bull->setPos(x()+boundingRect().width()/4,y()-boundingRect().height()/2);
                //qDebug()<<bull->getAngle();
                scene()->addItem(bull);
//                setTransformOriginPoint(boundingRect().width()/2,boundingRect().height()/2);
//                setRotation(bull->getAngle());
            }
            else{
                game->negative++;
                //qDebug()<< game->negative;
            }
        }

        break;
    case Qt::Key_B :
        for (int i = 0; i < game->enemies->size(); i++) {
            if (game->enemies->at(i)->ch=='B') {
                //game->enemies->at(i)->setMark(true);
                Bullet* bull = new Bullet(*game->enemies->at(i)->location,*game->enemies->at(i)->yValues);
                bull->setPos(x()+boundingRect().width()/2,y()-boundingRect().height()/2);
                scene()->addItem(bull);
               // setRotation(bull->getAngle());
            }
            else{
                game->negative++;
                //qDebug()<< game->negative;
            }
        }


        break;
    case Qt::Key_C :
        for (int i = 0; i < game->enemies->size(); i++) {
            if (game->enemies->at(i)->ch=='C') {
                //game->enemies->at(i)->setMark(true);
                Bullet* bull = new Bullet(*game->enemies->at(i)->location,*game->enemies->at(i)->yValues);
                bull->setPos(x()+boundingRect().width()/2,y()-boundingRect().height()/2);
                scene()->addItem(bull);
                //setRotation(bull->getAngle());
            }
            else{
                game->negative++;
                //qDebug()<< game->negative;
            }

        }

        break;
    case Qt::Key_D :
        for (int i = 0; i < game->enemies->size(); i++) {
            if (game->enemies->at(i)->ch=='D') {
                //game->enemies->at(i)->setMark(true);
                Bullet* bull = new Bullet(*game->enemies->at(i)->location,*game->enemies->at(i)->yValues);
                bull->setPos(x()+boundingRect().width()/2,y()-boundingRect().height()/2);
                scene()->addItem(bull);
            }
            else{
                game->negative++;
                //qDebug()<< game->negative;
            }
        }

        break;
    case Qt::Key_E :
        for (int i = 0; i < game->enemies->size(); i++) {
            if (game->enemies->at(i)->ch=='E') {
                //game->enemies->at(i)->setMark(true);
                Bullet* bull = new Bullet(*game->enemies->at(i)->location,*game->enemies->at(i)->yValues);
                bull->setPos(x()+boundingRect().width()/2,y()-boundingRect().height()/2);
                scene()->addItem(bull);
//                setRotation(bull->getAngle());
//                setRotation(bull->getAngle());
            }
            else{
                game->negative++;
                //qDebug()<< game->negative;
            }
        }

        break;
    case Qt::Key_F :
        for (int i = 0; i < game->enemies->size(); i++) {
            if (game->enemies->at(i)->ch=='F') {
                //game->enemies->at(i)->setMark(true);
                Bullet* bull = new Bullet(*game->enemies->at(i)->location,*game->enemies->at(i)->yValues);
                bull->setPos(x()+boundingRect().width()/2,y()-boundingRect().height()/2);
                scene()->addItem(bull);
                //setRotation(bull->getAngle());
            }
            else{
                game->negative++;
                //qDebug()<< game->negative;
            }
        }

        break;
    case Qt::Key_G :
        for (int i = 0; i < game->enemies->size(); i++) {
            if (game->enemies->at(i)->ch=='G') {
                //game->enemies->at(i)->setMark(true);
                Bullet* bull = new Bullet(*game->enemies->at(i)->location,*game->enemies->at(i)->yValues);
                bull->setPos(x()+boundingRect().width()/2,y()-boundingRect().height()/2);
                scene()->addItem(bull);
                //setRotation(bull->getAngle());
            }
            else{
                game->negative++;
                //qDebug()<< game->negative;
            }
        }
        break;
    case Qt::Key_H :
        for (int i = 0; i < game->enemies->size(); i++) {
            if (game->enemies->at(i)->ch=='H') {
                //game->enemies->at(i)->setMark(true);
                Bullet* bull = new Bullet(*game->enemies->at(i)->location,*game->enemies->at(i)->yValues);
                bull->setPos(x()+boundingRect().width()/2,y()-boundingRect().height()/2);
                scene()->addItem(bull);
            }
            else{
                game->negative++;
                //qDebug()<< game->negative;
            }
        }

        break;
    case Qt::Key_I :
        for (int i = 0; i < game->enemies->size(); i++) {
            if (game->enemies->at(i)->ch=='I') {
                //game->enemies->at(i)->setMark(true);
                Bullet* bull = new Bullet(*game->enemies->at(i)->location,*game->enemies->at(i)->yValues);
                bull->setPos(x()+boundingRect().width()/2,y()-boundingRect().height()/2);
                scene()->addItem(bull);
            }
            else{
                game->negative++;
                //qDebug()<< game->negative;
            }
        }

        break;
    case Qt::Key_J :
        for (int i = 0; i < game->enemies->size(); i++) {
            if (game->enemies->at(i)->ch=='J') {
                //game->enemies->at(i)->setMark(true);
                Bullet* bull = new Bullet(*game->enemies->at(i)->location,*game->enemies->at(i)->yValues);
                bull->setPos(x()+boundingRect().width()/2,y()-boundingRect().height()/2);
                scene()->addItem(bull);
            }
            else{
                game->negative++;
                //qDebug()<< game->negative;
            }
        }

        break;
    case Qt::Key_K :
        for (int i = 0; i < game->enemies->size(); i++) {
            if (game->enemies->at(i)->ch=='K') {
                //game->enemies->at(i)->setMark(true);
                Bullet* bull = new Bullet(*game->enemies->at(i)->location,*game->enemies->at(i)->yValues);
                bull->setPos(x()+boundingRect().width()/2,y()-boundingRect().height()/2);
                scene()->addItem(bull);
            }
            else{
                game->negative++;
                //qDebug()<< game->negative;
            }
        }

        break;
    case Qt::Key_L :
        for (int i = 0; i < game->enemies->size(); i++) {
            if (game->enemies->at(i)->ch=='L') {
                //game->enemies->at(i)->setMark(true);
                Bullet* bull = new Bullet(*game->enemies->at(i)->location,*game->enemies->at(i)->yValues);
                bull->setPos(x()+boundingRect().width()/2,y()-boundingRect().height()/2);
                scene()->addItem(bull);
            }
            else{
                game->negative++;
                //qDebug()<< game->negative;
            }
        }

        break;
    case Qt::Key_M :
        for (int i = 0; i < game->enemies->size(); i++) {
            if (game->enemies->at(i)->ch=='M') {
                //game->enemies->at(i)->setMark(true);
                Bullet* bull = new Bullet(*game->enemies->at(i)->location,*game->enemies->at(i)->yValues);
                bull->setPos(x()+boundingRect().width()/2,y()-boundingRect().height()/2);
                scene()->addItem(bull);
            }
            else{
                game->negative++;
                //qDebug()<< game->negative;
            }
        }
        break;
    case Qt::Key_N :
        for (int i = 0; i < game->enemies->size(); i++) {
            if (game->enemies->at(i)->ch=='N') {
                //game->enemies->at(i)->setMark(true);
                Bullet* bull = new Bullet(*game->enemies->at(i)->location,*game->enemies->at(i)->yValues);
                bull->setPos(x()+boundingRect().width()/2,y()-boundingRect().height()/2);
                scene()->addItem(bull);
            }
            else{
                game->negative++;
                //qDebug()<< game->negative;
            }
        }

        break;
    case Qt::Key_O :
        for (int i = 0; i < game->enemies->size(); i++) {
            if (game->enemies->at(i)->ch=='O') {
                //game->enemies->at(i)->setMark(true);
                Bullet* bull = new Bullet(*game->enemies->at(i)->location,*game->enemies->at(i)->yValues);
                bull->setPos(x()+boundingRect().width()/2,y()-boundingRect().height()/2);
                scene()->addItem(bull);
            }
            else{
                game->negative++;
                //qDebug()<< game->negative;
            }
        }

        break;
    case Qt::Key_P :
        for (int i = 0; i < game->enemies->size(); i++) {
            if (game->enemies->at(i)->ch=='P') {
                //game->enemies->at(i)->setMark(true);
                Bullet* bull = new Bullet(*game->enemies->at(i)->location,*game->enemies->at(i)->yValues);
                bull->setPos(x()+boundingRect().width()/2,y()-boundingRect().height()/2);
                scene()->addItem(bull);
            }
            else{
                game->negative++;
                //qDebug()<< game->negative;
            }
        }

        break;
    case Qt::Key_Q :
        for (int i = 0; i < game->enemies->size(); i++) {
            if (game->enemies->at(i)->ch=='Q') {
                //game->enemies->at(i)->setMark(true);
                Bullet* bull = new Bullet(*game->enemies->at(i)->location,*game->enemies->at(i)->yValues);
                bull->setPos(x()+boundingRect().width()/2,y()-boundingRect().height()/2);
                scene()->addItem(bull);
            }
            else{
                game->negative++;
                //qDebug()<< game->negative;
            }
        }

        break;
    case Qt::Key_R :
        for (int i = 0; i < game->enemies->size(); i++) {
            if (game->enemies->at(i)->ch=='R') {
                //game->enemies->at(i)->setMark(true);
                Bullet* bull = new Bullet(*game->enemies->at(i)->location,*game->enemies->at(i)->yValues);
                bull->setPos(x()+boundingRect().width()/2,y()-boundingRect().height()/2);
                scene()->addItem(bull);
            }
            else{
                game->negative++;
                //qDebug()<< game->negative;
            }
        }
        break;
    case Qt::Key_S :
        for (int i = 0; i < game->enemies->size(); i++) {
            if (game->enemies->at(i)->ch=='S') {
                //game->enemies->at(i)->setMark(true);
                Bullet* bull = new Bullet(*game->enemies->at(i)->location,*game->enemies->at(i)->yValues);
                bull->setPos(x()+boundingRect().width()/2,y()-boundingRect().height()/2);
                scene()->addItem(bull);
            }
            else{
                game->negative++;
                //qDebug()<< game->negative;
            }
        }
        break;
    case Qt::Key_T :
        for (int i = 0; i < game->enemies->size(); i++) {
            if (game->enemies->at(i)->ch=='T') {
                //game->enemies->at(i)->setMark(true);
                Bullet* bull = new Bullet(*game->enemies->at(i)->location,*game->enemies->at(i)->yValues);
                bull->setPos(x()+boundingRect().width()/2,y()-boundingRect().height()/2);
                scene()->addItem(bull);
            }
            else{
                game->negative++;
                //qDebug()<< game->negative;
            }
        }
        break;
    case Qt::Key_U :
        for (int i = 0; i < game->enemies->size(); i++) {
            if (game->enemies->at(i)->ch=='U') {
                //game->enemies->at(i)->setMark(true);
                Bullet* bull = new Bullet(*game->enemies->at(i)->location,*game->enemies->at(i)->yValues);
                bull->setPos(x()+boundingRect().width()/2,y()-boundingRect().height()/2);
                scene()->addItem(bull);
            }
            else{
                game->negative++;
                //qDebug()<< game->negative;
            }
        }
        break;
    case Qt::Key_V :
        for (int i = 0; i < game->enemies->size(); i++) {
            if (game->enemies->at(i)->ch=='V') {
                //game->enemies->at(i)->setMark(true);
                Bullet* bull = new Bullet(*game->enemies->at(i)->location,*game->enemies->at(i)->yValues);
                bull->setPos(x()+boundingRect().width()/2,y()-boundingRect().height()/2);
                scene()->addItem(bull);
            }
            else{
                game->negative++;
                //qDebug()<< game->negative;
            }
        }
        break;
    case Qt::Key_W :
        for (int i = 0; i < game->enemies->size(); i++) {
            if (game->enemies->at(i)->ch=='W') {
                //game->enemies->at(i)->setMark(true);
                Bullet* bull = new Bullet(*game->enemies->at(i)->location,*game->enemies->at(i)->yValues);
                bull->setPos(x()+boundingRect().width()/2,y()-boundingRect().height()/2);
                scene()->addItem(bull);
            }
            else{
                game->negative++;
                //qDebug()<< game->negative;
            }
        }
        break;
    case Qt::Key_X :
        for (int i = 0; i < game->enemies->size(); i++) {
            if (game->enemies->at(i)->ch=='X') {
                //game->enemies->at(i)->setMark(true);
                Bullet* bull = new Bullet(*game->enemies->at(i)->location,*game->enemies->at(i)->yValues);
                bull->setPos(x()+boundingRect().width()/2,y()-boundingRect().height()/2);
                scene()->addItem(bull);
            }
            else{
                game->negative++;
                //qDebug()<< game->negative;
            }
        }
        break;
    case Qt::Key_Y :
        for (int i = 0; i < game->enemies->size(); i++) {
            if (game->enemies->at(i)->ch=='Y') {
                //game->enemies->at(i)->setMark(true);
                Bullet* bull = new Bullet(*game->enemies->at(i)->location,*game->enemies->at(i)->yValues);
                bull->setPos(x()+boundingRect().width()/2,y()-boundingRect().height()/2);
                scene()->addItem(bull);
            }
            else{
                game->negative++;
                //qDebug()<< game->negative;
            }
        }

        break;
    case Qt::Key_Z :
        for (int i = 0; i < game->enemies->size(); i++) {
            if (game->enemies->at(i)->ch=='Z') {
                //game->enemies->at(i)->setMark(true);
                Bullet* bull = new Bullet(*game->enemies->at(i)->location,*game->enemies->at(i)->yValues);
                bull->setPos(x()+boundingRect().width()/2,y()-boundingRect().height()/2);
                scene()->addItem(bull);
            }
            else{
                game->negative++;
                //qDebug()<< game->negative;
            }
        }

        break;
    default:
        break;
//        qDebug()<< "ia m here";
//        for (int i = 0; i < game->enemies->size(); ++i) {
//            if (game->enemies->at(i)->ch==event->key()) {
//                Bullet* bull = new Bullet(*game->enemies->at(i)->location,*game->enemies->at(i)->yValues);
//                bull->setPos(x()+boundingRect().width()/2,y()-boundingRect().height()/2);
//                scene()->addItem(bull);
//                break;
//            }
//           if (game->enemies->at(i)->ch!=event->key()){
//               game->negative++;
//               qDebug()<<game->negative;
//           }

//        }
//        //game->negative++;

    }


}



