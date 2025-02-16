#ifndef GAMEUI_H
#define GAMEUI_H

#include <QWidget>

namespace Ui {
class GameUI;
}

class GameUI : public QWidget
{
    Q_OBJECT

public:
    explicit GameUI(QWidget *parent = nullptr);
    ~GameUI();

private:
    Ui::GameUI *ui;
};

#endif // GAMEUI_H
