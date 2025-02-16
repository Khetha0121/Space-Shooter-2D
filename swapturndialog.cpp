#include "swapturndialog.h"
#include "ui_swapturndialog.h"
#include "Game.h"
extern Game * game;

SwapTurnDialog::SwapTurnDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SwapTurnDialog)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/images/space-planet-background-planets-surface-with-craters-stars-comets-dark-space_53562-8705.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

SwapTurnDialog::~SwapTurnDialog()
{
    delete ui;
}

void SwapTurnDialog::on_playButton_clicked()
{
    close();
    game->setUpLevel();

}
