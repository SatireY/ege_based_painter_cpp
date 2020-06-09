#pragma once
#include "graphics.h"
#include <stdexcept>

class Color
{
    public:
        color_t colorValue;
        Color();
        Color(const Color &origColor);
        Color(color_t colorValue);
        Color(int R, int G, int B);
        color_t setColorValue(color_t colorValue);
        color_t setColorValue(int R, int G, int B);
        color_t getColorValue();
        bool operator==(const Color inColor);
        bool operator!=(const Color inColor);
        color_t operator[](const int &idx);
        Color &operator++();
        Color operator++(int);
        Color &operator--();
        Color operator--(int);
};

