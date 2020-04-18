#pragma once
#include "global.h"
#include "Shape.h"
#include "draw.h"

class Polygon :
	public Shape
{
public:
	static                   int polygonCount;
	Color*                   fillColor = new Color{};
	int                      vertexCount;
	std::vector <Coordinate> coords;
	bool                     isFill;
	void                     Draw(bool withColor) override;
	Polygon();
	Polygon(const std::vector <Coordinate> coords);
	Polygon(const std::vector <Coordinate> coords, color_t outlineColor);
	Polygon(const std::vector <Coordinate> coords, color_t outlineColor, color_t fillColor);
	~Polygon();
};

