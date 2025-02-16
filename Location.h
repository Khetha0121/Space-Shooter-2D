#ifndef LOCATION_H
#define LOCATION_H

class Location
{
private:
    int x,y;
public:
    Location();
    Location(int x, int y);
    Location(Location &other);
    int getX();
    int getY();
    void setY(int y);
    Location& operator=(Location& source);
    ~Location();

};
#endif // LOCATION_H
