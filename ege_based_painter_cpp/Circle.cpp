#include "Circle.h"

void Circle::Draw(bool withColor)
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
        fillellipse(coords.x,
                    coords.y,
                    radius,
                    radius);
    }
    else
    {
        circle(coords.x,
               coords.y,
               radius);
    }
}

int Circle::getCircleCount()
{
    return Circle::circleCount;
}

Circle::Circle()
{
    circleCount++;
}

Circle::Circle(const Circle& origShape)
{
    delete outlineColor;
    outlineColor    = new Color{ origShape.outlineColor->colorValue };
    this->shapeType = origShape.shapeType;

    delete fillColor;
    fillColor       = new Color{ origShape.fillColor->colorValue };
    this->coords.x  = origShape.coords.x;
    this->coords.y  = origShape.coords.y;
    this->radius    = origShape.radius;
    this->isFill    = origShape.isFill;
}
Circle::Circle(int x, int y, int radius) : Circle()
{
    shapeType                = SHAPE::shape_circle;
    isFill                   = false;
    outlineColor->colorValue = RandColor();
    coords.x                 = x;
    coords.y                 = y;
    this->radius = radius;
}

Circle::Circle(int x, int y, int radius, color_t outlineColor) : Circle()
{
    shapeType                      = SHAPE::shape_circle;
    isFill                         = false;
    this->outlineColor->colorValue = outlineColor;
    coords.x                       = x;
    coords.y                       = y;
    this->radius                   = radius;
}

Circle::Circle(int x, int y, int radius, color_t outlineColor,
               color_t fillColor) : Circle()
{
    shapeType                      = SHAPE::shape_circle;
    isFill                         = true;
    this->outlineColor->colorValue = outlineColor;
    this->fillColor->colorValue    = fillColor;
    coords.x                       = x;
    coords.y                       = y;
    this->radius                   = radius;
}

Circle::~Circle()
{
    Circle::circleCount--;
    Shape::shapeCount--;
    delete outlineColor;
    delete fillColor;
    setcolor(0x000000);
    xyprintf(245 + 81, 582, "圆: %d", Circle::getCircleCount());
}