#include "Coordinate.h"

Coordinate::Coordinate()
{
    x = 0;
    y = 0;
}

Coordinate::Coordinate(int x_, int y_) : x(x_), y(y_)
{
}

Coordinate Coordinate::operator+(const Coordinate &inCoord)
{
    return Coordinate((this->x + inCoord.x) / 2, (this->y + inCoord.y) / 2);
}

bool Coordinate::operator==(const Coordinate inCoord)
{
    return (this->x == inCoord.x) && (this->y == inCoord.y);
}

bool Coordinate::operator!=(const Coordinate inCoord)
{
    return !(*this == inCoord);
}

int Coordinate::operator[](const int &idx)
{
    if ((idx != 0) && (idx != 1))
    {
        throw std::out_of_range{"coordinate index out of range"};
    }

    return idx ? y : x;
}
