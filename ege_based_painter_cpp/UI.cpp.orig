#include "UI.h"


void InitUI(short int errCode)
{
    static int tmp_totalShapes;

    //count the number of each shape
    if (shapeData.size() > 0)
    {
        if (tmp_totalShapes != shapeData[0]->shapeCount)
        {
            g_isFileEdited = true; // indicates whether the picture is edited
        }
        tmp_totalShapes = shapeData[0]->shapeCount;
    }

    // draw UI outlines
    setcaption("CC 画板");
    setcolor(0x909090);
    line(0, 579, 800, 579);
    line(675, 579, 675, graphicsEnvironment.GetCanvasHeight());
    line(142, 579, 142, graphicsEnvironment.GetCanvasHeight());
    line(280, 579, 280, graphicsEnvironment.GetCanvasHeight());
    line(500, 579, 500, graphicsEnvironment.GetCanvasHeight());
    line(62, 579, 62, graphicsEnvironment.GetCanvasHeight());
    line(10 + graphicsEnvironment.GetMenuWidth(), 1,
         10 + graphicsEnvironment.GetMenuWidth(), 579);

    if (errCode == 0)
    {
        setcolor(0x50AA50);
        xyprintf(2, 582, "准备就绪");
    }
    else
    {
        setcolor(0xAAAA50);
        xyprintf(2, 582, "正在绘图");
    }

    if (g_isFileEdited)
    {
        setcolor(0xAA5050);
        xyprintf(67, 582, "更改未保存");
    }
    else
    {
        setcolor(0x50AA50);
        xyprintf(67, 582, "更改已保存");
    }

    setcolor(0x000000);
    xyprintf(133 + 16, 582, "提示信息请看控制台");

    // display the number of each shape
    /*xyprintf(203 + 81, 582, "线: %d", nLines);
    xyprintf(245 + 81, 582, "圆: %d", nCircles);
    xyprintf(287 + 81, 582, "矩形: %d", nRectangles);
    xyprintf(343 + 81, 582, "多边形: %d", nPolygons);*/
    xyprintf(245 + 81, 582, "圆: %d", Circle::getCircleCount());
    xyprintf(203 + 81, 582, "线: %d", Line::getLineCount());
    xyprintf(343 + 81, 582, "多边形: %d", myPolygon::getPolygonCount());
    xyprintf(287 + 81, 582, "矩形: %d", myRectangle::getRectangleCount());

    // shhow the current color settings
    xyprintf(505, 582, "前景:");

    if (g_isUserSetColor)
    {
        setfillcolor(g_customColor);
        bar(540, 585, 565, 597);
    }
    else
    {
        setcolor(0x000000);
        xyprintf(540, 582, "随机");
    }

    xyprintf(585, 582, "填充:");

    if (g_isUserSetFillColor)
    {
        if (g_isFillColorRandom)
        {
            setcolor(0x000000);
            xyprintf(620, 582, "随机");
        }
        else
        {
            setfillcolor(g_customFillColor);
            bar(620, 585, 645, 597);
        }
    }
    else
    {
        setcolor(0x000000);
        xyprintf(620, 582, "无");
    }
}

void ClearData(void)
{
    for (auto i : shapeData)
    {
        delete i;
        shapeData.pop_back();
    }

}

void DrawMenuOutline(WORD lnStart,
                     WORD lnEnd,
                     WORD col)
{
    setcolor(0x909090);

    // vertical lines
    for (int j = 0; j <= col; j++)
    {
        line(5 + j * graphicsEnvironment.GetMenuWidth() / col,
             5 + graphicsEnvironment.GetMenuHeight() * (lnStart - 1),
             5 + j * graphicsEnvironment.GetMenuWidth() / col,
             5 + graphicsEnvironment.GetMenuHeight() * lnEnd);
    }

    // horizontal lines
    for (int i = lnStart - 1; i <= lnEnd; i++)
    {
        line(5,
             5 + graphicsEnvironment.GetMenuHeight() * i,
             5 + graphicsEnvironment.GetMenuWidth(),
             5 + graphicsEnvironment.GetMenuHeight() * i);
        //xyprintf(6 + graphicsEnvironment.GetMenuWidth(), 5 + graphicsEnvironment.GetMenuHeight() * (i - 1) - 10,"%d\n", 5 + graphicsEnvironment.GetMenuHeight() * (i - 1));
        //xyprintf(5, 5 + graphicsEnvironment.GetMenuHeight() * (i - 1) + 1, "%d", i);
    }
}

struct MenuLnAndCol GetMouseCurrentLnAndCol(
    WORD lnStart,
    WORD lnEnd,
    WORD colNeeded,
    WORD colTotal)
{
    int x, y;
    struct MenuLnAndCol coord;
    coord.ln = 0;
    coord.col = 0;
    mousepos(&x, &y);

    /*
    at first, i used the getmouse() function
    but a i encountered a issue where the function keeps waiting mouse input when there is no mouse input
    thus causing possible delays
    later i switched to the mousepos() function
    finally!!!!
    there is no delay
    */

    if ((x >= 5 + (colNeeded - 1) * (graphicsEnvironment.GetMenuWidth() / colTotal))
        && (y >= 5 + (lnStart - 1) * graphicsEnvironment.GetMenuHeight())
        && (x <= 5 + (colNeeded) * (graphicsEnvironment.GetMenuWidth() / colTotal))
        && (y <= 5 + lnEnd * graphicsEnvironment.GetMenuHeight()))
    {
        coord.ln = (y - 5) / graphicsEnvironment.GetMenuHeight() + 1;
        coord.col = (x - 5) / (graphicsEnvironment.GetMenuWidth() / colTotal) + 1;
    }

    return coord;
}