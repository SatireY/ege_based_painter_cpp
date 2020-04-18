#pragma once
#include "graphics.h"

class Color
{
    public:
        color_t colorValue;
        Color();
        Color(color_t colorValue);
        Color(int R, int G, int B);
        color_t setColorValue(color_t colorValue);
        color_t setColorValue(int R, int G, int B);
        color_t getColorValue();
};

