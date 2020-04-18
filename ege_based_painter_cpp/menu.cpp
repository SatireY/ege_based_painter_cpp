#include "menu.h"

void Menu(bool readResult)
{
    const short int TOTAL_LN = 7;

    cleardevice();
    InitUI(0);
    printf("���ڲ˵����������������\n");
    DrawMenuOutline(1, TOTAL_LN, 1);
    setcolor(0x000000);
    PrintMenu(0);
    mouse_msg msg;

    for (; ; delay_fps(REFRESH_RATE))
    {
        msg = getmouse();

        switch (msg.msg)
        {
            case mouse_msg_down:
                switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
                {
                    case 1: // �˳�
                        if (g_isFileEdited)
                        {
                            int selection = MessageBox(NULL,
                                                       TEXT("��ǰ�и���δ���棬�Ƿ�ȷ��Ҫ�˳���"),
                                                       TEXT("��ʾ"),
                                                       MB_OKCANCEL | MB_SYSTEMMODAL | MB_ICONEXCLAMATION);

                            if (selection == IDOK)
                            {
                                return;
                            }
                            else if (selection == IDCANCEL)
                            {
                                break;
                            }
                        }

                        return;
                        break;

                    case 2: // ���Ϊ
                        WriteToFile();
                        goto move;
                        break;

                    case 3: // �������ͼ��
                        ClearData();
                        cleardevice();
                        InitUI(0);
                        delay_fps(REFRESH_RATE);
                        MessageBox(NULL,
                                   TEXT("���������ͼ��"),
                                   TEXT("��ʾ"),
                                   MB_OK | MB_SYSTEMMODAL | MB_ICONINFORMATION);
                        
                        goto move;
                        break;

                    case 4: // ����
                        cleardevice();
                        InitUI(0);
                        mouse_DrawLine();
                        cleardevice();
                        InitUI(0);
                        goto move;
                        break;

                    case 5: // ��Բ
                        cleardevice();
                        InitUI(0);
                        mouse_DrawCircle();
                        cleardevice();
                        InitUI(0);
                        goto move;
                        break;

                    case 6: // ������
                        cleardevice();
                        InitUI(0);
                        mouse_DrawRectangle();
                        cleardevice();
                        InitUI(0);
                        goto move;
                        break;

                    case 7: // �������
                        cleardevice();
                        InitUI(0);
                        mouse_DrawPoly();
                        cleardevice();
                        InitUI(0);
                        goto move;
                        break;

                    //case 8: // �������
                    //    cleardevice();
                    //    InitUI(0);
                    //    coord_DrawPoly();
                    //    cleardevice();
                    //    InitUI(0);
                    //    goto move;
                    //    break;

                    default:
                        break;
                }

                break; // not needed

            case mouse_msg_move:
move:
                setcolor(0x50AA50);
                xyprintf(678, 582, "��ǰ����: (%03d, %03d)", msg.x, msg.y);
                DrawAllPrevShapes(false);
                DrawMenuOutline(1, TOTAL_LN, 1);

                switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
                {
                    case 0:
                        DrawMenuOutline(1, TOTAL_LN, 1);
                        setcolor(0x000000);
                        PrintMenu(0);
                        break;

                    case 1:
                        setcolor(0x000000);
                        PrintMenu(0);
                        setcolor(0x5050AA);
                        PrintMenu(1);
                        break;

                    case 2:
                        setcolor(0x000000);
                        PrintMenu(0);
                        setcolor(0x5050AA);
                        PrintMenu(2);
                        break;

                    case 3:
                        setcolor(0x000000);
                        PrintMenu(0);
                        setcolor(0x5050AA);
                        PrintMenu(3);
                        break;

                    case 4:
                        setcolor(0x000000);
                        PrintMenu(0);
                        setcolor(0x5050AA);
                        PrintMenu(4);
                        break;

                    case 5:
                        setcolor(0x000000);
                        PrintMenu(0);
                        setcolor(0x5050AA);
                        PrintMenu(5);
                        break;

                    case 6:
                        setcolor(0x000000);
                        PrintMenu(0);
                        setcolor(0x5050AA);
                        PrintMenu(6);
                        break;

                    case 7:
                        setcolor(0x000000);
                        PrintMenu(0);
                        setcolor(0x5050AA);
                        PrintMenu(7);
                        break;

                    /*case 8:
                        setcolor(0x000000);
                        PrintMenu(0);
                        setcolor(0x5050AA);
                        PrintMenu(8);
                        break;*/

                    default:
                        break;
                }

                break;

            default:
                break;
        }
    }
}


void PrintMenu(short int lnToPrint)
{
    switch (lnToPrint)
    {
        case 0:
            setfont(40, 0, "Segoe UI");
            xyprintf(graphicsEnvironment.GetMenuWidth() + 170, 250, "��ӭ���� CC ����");
            setfont(graphicsEnvironment.GetFontSize(), 0, graphicsEnvironment.GetFont());
            /*xyprintf(graphicsEnvironment.GetMenuWidth() + 118, 300,
                     "ע����������ҵ�������뿴���С�(��ҵ)����ѡ��");*/
            xyprintf(8, 8 + 0 * graphicsEnvironment.GetMenuHeight(), "�˳�");
            xyprintf(8, 8 + 1 * graphicsEnvironment.GetMenuHeight(), "���Ϊ");
            xyprintf(8, 8 + 2 * graphicsEnvironment.GetMenuHeight(), "�������ͼ��");
            xyprintf(8, 8 + 3 * graphicsEnvironment.GetMenuHeight(), "����껭��");
            xyprintf(8, 8 + 4 * graphicsEnvironment.GetMenuHeight(), "����껭Բ");
            xyprintf(8, 8 + 5 * graphicsEnvironment.GetMenuHeight(), "����껭����");
            xyprintf(8, 8 + 6 * graphicsEnvironment.GetMenuHeight(), "����껭�����");
            //xyprintf(8, 8 + 7 * graphicsEnvironment.GetMenuHeight(), "!!!����ҵ��������ƶ����");
            break;

        case 1:
            xyprintf(8, 8 + 0 * graphicsEnvironment.GetMenuHeight(), "�˳�");
            break;

        case 2:
            xyprintf(8, 8 + 1 * graphicsEnvironment.GetMenuHeight(), "���Ϊ");
            break;

        case 3:
            xyprintf(8, 8 + 2 * graphicsEnvironment.GetMenuHeight(), "�������ͼ��");
            break;

        case 4:
            xyprintf(8, 8 + 3 * graphicsEnvironment.GetMenuHeight(), "����껭��");
            break;

        case 5:
            xyprintf(8, 8 + 4 * graphicsEnvironment.GetMenuHeight(), "����껭Բ");
            break;

        case 6:
            xyprintf(8, 8 + 5 * graphicsEnvironment.GetMenuHeight(), "����껭����");
            break;

        case 7:
            xyprintf(8, 8 + 6 * graphicsEnvironment.GetMenuHeight(), "����껭�����");
            break;

        /*case 8:
            xyprintf(8, 8 + 7 * graphicsEnvironment.GetMenuHeight(), "!!!����ҵ��������ƶ����");
            break;*/

        default:
            break;
    }
}

