#ifndef USER_H
#define USER_H
#include "Stat.h"
#include <QVector>

class User{

public:
    QVector<Stat*> * stats;
    Stat *final ;
    User();
    bool getTurn();
    void setTurn(bool turn);
    void computeFinalStat();
    bool betterThan(User& other);

private:
   bool turn;


};

#endif // USER_H
