#include "global.h"

bool             g_isUserSetColor = false;
bool             g_isUserSetFillColor = false;
bool             g_isFillColorRandom = false;
int              g_customColor = 0x0;
int              g_customFillColor = 0x0;
struct ShapeData shapeData[512];
WORD             g_nTotalShapes = 0;
bool             g_isFileEdited = false;
char             fileValidityCheckSuffix = '\0';

EGEEnvironmentController graphicsEnvironment{};
int Shape::shapeCount = 0;
int Circle::circleCount = 0;
int Rectangle::rectangleCount = 0;
int Line::lineCount = 0;
int Polygon::polygonCount = 0;