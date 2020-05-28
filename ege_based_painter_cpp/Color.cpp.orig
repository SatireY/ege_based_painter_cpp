#include "Color.h"

Color::Color()
{
    this->colorValue = 0x0;
}

Color::Color(const Color& origColor)
{
    this->colorValue = origColor.colorValue;
}

Color::Color(color_t colorValue)
{
    this->colorValue = colorValue;
}

Color::Color(int R, int G, int B)
{
    this->colorValue = EGERGB(R, G, B);
}

color_t Color::setColorValue(color_t colorValue)
{
    this->colorValue = colorValue;
    return this->colorValue;
}

color_t Color::setColorValue(int R, int G, int B)
{
    this->colorValue = EGERGB(R, G, B);
    return this->colorValue;
}

color_t Color::getColorValue()
{
    return this->colorValue;
}