#include "Color.h"

Color::Color()
{
	this->colorValue = 0x0;
}

Color::Color(color_t colorValue)
{
	this->colorValue = colorValue;
}

Color::Color(int R, int G, int B)
{
	this->colorValue = EGERGB(R, G, B);
}