#ifndef LEVELDIALOG_H
#define LEVELDIALOG_H

#include <QDialog>

namespace Ui {
class LevelDialog;
}

class LevelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LevelDialog(QWidget *parent = nullptr);
    ~LevelDialog();

private slots:
    void on_pushButton_clicked();

    void on_rePlayPButton_clicked();

    void on_backToMain_clicked();

    void on_nextLevelButton_clicked();

private:
    Ui::LevelDialog *ui;
};

#endif // LEVELDIALOG_H
