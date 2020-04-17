#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define SHOW_CONSOLE /graphicsEnvironment.GetMenuWidth()/ Display the console in addition to the EGE window, providing easier drawing experience
#define CANVAS_WIDTH 800
#define CANVAS_HIGHT 602
// #define graphicsEnvironment.GetFontSize() 18
// #define graphicsEnvironment.GetFont() "Segoe UI"
// #define graphicsEnvironment.GetMenuWidth() 220
// #define graphicsEnvironment.GetMenuHeight() 21
#define REFRESH_RATE 800

#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
#include <Commdlg.h>
#include <string>
#include "EGEEnvironmentController.h"



enum SHAPE
{
    shape_line,
    shape_circle,
    shape_rectangle,
    shape_polygon
};

struct Coordinate
{
    WORD x;
    WORD y;
};

struct ShapeData
{
    enum SHAPE        shapeType;
    int               extraData[10];
    struct Coordinate coords[50];
    bool              isFill;
    UINT              foregroundColor;
    UINT              fillColor;
};

struct MenuLnAndCol
{
    WORD ln;
    WORD col;
};