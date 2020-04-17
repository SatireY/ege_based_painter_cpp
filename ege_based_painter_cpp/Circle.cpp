#include "Circle.h"

Circle::Circle()
{
	circleCount++;
}

Circle::Circle(int x, int y, int radius) : Circle()
{
	isFill       = false;
	outlineColor = RandColor();
	coords.x     = x;
	coords.y     = y;
	this->radius = radius;
}

Circle::Circle(int x, int y, int radius, color_t outlineColor) : Circle()
{
	isFill             = false;
	this->outlineColor = outlineColor;
	coords.x           = x;
	coords.y           = y;
	this->radius       = radius;
}

Circle::Circle(int x, int y, int radius, color_t outlineColor, color_t fillColor) : Circle()
{
	isFill             = true;
	this->outlineColor = outlineColor;
	this->fillColor    = fillColor;
	coords.x           = x;
	coords.y           = y;
	this->radius       = radius;
}

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

Circle::~Circle()
{
	circleCount--;
}