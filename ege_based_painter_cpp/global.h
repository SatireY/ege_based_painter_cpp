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

enum SHAPE
{
    shape_line,
    shape_circle,
    shape_rectangle,
    shape_polygon
};

struct ShapeData
{
    enum              SHAPE        shapeType;
    int               extraData[10];
    Coordinate        coords[50];
    bool              isFill;
    UINT              foregroundColor;
    UINT              fillColor;
};

struct MenuLnAndCol
{
    WORD ln;
    WORD col;
};