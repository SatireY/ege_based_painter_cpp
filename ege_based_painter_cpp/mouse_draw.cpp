#include "mouse_draw.h"

//void mouse_DrawCircle(void)
//{
//    const short int TOTAL_LN = 4; // total items in the menu bar
//    // To determine whether the mouse click is the first step or the second step
//    bool            isInProgress = false;
//    int             circleCenterX;
//    int             circleCenterY;
//    int             circleOuterX;
//    int             circleOuterY;
//
//    printf("�ѽ�����껭Բģʽ\n");
//    printf("����ָ�ϣ�\n");
//    printf("������ȵ�ѡԲ���ٵ�ѡԲ������һ�㼴��������Բ\n");
//    DrawAllPrevShapes(true);
//    DrawMenuOutline(1, TOTAL_LN, 1);
//    setcolor(0x000000);
//    PrintMouseDrawingInsideMenu(0);
//    mouse_msg msg;
//
//    for (; is_run();
//         delay_fps(
//             REFRESH_RATE)) // Using "for" statement to draw multiple circles at a time and refresh the screen
//    {
//        msg = getmouse();
//
//        switch (msg.msg)
//        {
//            case mouse_msg_up:
//
//                /* if the mouse click indicates the first dot,
//                store the position data of another dot on the circle */
//                if (isInProgress)
//                {
//                    if (msg.x == circleCenterX || msg.y == circleCenterY)
//                    {
//                        continue;
//                    }
//
//                    circleOuterX = msg.x;
//                    circleOuterY = msg.y;
//
//                    printf("	����ѡ��Բ��һ�� (%d, %d)\n", circleOuterX, circleOuterY);
//
//                    // store coordinate data
//                    /*g_nTotalShapes++;
//                    shapeData[g_nTotalShapes - 1].shapeType = SHAPE::shape_circle;
//                    shapeData[g_nTotalShapes - 1].coords[0].x = circleCenterX;
//                    shapeData[g_nTotalShapes - 1].coords[0].y = circleCenterY;
//                    shapeData[g_nTotalShapes - 1].coords[1].x = circleOuterX;
//                    shapeData[g_nTotalShapes - 1].coords[1].y = circleOuterY;*/
//
//                    /*shapeData.push_back(new Circle{ circleCenterX, circleCenterY, static_cast<int>(sqrt(pow(circleCenterX - circleOuterX, 2) +
//                                                        pow(circleCenterY - circleOuterY, 2))) });*/
//
//                    // store current color settings
//                    if (!g_isUserSetColor)
//                    {
//                        /*shapeData.push_back(new Circle{ circleCenterX, circleCenterY, static_cast<int>(sqrt(pow(circleCenterX - circleOuterX, 2) +
//                                                        pow(circleCenterY - circleOuterY, 2))) });*/
//                        if (!g_isUserSetFillColor)
//                        {
//                            // shapeData[g_nTotalShapes - 1].isFill = false;
//                            shapeData.push_back(new Circle{ circleCenterX, circleCenterY, static_cast<int>(sqrt(pow(circleCenterX - circleOuterX, 2) +
//                                                            pow(circleCenterY - circleOuterY, 2)))});
//                        }
//                        else
//                        {
//                            // shapeData[g_nTotalShapes - 1].isFill = true;
//
//                            if (g_isFillColorRandom)
//                            {
//                                // shapeData[g_nTotalShapes - 1].fillColor = RandColor();
//                                shapeData.push_back(new Circle{ circleCenterX, circleCenterY, static_cast<int>(sqrt(pow(circleCenterX - circleOuterX, 2) +
//                                                            pow(circleCenterY - circleOuterY, 2))), RandColor(), RandColor()});
//                            }
//                            else
//                            {
//                                // shapeData[g_nTotalShapes - 1].fillColor = g_customFillColor;
//                                shapeData.push_back(new Circle{ circleCenterX, circleCenterY, static_cast<int>(sqrt(pow(circleCenterX - circleOuterX, 2) +
//                                                            pow(circleCenterY - circleOuterY, 2))), RandColor(), g_customFillColor});
//                            }
//                        }
//                    }
//                    else // hasSetColor
//                    {
//                        /*shapeData.push_back(new Circle{ circleCenterX, circleCenterY, static_cast<int>(sqrt(pow(circleCenterX - circleOuterX, 2) +
//                                                        pow(circleCenterY - circleOuterY, 2))) ,g_customColor});*/
//                        if (!g_isUserSetFillColor)
//                        {
//                            // shapeData[g_nTotalShapes - 1].isFill = false;
//                            shapeData.push_back(new Circle{ circleCenterX, circleCenterY, static_cast<int>(sqrt(pow(circleCenterX - circleOuterX, 2) +
//                                                            pow(circleCenterY - circleOuterY, 2))), g_customColor});
//                        }
//                        else
//                        {
//                            // shapeData[g_nTotalShapes - 1].isFill = true;
//
//                            if (g_isFillColorRandom)
//                            {
//                                // shapeData[g_nTotalShapes - 1].fillColor = RandColor();
//                                shapeData.push_back(new Circle{ circleCenterX, circleCenterY, static_cast<int>(sqrt(pow(circleCenterX - circleOuterX, 2) +
//                                                            pow(circleCenterY - circleOuterY, 2))), g_customColor, RandColor()});
//                            }
//                            else
//                            {
//                                // shapeData[g_nTotalShapes - 1].fillColor = g_customFillColor;
//                                shapeData.push_back(new Circle{ circleCenterX, circleCenterY, static_cast<int>(sqrt(pow(circleCenterX - circleOuterX, 2) +
//                                                            pow(circleCenterY - circleOuterY, 2))), g_customColor, g_customFillColor});
//                            }
//                        }
//                    }
//
//                    //if (!g_isUserSetFillColor)
//                    //{
//                    //    // shapeData[g_nTotalShapes - 1].isFill = false;
//                    //}
//                    //else
//                    //{
//                    //    // shapeData[g_nTotalShapes - 1].isFill = true;
//
//                    //    if (g_isFillColorRandom)
//                    //    {
//                    //        // shapeData[g_nTotalShapes - 1].fillColor = RandColor();
//                    //        shapeData.push_back(new Circle{ circleCenterX, circleCenterY, static_cast<int>(sqrt(pow(circleCenterX - circleOuterX, 2) +
//                    //                                    pow(circleCenterY - circleOuterY, 2))) });
//                    //    }
//                    //    else
//                    //    {
//                    //        // shapeData[g_nTotalShapes - 1].fillColor = g_customFillColor;
//                    //        shapeData.push_back(new Circle{ circleCenterX, circleCenterY, static_cast<int>(sqrt(pow(circleCenterX - circleOuterX, 2) +
//                    //                                    pow(circleCenterY - circleOuterY, 2))) });
//                    //    }
//                    //}
//
//                    DrawAllPrevShapes(true);
//
//                    printf("	�ѻ����� (%d, %d) ΪԲ�ģ�(%d, %d) ΪԲ��һ�㣬�뾶Ϊ %d ��һ��Բ\n",
//                           circleCenterX,
//                           circleCenterY,
//                           circleOuterX,
//                           circleOuterY,
//                           (int)sqrt(pow(circleCenterX -
//                               circleOuterX, 2) +
//                                     pow(circleCenterY - circleOuterY, 2)));
//
//                    isInProgress = false;
//                    goto move;
//                    break;
//                }
//
//                break;
//
//            case mouse_msg_down:
//                switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
//                {
//                    case 1:
//                        return;
//                        break;
//
//                    case 2: // undo
//                        /*if (g_nTotalShapes > 0)
//                        {
//                            if (!isInProgress)
//                            {
//                                g_nTotalShapes--;
//                            }
//                        }*/
//
//                        if (shapeData.size() > 0)
//                        {
//                            if (!isInProgress)
//                            {
//                                delete shapeData[shapeData.size() - 1];
//                                shapeData.pop_back();
//                            }
//                        }
//
//                        // refresh the windows with menu contents
//                        cleardevice();
//                        InitUI(0);
//                        DrawMenuOutline(1, TOTAL_LN, 1);
//                        setcolor(0x000000);
//                        PrintMouseDrawingInsideMenu(0);
//                        setcolor(0x50AA50);
//                        xyprintf(678, 582, "��ǰ����: (%03d, %03d)", msg.x, msg.y);
//                        DrawAllPrevShapes(true);
//                        goto move;
//                        break;
//
//                    case 3: // choose foreground color
//                        ChooseColor_EGE(0);
//                        cleardevice();
//                        InitUI(0);
//                        DrawMenuOutline(1, TOTAL_LN, 1);
//                        DrawAllPrevShapes(true);
//                        goto move;
//                        break;
//
//                    case 4: // choose fill color
//                        ChooseColor_EGE(1);
//                        cleardevice();
//                        InitUI(0);
//                        DrawMenuOutline(1, TOTAL_LN, 1);
//                        DrawAllPrevShapes(true);
//                        goto move;
//                        break;
//
//                    default:
//                        break;
//                }
//
//                /* if the mouse click indicates the first dot,
//                store the position data of the center of the circle */
//                if (!isInProgress)
//                {
//                    circleCenterX = msg.x;
//                    circleCenterY = msg.y;
//
//                    // print a big dot
//                    putpixel(circleCenterX, circleCenterY, 0x707000);
//                    putpixel(circleCenterX + 1, circleCenterY, 0x707000);
//                    putpixel(circleCenterX - 1, circleCenterY, 0x707000);
//                    putpixel(circleCenterX, circleCenterY + 1, 0x707000);
//                    putpixel(circleCenterX, circleCenterY - 1, 0x707000);
//
//                    printf("	����ѡ��Բ�� (%d, %d)\n", circleCenterX, circleCenterY);
//
//                    isInProgress = true;
//                    break;
//                }
//
//
//                break; // not needed
//
//            case mouse_msg_move:
//move:
//                if (!isInProgress)
//                {
//                    InitUI(0);
//                    //DrawMenuOutline(1, TOTAL_LN, 1);
//                    //setcolor(0x000000);
//                    //PrintMouseDrawingInsideMenu(0);
//                    setcolor(0x50AA50);
//                    xyprintf(678, 582, "��ǰ����: (%03d, %03d)", msg.x, msg.y);
//
//                    switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
//                    {
//                        case 0:
//                            DrawMenuOutline(1, TOTAL_LN, 1);
//                            setcolor(0x000000);
//                            PrintMouseDrawingInsideMenu(0);
//                            break;
//
//                        case 1:
//                            setcolor(0x000000);
//                            PrintMouseDrawingInsideMenu(0);
//                            setcolor(0x5050AA);
//                            PrintMouseDrawingInsideMenu(1);
//                            break;
//
//                        case 2:
//                            setcolor(0x000000);
//                            PrintMouseDrawingInsideMenu(0);
//                            setcolor(0x5050AA);
//                            PrintMouseDrawingInsideMenu(2);
//                            break;
//
//                        case 3:
//                            setcolor(0x000000);
//                            PrintMouseDrawingInsideMenu(0);
//                            setcolor(0x5050AA);
//                            PrintMouseDrawingInsideMenu(3);
//                            break;
//
//                        case 4:
//                            setcolor(0x000000);
//                            PrintMouseDrawingInsideMenu(0);
//                            setcolor(0x5050AA);
//                            PrintMouseDrawingInsideMenu(4);
//                            break;
//
//                        default:
//                            break;
//                    }
//                }
//
//                if (isInProgress)
//                {
//                    // refresh continuously the screen to show live shape preview
//                    cleardevice();
//                    delay_fps(10000);
//                    InitUI(1);
//                    setcolor(0x50AA50);
//                    xyprintf(678, 582, "��ǰ����: (%03d, %03d)", msg.x, msg.y);
//
//                    putpixel(circleCenterX, circleCenterY, 0x707000);
//                    putpixel(circleCenterX + 1, circleCenterY, 0x707000);
//                    putpixel(circleCenterX - 1, circleCenterY, 0x707000);
//                    putpixel(circleCenterX, circleCenterY + 1, 0x707000);
//                    putpixel(circleCenterX, circleCenterY - 1, 0x707000);
//                    putpixel(msg.x, msg.y, 0x707000);
//                    putpixel(msg.x + 1, msg.y, 0x707000);
//                    putpixel(msg.x - 1, msg.y, 0x707000);
//                    putpixel(msg.x, msg.y + 1, 0x707000);
//                    putpixel(msg.x, msg.y - 1, 0x707000);
//                    DrawAllPrevShapes(true);
//                    setcolor(0x909090);
//
//                    circle(circleCenterX, circleCenterY,
//                           (int)sqrt(pow((double)circleCenterX - (double)msg.x,
//                                         2) + pow((double)circleCenterY - (double)msg.y, 2)));
//                }
//
//                break;
//
//            default:
//                break;
//        }
//    }
//}

