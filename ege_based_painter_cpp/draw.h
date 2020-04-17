#pragma once
#include <Windows.h>
#include "EGEEnvironmentController.h"
#include "graphics.h"

extern bool g_isUserSetColor;
extern bool g_isUserSetFillColor;
extern bool  g_isFillColorRandom;
extern int g_customColor;
extern int g_customFillColor;
extern WORD g_nTotalShapes;
extern struct ShapeData shapeData[512];
extern int colorInf[7];

void DrawAllPrevShapes(bool withColor);
color_t RandColor(void);
void PrintMouseDrawingInsideMenu(WORD lnToPrint);
void PrintCoordDrawingInsideMenu(WORD lnToPrint);