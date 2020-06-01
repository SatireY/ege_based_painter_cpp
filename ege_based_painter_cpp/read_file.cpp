#include "read_file.h"

extern std::vector <Shape *> shapeData;

int ReadFromFile(void)
{
    const short int TOTAL_LN                = 2;
    short int       readResult              = 1;
    bool            isReadyToExit           = false;
    OPENFILENAME    ofn                     = { 0 };
    TCHAR           strFilename[MAX_PATH]   = { 0 };
    char            c_strFilename[MAX_PATH] = { 0 };
    int             shapeID                 = 0;
    int             dataBuffer[256]         = { 0 };
begin:
    cleardevice();
    InitUI(0);
    printf("请在菜单界面用鼠标点击操作\n");

    mouse_msg msg;

    DrawMenuOutline(1, TOTAL_LN, 1);
    setcolor(0x000000);
    setfont(graphicsEnvironment.GetFontSize(), 0, graphicsEnvironment.GetFont());

    xyprintf(8, 8 + 0 * graphicsEnvironment.GetMenuHeight(), "读取绘图存档");
    xyprintf(8, 8 + 1 * graphicsEnvironment.GetMenuHeight(), "不读取绘图存档");
    xyprintf(graphicsEnvironment.GetMenuWidth() + 15,
             8 + 2 * graphicsEnvironment.GetMenuHeight(), "用鼠标点击菜单");

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
                        ofn.lStructSize = sizeof(OPENFILENAME);
                        ofn.hwndOwner = NULL;
                        ofn.lpstrFilter = TEXT("Shape Data (*.draw)\0*.draw\0\0");
                        ofn.nFilterIndex = 1;
                        ofn.lpstrFile = strFilename;
                        ofn.nMaxFile = sizeof(strFilename);
                        ofn.lpstrInitialDir = NULL;
                        ofn.lpstrTitle = TEXT("请选择一个文件");
                        ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY;

                        if (!(GetOpenFileName(&ofn)))
                        {
                            goto begin;
                        }

                        TCHARToChar(strFilename, c_strFilename);

                        // convert wide character strings to standard strings
                        // to avoid certain errors

                        if (c_strFilename)
                        {
                            std::ifstream saveFileStream{ c_strFilename };

                            if (saveFileStream.fail())
                            {
READINGFAILED:
                                cleardevice();
                                InitUI(0);
                                int selection = MessageBox(NULL,
                                                           TEXT("请检查文件是否正确"),
                                                           TEXT("读取错误！"),
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

                                while (!saveFileStream.eof())
                                {
                                    shapeID = 0;
                                    saveFileStream >> shapeID;

                                    switch (shapeID)
                                    {
                                        case 1: // Circle
                                            for (int j = 0; j < 5; j++)
                                            {
                                                saveFileStream >> dataBuffer[j];
                                            }

                                            if (dataBuffer[4]) // filled
                                            {
                                                saveFileStream >> dataBuffer[5];
                                                shapeData.push_back(new Circle
                                                {
                                                    dataBuffer[0],
                                                    dataBuffer[1],
                                                    dataBuffer[2],
                                                    (color_t)dataBuffer[3],
                                                    (color_t)dataBuffer[5] });
                                            }
                                            else // not filled
                                            {
                                                shapeData.push_back(new Circle
                                                {
                                                    dataBuffer[0],
                                                    dataBuffer[1],
                                                    dataBuffer[2],
                                                    (color_t)dataBuffer[3] });
                                            }

                                            break;

                                        case 2: // Line
                                            for (int j = 0; j < 5; j++)
                                            {
                                                saveFileStream >> dataBuffer[j];
                                            }

                                            shapeData.push_back(new Line
                                            {
                                                dataBuffer[0],
                                                dataBuffer[1],
                                                dataBuffer[2],
                                                dataBuffer[3],
                                                (color_t)dataBuffer[4] });
                                            break;

                                        case 3: // Polygon
                                            saveFileStream >> dataBuffer[0]; // vertex count

                                            for (int j = 1; j <= dataBuffer[0] * 2; j++)
                                            {
                                                saveFileStream >> dataBuffer[j];
                                            }

                                            // close polygon
                                            dataBuffer[dataBuffer[0] * 2 + 1] = dataBuffer[1]; 
                                            dataBuffer[dataBuffer[0] * 2 + 2] = dataBuffer[2];

                                            saveFileStream >> dataBuffer[dataBuffer[0] * 2 + 3]; // outline color
                                            saveFileStream >> dataBuffer[dataBuffer[0] * 2 + 4]; // isFilled

                                            if (dataBuffer[dataBuffer[0] * 2 + 4]) // filled
                                            {
                                                saveFileStream >> dataBuffer[dataBuffer[0] * 2 + 5]; // fill color
                                                std::vector <int> v_polyCoords(dataBuffer + 1,
                                                                               dataBuffer + (dataBuffer[0] * 2 + 2 + 1));
                                                shapeData.push_back(new myPolygon
                                                {
                                                    v_polyCoords,
                                                    dataBuffer[0],
                                                    (color_t)dataBuffer[dataBuffer[0] * 2 + 3],
                                                    (color_t)dataBuffer[dataBuffer[0] * 2 + 5] });
                                            }
                                            else // not filled
                                            {
                                                std::vector <int> v_polyCoords(dataBuffer + 1,
                                                                               dataBuffer + dataBuffer[0] * 2 + 2 + 1);
                                                shapeData.push_back(new myPolygon
                                                {
                                                    v_polyCoords,
                                                    dataBuffer[0],
                                                    (color_t)dataBuffer[dataBuffer[0] * 2 + 3] });
                                            }

                                            break;

                                        case 4: // Rectangle
                                            for (int j = 0; j < 6; j++)
                                            {
                                                saveFileStream >> dataBuffer[j];
                                            }

                                            if (dataBuffer[5]) // filled
                                            {
                                                saveFileStream >> dataBuffer[6];

                                                shapeData.push_back(new myRectangle
                                                {
                                                    dataBuffer[0],
                                                    dataBuffer[1],
                                                    dataBuffer[2],
                                                    dataBuffer[3],
                                                    (color_t)dataBuffer[4],
                                                    (color_t)dataBuffer[6] });
                                            }
                                            else // not filled
                                            {
                                                shapeData.push_back(new myRectangle
                                                {
                                                    dataBuffer[0],
                                                    dataBuffer[1],
                                                    dataBuffer[2],
                                                    dataBuffer[3],
                                                    (color_t)dataBuffer[4] });
                                            }

                                            break;

                                        default:
                                            continue;
                                            break;
                                    }

                                    if (saveFileStream.fail())
                                    {
                                        int selection = MessageBox(NULL,
                                                                   TEXT("发现非法数据，请检查文件合法性！"),
                                                                   TEXT("读取错误！"),
                                                                   MB_ABORTRETRYIGNORE | MB_SYSTEMMODAL | MB_ICONEXCLAMATION);

                                        switch (selection)
                                        {
                                            case IDRETRY:
                                                for (auto i : shapeData)
                                                {
                                                    delete i;
                                                    shapeData.pop_back();
                                                }

                                                goto case1;
                                                break;

                                            case IDABORT:
                                                exit(1);
                                                break;

                                            case IDIGNORE:
                                                return 0;
                                                break;

                                            default:
                                                break;
                                        }
                                    }
                                }

                                if (readResult) // check the validity of the data written
                                {
                                   /* MessageBox(NULL,
                                               TEXT("读取成功"),
                                               TEXT("提示"),
                                               MB_OK | MB_SYSTEMMODAL | MB_ICONINFORMATION);*/

                                    saveFileStream.close();
                                    readResult = 1;
                                    isReadyToExit = true;
                                }
                                else
                                {
                                    goto READINGFAILED;
                                }
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
                xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);
                DrawMenuOutline(1, TOTAL_LN, 1);

                switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
                {
                    case 0:
                        DrawMenuOutline(1, TOTAL_LN, 1);
                        setcolor(0x000000);
                        xyprintf(8, 8 + 0 * graphicsEnvironment.GetMenuHeight(), "读取绘图存档");
                        xyprintf(8, 8 + 1 * graphicsEnvironment.GetMenuHeight(), "不读取绘图存档");
                        break;

                    case 1:
                        setcolor(0x000000);
                        xyprintf(8, 8 + 0 * graphicsEnvironment.GetMenuHeight(), "读取绘图存档");
                        xyprintf(8, 8 + 1 * graphicsEnvironment.GetMenuHeight(), "不读取绘图存档");
                        setcolor(0x5050AA);
                        xyprintf(8, 8 + 0 * graphicsEnvironment.GetMenuHeight(), "读取绘图存档");
                        break;

                    case 2:
                        setcolor(0x000000);
                        xyprintf(8, 8 + 0 * graphicsEnvironment.GetMenuHeight(), "读取绘图存档");
                        xyprintf(8, 8 + 1 * graphicsEnvironment.GetMenuHeight(), "不读取绘图存档");
                        setcolor(0x5050AA);
                        xyprintf(8, 8 + 1 * graphicsEnvironment.GetMenuHeight(), "不读取绘图存档");
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











//    FILE           *fp;
//    const short int TOTAL_LN                = 2;
//    short int       readResult;
//    bool            isReadyToExit           = false;
//    OPENFILENAME    ofn                     = { 0 };
//    TCHAR           strFilename[MAX_PATH]   = { 0 };
//    char            c_strFilename[MAX_PATH] = { 0 };
//    char            readFileValidityCheckSuffix;
//begin:
//    cleardevice();
//    InitUI(0);
//    printf("请在菜单界面用鼠标点击操作\n");
//
//    mouse_msg msg;
//
//    DrawMenuOutline(1, TOTAL_LN, 1);
//    setcolor(0x000000);
//    setfont(graphicsEnvironment.GetFontSize(), 0, graphicsEnvironment.GetFont());
//
//    xyprintf(8, 8 + 0 * graphicsEnvironment.GetMenuHeight(), "读取绘图存档");
//    xyprintf(8, 8 + 1 * graphicsEnvironment.GetMenuHeight(), "不读取绘图存档");
//    xyprintf(graphicsEnvironment.GetMenuWidth() + 15, 8 + 2 * graphicsEnvironment.GetMenuHeight(), "用鼠标点击菜单");
//
//    for (; !isReadyToExit; delay_fps(REFRESH_RATE))
//    {
//        msg = getmouse();
//
//        switch (msg.msg)
//        {
//            case mouse_msg_down:
//                switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
//                {
//                    case 1:
//case1:
//                        ofn.lStructSize     = sizeof(OPENFILENAME);
//                        ofn.hwndOwner       = NULL;
//                        ofn.lpstrFilter     = TEXT("Shape Data (*.draw)\0*.draw\0\0");
//                        ofn.nFilterIndex    = 1;
//                        ofn.lpstrFile       = strFilename;
//                        ofn.nMaxFile        = sizeof(strFilename);
//                        ofn.lpstrInitialDir = NULL;
//                        ofn.lpstrTitle      = TEXT("请选择一个文件");
//                        ofn.Flags           = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY;
//
//                        if (!(GetOpenFileName(&ofn)))
//                        {
//                            goto begin;
//                        }
//
//                        TCHARToChar(strFilename,
//                                    c_strFilename); // convert wide character strings to standard strings
//                        // to avoid certain errors
//
//                        fp = fopen(c_strFilename, "rb");
//                        rewind(fp);
//
//                        if (fp == NULL)
//                        {
//READINGFAILED:
//                            cleardevice();
//                            InitUI(0);
//                            int selection = MessageBox(NULL,
//                                                       TEXT("请检查文件是否正确"),
//                                                       TEXT("读取错误！"),
//                                                       MB_ABORTRETRYIGNORE | MB_SYSTEMMODAL | MB_ICONEXCLAMATION);
//
//                            switch (selection)
//                            {
//                                case IDRETRY:
//                                    goto case1;
//                                    break;
//
//                                case IDABORT:
//                                    isReadyToExit = false;
//                                    break;
//
//                                case IDIGNORE:
//                                    isReadyToExit = true;
//                                    readResult = 0;
//                                    break;
//
//                                default:
//                                    break;
//                            }
//                        }
//                        else
//                        {
//                            cleardevice();
//                            InitUI(0);
//
//                            if ((fread(shapeData,
//                                       sizeof(shapeData[0]),
//                                       sizeof(shapeData) / sizeof(shapeData[0]),
//                                       fp) ==
//                                 sizeof(shapeData) / sizeof(shapeData[0]))
//                                && (fread(&g_nTotalShapes,
//                                          sizeof(WORD),
//                                          1,
//                                          fp) == 1)
//                                && (fread(&readFileValidityCheckSuffix,
//                                          sizeof(readFileValidityCheckSuffix),
//                                          1,
//                                          fp) == 1)) // check the validity of the data written
//                            {
//                                if (readFileValidityCheckSuffix
//                                    == fileValidityCheckSuffix)
//                                {
//                                    MessageBox(NULL,
//                                               TEXT("读取成功"),
//                                               TEXT("提示"),
//                                               MB_OK | MB_SYSTEMMODAL | MB_ICONINFORMATION);
//
//                                    if (fclose(fp) == EOF)
//                                    {
//                                        int selection2 = MessageBox(NULL,
//                                                                    TEXT("无法关闭被打开的文件！"),
//                                                                    TEXT(""),
//                                                                    MB_RETRYCANCEL | MB_SYSTEMMODAL | MB_ICONEXCLAMATION);
//
//                                        switch (selection2)
//                                        {
//                                            case IDRETRY:
//                                                goto case1;
//                                                break;
//
//                                            case IDCANCEL:
//                                                isReadyToExit = true;
//                                                readResult = 0;
//                                                break;
//
//                                            default:
//                                                break;
//                                        }
//                                    }
//                                    else
//                                    {
//                                        fclose(fp);
//                                        readResult = 1;
//                                        isReadyToExit = true;
//                                    }
//                                }
//                                else
//                                {
//                                    goto READINGFAILED;
//                                }
//                            }
//                            else
//                            {
//                                goto READINGFAILED;
//                            }
//                        }
//
//                        break;
//
//                    case 2: // do not read file
//                        readResult = 0;
//                        isReadyToExit = true;
//                        break;
//
//                    default:
//                        break;
//                }
//
//                break; // not needed
//
//            case mouse_msg_move:
//                setcolor(0x50AA50);
//                xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);
//                DrawMenuOutline(1, TOTAL_LN, 1);
//
//                switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
//                {
//                    case 0:
//                        DrawMenuOutline(1, TOTAL_LN, 1);
//                        setcolor(0x000000);
//                        xyprintf(8, 8 + 0 * graphicsEnvironment.GetMenuHeight(), "读取绘图存档");
//                        xyprintf(8, 8 + 1 * graphicsEnvironment.GetMenuHeight(), "不读取绘图存档");
//                        break;
//
//                    case 1:
//                        setcolor(0x000000);
//                        xyprintf(8, 8 + 0 * graphicsEnvironment.GetMenuHeight(), "读取绘图存档");
//                        xyprintf(8, 8 + 1 * graphicsEnvironment.GetMenuHeight(), "不读取绘图存档");
//                        setcolor(0x5050AA);
//                        xyprintf(8, 8 + 0 * graphicsEnvironment.GetMenuHeight(), "读取绘图存档");
//                        break;
//
//                    case 2:
//                        setcolor(0x000000);
//                        xyprintf(8, 8 + 0 * graphicsEnvironment.GetMenuHeight(), "读取绘图存档");
//                        xyprintf(8, 8 + 1 * graphicsEnvironment.GetMenuHeight(), "不读取绘图存档");
//                        setcolor(0x5050AA);
//                        xyprintf(8, 8 + 1 * graphicsEnvironment.GetMenuHeight(), "不读取绘图存档");
//                        break;
//
//                    default:
//                        break;
//                }
//
//                break;
//
//            default:
//                break;
//        }
//    }
//
//    InitUI(0);
//    g_isFileEdited = false;
//    return readResult;



void TCHARToChar(const TCHAR *tchar, char *_char)
{
    int iLength;
    iLength = WideCharToMultiByte(
                  CP_ACP,
                  0,
                  tchar,
                  -1,
                  NULL,
                  0,
                  NULL,
                  NULL);
    WideCharToMultiByte(
        CP_ACP,
        0,
        tchar,
        -1,
        _char,
        iLength,
        NULL,
        NULL);
}