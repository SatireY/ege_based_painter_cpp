#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define SHOW_CONSOLE // Display the console in addition to the EGE window, providing easier drawing experience
#define REFRESH_RATE 800

#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
#include <Commdlg.h>
#include <string>
#include <vector>
#include "EGEEnvironmentController.h"
#include "Coordinate.h"
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Line.h"
#include "Polygon.h"

struct MenuLnAndCol
{
    WORD ln;
    WORD col;
};