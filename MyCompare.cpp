#include "MyCompare.h"


template<typename T>
MyCompare<T>::MyCompare(T &x, T &y)
{
  this->x=x;
  this->y = y;
}

template<typename T>
int MyCompare<T>::operator()()
{
    if(x<y)
        return -1;
    if(x>y)
        return 1;
    return 0;
}

template<typename T>
T MyCompare<T>::getX()
{
    return x;
}

template<typename T>
T MyCompare<T>::getY()
{
    return y;
}

template<typename T>
void MyCompare<T>::setX(T &x)
{
    this->x=x;
}

template<typename T>
void MyCompare<T>::setY(T &y)
{
    this->y=y;
}

