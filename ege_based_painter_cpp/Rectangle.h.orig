#pragma once
#include "global.h"
#include <Windows.h>
#include "Shape.h"
#include "draw.h"

class myRectangle :
	public Shape
{
public:
	static             int rectangleCount;
	Color*             fillColor = new Color{};
	Coordinate         coords[2];
	bool               isFill;
	void       Draw(bool withColor) override;
	myRectangle();
	myRectangle(int x1, int y1, int x2, int y2);
	myRectangle(int x1, int y1, int x2, int y2, color_t outlineColor);
	myRectangle(int x1, int y1, int x2, int y2, color_t outlineColor, color_t fillColor);
	~myRectangle();
};

