#pragma once
#include "global.h"
#include "UI.h"
#include "EGEEnvironmentController.h"

extern struct ShapeData shapeData[512];
extern char fileValidityCheckSuffix;
extern EGEEnvironmentController graphicsEnvironment;

bool ReadFromFile(void);
void TCHARToChar(const TCHAR *tchar, char *_char);