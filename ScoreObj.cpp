#include "ScoreObj.h"
#include<QString>
#include<QFont>

ScoreObj::ScoreObj()
{

}

ScoreObj::ScoreObj(QString text, QGraphicsTextItem *parent): QGraphicsTextItem(parent)
{
 value =0;
 this->text = text;
 setPlainText(text+QString::number(value));
 setFont(QFont("times",16));//sets the desired font style with the integer size given

}

void ScoreObj::decrease()
{
    value--;
    setPlainText(text+QString::number(value));
}

void ScoreObj::increase()
{
    value++;
    setPlainText(text+QString::number(value));
}

int ScoreObj::getValue()
{
    return value;
}

void ScoreObj::setValue(int value)
{
    this->value= value;
    setPlainText(text+QString::number(value));
}

void ScoreObj::setHealthColour()
{
    setDefaultTextColor(Qt::red);
}

void ScoreObj::setScoreColour()
{
    setDefaultTextColor(Qt::blue);
}



