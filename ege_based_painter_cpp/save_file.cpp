#include "save_file.h"

void WriteToFile(void)
{
    FILE *fp;
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
    ofn.Flags                    = OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;
    ofn.lpstrTitle               = TEXT("��ͼ�ļ����Ϊ");
    ofn.lpstrDefExt              = TEXT("draw");

    if (!(GetSaveFileName(&ofn)))
    {
        return;
    }

    TCHARToChar(strFilename,
                c_strFilename);// convert wide character strings to standard strings
    // to avoid certain errors

    fp = fopen(c_strFilename, "wb");

    if (fp == NULL)
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
        if ((fwrite(shapeData,
                    sizeof(shapeData[0]),
                    sizeof(shapeData) / sizeof(shapeData[0]),
                    fp) ==
             sizeof(shapeData) / sizeof(shapeData[0]))
            && (fwrite(&g_nTotalShapes,
                       sizeof(WORD),
                       1,
                       fp) == 1)
            && (fwrite(&fileValidityCheckSuffix,
                       sizeof(fileValidityCheckSuffix),
                       1,
                       fp) == 1)) // check the validity of the data read
        {
            MessageBox(NULL,
                       TEXT("����ɹ�"),
                       TEXT("��ʾ"),
                       MB_OK | MB_SYSTEMMODAL | MB_ICONINFORMATION);

            if (fclose(fp) == EOF)
            {
                int selection2 = MessageBox(NULL,
                                            TEXT("�޷��رձ�д����ļ���"),
                                            TEXT(""),
                                            MB_RETRYCANCEL | MB_SYSTEMMODAL | MB_ICONEXCLAMATION);

                switch (selection2)
                {
                    case IDRETRY:
                        goto reread;
                        break;

                    case IDCANCEL:
                        break;

                    default:
                        break;
                }
            }
            else
            {
                g_isFileEdited = false;
            }
        }
        else
        {
            goto reread;
        }
    }

    InitUI(0);
    return;
}