#include "gameui.h"
#include "ui_gameui.h"
#include "Game.h"

extern Game* game;
extern int length;
extern int breadth;
GameUI::GameUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameUI)
{
    ui->setupUi(this);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->show();
    game = new Game();
    setGeometry(150,20,length,breadth);
//    setFixedWidth(length);
//    setFixedHeight(breadth);
    ui->graphicsView->setFixedSize(length,breadth);
    ui->graphicsView->setScene(game->scene);
    //setWindowState(Qt::WindowFullScreen);
    //setWindowState(Qt::WindowMaximized);



}

GameUI::~GameUI()
{
    delete ui;
//    delete game;
}
