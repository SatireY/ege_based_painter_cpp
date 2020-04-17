#pragma once

typedef enum
{
	shape_line,
	shape_circle,
	shape_rectangle,
	shape_polygon
} SHAPE;

class Shape
{
public:
	static int shapeCount;
	SHAPE shapeType;
	virtual void Draw(bool withColor) = 0;
	Shape();
	~Shape();

};

