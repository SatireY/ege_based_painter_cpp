#pragma once
#include "graphics.h"
#include "Color.h"

enum class SHAPE
{
    shape_line,
    shape_circle,
    shape_rectangle,
    shape_polygon
};

class Shape
{
    public:
        static     int shapeCount;
        SHAPE      shapeType;
        Color     *outlineColor = new Color{};
        virtual void Draw(bool withColor) = 0;
        Shape();
        virtual ~Shape() {};
};

