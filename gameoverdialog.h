#ifndef GAMEOVERDIALOG_H
#define GAMEOVERDIALOG_H

#include <QDialog>

namespace Ui {
class GameOverDialog;
}

class GameOverDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GameOverDialog(QWidget *parent = nullptr);
    ~GameOverDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::GameOverDialog *ui;
};

#endif // GAMEOVERDIALOG_H
