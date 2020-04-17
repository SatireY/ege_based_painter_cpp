#pragma once
#include "global.h"

class Color
{
public:
	color_t colorValue;
	Color();
	Color(color_t colorValue);
	Color(int R, int G, int B);
};

