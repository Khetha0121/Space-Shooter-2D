#include "User.h"


User::User()
{
    stats = new QVector<Stat*>();
    final = new Stat();
    turn = false;
}

bool User::getTurn()
{
    return turn;
}

void User::setTurn(bool turn)
{
    this->turn = turn;
}

void User::computeFinalStat()
{
    int score = 0;
    double grade = 0.0;
    double accuracy = 0.0;

    for (int i = 0; i < stats->size(); ++i) {
        score+= stats->at(i)->score;
        grade+=stats->at(i)->grade;
        accuracy+=stats->at(i)->accuracy;
    }

    grade = grade/stats->size();
    accuracy = accuracy/stats->size();
    final->score= score;
    final->grade= grade;
    final->accuracy= accuracy;
}
