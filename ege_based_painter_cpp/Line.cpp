#include "Line.h"

void Line::Draw(bool withColor)
{
    // set foreground color and fill color
    if (withColor)
    {
        setcolor(outlineColor->colorValue);
    }
    else
    {
        setcolor(0xCCCCCC);
        setfillcolor(0xDDDDDD);
    } // end of if

    line(coords[0].x,
         coords[0].y,
         coords[1].x,
         coords[1].y);
}

int Line::getLineCount()
{
    return Line::lineCount;
}

Line::Line()
{
    lineCount++;
}

Line::Line(const Line& origShape)
{
    delete outlineColor;
    outlineColor      = new Color{ origShape.outlineColor->colorValue };
    this->shapeType   = origShape.shapeType;
  
    this->coords[0].x = origShape.coords[0].x;
    this->coords[0].y = origShape.coords[0].y;
    this->coords[1].x = origShape.coords[1].x;
    this->coords[1].y = origShape.coords[1].y;
}

Line::Line(int x1, int y1, int x2, int y2) : Line()
{
    shapeType                = SHAPE::shape_line;
    outlineColor->colorValue = RandColor();
    coords[0].x              = x1;
    coords[0].y              = y1;
    coords[1].x              = x2;
    coords[1].y              = y2;

}

Line::Line(int x1, int y1, int x2, int y2, color_t outlineColor) : Line()
{
    shapeType                      = SHAPE::shape_line;
    this->outlineColor->colorValue = outlineColor;
    coords[0].x                    = x1;
    coords[0].y                    = y1;
    coords[1].x                    = x2;
    coords[1].y                    = y2;
}

Line::~Line()
{
    Line::lineCount--;
    Shape::shapeCount--;
    delete outlineColor;
    setcolor(0x000000);
    xyprintf(203 + 81, 582, "Ïß: %d", Line::getLineCount());
}