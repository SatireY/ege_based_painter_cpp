#pragma once
#include "global.h"
#include "UI.h"
#include "EGEEnvironmentController.h"
#include <filesystem>
#include <fstream>

// extern struct ShapeData shapeData[512];
extern char fileValidityCheckSuffix;
extern      EGEEnvironmentController graphicsEnvironment;

int ReadFromFile(void);
void TCHARToChar(const TCHAR *tchar, char *_char);