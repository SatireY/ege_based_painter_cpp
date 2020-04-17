#pragma once
#include "graphics.h"

enum class SHAPE
{
	shape_line,
	shape_circle,
	shape_rectangle,
	shape_polygon
};

class Shape
{
public:
	static     int shapeCount;
	SHAPE      shapeType;
	color_t    outlineColor;
	virtual void Draw(bool withColor) = 0;
	Shape();
	~Shape();
};

