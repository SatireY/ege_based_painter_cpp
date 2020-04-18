#pragma once
#include <Windows.h>
#include "EGEEnvironmentController.h"
#include "graphics.h"
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Line.h"
#include "Polygon.h"
// #include "global.h"

extern bool g_isUserSetColor;
extern bool g_isUserSetFillColor;
extern bool  g_isFillColorRandom;
extern color_t g_customColor;
extern color_t g_customFillColor;
// extern WORD g_nTotalShapes;
//     extern struct ShapeData shapeData[512];
extern int colorInf[7];

extern std::vector <Shape*> shapeData;
//extern int shapeCount;
//extern int circleCount;
//extern int rectangleCount;
//extern int lineCount;
//extern int polygonCount;
void DrawAllPrevShapes(bool withColor);
color_t RandColor(void);
void PrintMouseDrawingInsideMenu(WORD lnToPrint);
void PrintCoordDrawingInsideMenu(WORD lnToPrint);