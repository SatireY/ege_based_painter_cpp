#include "save_file.h"

extern std::vector <Shape *> shapeData;

void WriteToFile(void)
{
reopen:
    OPENFILENAME ofn             = { 0 };
    TCHAR strFilename[MAX_PATH]  = { 0 };
    char c_strFilename[MAX_PATH] = { 0 };
    ofn.lStructSize              = sizeof(OPENFILENAME);
    ofn.hwndOwner                = NULL;
    ofn.lpstrFilter              = TEXT("Shape Data (*.draw)\0*.draw\0\0");
    ofn.nFilterIndex             = 1;
    ofn.lpstrFile                = strFilename;
    ofn.nMaxFile                 = sizeof(strFilename);
    ofn.lpstrInitialDir          = NULL;
    ofn.Flags                    = OFN_PATHMUSTEXIST | OFN_HIDEREADONLY |
                                   OFN_OVERWRITEPROMPT;
    ofn.lpstrTitle               = TEXT("��ͼ�ļ����Ϊ");
    ofn.lpstrDefExt              = TEXT("draw");

    if (!(GetSaveFileName(&ofn)))
    {
        return;
    }

    TCHARToChar(strFilename, c_strFilename);
    // convert wide character strings to standard strings
    // to avoid certain errors

    std::ofstream saveFileStream{ c_strFilename };

    if (saveFileStream.fail())
    {
reread:
        int selection = MessageBox(NULL,
                                   TEXT("�޷�׼����д����ļ���\nȷ������ӵ��д��Ȩ��"),
                                   TEXT(""),
                                   MB_ABORTRETRYIGNORE | MB_SYSTEMMODAL | MB_ICONEXCLAMATION);

        switch (selection)
        {
            case IDRETRY:
                goto reread;
                break;

            case IDABORT:
                goto reopen;
                break;

            case IDIGNORE:
                return;
                break;

            default:
                break;
        }
    }
    else
    {
        bool                    isFileSavingSucceed = true;
        Circle                  circleObj_tmp{};
        Line                    lineObj_tmp{};
        myPolygon               polygonObj_tmp{};
        myRectangle             rectangleObj_tmp{};
        auto &typeidCircle    = typeid(circleObj_tmp);
        auto &typeidLine      = typeid(lineObj_tmp);
        auto &typeidPolygon   = typeid(polygonObj_tmp);
        auto &typeidRectangle = typeid(rectangleObj_tmp);

        for (auto i : shapeData)
        {
            if (typeid(*i) == typeidCircle) // Circle
            {
                saveFileStream
                        << 1
                        << std::endl;

                saveFileStream
                        << dynamic_cast<Circle *>(i)->coords.x << DELIMITER_SPACE
                        << dynamic_cast<Circle *>(i)->coords.y << DELIMITER_SPACE
                        << dynamic_cast<Circle *>(i)->radius
                        << std::endl;

                if (dynamic_cast<Circle *>(i)->isFill)
                {
                    saveFileStream
                            << i->outlineColor->getColorValue() << DELIMITER_SPACE
                            << dynamic_cast<Circle *>(i)->isFill << DELIMITER_SPACE
                            << dynamic_cast<Circle *>(i)->fillColor->getColorValue()
                            << std::endl;
                }
                else
                {
                    saveFileStream
                            << i->outlineColor->getColorValue() << DELIMITER_SPACE
                            << dynamic_cast<Circle *>(i)->isFill
                            << std::endl;
                }
            }
            else if (typeid(*i) == typeidLine) // Line
            {
                saveFileStream
                        << 2
                        << std::endl;

                saveFileStream
                        << dynamic_cast<Line *>(i)->coords[0].x << DELIMITER_SPACE
                        << dynamic_cast<Line *>(i)->coords[0].y << DELIMITER_SPACE
                        << dynamic_cast<Line *>(i)->coords[1].x << DELIMITER_SPACE
                        << dynamic_cast<Line *>(i)->coords[1].y
                        << std::endl;

                saveFileStream
                        << i->outlineColor->getColorValue()
                        << std::endl;
            }
            else if (typeid(*i) == typeidPolygon) // Polygon
            {
                saveFileStream
                        << 3
                        << std::endl;

                saveFileStream
                        << dynamic_cast<myPolygon *>(i)->vertexCount << DELIMITER_SPACE;

                for (int j = 0; j < dynamic_cast<myPolygon *>(i)->vertexCount * 2; j++)
                {
                    saveFileStream
                            << dynamic_cast<myPolygon *>(i)->coords[j] << DELIMITER_SPACE;
                }

                saveFileStream
                        << std::endl;

                if (dynamic_cast<myPolygon *>(i)->isFill)
                {
                    saveFileStream
                            << i->outlineColor->getColorValue() << DELIMITER_SPACE
                            << dynamic_cast<myPolygon *>(i)->isFill << DELIMITER_SPACE
                            << dynamic_cast<myPolygon *>(i)->fillColor->getColorValue()
                            << std::endl;
                }
                else
                {
                    saveFileStream
                            << i->outlineColor->getColorValue() << DELIMITER_SPACE
                            << dynamic_cast<myPolygon *>(i)->isFill
                            << std::endl;
                }
            }
            else if (typeid(*i) == typeidRectangle) // Rectangle
            {
                saveFileStream
                        << 4
                        << std::endl;

                saveFileStream
                        << dynamic_cast<myRectangle *>(i)->coords[0].x << DELIMITER_SPACE
                        << dynamic_cast<myRectangle *>(i)->coords[0].y << DELIMITER_SPACE
                        << dynamic_cast<myRectangle *>(i)->coords[1].x << DELIMITER_SPACE
                        << dynamic_cast<myRectangle *>(i)->coords[1].y
                        << std::endl;

                if (dynamic_cast<myRectangle *>(i)->isFill)
                {
                    saveFileStream
                            << i->outlineColor->getColorValue() << DELIMITER_SPACE
                            << dynamic_cast<myRectangle *>(i)->isFill << DELIMITER_SPACE
                            << dynamic_cast<myRectangle *>(i)->fillColor->getColorValue()
                            << std::endl;
                }
                else
                {
                    saveFileStream
                            << i->outlineColor->getColorValue() << DELIMITER_SPACE
                            << dynamic_cast<myRectangle *>(i)->isFill
                            << std::endl;
                }
            }
            else
            {
                isFileSavingSucceed = false;
            }
        }

        if (isFileSavingSucceed)
        {
            MessageBox(NULL,
                       TEXT("����ɹ�"),
                       TEXT("��ʾ"),
                       MB_OK | MB_SYSTEMMODAL | MB_ICONINFORMATION);

            saveFileStream.close();
            g_isFileEdited = false;
        }
        else
        {
            goto reread;
        }
    }

    InitUI(0);
    return;
}



