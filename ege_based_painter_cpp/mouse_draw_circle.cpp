#include "mouse_draw_circle.h"

void mouse_DrawCircle(void)
{
    const short int TOTAL_LN = 4; // total items in the menu bar
    // To determine whether the mouse click is the first step or the second step
    bool            isInProgress = false;
    int             circleCenterX;
    int             circleCenterY;
    int             circleOuterX;
    int             circleOuterY;

    printf("已进入鼠标画圆模式\n");
    printf("操作指南：\n");
    printf("用鼠标先点选圆心再点选圆上任意一点即可连续画圆\n");
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
        case mouse_msg_up:

            /* if the mouse click indicates the first dot,
            store the position data of another dot on the circle */
            if (isInProgress)
            {
                if (msg.x == circleCenterX || msg.y == circleCenterY)
                {
                    continue;
                }

                circleOuterX = msg.x;
                circleOuterY = msg.y;

                printf("	您已选中圆上一点 (%d, %d)\n", circleOuterX, circleOuterY);

                // store coordinate data
                /*g_nTotalShapes++;
                shapeData[g_nTotalShapes - 1].shapeType = SHAPE::shape_circle;
                shapeData[g_nTotalShapes - 1].coords[0].x = circleCenterX;
                shapeData[g_nTotalShapes - 1].coords[0].y = circleCenterY;
                shapeData[g_nTotalShapes - 1].coords[1].x = circleOuterX;
                shapeData[g_nTotalShapes - 1].coords[1].y = circleOuterY;*/

                /*shapeData.push_back(new Circle{ circleCenterX, circleCenterY, static_cast<int>(sqrt(pow(circleCenterX - circleOuterX, 2) +
                                                    pow(circleCenterY - circleOuterY, 2))) });*/

                                                    // store current color settings
                if (!g_isUserSetColor)
                {
                    /*shapeData.push_back(new Circle{ circleCenterX, circleCenterY, static_cast<int>(sqrt(pow(circleCenterX - circleOuterX, 2) +
                                                    pow(circleCenterY - circleOuterY, 2))) });*/
                    if (!g_isUserSetFillColor)
                    {
                        // shapeData[g_nTotalShapes - 1].isFill = false;
                        shapeData.push_back(new Circle{ circleCenterX, circleCenterY, static_cast<int>(sqrt(pow(circleCenterX - circleOuterX, 2) +
                                                        pow(circleCenterY - circleOuterY, 2))) });
                    }
                    else
                    {
                        // shapeData[g_nTotalShapes - 1].isFill = true;

                        if (g_isFillColorRandom)
                        {
                            // shapeData[g_nTotalShapes - 1].fillColor = RandColor();
                            shapeData.push_back(new Circle{ circleCenterX, circleCenterY, static_cast<int>(sqrt(pow(circleCenterX - circleOuterX, 2) +
                                                        pow(circleCenterY - circleOuterY, 2))), RandColor(), RandColor() });
                        }
                        else
                        {
                            // shapeData[g_nTotalShapes - 1].fillColor = g_customFillColor;
                            shapeData.push_back(new Circle{ circleCenterX, circleCenterY, static_cast<int>(sqrt(pow(circleCenterX - circleOuterX, 2) +
                                                        pow(circleCenterY - circleOuterY, 2))), RandColor(), g_customFillColor });
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
                        shapeData.push_back(new Circle{ circleCenterX, circleCenterY, static_cast<int>(sqrt(pow(circleCenterX - circleOuterX, 2) +
                                                        pow(circleCenterY - circleOuterY, 2))), g_customColor });
                    }
                    else
                    {
                        // shapeData[g_nTotalShapes - 1].isFill = true;

                        if (g_isFillColorRandom)
                        {
                            // shapeData[g_nTotalShapes - 1].fillColor = RandColor();
                            shapeData.push_back(new Circle{ circleCenterX, circleCenterY, static_cast<int>(sqrt(pow(circleCenterX - circleOuterX, 2) +
                                                        pow(circleCenterY - circleOuterY, 2))), g_customColor, RandColor() });
                        }
                        else
                        {
                            // shapeData[g_nTotalShapes - 1].fillColor = g_customFillColor;
                            shapeData.push_back(new Circle{ circleCenterX, circleCenterY, static_cast<int>(sqrt(pow(circleCenterX - circleOuterX, 2) +
                                                        pow(circleCenterY - circleOuterY, 2))), g_customColor, g_customFillColor });
                        }
                    }
                }

                //if (!g_isUserSetFillColor)
                //{
                //    // shapeData[g_nTotalShapes - 1].isFill = false;
                //}
                //else
                //{
                //    // shapeData[g_nTotalShapes - 1].isFill = true;

                //    if (g_isFillColorRandom)
                //    {
                //        // shapeData[g_nTotalShapes - 1].fillColor = RandColor();
                //        shapeData.push_back(new Circle{ circleCenterX, circleCenterY, static_cast<int>(sqrt(pow(circleCenterX - circleOuterX, 2) +
                //                                    pow(circleCenterY - circleOuterY, 2))) });
                //    }
                //    else
                //    {
                //        // shapeData[g_nTotalShapes - 1].fillColor = g_customFillColor;
                //        shapeData.push_back(new Circle{ circleCenterX, circleCenterY, static_cast<int>(sqrt(pow(circleCenterX - circleOuterX, 2) +
                //                                    pow(circleCenterY - circleOuterY, 2))) });
                //    }
                //}

                DrawAllPrevShapes(true);

                printf("	已画出以 (%d, %d) 为圆心，(%d, %d) 为圆上一点，半径为 %d 的一个圆\n",
                    circleCenterX,
                    circleCenterY,
                    circleOuterX,
                    circleOuterY,
                    (int)sqrt(pow(circleCenterX -
                        circleOuterX, 2) +
                        pow(circleCenterY - circleOuterY, 2)));

                isInProgress = false;
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
                /*if (g_nTotalShapes > 0)
                {
                    if (!isInProgress)
                    {
                        g_nTotalShapes--;
                    }
                }*/

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
            store the position data of the center of the circle */
            if (!isInProgress)
            {
                circleCenterX = msg.x;
                circleCenterY = msg.y;

                // print a big dot
                putpixel(circleCenterX, circleCenterY, 0x707000);
                putpixel(circleCenterX + 1, circleCenterY, 0x707000);
                putpixel(circleCenterX - 1, circleCenterY, 0x707000);
                putpixel(circleCenterX, circleCenterY + 1, 0x707000);
                putpixel(circleCenterX, circleCenterY - 1, 0x707000);

                printf("	您已选中圆心 (%d, %d)\n", circleCenterX, circleCenterY);

                isInProgress = true;
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

                putpixel(circleCenterX, circleCenterY, 0x707000);
                putpixel(circleCenterX + 1, circleCenterY, 0x707000);
                putpixel(circleCenterX - 1, circleCenterY, 0x707000);
                putpixel(circleCenterX, circleCenterY + 1, 0x707000);
                putpixel(circleCenterX, circleCenterY - 1, 0x707000);
                putpixel(msg.x, msg.y, 0x707000);
                putpixel(msg.x + 1, msg.y, 0x707000);
                putpixel(msg.x - 1, msg.y, 0x707000);
                putpixel(msg.x, msg.y + 1, 0x707000);
                putpixel(msg.x, msg.y - 1, 0x707000);
                DrawAllPrevShapes(true);
                setcolor(0x909090);

                circle(circleCenterX, circleCenterY,
                    (int)sqrt(pow((double)circleCenterX - (double)msg.x,
                        2) + pow((double)circleCenterY - (double)msg.y, 2)));
            }

            break;

        default:
            break;
        }
    }
}