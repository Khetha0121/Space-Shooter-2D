#include "Location.h"

Location::Location()
{
    this->x=0;
    this->y=0;
}

Location::Location(int x, int y)
{
    this->x=x;
    this->y=y;
}

Location::Location(Location &other)
{

        this->x= other.getX();
        this->y = other.getY();

}

int Location::getX()
{
    return x;
}

int Location::getY()
{
    return y;
}

void Location::setY(int y)
{
    this->y = y;
}

Location &Location::operator=(Location &source)
{
    //if(x!=source.getX()&& y!=source.getY()){
        //Location(source);
        x=0;
        y=0;
        this->x= source.getX();
        this->y = source.getY();
    //}

    return *this;
}

Location::~Location()
{
}
