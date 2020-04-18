#pragma once
#include "global.h"
#include "Shape.h"
#include "draw.h"

class myPolygon :
    public Shape
{
    public:
        static                   int polygonCount;
        Color                   *fillColor = new Color{};
        int                      vertexCount;
        std::vector <int>        coords;
        bool                     isFill;
        void                     Draw(bool withColor) override;
        myPolygon();
        myPolygon(const std::vector <int> coords, int vertexCount);
        myPolygon(const std::vector <int> coords, int vertexCount,
                  color_t outlineColor);
        myPolygon(const std::vector <int> coords, int vertexCount, color_t outlineColor,
                  color_t fillColor);
        ~myPolygon();
};

