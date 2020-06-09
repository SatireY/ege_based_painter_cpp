#include "Color.h"

Color::Color()
{
    this->colorValue = 0x0;
}

Color::Color(const Color &origColor)
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

bool Color::operator==(const Color inColor)
{
    return this->colorValue == inColor.colorValue;
}

bool Color::operator!=(const Color inColor)
{
    return this->colorValue != inColor.colorValue;
}

color_t Color::operator[](const int &idx)
{
    switch (idx)
    {
        case 0:
            return colorValue >> 16;
            break;

        case 1:
            return ((colorValue >> 16 << 16) ^ (colorValue >> 8 << 8)) >> 8;
            break;

        case 2:
            return (colorValue >> 8 << 8) ^ colorValue;
            break;

        default:
            throw std::out_of_range{ "color index out of range" };
            return 0;
            break;
    }
}

Color &Color::operator++()
{
    if ((colorValue >> 16) < 0xFE) // R
    {
        colorValue += 1 << 16; // R + 1
    }

    if ((((colorValue >> 16 << 16) ^ (colorValue >> 8 << 8)) >> 8) < 0xFE) // G
    {
        colorValue += 1 << 8; // G + 1
    }

    if (((colorValue >> 8 << 8) ^ colorValue) < 0xFE) // B
    {
        colorValue += 1; // B - 1
    }

    return *this;
}

Color Color::operator++(int)
{
    color_t tmp = colorValue;

    if ((colorValue >> 16) < 0xFE) // R
    {
        colorValue += 1 << 16; // R + 1
    }

    if ((((colorValue >> 16 << 16) ^ (colorValue >> 8 << 8)) >> 8) < 0xFE) // G
    {
        colorValue += 1 << 8; // G + 1
    }

    if (((colorValue >> 8 << 8) ^ colorValue) < 0xFE) // B
    {
        colorValue += 1; // B - 1
    }

    return Color(tmp);
}

Color &Color::operator--()
{
    if ((colorValue >> 16) > 0x0) // R
    {
        colorValue -= 1 << 16; // R - 1
    }

    if ((((colorValue >> 16 << 16) ^ (colorValue >> 8 << 8)) >> 8) > 0x0) // G
    {
        colorValue -= 1 << 8; // G - 1
    }

    if (((colorValue >> 8 << 8) ^ colorValue) > 0x0) // B
    {
        colorValue -= 1; // B - 1
    }

    return *this;
}

Color Color::operator--(int)
{
    color_t tmp = colorValue;

    if ((colorValue >> 16) > 0x0) // R
    {
        colorValue -= 1 << 16; // R - 1
    }

    if ((((colorValue >> 16 << 16) ^ (colorValue >> 8 << 8)) >> 8) > 0x0) // G
    {
        colorValue -= 1 << 8; // G - 1
    }

    if (((colorValue >> 8 << 8) ^ colorValue) > 0x0) // B
    {
        colorValue -= 1; // B - 1
    }

    return Color(tmp);
}
