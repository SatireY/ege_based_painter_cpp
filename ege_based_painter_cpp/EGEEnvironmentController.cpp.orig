#include "EGEEnvironmentController.h"

EGEEnvironmentController::EGEEnvironmentController()
{
    canvasWidth  = 800;
    canvasHeight = 602;
    fontSize     = 18;
    font         = "Segoe UI";
    menuWidth    = 220;
    menuHeight   = 21;
    refreshRate  = 800;
}

void EGEEnvironmentController::Initialize()
{
    initgraph(GetCanvasWidth(), GetCanvasHeight());
    setfont(GetFontSize(), 0, GetFont());
}

INT EGEEnvironmentController::GetCanvasWidth()
{
    return canvasWidth;
}

INT EGEEnvironmentController::GetCanvasHeight()
{
    return canvasHeight;
}

INT EGEEnvironmentController::GetFontSize()
{
    return fontSize;
}

const char* EGEEnvironmentController::GetFont()
{
    return font.c_str();
}

INT EGEEnvironmentController::GetMenuWidth()
{
    return menuWidth;
}

INT EGEEnvironmentController::GetMenuHeight()
{
    return menuHeight;
}

INT EGEEnvironmentController::GetRefreshRate()
{
    return refreshRate;
}