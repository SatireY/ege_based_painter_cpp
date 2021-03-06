#include "Polygon.h"

void myPolygon::Draw(bool withColor)
{
    int coordData[50];

    if (withColor)
    {
        setcolor(outlineColor->colorValue);

        if (isFill)
        {
            setfillcolor(fillColor->colorValue);
        }
        else
        {
            setfillcolor(0xFFFFFF);
        } // end of if
    }
    else
    {
        setcolor(0xCCCCCC);
        setfillcolor(0xDDDDDD);
    } // end of if

    for (int j = 0; j < vertexCount; j++)
    {
        coordData[2 * j]     = coords[2 * j];
        coordData[2 * j + 1] = coords[2 * j + 1];
    }

    coordData[2 * vertexCount]     = coords[0];
    coordData[2 * vertexCount + 1] = coords[1];

    if (isFill)
    {
        fillpoly(vertexCount, coordData);
    }
    else
    {
        drawpoly(vertexCount + 1, coordData);
    }
}

int myPolygon::getPolygonCount()
{
    return myPolygon::polygonCount;
}

myPolygon::myPolygon()
{
    polygonCount++;
}

myPolygon::myPolygon(const myPolygon &origShape)
{
    delete outlineColor;
    outlineColor      = new Color{ origShape.outlineColor->colorValue };
    this->shapeType   = origShape.shapeType;

    delete fillColor;
    fillColor         = new Color{ origShape.fillColor->colorValue };
    this->vertexCount = origShape.vertexCount;
    this->coords      = origShape.coords;
    this->isFill      = origShape.isFill;
}

myPolygon::myPolygon(const std::vector <int> coords,
                     int vertexCount) : myPolygon()
{
    shapeType                = SHAPE::shape_polygon;
    isFill                   = false;
    outlineColor->colorValue = RandColor();
    this->coords             = coords;
    this->vertexCount        = vertexCount;
}

myPolygon::myPolygon(const std::vector <int> coords, int vertexCount,
                     color_t outlineColor) : myPolygon()
{
    shapeType                      = SHAPE::shape_polygon;
    isFill                         = false;
    this->outlineColor->colorValue = outlineColor;
    this->coords                   = coords;
    this->vertexCount              = vertexCount;
}

myPolygon::myPolygon(const std::vector <int> coords, int vertexCount,
                     color_t outlineColor, color_t fillColor) : myPolygon()
{
    shapeType                      = SHAPE::shape_polygon;
    isFill                         = true;
    this->outlineColor->colorValue = outlineColor;
    this->fillColor->colorValue    = fillColor;
    this->coords                   = coords;
    this->vertexCount              = vertexCount;
}

myPolygon::~myPolygon()
{
    myPolygon::polygonCount--;
    delete fillColor;
    Shape::shapeCount--;
    delete outlineColor;
    setcolor(0x000000);
    xyprintf(343 + 81, 582, "??????: %d", myPolygon::getPolygonCount());
}