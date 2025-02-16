#include "levelovermulti.h"
#include "ui_levelovermulti.h"
#include "Game.h"

extern Game * game;
LevelOverMulti::LevelOverMulti(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LevelOverMulti)

{
    ui->setupUi(this);

    QPixmap bkgnd(":/images/space-planet-background-planets-surface-with-craters-stars-comets-dark-space_53562-8705.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    //display player1 stats
    ui->p1ScoreLbl->setText(QString::number(game->player1->stats->at(game->difficulty-1)->score)+
    " / "+QString::number(game->enemiesCreated));
    ui->p1AccuracyLbl->setText(QString::number(game->player1->stats->at(game->difficulty-1)->accuracy));
    ui->p1GradeLbl->setText(QString::number(game->player1->stats->at(game->difficulty-1)->grade));

    //display player2 stats
    ui->p2Score->setText(QString::number(game->player2->stats->at(game->difficulty-1)->score)+
   + " / "+QString::number(game->enemiesCreated));
    ui->p2Accuracy->setText(QString::number(game->player2->stats->at(game->difficulty-1)->accuracy));
    ui->p2Grade->setText(QString::number(game->player2->stats->at(game->difficulty-1)->grade));

    ui->lblWinner_Display->setText(game->roundWinner);
}

LevelOverMulti::~LevelOverMulti()
{
    delete ui;
}

void LevelOverMulti::on_multi_Next_clicked()
{
    close();
    game->nextLevel();
}

void LevelOverMulti::on_multi_Replay_clicked()
{
    close();
    game->setUpLevel();
}
