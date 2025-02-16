#ifndef SCOREOBJ_H
#define SCOREOBJ_H
#include <QGraphicsTextItem>
#include<QString>

class ScoreObj:public QGraphicsTextItem{
public:
    ScoreObj();
    ScoreObj(QString text,QGraphicsTextItem* parent = 0);

    void increase();
    void decrease();
    int getValue();
    void setValue(int value);
    void setHealthColour();
    void setScoreColour();
private:
    int value;
    QString text;


};


#endif // SCOREOBJ_H
