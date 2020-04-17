#pragma once
#include "global.h"
#include <Windows.h>
#include "Shape.h"
#include "draw.h"

class Circle :
	public Shape
{
public:
	static       int circleCount;
	color_t      fillColor;
	Coordinate   coords;
	UINT         radius;
	bool         isFill;
	virtual void Draw(bool withColor) override;
	Circle();
	Circle(int x, int y, int radius);
	Circle(int x, int y, int radius, color_t outlineColor);
	Circle(int x, int y, int radius, color_t outlineColor, color_t fillColor);
	~Circle();
};

