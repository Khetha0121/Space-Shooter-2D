#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPixmap>
#include <QPalette>

extern bool multiplayer;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->playButton_R->setVisible(false);
    //ui->label->setPixmap();
    //ui->bkgrdLbl_1->setEnabled(false);
    //ui->stackedWidget->setbas
    //ui->playButton_R->setEnabled(false);
    //QPixmap bkgnd(":/images/130-1303740_background-overlay-space-galaxy-planets-stars-fantasy-space.png");
    QPixmap bkgnd(":/images/space-planet-background-planets-surface-with-craters-stars-comets-dark-space_53562-8705.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    //ui->bkgrdLbl_1->setPixmap(QPixmap());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_rdoSingle_clicked()
{
    multiplayer= false;
    ui->playButton_R->setVisible(true);
    //ui->playButton_R->setEnabled(true);
    qDebug()<< multiplayer;
}

void MainWindow::on_rdoMulti_clicked()
{
    multiplayer= true;
    ui->playButton_R->setVisible(true);
    //ui->playButton_R->setEnabled(true);
    qDebug()<< multiplayer;
}

void MainWindow::on_playButton_R_clicked()
{
    gui = new GameUI;
    gui->show();
}
