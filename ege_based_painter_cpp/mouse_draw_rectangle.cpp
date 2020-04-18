#include "mouse_draw_rectangle.h"

void mouse_DrawRectangle(void)
{
    const short int TOTAL_LN = 4; // total items in the menu bar
    bool            isInProgress = false;
    int             rectUpLCornerX;
    int             rectUpLCornerY;
    int             rectLowRCornerX;
    int             rectLowRCornerY;

    printf("已进入鼠标画矩形模式\n");
    printf("操作指南：\n");
    printf("用鼠标点选两个对角点即可连续画矩形\n");
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
        msg = getmouse();

        switch (msg.msg)
        {
            case mouse_msg_up:

                /* if the mouse click indicates the second dot,
                store the position data of the lower rignt corner */
                if (isInProgress)
                {
                    if (msg.x == rectUpLCornerX || msg.y == rectUpLCornerY)
                    {
                        continue;
                    }

                    rectLowRCornerX = msg.x;
                    rectLowRCornerY = msg.y;

                    printf("	您已选中点 (%d, %d)\n", rectLowRCornerX, rectLowRCornerY);

                    // store coordinate data
                    /*g_nTotalShapes++;
                    shapeData[g_nTotalShapes - 1].shapeType = SHAPE::shape_rectangle;
                    shapeData[g_nTotalShapes - 1].coords[0].x = rectUpLCornerX;
                    shapeData[g_nTotalShapes - 1].coords[0].y = rectUpLCornerY;
                    shapeData[g_nTotalShapes - 1].coords[1].x = rectLowRCornerX;
                    shapeData[g_nTotalShapes - 1].coords[1].y = rectLowRCornerY;*/

                    //// store current color settings
                    //if (!g_isUserSetColor)
                    //{
                    //    shapeData[g_nTotalShapes - 1].foregroundColor = RandColor();
                    //}
                    //else
                    //{
                    //    shapeData[g_nTotalShapes - 1].foregroundColor = g_customColor;
                    //} // end of if

                    //if (!g_isUserSetFillColor)
                    //{
                    //    shapeData[g_nTotalShapes - 1].isFill = false;
                    //}
                    //else
                    //{
                    //    shapeData[g_nTotalShapes - 1].isFill = true;

                    //    if (g_isFillColorRandom)
                    //    {
                    //        shapeData[g_nTotalShapes - 1].fillColor = RandColor();
                    //    }
                    //    else
                    //    {
                    //        shapeData[g_nTotalShapes - 1].fillColor = g_customFillColor;
                    //    } // end of if
                    //} // end of if

                    if (!g_isUserSetColor)
                    {
                        /*shapeData.push_back(new Circle{ circleCenterX, circleCenterY, static_cast<int>(sqrt(pow(circleCenterX - circleOuterX, 2) +
                                                        pow(circleCenterY - circleOuterY, 2))) });*/
                        if (!g_isUserSetFillColor)
                        {
                            // shapeData[g_nTotalShapes - 1].isFill = false;
                            shapeData.push_back(new myRectangle{ rectUpLCornerX, rectUpLCornerY, rectLowRCornerX, rectLowRCornerY });
                        }
                        else
                        {
                            // shapeData[g_nTotalShapes - 1].isFill = true;

                            if (g_isFillColorRandom)
                            {
                                // shapeData[g_nTotalShapes - 1].fillColor = RandColor();
                                shapeData.push_back(new myRectangle{ rectUpLCornerX, rectUpLCornerY, rectLowRCornerX, rectLowRCornerY, RandColor(), RandColor() });
                            }
                            else
                            {
                                // shapeData[g_nTotalShapes - 1].fillColor = g_customFillColor;
                                shapeData.push_back(new myRectangle{ rectUpLCornerX, rectUpLCornerY, rectLowRCornerX, rectLowRCornerY, RandColor(), g_customFillColor });
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
                            shapeData.push_back(new myRectangle{ rectUpLCornerX, rectUpLCornerY, rectLowRCornerX, rectLowRCornerY, g_customColor });
                        }
                        else
                        {
                            // shapeData[g_nTotalShapes - 1].isFill = true;

                            if (g_isFillColorRandom)
                            {
                                // shapeData[g_nTotalShapes - 1].fillColor = RandColor();
                                shapeData.push_back(new myRectangle{ rectUpLCornerX, rectUpLCornerY, rectLowRCornerX, rectLowRCornerY, g_customColor, RandColor() });
                            }
                            else
                            {
                                // shapeData[g_nTotalShapes - 1].fillColor = g_customFillColor;
                                shapeData.push_back(new myRectangle{ rectUpLCornerX, rectUpLCornerY, rectLowRCornerX, rectLowRCornerY, g_customColor, g_customFillColor });
                            }
                        }
                    }

                    DrawAllPrevShapes(true);

                    printf("	已画出以 (%d, %d) 和 (%d, %d) 为对角点的一个矩形\n",
                           rectUpLCornerX,
                           rectUpLCornerY,
                           rectLowRCornerX,
                           rectLowRCornerY);

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
                store the position data of the upper left corner */
                if (!isInProgress)
                {
                    rectUpLCornerX = msg.x;
                    rectUpLCornerY = msg.y;

                    // print a big dot
                    putpixel(rectUpLCornerX, rectUpLCornerY, 0x707000);
                    putpixel(rectUpLCornerX + 1, rectUpLCornerY, 0x707000);
                    putpixel(rectUpLCornerX - 1, rectUpLCornerY, 0x707000);
                    putpixel(rectUpLCornerX, rectUpLCornerY + 1, 0x707000);
                    putpixel(rectUpLCornerX, rectUpLCornerY - 1, 0x707000);

                    printf("	您已选中点 (%d, %d)\n", rectUpLCornerX, rectUpLCornerY);

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

                    putpixel(rectUpLCornerX, rectUpLCornerY, 0x707000);
                    putpixel(rectUpLCornerX + 1, rectUpLCornerY, 0x707000);
                    putpixel(rectUpLCornerX - 1, rectUpLCornerY, 0x707000);
                    putpixel(rectUpLCornerX, rectUpLCornerY + 1, 0x707000);
                    putpixel(rectUpLCornerX, rectUpLCornerY - 1, 0x707000);
                    putpixel(msg.x, msg.y, 0x707000);
                    putpixel(msg.x + 1, msg.y, 0x707000);
                    putpixel(msg.x - 1, msg.y, 0x707000);
                    putpixel(msg.x, msg.y + 1, 0x707000);
                    putpixel(msg.x, msg.y - 1, 0x707000);
                    DrawAllPrevShapes(true);
                    setcolor(0x909090);

                    rectangle(rectUpLCornerX, rectUpLCornerY, msg.x, msg.y);
                }

                break;

            default:
                break;
        }
    }
}