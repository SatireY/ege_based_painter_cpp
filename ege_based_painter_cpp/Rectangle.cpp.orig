#include "Rectangle.h"

void myRectangle::Draw(bool withColor)
{
    // set foreground color and fill color
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

    if (isFill)
    {
        bar(coords[0].x,
            coords[0].y,
            coords[1].x,
            coords[1].y);
    }
    else
    {
        rectangle(coords[0].x,
                  coords[0].y,
                  coords[1].x,
                  coords[1].y);
    }
}

int myRectangle::getRectangleCount()
{
    return myRectangle::rectangleCount;
}

myRectangle::myRectangle()
{
    rectangleCount++;
}

myRectangle::myRectangle(const myRectangle& origShape)
{
    delete outlineColor;
    outlineColor      = new Color{ origShape.outlineColor->colorValue };
    this->shapeType   = origShape.shapeType;

    delete fillColor;
    fillColor         = new Color{ origShape.fillColor->colorValue };
    this->coords[0].x = origShape.coords[0].x;
    this->coords[0].y = origShape.coords[0].y;
    this->coords[1].x = origShape.coords[1].x;
    this->coords[1].y = origShape.coords[1].y;
    this->isFill      = origShape.isFill;
}

myRectangle::myRectangle(int x1, int y1, int x2, int y2) : myRectangle()
{
    shapeType                = SHAPE::shape_rectangle;
    isFill                   = false;
    outlineColor->colorValue = RandColor();
    coords[0].x              = x1;
    coords[0].y              = y1;
    coords[1].x              = x2;
    coords[1].y              = y2;
}

myRectangle::myRectangle(int x1, int y1, int x2, int y2,
                         color_t outlineColor) : myRectangle()
{
    shapeType                      = SHAPE::shape_rectangle;
    isFill                         = false;
    this->outlineColor->colorValue = outlineColor;
    coords[0].x                    = x1;
    coords[0].y                    = y1;
    coords[1].x                    = x2;
    coords[1].y                    = y2;
}

myRectangle::myRectangle(int x1, int y1, int x2, int y2, color_t outlineColor,
                         color_t fillColor) : myRectangle()
{
    shapeType                      = SHAPE::shape_rectangle;
    isFill                         = true;
    this->outlineColor->colorValue = outlineColor;
    this->fillColor->colorValue    = fillColor;
    coords[0].x                    = x1;
    coords[0].y                    = y1;
    coords[1].x                    = x2;
    coords[1].y                    = y2;
}

myRectangle::~myRectangle()
{
    myRectangle::rectangleCount--;
    delete fillColor;
    Shape::shapeCount--;
    delete outlineColor;
    setcolor(0x000000);
    xyprintf(287 + 81, 582, "¾ØÐÎ: %d", myRectangle::getRectangleCount());
}