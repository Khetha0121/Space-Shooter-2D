#ifndef LEVELOVERMULTI_H
#define LEVELOVERMULTI_H

#include <QDialog>

namespace Ui {
class LevelOverMulti;
}

class LevelOverMulti : public QDialog
{
    Q_OBJECT

public:
    explicit LevelOverMulti(QWidget *parent = nullptr);
    ~LevelOverMulti();

private slots:
    void on_multi_Next_clicked();

    void on_multi_Replay_clicked();

private:
    Ui::LevelOverMulti *ui;
};

#endif // LEVELOVERMULTI_H
