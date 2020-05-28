#include "global.h"

bool                 g_isUserSetColor                = false;
bool                 g_isUserSetFillColor            = false;
bool                 g_isFillColorRandom             = false;
color_t              g_customColor                   = 0x0;
color_t              g_customFillColor               = 0x0;
//                   struct ShapeData shapeData[512];
//                   WORD             g_nTotalShapes = 0;
bool                 g_isFileEdited                  = false;
char                 fileValidityCheckSuffix         = '\0';
char                 DELIMITER_SPACE                 = ' ';

EGEEnvironmentController graphicsEnvironment{};
int Shape::shapeCount           = 0;
int Circle::circleCount         = 0;
int myRectangle::rectangleCount = 0;
int Line::lineCount             = 0;
int myPolygon::polygonCount     = 0;


std::vector <Shape *> shapeData; // the vector that stores all the shapes