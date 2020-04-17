#include "Circle.h"

void Circle::Draw(bool withColor)
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

Circle::Circle()
{
	circleCount++;
}

Circle::Circle(int x, int y, int radius) : Circle()
{
	shapeType    = SHAPE::shape_circle;
	isFill       = false;
	outlineColor = RandColor();
	coords.x     = x;
	coords.y     = y;
	this->radius = radius;
}

Circle::Circle(int x, int y, int radius, color_t outlineColor) : Circle()
{
	shapeType          = SHAPE::shape_circle;
	isFill             = false;
	this->outlineColor = outlineColor;
	coords.x           = x;
	coords.y           = y;
	this->radius       = radius;
}

Circle::Circle(int x, int y, int radius, color_t outlineColor, color_t fillColor) : Circle()
{
	shapeType          = SHAPE::shape_circle;
	isFill             = true;
	this->outlineColor = outlineColor;
	this->fillColor    = fillColor;
	coords.x           = x;
	coords.y           = y;
	this->radius       = radius;
}

Circle::~Circle()
{
	circleCount--;
}