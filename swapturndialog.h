#ifndef SWAPTURNDIALOG_H
#define SWAPTURNDIALOG_H

#include <QDialog>

namespace Ui {
class SwapTurnDialog;
}

class SwapTurnDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SwapTurnDialog(QWidget *parent = nullptr);
    ~SwapTurnDialog();

private slots:
    void on_playButton_clicked();

private:
    Ui::SwapTurnDialog *ui;
};

#endif // SWAPTURNDIALOG_H