//void mouse_DrawLine(void)
//{
//    const short int TOTAL_LN = 4;
//    bool            isInProgress = false;
//    int             lineStartPositionX;
//    int             lineStartPositionY;
//    int             lineEndPositionX;
//    int             lineEndPositionY;
//
//    printf("�ѽ�����껭��ģʽ\n");
//    printf("����ָ�ϣ�\n");
//    printf("������ȵ�ѡ����ٵ�ѡ�յ㼴����������\n");
//    //setcolor(0x909090);
//    DrawAllPrevShapes(true);
//    DrawMenuOutline(1, TOTAL_LN, 1);
//    setcolor(0x000000);
//    PrintMouseDrawingInsideMenu(0);
//    mouse_msg msg;
//
//    for (; is_run();
//         delay_fps(
//             REFRESH_RATE)) // Using "for" statement to draw multiple circles at a time and refresh the screen
//    {
//        msg = getmouse(); // Get mouse clicks and position
//
//        switch (msg.msg)
//        {
//            case mouse_msg_up:
//                if (isInProgress)
//                {
//                    if (msg.x == lineStartPositionX && msg.y == lineStartPositionY)
//                    {
//                        continue;
//                    }
//
//                    lineEndPositionX = msg.x;
//                    lineEndPositionY = msg.y;
//
//                    printf("	����ѡ���յ� (%d, %d)\n", lineEndPositionX, lineEndPositionY);
//
//                    // store coordinate data
//                    g_nTotalShapes++;
//                    shapeData[g_nTotalShapes - 1].shapeType = SHAPE::shape_line;
//                    shapeData[g_nTotalShapes - 1].coords[0].x = lineStartPositionX;
//                    shapeData[g_nTotalShapes - 1].coords[0].y = lineStartPositionY;
//                    shapeData[g_nTotalShapes - 1].coords[1].x = lineEndPositionX;
//                    shapeData[g_nTotalShapes - 1].coords[1].y = lineEndPositionY;
//
//                    // store current color settings
//                    if (!g_isUserSetColor)
//                    {
//                        shapeData[g_nTotalShapes - 1].foregroundColor = RandColor();
//                    }
//                    else
//                    {
//                        shapeData[g_nTotalShapes - 1].foregroundColor = g_customColor;
//                    }
//
//                    DrawAllPrevShapes(true);
//
//                    printf("	�ѻ����� (%d, %d) �� (%d, %d) ��һ��ֱ��\n",
//                           lineStartPositionX,
//                           lineStartPositionY,
//                           lineEndPositionX,
//                           lineEndPositionY);
//
//                    isInProgress = false; // reset the drawing process
//                    goto move;
//                    break;
//                }
//
//                break;
//
//            case mouse_msg_down:
//                switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
//                {
//                    case 1:
//                        return;
//                        break;
//
//                    case 2: // undo
//                        if (g_nTotalShapes > 0)
//                        {
//                            if (!isInProgress)
//                            {
//                                g_nTotalShapes--;
//                            }
//                        }
//
//                        // refresh the windows with menu contents
//                        cleardevice();
//                        InitUI(0);
//                        DrawMenuOutline(1, TOTAL_LN, 1);
//                        setcolor(0x000000);
//                        PrintMouseDrawingInsideMenu(0);
//                        setcolor(0x50AA50);
//                        xyprintf(678, 582, "��ǰ����: (%03d, %03d)", msg.x, msg.y);
//                        DrawAllPrevShapes(true);
//                        goto move;
//                        break;
//
//                    case 3: // choose foreground color
//                        ChooseColor_EGE(0);
//                        cleardevice();
//                        InitUI(0);
//                        DrawMenuOutline(1, TOTAL_LN, 1);
//                        DrawAllPrevShapes(true);
//                        goto move;
//                        break;
//
//                    case 4: // choose fill color
//                        ChooseColor_EGE(1);
//                        cleardevice();
//                        InitUI(0);
//                        DrawMenuOutline(1, TOTAL_LN, 1);
//                        DrawAllPrevShapes(true);
//                        goto move;
//                        break;
//
//                    default:
//                        break;
//                }
//
//                /* if the mouse click indicates the first dot,
//                store the position data of the starting point */
//                if (!isInProgress)
//                {
//                    lineStartPositionX = msg.x;
//                    lineStartPositionY = msg.y;
//
//                    putpixel(lineStartPositionX, lineStartPositionY, 0x707000);
//                    putpixel(lineStartPositionX + 1, lineStartPositionY, 0x707000);
//                    putpixel(lineStartPositionX - 1, lineStartPositionY, 0x707000);
//                    putpixel(lineStartPositionX, lineStartPositionY + 1, 0x707000);
//                    putpixel(lineStartPositionX, lineStartPositionY - 1, 0x707000);
//
//                    printf("	����ѡ����� (%d, %d)\n", lineStartPositionX, lineStartPositionY);
//
//                    isInProgress = true; // updete the drawing process
//
//                    break;
//                }
//
//                break; // not needed
//
//            case mouse_msg_move:
//move:
//                if (!isInProgress)
//                {
//                    InitUI(0);
//                    //DrawMenuOutline(1, TOTAL_LN, 1);
//                    //setcolor(0x000000);
//                    //PrintMouseDrawingInsideMenu(0);
//                    setcolor(0x50AA50);
//                    xyprintf(678, 582, "��ǰ����: (%03d, %03d)", msg.x, msg.y);
//
//                    switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
//                    {
//                        case 0:
//                            DrawMenuOutline(1, TOTAL_LN, 1);
//                            setcolor(0x000000);
//                            PrintMouseDrawingInsideMenu(0);
//                            break;
//
//                        case 1:
//                            setcolor(0x000000);
//                            PrintMouseDrawingInsideMenu(0);
//                            setcolor(0x5050AA);
//                            PrintMouseDrawingInsideMenu(1);
//                            break;
//
//                        case 2:
//                            setcolor(0x000000);
//                            PrintMouseDrawingInsideMenu(0);
//                            setcolor(0x5050AA);
//                            PrintMouseDrawingInsideMenu(2);
//                            break;
//
//                        case 3:
//                            setcolor(0x000000);
//                            PrintMouseDrawingInsideMenu(0);
//                            setcolor(0x5050AA);
//                            PrintMouseDrawingInsideMenu(3);
//                            break;
//
//                        case 4:
//                            setcolor(0x000000);
//                            PrintMouseDrawingInsideMenu(0);
//                            setcolor(0x5050AA);
//                            PrintMouseDrawingInsideMenu(4);
//                            break;
//
//                        default:
//                            break;
//                    }
//                }
//
//                if (isInProgress)
//                {
//                    // refresh continuously the screen to show live shape preview
//                    cleardevice();
//                    delay_fps(10000);
//                    InitUI(1);
//                    setcolor(0x50AA50);
//                    xyprintf(678, 582, "��ǰ����: (%03d, %03d)", msg.x, msg.y);
//
//                    putpixel(lineStartPositionX, lineStartPositionY, 0x707000);
//                    putpixel(lineStartPositionX + 1, lineStartPositionY, 0x707000);
//                    putpixel(lineStartPositionX - 1, lineStartPositionY, 0x707000);
//                    putpixel(lineStartPositionX, lineStartPositionY + 1, 0x707000);
//                    putpixel(lineStartPositionX, lineStartPositionY - 1, 0x707000);
//                    putpixel(msg.x, msg.y, 0x707000);
//                    putpixel(msg.x + 1, msg.y, 0x707000);
//                    putpixel(msg.x - 1, msg.y, 0x707000);
//                    putpixel(msg.x, msg.y + 1, 0x707000);
//                    putpixel(msg.x, msg.y - 1, 0x707000);
//
//                    DrawAllPrevShapes(true);
//                    setcolor(0x909090);
//
//                    line(lineStartPositionX, lineStartPositionY, msg.x, msg.y);
//                }
//
//                break;
//
//            default:
//                break;
//        }
//    }
//}

