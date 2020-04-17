#include "global.h"
#include "menu.h"

extern EGEEnvironmentController graphicsEnvironment;

int main()
{
    graphicsEnvironment.Initialize();
    setbkcolor(0xFFFFFF);
    Menu(ReadFromFile());
    return 0;
}
