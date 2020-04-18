#include "Polygon.h"

void myPolygon::Draw(bool withColor)
{
	int coordData[50];

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

	for (int j = 0; j < vertexCount; j++)
	{
		coordData[2 * j] = coords[2 * j];
		coordData[2 * j + 1] = coords[2 * j + 1];
	}

	coordData[2 * vertexCount] = coords[0];
	coordData[2 * vertexCount + 1] = coords[1];

	if (isFill)
	{
		fillpoly(vertexCount, coordData);
	}
	else
	{
		drawpoly(vertexCount + 1, coordData);
	}
}

myPolygon::myPolygon()
{
	polygonCount++;
}

myPolygon::myPolygon(const std::vector <int> coords, int vertexCount) : myPolygon()
{
	shapeType                = SHAPE::shape_polygon;
	isFill                   = false;
	outlineColor->colorValue = RandColor();
	this->coords             = coords;
	this->vertexCount        = vertexCount;
}

myPolygon::myPolygon(const std::vector <int> coords, int vertexCount, color_t outlineColor) : myPolygon()
{
	shapeType                      = SHAPE::shape_polygon;
	isFill                         = false;
	this->outlineColor->colorValue = outlineColor;
	this->coords                   = coords;
	this->vertexCount              = vertexCount;
}

myPolygon::myPolygon(const std::vector <int> coords, int vertexCount, color_t outlineColor, color_t fillColor) : myPolygon()
{
	shapeType                      = SHAPE::shape_polygon;
	isFill                         = true;
	this->outlineColor->colorValue = outlineColor;
	this->fillColor->colorValue    = fillColor;
	this->coords                   = coords;
	this->vertexCount              = vertexCount;
}

myPolygon::~myPolygon()
{
	polygonCount--;
	delete fillColor;
}