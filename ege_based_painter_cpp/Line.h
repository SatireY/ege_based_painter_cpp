#pragma once
#include "Shape.h"
#include "global.h"
#include "draw.h"

class Line :
    public Shape
{
    public:
        static int lineCount;
        Coordinate coords[2];
        void Draw(bool withColor) override;
        Line();
        Line(int x1, int y1, int x2, int y2);
        Line(int x1, int y1, int x2, int y2, color_t outlineColor);
        ~Line();
};

