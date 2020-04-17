#include "Line.h"

void Line::Draw(bool withColor)
{
	// set foreground color and fill color
	if (withColor)
	{
		setcolor(outlineColor);

		if (isFill)
		{
			setfillcolor(fillColor);
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

	line(coords[0].x,
		coords[0].y,
		coords[1].x,
		coords[1].y);
}

Line::Line()
{
	lineCount++;
}

Line::Line(int x1, int y1, int x2, int y2) : Line()
{
	shapeType = SHAPE::shape_line;
	outlineColor = RandColor();
	coords[0].x = x1;
	coords[0].y = y1;
	coords[1].x = x2;
	coords[1].y = y2;

}

Line::Line(int x1, int y1, int x2, int y2, color_t outlineColor) : Line()
{
	shapeType = SHAPE::shape_line;
	this->outlineColor = outlineColor;
	coords[0].x = x1;
	coords[0].y = y1;
	coords[1].x = x2;
	coords[1].y = y2;
}

Line::~Line()
{
	lineCount--;
}