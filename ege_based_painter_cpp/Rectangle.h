#pragma once
#include "global.h"
#include <Windows.h>
#include "Shape.h"
#include "draw.h"

class Rectangle :
	public Shape
{
public:
	static             int rectangleCount;
	color_t            fillColor;
	Coordinate         coords[2];
	bool               isFill;
	virtual void       Draw(bool withColor) override;
	Rectangle();
	Rectangle(int x1, int y1, int x2, int y2);
	Rectangle(int x1, int y1, int x2, int y2, color_t outlineColor);
	Rectangle(int x1, int y1, int x2, int y2, color_t outlineColor, color_t fillColor);
	~Rectangle();
};