//    FILE *fp;
//reopen:
//    OPENFILENAME ofn             = { 0 };
//    TCHAR strFilename[MAX_PATH]  = { 0 };
//    char c_strFilename[MAX_PATH] = { 0 };
//    ofn.lStructSize              = sizeof(OPENFILENAME);
//    ofn.hwndOwner                = NULL;
//    ofn.lpstrFilter              = TEXT("Shape Data (*.draw)\0*.draw\0\0");
//    ofn.nFilterIndex             = 1;
//    ofn.lpstrFile                = strFilename;
//    ofn.nMaxFile                 = sizeof(strFilename);
//    ofn.lpstrInitialDir          = NULL;
//    ofn.Flags                    = OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;
//    ofn.lpstrTitle               = TEXT("��ͼ�ļ����Ϊ");
//    ofn.lpstrDefExt              = TEXT("draw");
//
//    if (!(GetSaveFileName(&ofn)))
//    {
//        return;
//    }
//
//    TCHARToChar(strFilename,
//                c_strFilename);// convert wide character strings to standard strings
//    // to avoid certain errors
//
//    fp = fopen(c_strFilename, "wb");
//
//    if (fp == NULL)
//    {
//reread:
//        int selection = MessageBox(NULL,
//                                   TEXT("�޷�׼����д����ļ���\nȷ������ӵ��д��Ȩ��"),
//                                   TEXT(""),
//                                   MB_ABORTRETRYIGNORE | MB_SYSTEMMODAL | MB_ICONEXCLAMATION);
//
//        switch (selection)
//        {
//            case IDRETRY:
//                goto reread;
//                break;
//
//            case IDABORT:
//                goto reopen;
//                break;
//
//            case IDIGNORE:
//                return;
//                break;
//
//            default:
//                break;
//        }
//    }
//    else
//    {
//        if ((fwrite(shapeData,
//                    sizeof(shapeData[0]),
//                    sizeof(shapeData) / sizeof(shapeData[0]),
//                    fp) ==
//             sizeof(shapeData) / sizeof(shapeData[0]))
//            && (fwrite(&g_nTotalShapes,
//                       sizeof(WORD),
//                       1,
//                       fp) == 1)
//            && (fwrite(&fileValidityCheckSuffix,
//                       sizeof(fileValidityCheckSuffix),
//                       1,
//                       fp) == 1)) // check the validity of the data read
//        {
//            MessageBox(NULL,
//                       TEXT("����ɹ�"),
//                       TEXT("��ʾ"),
//                       MB_OK | MB_SYSTEMMODAL | MB_ICONINFORMATION);
//
//            if (fclose(fp) == EOF)
//            {
//                int selection2 = MessageBox(NULL,
//                                            TEXT("�޷��رձ�д����ļ���"),
//                                            TEXT(""),
//                                            MB_RETRYCANCEL | MB_SYSTEMMODAL | MB_ICONEXCLAMATION);
//
//                switch (selection2)
//                {
//                    case IDRETRY:
//                        goto reread;
//                        break;
//
//                    case IDCANCEL:
//                        break;
//
//                    default:
//                        break;
//                }
//            }
//            else
//            {
//                g_isFileEdited = false;
//            }
//        }
//        else
//        {
//            goto reread;
//        }
//    }
//
//    InitUI(0);
//    return;
