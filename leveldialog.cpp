#include "leveldialog.h"
#include "ui_leveldialog.h"
#include "Game.h"
#include <QString>

extern Game* game;
LevelDialog::LevelDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LevelDialog)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/images/space-planet-background-planets-surface-with-craters-stars-comets-dark-space_53562-8705.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    ui->scoreDisplay->setText(QString::number(game->lvlStat->score)+" / "+QString::number(game->enemiesCreated));
    ui->accuracyDsiplay->setText(QString::number(game->lvlStat->accuracy));
    ui->gradeDisplay->setText(QString::number(game->lvlStat->grade));
    if(game->healthBar->getValue()==0||game->difficulty==4)
        ui->nextLevelButton->setVisible(false);

}

LevelDialog::~LevelDialog()
{
    delete ui;
}


void LevelDialog::on_rePlayPButton_clicked()
{
    close();
    game->replayLevel();
}

void LevelDialog::on_backToMain_clicked()
{
    close();
}

void LevelDialog::on_nextLevelButton_clicked()
{
    close();
   game->nextLevel();
}