void mouse_DrawRectangle(void)
{
//    const short int TOTAL_LN = 4; // total items in the menu bar
//    bool            isInProgress = false;
//    int             rectUpLCornerX;
//    int             rectUpLCornerY;
//    int             rectLowRCornerX;
//    int             rectLowRCornerY;
//
//    printf("�ѽ�����껭����ģʽ\n");
//    printf("����ָ�ϣ�\n");
//    printf("������ѡ�����Խǵ㼴������������\n");
//    //setcolor(0x909090);
//    DrawAllPrevShapes(true);
//    DrawMenuOutline(1, TOTAL_LN, 1);
//    setcolor(0x000000);
//    PrintMouseDrawingInsideMenu(0);
//    mouse_msg msg;
//
//    for (; is_run();
//         delay_fps(
//             REFRESH_RATE)) // Using "for" statement to draw multiple circles at a time and refresh the screen
//    {
//        msg = getmouse();
//
//        switch (msg.msg)
//        {
//            case mouse_msg_up:
//
//                /* if the mouse click indicates the second dot,
//                store the position data of the lower rignt corner */
//                if (isInProgress)
//                {
//                    if (msg.x == rectUpLCornerX || msg.y == rectUpLCornerY)
//                    {
//                        continue;
//                    }
//
//                    rectLowRCornerX = msg.x;
//                    rectLowRCornerY = msg.y;
//
//                    printf("	����ѡ�е� (%d, %d)\n", rectLowRCornerX, rectLowRCornerY);
//
//                    // store coordinate data
//                    g_nTotalShapes++;
//                    shapeData[g_nTotalShapes - 1].shapeType = SHAPE::shape_rectangle;
//                    shapeData[g_nTotalShapes - 1].coords[0].x = rectUpLCornerX;
//                    shapeData[g_nTotalShapes - 1].coords[0].y = rectUpLCornerY;
//                    shapeData[g_nTotalShapes - 1].coords[1].x = rectLowRCornerX;
//                    shapeData[g_nTotalShapes - 1].coords[1].y = rectLowRCornerY;
//
//                    // store current color settings
//                    if (!g_isUserSetColor)
//                    {
//                        shapeData[g_nTotalShapes - 1].foregroundColor = RandColor();
//                    }
//                    else
//                    {
//                        shapeData[g_nTotalShapes - 1].foregroundColor = g_customColor;
//                    } // end of if
//
//                    if (!g_isUserSetFillColor)
//                    {
//                        shapeData[g_nTotalShapes - 1].isFill = false;
//                    }
//                    else
//                    {
//                        shapeData[g_nTotalShapes - 1].isFill = true;
//
//                        if (g_isFillColorRandom)
//                        {
//                            shapeData[g_nTotalShapes - 1].fillColor = RandColor();
//                        }
//                        else
//                        {
//                            shapeData[g_nTotalShapes - 1].fillColor = g_customFillColor;
//                        } // end of if
//                    } // end of if
//
//                    DrawAllPrevShapes(true);
//
//                    printf("	�ѻ����� (%d, %d) �� (%d, %d) Ϊ�Խǵ��һ������\n",
//                           rectUpLCornerX,
//                           rectUpLCornerY,
//                           rectLowRCornerX,
//                           rectLowRCornerY);
//
//                    isInProgress = false;
//                    goto move;
//                    break;
//                }
//
//                break;
//
//            case mouse_msg_down:
//                switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
//                {
//                    case 1:
//                        return;
//                        break;
//
//                    case 2: // undo
//                        if (g_nTotalShapes > 0)
//                        {
//                            if (!isInProgress)
//                            {
//                                g_nTotalShapes--;
//                            }
//                        }
//
//                        // refresh the windows with menu contents
//                        cleardevice();
//                        InitUI(0);
//                        DrawMenuOutline(1, TOTAL_LN, 1);
//                        setcolor(0x000000);
//                        PrintMouseDrawingInsideMenu(0);
//                        setcolor(0x50AA50);
//                        xyprintf(678, 582, "��ǰ����: (%03d, %03d)", msg.x, msg.y);
//                        DrawAllPrevShapes(true);
//                        goto move;
//                        break;
//
//                    case 3: // choose foreground color
//                        ChooseColor_EGE(0);
//                        cleardevice();
//                        InitUI(0);
//                        DrawMenuOutline(1, TOTAL_LN, 1);
//                        DrawAllPrevShapes(true);
//                        goto move;
//                        break;
//
//                    case 4: // choose fill color
//                        ChooseColor_EGE(1);
//                        cleardevice();
//                        InitUI(0);
//                        DrawMenuOutline(1, TOTAL_LN, 1);
//                        DrawAllPrevShapes(true);
//                        goto move;
//                        break;
//
//                    default:
//                        break;
//                }
//
//                /* if the mouse click indicates the first dot,
//                store the position data of the upper left corner */
//                if (!isInProgress)
//                {
//                    rectUpLCornerX = msg.x;
//                    rectUpLCornerY = msg.y;
//
//                    // print a big dot
//                    putpixel(rectUpLCornerX, rectUpLCornerY, 0x707000);
//                    putpixel(rectUpLCornerX + 1, rectUpLCornerY, 0x707000);
//                    putpixel(rectUpLCornerX - 1, rectUpLCornerY, 0x707000);
//                    putpixel(rectUpLCornerX, rectUpLCornerY + 1, 0x707000);
//                    putpixel(rectUpLCornerX, rectUpLCornerY - 1, 0x707000);
//
//                    printf("	����ѡ�е� (%d, %d)\n", rectUpLCornerX, rectUpLCornerY);
//
//                    isInProgress = true;
//                    break;
//                }
//
//
//                break; // not needed
//
//            case mouse_msg_move:
//move:
//                if (!isInProgress)
//                {
//                    InitUI(0);
//                    //DrawMenuOutline(1, TOTAL_LN, 1);
//                    //setcolor(0x000000);
//                    //PrintMouseDrawingInsideMenu(0);
//                    setcolor(0x50AA50);
//                    xyprintf(678, 582, "��ǰ����: (%03d, %03d)", msg.x, msg.y);
//
//                    switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
//                    {
//                        case 0:
//                            DrawMenuOutline(1, TOTAL_LN, 1);
//                            setcolor(0x000000);
//                            PrintMouseDrawingInsideMenu(0);
//                            break;
//
//                        case 1:
//                            setcolor(0x000000);
//                            PrintMouseDrawingInsideMenu(0);
//                            setcolor(0x5050AA);
//                            PrintMouseDrawingInsideMenu(1);
//                            break;
//
//                        case 2:
//                            setcolor(0x000000);
//                            PrintMouseDrawingInsideMenu(0);
//                            setcolor(0x5050AA);
//                            PrintMouseDrawingInsideMenu(2);
//                            break;
//
//                        case 3:
//                            setcolor(0x000000);
//                            PrintMouseDrawingInsideMenu(0);
//                            setcolor(0x5050AA);
//                            PrintMouseDrawingInsideMenu(3);
//                            break;
//
//                        case 4:
//                            setcolor(0x000000);
//                            PrintMouseDrawingInsideMenu(0);
//                            setcolor(0x5050AA);
//                            PrintMouseDrawingInsideMenu(4);
//                            break;
//
//                        default:
//                            break;
//                    }
//                }
//
//                if (isInProgress)
//                {
//                    // refresh continuously the screen to show live shape preview
//                    cleardevice();
//                    delay_fps(10000);
//                    InitUI(1);
//                    setcolor(0x50AA50);
//                    xyprintf(678, 582, "��ǰ����: (%03d, %03d)", msg.x, msg.y);
//
//                    putpixel(rectUpLCornerX, rectUpLCornerY, 0x707000);
//                    putpixel(rectUpLCornerX + 1, rectUpLCornerY, 0x707000);
//                    putpixel(rectUpLCornerX - 1, rectUpLCornerY, 0x707000);
//                    putpixel(rectUpLCornerX, rectUpLCornerY + 1, 0x707000);
//                    putpixel(rectUpLCornerX, rectUpLCornerY - 1, 0x707000);
//                    putpixel(msg.x, msg.y, 0x707000);
//                    putpixel(msg.x + 1, msg.y, 0x707000);
//                    putpixel(msg.x - 1, msg.y, 0x707000);
//                    putpixel(msg.x, msg.y + 1, 0x707000);
//                    putpixel(msg.x, msg.y - 1, 0x707000);
//                    DrawAllPrevShapes(true);
//                    setcolor(0x909090);
//
//                    rectangle(rectUpLCornerX, rectUpLCornerY, msg.x, msg.y);
//                }
//
//                break;
//
//            default:
//                break;
//        }
//    }
}

