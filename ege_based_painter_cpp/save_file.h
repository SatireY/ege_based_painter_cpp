#pragma once
#include "global.h"
#include "read_file.h"
#include <filesystem>
#include <fstream>
#include <typeinfo>

extern WORD       g_nTotalShapes;
extern char       fileValidityCheckSuffix;
extern bool       g_isFileEdited;
extern char       DELIMITER_SPACE;

void WriteToFile(void);