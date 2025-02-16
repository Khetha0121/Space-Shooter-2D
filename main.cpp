#include <QApplication>
#include <QGraphicsScene>
#include "Player.h"
#include <QGraphicsView>
#include <QObject>
#include <QTimer>
#include <QLabel>
#include <QMovie>
#include "Game.h"
#include <QtMath>
#include <QDebug>
#include "mainwindow.h"
#include <QDesktopWidget>

Game *game;
bool multiplayer ;
int length,breadth;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //QScreen *screen = QGuiApplication::primaryScreen();
    QRect rec = QApplication::desktop()->screenGeometry();
    //breadth = rec.height()-100;
    breadth = 700;
    length = 974;
    //length = rec.width()-100;


    qDebug() <<breadth;
    qDebug() <<length;
    //qDebug() << qRadiansToDegrees(qAsin(0.5));
    MainWindow w;
    w.show();
    return a.exec();
}
