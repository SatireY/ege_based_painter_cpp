#include "read_file.h"

bool ReadFromFile(void)
{
    FILE           *fp;
    const short int TOTAL_LN                = 2;
    short int       readResult;
    bool            isReadyToExit           = false;
    OPENFILENAME    ofn                     = { 0 };
    TCHAR           strFilename[MAX_PATH]   = { 0 };
    char            c_strFilename[MAX_PATH] = { 0 };
    char            readFileValidityCheckSuffix;
begin:
    cleardevice();
    InitUI(0);
    printf("���ڲ˵����������������\n");

    mouse_msg msg;

    DrawMenuOutline(1, TOTAL_LN, 1);
    setcolor(0x000000);
    setfont(graphicsEnvironment.GetFontSize(), 0, graphicsEnvironment.GetFont());

    xyprintf(8, 8 + 0 * graphicsEnvironment.GetMenuHeight(), "��ȡ��ͼ�浵");
    xyprintf(8, 8 + 1 * graphicsEnvironment.GetMenuHeight(), "����ȡ��ͼ�浵");
    xyprintf(graphicsEnvironment.GetMenuWidth() + 15, 8 + 2 * graphicsEnvironment.GetMenuHeight(), "��������˵�");

    for (; !isReadyToExit; delay_fps(REFRESH_RATE))
    {
        msg = getmouse();

        switch (msg.msg)
        {
            case mouse_msg_down:
                switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
                {
                    case 1:
case1:
                        ofn.lStructSize     = sizeof(OPENFILENAME);
                        ofn.hwndOwner       = NULL;
                        ofn.lpstrFilter     = TEXT("Shape Data (*.draw)\0*.draw\0\0");
                        ofn.nFilterIndex    = 1;
                        ofn.lpstrFile       = strFilename;
                        ofn.nMaxFile        = sizeof(strFilename);
                        ofn.lpstrInitialDir = NULL;
                        ofn.lpstrTitle      = TEXT("��ѡ��һ���ļ�");
                        ofn.Flags           = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY;

                        if (!(GetOpenFileName(&ofn)))
                        {
                            goto begin;
                        }

                        TCHARToChar(strFilename,
                                    c_strFilename); // convert wide character strings to standard strings
                        // to avoid certain errors

                        fp = fopen(c_strFilename, "rb");
                        rewind(fp);

                        if (fp == NULL)
                        {
READINGFAILED:
                            cleardevice();
                            InitUI(0);
                            int selection = MessageBox(NULL,
                                                       TEXT("�����ļ��Ƿ���ȷ"),
                                                       TEXT("��ȡ����"),
                                                       MB_ABORTRETRYIGNORE | MB_SYSTEMMODAL | MB_ICONEXCLAMATION);

                            switch (selection)
                            {
                                case IDRETRY:
                                    goto case1;
                                    break;

                                case IDABORT:
                                    isReadyToExit = false;
                                    break;

                                case IDIGNORE:
                                    isReadyToExit = true;
                                    readResult = 0;
                                    break;

                                default:
                                    break;
                            }
                        }
                        else
                        {
                            cleardevice();
                            InitUI(0);

                            if ((fread(shapeData,
                                       sizeof(shapeData[0]),
                                       sizeof(shapeData) / sizeof(shapeData[0]),
                                       fp) ==
                                 sizeof(shapeData) / sizeof(shapeData[0]))
                                && (fread(&g_nTotalShapes,
                                          sizeof(WORD),
                                          1,
                                          fp) == 1)
                                && (fread(&readFileValidityCheckSuffix,
                                          sizeof(readFileValidityCheckSuffix),
                                          1,
                                          fp) == 1)) // check the validity of the data written
                            {
                                if (readFileValidityCheckSuffix
                                    == fileValidityCheckSuffix)
                                {
                                    MessageBox(NULL,
                                               TEXT("��ȡ�ɹ�"),
                                               TEXT("��ʾ"),
                                               MB_OK | MB_SYSTEMMODAL | MB_ICONINFORMATION);

                                    if (fclose(fp) == EOF)
                                    {
                                        int selection2 = MessageBox(NULL,
                                                                    TEXT("�޷��رձ��򿪵��ļ���"),
                                                                    TEXT(""),
                                                                    MB_RETRYCANCEL | MB_SYSTEMMODAL | MB_ICONEXCLAMATION);

                                        switch (selection2)
                                        {
                                            case IDRETRY:
                                                goto case1;
                                                break;

                                            case IDCANCEL:
                                                isReadyToExit = true;
                                                readResult = 0;
                                                break;

                                            default:
                                                break;
                                        }
                                    }
                                    else
                                    {
                                        fclose(fp);
                                        readResult = 1;
                                        isReadyToExit = true;
                                    }
                                }
                                else
                                {
                                    goto READINGFAILED;
                                }
                            }
                            else
                            {
                                goto READINGFAILED;
                            }
                        }

                        break;

                    case 2: // do not read file
                        readResult = 0;
                        isReadyToExit = true;
                        break;

                    default:
                        break;
                }

                break; // not needed

            case mouse_msg_move:
                setcolor(0x50AA50);
                xyprintf(678, 582, "��ǰ����: (%03d, %03d)", msg.x, msg.y);
                DrawMenuOutline(1, TOTAL_LN, 1);

                switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
                {
                    case 0:
                        DrawMenuOutline(1, TOTAL_LN, 1);
                        setcolor(0x000000);
                        xyprintf(8, 8 + 0 * graphicsEnvironment.GetMenuHeight(), "��ȡ��ͼ�浵");
                        xyprintf(8, 8 + 1 * graphicsEnvironment.GetMenuHeight(), "����ȡ��ͼ�浵");
                        break;

                    case 1:
                        setcolor(0x000000);
                        xyprintf(8, 8 + 0 * graphicsEnvironment.GetMenuHeight(), "��ȡ��ͼ�浵");
                        xyprintf(8, 8 + 1 * graphicsEnvironment.GetMenuHeight(), "����ȡ��ͼ�浵");
                        setcolor(0x5050AA);
                        xyprintf(8, 8 + 0 * graphicsEnvironment.GetMenuHeight(), "��ȡ��ͼ�浵");
                        break;

                    case 2:
                        setcolor(0x000000);
                        xyprintf(8, 8 + 0 * graphicsEnvironment.GetMenuHeight(), "��ȡ��ͼ�浵");
                        xyprintf(8, 8 + 1 * graphicsEnvironment.GetMenuHeight(), "����ȡ��ͼ�浵");
                        setcolor(0x5050AA);
                        xyprintf(8, 8 + 1 * graphicsEnvironment.GetMenuHeight(), "����ȡ��ͼ�浵");
                        break;

                    default:
                        break;
                }

                break;

            default:
                break;
        }
    }

    InitUI(0);
    g_isFileEdited = false;
    return readResult;
}


void TCHARToChar(const TCHAR *tchar, char *_char)
{
    int iLength;
    iLength = WideCharToMultiByte(CP_ACP, 0, tchar, -1, NULL, 0, NULL, NULL);
    WideCharToMultiByte(CP_ACP, 0, tchar, -1, _char, iLength, NULL, NULL);
}