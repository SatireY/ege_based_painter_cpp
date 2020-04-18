#pragma once
#include "global.h"
#include "Shape.h"
#include "draw.h"

class Circle :
    public Shape
{
    public:
        static       int circleCount;
        Color       *fillColor = new Color{};
        Coordinate   coords;
        int          radius;
        bool         isFill;
        void Draw(bool withColor) override;
        Circle();
        Circle(int x, int y, int radius);
        Circle(int x, int y, int radius, color_t outlineColor);
        Circle(int x, int y, int radius, color_t outlineColor, color_t fillColor);
        ~Circle();
};

