#pragma once
#include "global.h"

class EGEEnvironmentController
{
private:
    INT         canvasWidth;
    INT         canvasHeight;
    INT         fontSize;
    std::string font;
    INT         menuWidth;
    INT         menuHeight;
    INT         refreshRate;
public:
                EGEEnvironmentController();
    void        Initialize();
    INT         GetCanvasWidth();
    INT         GetCanvasHeight();
    INT         GetFontSize();
    const char* GetFont();
    INT         GetMenuWidth();
    INT         GetMenuHeight();
    INT         GetRefreshRate();
    
};

