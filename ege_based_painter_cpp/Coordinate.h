#pragma once
#include <stdexcept>

class Coordinate
{
    public:
        Coordinate();
        Coordinate(int x_, int y_);
        int           x;
        int           y;
        Coordinate operator+(const Coordinate &inCoord);
        bool operator==(const Coordinate inCoord);
        bool operator!=(const Coordinate inCoord);
        int operator[](const int &idx);
};

