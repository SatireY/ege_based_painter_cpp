#include "Polygon.h"

void Polygon::Draw(bool withColor)
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
		coordData[2 * j] = coords[j].x;
		coordData[2 * j + 1] = coords[j].y;
	}

	coordData[2 * vertexCount] = coords[0].x;
	coordData[2 * vertexCount + 1] = coords[0].y;

	if (isFill)
	{
		fillpoly(vertexCount, coordData);
	}
	else
	{
		drawpoly(vertexCount + 1, coordData);
	}
}

Polygon::Polygon()
{
	polygonCount++;
}

Polygon::Polygon(const std::vector <Coordinate> coords) : Polygon()
{
	shapeType                = SHAPE::shape_polygon;
	isFill                   = false;
	outlineColor->colorValue = RandColor();
	this->coords             = coords;
	vertexCount              = coords.size() / 2;
}

Polygon::Polygon(const std::vector <Coordinate> coords, color_t outlineColor) : Polygon()
{
	shapeType                      = SHAPE::shape_polygon;
	isFill                         = false;
	this->outlineColor->colorValue = outlineColor;
	this->coords                   = coords;
	vertexCount                    = coords.size() / 2;
}

Polygon::Polygon(const std::vector <Coordinate> coords, color_t outlineColor, color_t fillColor) : Polygon()
{
	shapeType                      = SHAPE::shape_polygon;
	isFill                         = true;
	this->outlineColor->colorValue = outlineColor;
	this->fillColor->colorValue    = fillColor;
	this->coords                   = coords;
	vertexCount                    = coords.size() / 2;
}

Polygon::~Polygon()
{
	polygonCount--;
	delete fillColor;
}