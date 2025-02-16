#ifndef MYCOMPARE_H
#define MYCOMPARE_H

template <typename T>
class MyCompare{

public:
    MyCompare(T &x, T &y);
    int operator()();
    T getX();
    T getY();
    void setX(T &x);
    void setY(T &y);

private:
    T x,y;


};
#endif // MYCOMPARE_H
