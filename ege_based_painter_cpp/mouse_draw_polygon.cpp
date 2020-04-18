#include "mouse_draw_polygon.h"

void mouse_DrawPoly(void)
{
    const short int   TOTAL_LN = 4; // total items in the menu bar
    bool              isInProgress = false;
    WORD              polyCoords[50];
    WORD              sides = 0;

    printf("已进入鼠标画多边形模式\n");
    printf("操作指南：\n");
    printf("用鼠标点选顶点，最后一个点靠近起始点来结束\n");
    DrawAllPrevShapes(true);
    DrawMenuOutline(1, TOTAL_LN, 1);
    setcolor(0x000000);
    PrintMouseDrawingInsideMenu(0);
    mouse_msg msg;

    for (; is_run();
         delay_fps(
             REFRESH_RATE)) // Using "for" statement to draw multiple circles at a time and refresh the screen
    {
        msg = getmouse();

        switch (msg.msg)
        {
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
                store the position data of it */
                if (!isInProgress)
                {
                    // store coordinate data
                    polyCoords[0] = msg.x;
                    polyCoords[1] = msg.y;
                    sides = 0;
                    printf("	您已选中点 (%d, %d)\n", polyCoords[0], polyCoords[1]);

                    isInProgress = true;
                    break;
                }

                /* if the mouse click indicates another dot,
                store the position data of it */
                if (isInProgress)
                {
                    // store coordinate data
                    sides++;
                    polyCoords[2 * sides] = msg.x;
                    polyCoords[2 * sides + 1] = msg.y;

                    printf("	您已选中点 (%d, %d)\n", polyCoords[2 * sides],
                           polyCoords[2 * sides + 1]);

                    // when the distance between
                    // the last dot and
                    // the first dot
                    // is smaller than 8 px
                    // then does the following things
                    if (sqrt(pow(polyCoords[0] - polyCoords[2 * sides], 2) +
                             pow(polyCoords[1] - polyCoords[2 * sides + 1], 2)) <= 8
                        && sides >= 3)
                    {
                        // closes the polygon
                        polyCoords[2 * sides] = polyCoords[0];
                        polyCoords[2 * sides + 1] = polyCoords[1];

                        std::vector <int> v_polyCoords(polyCoords, polyCoords + 50);

                        if (!g_isUserSetColor)
                        {
                            /*shapeData.push_back(new Circle{ circleCenterX, circleCenterY, static_cast<int>(sqrt(pow(circleCenterX - circleOuterX, 2) +
                                                            pow(circleCenterY - circleOuterY, 2))) });*/
                            if (!g_isUserSetFillColor)
                            {
                                // shapeData[g_nTotalShapes - 1].isFill = false;
                                shapeData.push_back(new myPolygon{ v_polyCoords, sides });
                            }
                            else
                            {
                                // shapeData[g_nTotalShapes - 1].isFill = true;

                                if (g_isFillColorRandom)
                                {
                                    // shapeData[g_nTotalShapes - 1].fillColor = RandColor();
                                    shapeData.push_back(new myPolygon{ v_polyCoords, sides, RandColor(), RandColor() });
                                }
                                else
                                {
                                    // shapeData[g_nTotalShapes - 1].fillColor = g_customFillColor;
                                    shapeData.push_back(new myPolygon{ v_polyCoords, sides, RandColor(), g_customFillColor });
                                }
                            }
                        }
                        else // hasSetColor
                        {
                            /*shapeData.push_back(new Circle{ circleCenterX, circleCenterY, static_cast<int>(sqrt(pow(circleCenterX - circleOuterX, 2) +
                                                            pow(circleCenterY - circleOuterY, 2))) ,g_customColor});*/
                            if (!g_isUserSetFillColor)
                            {
                                // shapeData[g_nTotalShapes - 1].isFill = false;
                                shapeData.push_back(new myPolygon{ v_polyCoords, sides, g_customColor });
                            }
                            else
                            {
                                // shapeData[g_nTotalShapes - 1].isFill = true;

                                if (g_isFillColorRandom)
                                {
                                    // shapeData[g_nTotalShapes - 1].fillColor = RandColor();
                                    shapeData.push_back(new myPolygon{ v_polyCoords, sides, g_customColor, RandColor() });
                                }
                                else
                                {
                                    // shapeData[g_nTotalShapes - 1].fillColor = g_customFillColor;
                                    shapeData.push_back(new myPolygon{ v_polyCoords, sides, g_customColor, g_customFillColor });
                                }
                            }
                        }

                        DrawAllPrevShapes(true);
                        isInProgress = false;
                        printf("	已完成%d边形的绘图\n", sides);
                        goto move;
                    }

                    if (sides >= 23)
                    {
                        MessageBox(NULL,
                                   TEXT("边数过多，请立即将正在绘画的多边形封口"),
                                   TEXT("即将溢出！"),
                                   MB_OK | MB_SYSTEMMODAL | MB_ICONEXCLAMATION);
                    }

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


                    DrawAllPrevShapes(true);
                    setcolor(0x909090);

                    // draws a line which is the line connecting
                    // the last dot of the polygon and the mouse pointer
                    if (sides >= 1)
                    {
                        for (int i = 0; i < sides * 2; i += 2)
                        {
                            line(polyCoords[i], polyCoords[i + 1], polyCoords[i + 2], polyCoords[i + 3]);
                        }
                    }

                    // closes the polgon automatically
                    // when the distance between
                    // the mouse pointer and the first dot of the polygon
                    // is smaller than 8px
                    if (sqrt(pow((double)polyCoords[0] - (double)msg.x, 2) +
                             pow((double)polyCoords[1] - (double)msg.y, 2)) <= 8
                        && sides >= 2)
                    {
                        line(polyCoords[sides * 2], polyCoords[sides * 2 + 1], polyCoords[0],
                             polyCoords[1]);
                    }
                    else
                    {
                        line(polyCoords[sides * 2], polyCoords[sides * 2 + 1], msg.x, msg.y);
                    }

                }

                break;

            default:
                break;
        }
    }
}