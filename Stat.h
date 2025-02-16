#ifndef STAT_H
#define STAT_H
#include "MyCompare.h"

struct Stat
{
int score;
double accuracy;
double grade;
    Stat() {}

    int compare(Stat &other){
        MyCompare<double> gradeComparer(grade,other.grade);
        MyCompare<double> accuracyComparer(accuracy,other.accuracy);
        MyCompare<int> scoreComparer(score,other.score);

        if(gradeComparer() > 0)
            return 1;
        if(gradeComparer() < 0)
            return -1;
        if(gradeComparer() == 0){

            if(scoreComparer() > 0)
                return 1;
            if(scoreComparer() < 0)
                return -1;
            if(scoreComparer() == 0){
                if(accuracyComparer() > 0)
                    return 1;
                if(accuracyComparer() < 0)
                    return -1;
            }
        }

    }
};

#endif // STAT_H
