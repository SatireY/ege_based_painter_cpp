#include "mouse_draw_line.h"

void mouse_DrawLine(void)
{
    const short int TOTAL_LN = 4;
    bool            isInProgress = false;
    int             lineStartPositionX;
    int             lineStartPositionY;
    int             lineEndPositionX;
    int             lineEndPositionY;

    printf("已进入鼠标画线模式\n");
    printf("操作指南：\n");
    printf("用鼠标先点选起点再点选终点即可连续画线\n");
    //setcolor(0x909090);
    DrawAllPrevShapes(true);
    DrawMenuOutline(1, TOTAL_LN, 1);
    setcolor(0x000000);
    PrintMouseDrawingInsideMenu(0);
    mouse_msg msg;

    for (; is_run();
         delay_fps(
             REFRESH_RATE)) // Using "for" statement to draw multiple circles at a time and refresh the screen
    {
        msg = getmouse(); // Get mouse clicks and position

        switch (msg.msg)
        {
            case mouse_msg_up:
                if (isInProgress)
                {
                    if (msg.x == lineStartPositionX && msg.y == lineStartPositionY)
                    {
                        continue;
                    }

                    lineEndPositionX = msg.x;
                    lineEndPositionY = msg.y;

                    printf("	您已选中终点 (%d, %d)\n", lineEndPositionX, lineEndPositionY);

                    // store coordinate data
                    /*g_nTotalShapes++;
                    shapeData[g_nTotalShapes - 1].shapeType = SHAPE::shape_line;
                    shapeData[g_nTotalShapes - 1].coords[0].x = lineStartPositionX;
                    shapeData[g_nTotalShapes - 1].coords[0].y = lineStartPositionY;
                    shapeData[g_nTotalShapes - 1].coords[1].x = lineEndPositionX;
                    shapeData[g_nTotalShapes - 1].coords[1].y = lineEndPositionY;*/

                    // store current color settings
                    if (!g_isUserSetColor)
                    {
                        shapeData.push_back(new Line{ 
                            lineStartPositionX, 
                            lineStartPositionY, 
                            lineEndPositionX, 
                            lineEndPositionY });
                    }
                    else
                    {
                        shapeData.push_back(new Line{ 
                            lineStartPositionX, 
                            lineStartPositionY, 
                            lineEndPositionX, 
                            lineEndPositionY, 
                            g_customColor });
                    }

                    DrawAllPrevShapes(true);

                    printf("	已画出从 (%d, %d) 到 (%d, %d) 的一条直线\n",
                           lineStartPositionX,
                           lineStartPositionY,
                           lineEndPositionX,
                           lineEndPositionY);

                    isInProgress = false; // reset the drawing process
                    goto move;
                    break;
                }

                break;

            case mouse_msg_down:
                switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
                {
                    case 1:
                        return;
                        break;

                    case 2: // undo
                        if (shapeData.size() > 0)
                        {
                            if (!isInProgress)
                            {
                                delete shapeData[shapeData.size() - 1];
                                shapeData.pop_back();
                            }
                        }

                        // refresh the windows with menu contents
                        cleardevice();
                        InitUI(0);
                        DrawMenuOutline(1, TOTAL_LN, 1);
                        setcolor(0x000000);
                        PrintMouseDrawingInsideMenu(0);
                        setcolor(0x50AA50);
                        xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);
                        DrawAllPrevShapes(true);
                        goto move;
                        break;

                    case 3: // choose foreground color
                        ChooseColor_EGE(0);
                        cleardevice();
                        InitUI(0);
                        DrawMenuOutline(1, TOTAL_LN, 1);
                        DrawAllPrevShapes(true);
                        goto move;
                        break;

                    case 4: // choose fill color
                        ChooseColor_EGE(1);
                        cleardevice();
                        InitUI(0);
                        DrawMenuOutline(1, TOTAL_LN, 1);
                        DrawAllPrevShapes(true);
                        goto move;
                        break;

                    default:
                        break;
                }

                /* if the mouse click indicates the first dot,
                store the position data of the starting point */
                if (!isInProgress)
                {
                    lineStartPositionX = msg.x;
                    lineStartPositionY = msg.y;

                    putpixel(lineStartPositionX, lineStartPositionY, 0x707000);
                    putpixel(lineStartPositionX + 1, lineStartPositionY, 0x707000);
                    putpixel(lineStartPositionX - 1, lineStartPositionY, 0x707000);
                    putpixel(lineStartPositionX, lineStartPositionY + 1, 0x707000);
                    putpixel(lineStartPositionX, lineStartPositionY - 1, 0x707000);

                    printf("	您已选中起点 (%d, %d)\n", lineStartPositionX, lineStartPositionY);

                    isInProgress = true; // updete the drawing process

                    break;
                }

                break; // not needed

            case mouse_msg_move:
move:
                if (!isInProgress)
                {
                    InitUI(0);
                    //DrawMenuOutline(1, TOTAL_LN, 1);
                    //setcolor(0x000000);
                    //PrintMouseDrawingInsideMenu(0);
                    setcolor(0x50AA50);
                    xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);

                    switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
                    {
                        case 0:
                            DrawMenuOutline(1, TOTAL_LN, 1);
                            setcolor(0x000000);
                            PrintMouseDrawingInsideMenu(0);
                            break;

                        case 1:
                            setcolor(0x000000);
                            PrintMouseDrawingInsideMenu(0);
                            setcolor(0x5050AA);
                            PrintMouseDrawingInsideMenu(1);
                            break;

                        case 2:
                            setcolor(0x000000);
                            PrintMouseDrawingInsideMenu(0);
                            setcolor(0x5050AA);
                            PrintMouseDrawingInsideMenu(2);
                            break;

                        case 3:
                            setcolor(0x000000);
                            PrintMouseDrawingInsideMenu(0);
                            setcolor(0x5050AA);
                            PrintMouseDrawingInsideMenu(3);
                            break;

                        case 4:
                            setcolor(0x000000);
                            PrintMouseDrawingInsideMenu(0);
                            setcolor(0x5050AA);
                            PrintMouseDrawingInsideMenu(4);
                            break;

                        default:
                            break;
                    }
                }

                if (isInProgress)
                {
                    // refresh continuously the screen to show live shape preview
                    cleardevice();
                    delay_fps(10000);
                    InitUI(1);
                    setcolor(0x50AA50);
                    xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);

                    putpixel(lineStartPositionX, lineStartPositionY, 0x707000);
                    putpixel(lineStartPositionX + 1, lineStartPositionY, 0x707000);
                    putpixel(lineStartPositionX - 1, lineStartPositionY, 0x707000);
                    putpixel(lineStartPositionX, lineStartPositionY + 1, 0x707000);
                    putpixel(lineStartPositionX, lineStartPositionY - 1, 0x707000);
                    putpixel(msg.x, msg.y, 0x707000);
                    putpixel(msg.x + 1, msg.y, 0x707000);
                    putpixel(msg.x - 1, msg.y, 0x707000);
                    putpixel(msg.x, msg.y + 1, 0x707000);
                    putpixel(msg.x, msg.y - 1, 0x707000);

                    DrawAllPrevShapes(true);
                    setcolor(0x909090);

                    line(lineStartPositionX, lineStartPositionY, msg.x, msg.y);
                }

                break;

            default:
                break;
        }
    }
}