void mouse_DrawPoly(void)
{
//    const short int TOTAL_LN = 4; // total items in the menu bar
//    bool            isInProgress = false;
//    WORD            polyCoords[50];
//    WORD            sides = 0;
//
//    printf("�ѽ�����껭�����ģʽ\n");
//    printf("����ָ�ϣ�\n");
//    printf("������ѡ���㣬���һ���㿿����ʼ��������\n");
//    DrawAllPrevShapes(true);
//    DrawMenuOutline(1, TOTAL_LN, 1);
//    setcolor(0x000000);
//    PrintMouseDrawingInsideMenu(0);
//    mouse_msg msg;
//
//    for (; is_run();
//         delay_fps(
//             REFRESH_RATE)) // Using "for" statement to draw multiple circles at a time and refresh the screen
//    {
//        msg = getmouse();
//
//        switch (msg.msg)
//        {
//            case mouse_msg_down:
//                switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
//                {
//                    case 1:
//                        return;
//                        break;
//
//                    case 2: // undo
//                        if (g_nTotalShapes > 0)
//                        {
//                            if (!isInProgress)
//                            {
//                                g_nTotalShapes--;
//                            }
//                        }
//
//                        // refresh the windows with menu contents
//                        cleardevice();
//                        InitUI(0);
//                        DrawMenuOutline(1, TOTAL_LN, 1);
//                        setcolor(0x000000);
//                        PrintMouseDrawingInsideMenu(0);
//                        setcolor(0x50AA50);
//                        xyprintf(678, 582, "��ǰ����: (%03d, %03d)", msg.x, msg.y);
//                        DrawAllPrevShapes(true);
//                        goto move;
//                        break;
//
//                    case 3: // choose foreground color
//                        ChooseColor_EGE(0);
//                        cleardevice();
//                        InitUI(0);
//                        DrawMenuOutline(1, TOTAL_LN, 1);
//                        DrawAllPrevShapes(true);
//                        goto move;
//                        break;
//
//                    case 4: // choose fill color
//                        ChooseColor_EGE(1);
//                        cleardevice();
//                        InitUI(0);
//                        DrawMenuOutline(1, TOTAL_LN, 1);
//                        DrawAllPrevShapes(true);
//                        goto move;
//                        break;
//
//                    default:
//                        break;
//                }
//
//                /* if the mouse click indicates the first dot,
//                store the position data of it */
//                if (!isInProgress)
//                {
//                    // store coordinate data
//                    polyCoords[0] = msg.x;
//                    polyCoords[1] = msg.y;
//                    sides = 0;
//                    printf("	����ѡ�е� (%d, %d)\n", polyCoords[0], polyCoords[1]);
//
//                    isInProgress = true;
//                    break;
//                }
//
//                /* if the mouse click indicates another dot,
//                store the position data of it */
//                if (isInProgress)
//                {
//                    // store coordinate data
//                    sides++;
//                    polyCoords[2 * sides] = msg.x;
//                    polyCoords[2 * sides + 1] = msg.y;
//
//                    printf("	����ѡ�е� (%d, %d)\n", polyCoords[2 * sides],
//                           polyCoords[2 * sides + 1]);
//
//                    // when the distance between
//                    // the last dot and
//                    // the first dot
//                    // is smaller than 8 px
//                    // then does the following things
//                    if (sqrt(pow(polyCoords[0] - polyCoords[2 * sides], 2) +
//                             pow(polyCoords[1] - polyCoords[2 * sides + 1], 2)) <= 8
//                        && sides >= 3)
//                    {
//                        // closes the polygon
//                        polyCoords[2 * sides] = polyCoords[0];
//                        polyCoords[2 * sides + 1] = polyCoords[1];
//                        g_nTotalShapes++;
//                        shapeData[g_nTotalShapes - 1].shapeType = SHAPE::shape_polygon;
//                        shapeData[g_nTotalShapes - 1].extraData[0] = sides; // record the sides
//
//                        // prepare the coordinate data for storage
//                        for (int j = 0; j < shapeData[g_nTotalShapes - 1].extraData[0]; j++)
//                        {
//                            shapeData[g_nTotalShapes - 1].coords[j].x = polyCoords[2 * j];
//                            shapeData[g_nTotalShapes - 1].coords[j].y = polyCoords[2 * j + 1];
//                        }
//
//                        // store current color settings
//                        if (!g_isUserSetColor)
//                        {
//                            shapeData[g_nTotalShapes - 1].foregroundColor = RandColor();
//                        }
//                        else
//                        {
//                            shapeData[g_nTotalShapes - 1].foregroundColor = g_customColor;
//                        }
//
//                        if (!g_isUserSetFillColor)
//                        {
//                            shapeData[g_nTotalShapes - 1].isFill = false;
//                        }
//                        else
//                        {
//                            shapeData[g_nTotalShapes - 1].isFill = true;
//
//                            if (g_isFillColorRandom)
//                            {
//                                shapeData[g_nTotalShapes - 1].fillColor = RandColor();
//                            }
//                            else
//                            {
//                                shapeData[g_nTotalShapes - 1].fillColor = g_customFillColor;
//                            }
//                        }
//
//                        DrawAllPrevShapes(true);
//                        isInProgress = false;
//                        printf("	�����%d���εĻ�ͼ\n", sides);
//                        goto move;
//                    }
//
//                    if (sides >= 23)
//                    {
//                        MessageBox(NULL,
//                                   TEXT("�������࣬�����������ڻ滭�Ķ���η��"),
//                                   TEXT("���������"),
//                                   MB_OK | MB_SYSTEMMODAL | MB_ICONEXCLAMATION);
//                    }
//
//                    break;
//                }
//
//                break; // not needed
//
//            case mouse_msg_move:
//move:
//                if (!isInProgress)
//                {
//                    InitUI(0);
//                    //DrawMenuOutline(1, TOTAL_LN, 1);
//                    //setcolor(0x000000);
//                    //PrintMouseDrawingInsideMenu(0);
//                    setcolor(0x50AA50);
//                    xyprintf(678, 582, "��ǰ����: (%03d, %03d)", msg.x, msg.y);
//
//                    switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
//                    {
//                        case 0:
//                            DrawMenuOutline(1, TOTAL_LN, 1);
//                            setcolor(0x000000);
//                            PrintMouseDrawingInsideMenu(0);
//                            break;
//
//                        case 1:
//                            setcolor(0x000000);
//                            PrintMouseDrawingInsideMenu(0);
//                            setcolor(0x5050AA);
//                            PrintMouseDrawingInsideMenu(1);
//                            break;
//
//                        case 2:
//                            setcolor(0x000000);
//                            PrintMouseDrawingInsideMenu(0);
//                            setcolor(0x5050AA);
//                            PrintMouseDrawingInsideMenu(2);
//                            break;
//
//                        case 3:
//                            setcolor(0x000000);
//                            PrintMouseDrawingInsideMenu(0);
//                            setcolor(0x5050AA);
//                            PrintMouseDrawingInsideMenu(3);
//                            break;
//
//                        case 4:
//                            setcolor(0x000000);
//                            PrintMouseDrawingInsideMenu(0);
//                            setcolor(0x5050AA);
//                            PrintMouseDrawingInsideMenu(4);
//                            break;
//
//                        default:
//                            break;
//                    }
//                }
//
//                if (isInProgress)
//                {
//                    // refresh continuously the screen to show live shape preview
//                    cleardevice();
//                    delay_fps(10000);
//                    InitUI(1);
//                    setcolor(0x50AA50);
//                    xyprintf(678, 582, "��ǰ����: (%03d, %03d)", msg.x, msg.y);
//
//
//                    DrawAllPrevShapes(true);
//                    setcolor(0x909090);
//
//                    // draws a line which is the line connecting
//                    // the last dot of the polygon and the mouse pointer
//                    if (sides >= 1)
//                    {
//                        for (int i = 0; i < sides * 2; i += 2)
//                        {
//                            line(polyCoords[i], polyCoords[i + 1], polyCoords[i + 2], polyCoords[i + 3]);
//                        }
//                    }
//
//                    // closes the polgon automatically
//                    // when the distance between
//                    // the mouse pointer and the first dot of the polygon
//                    // is smaller than 8px
//                    if (sqrt(pow((double)polyCoords[0] - (double)msg.x, 2) +
//                             pow((double)polyCoords[1] - (double)msg.y, 2)) <= 8
//                        && sides >= 2)
//                    {
//                        line(polyCoords[sides * 2], polyCoords[sides * 2 + 1], polyCoords[0],
//                             polyCoords[1]);
//                    }
//                    else
//                    {
//                        line(polyCoords[sides * 2], polyCoords[sides * 2 + 1], msg.x, msg.y);
//                    }
//
//                }
//
//                break;
//
//            default:
//                break;
//        }
//    }
}