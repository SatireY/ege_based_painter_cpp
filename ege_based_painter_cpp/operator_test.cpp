#include "operator_test.h"

void operator_test()
{
    setcolor(0x000000);
    xyprintf(8, 8 + 0 * graphicsEnvironment.GetMenuHeight(),
             "Point(100, 100) + Point(200, 200) = Point(%d, %d)",
             (Coordinate(100, 100) + Coordinate(200, 200)).x,
             (Coordinate(100, 100) + Coordinate(200, 200)).y);
    xyprintf(8, 8 + 1 * graphicsEnvironment.GetMenuHeight(),
             "Point(100, 100) == Point(200, 200) ? %s",
             Coordinate(100, 100) == Coordinate(200, 200) ? "true" : "false");
    xyprintf(8, 8 + 2 * graphicsEnvironment.GetMenuHeight(),
             "Point(100, 100) != Point(200, 200) ? %s",
             Coordinate(100, 100) != Coordinate(200, 200) ? "true" : "false");
    xyprintf(8, 8 + 3 * graphicsEnvironment.GetMenuHeight(),
             "Point(100, 200)[0] = %d, Point(100, 200)[1] = %d, �±�Խ�罫�׳��쳣",
             Coordinate(100, 200)[0],
             Coordinate(100, 200)[1]);
    xyprintf(8, 8 + 4 * graphicsEnvironment.GetMenuHeight(),
             "Color{128, 128, 128} == Color{255, 255, 255} ? %s",
             Color{ 128, 128, 128 } == Color{ 255, 255, 255 } ? "true" : "false");
    xyprintf(8, 8 + 5 * graphicsEnvironment.GetMenuHeight(),
             "Color{128, 128, 128} != Color{255, 255, 255} ? %s",
             Color{ 128, 128, 128 } != Color{ 255, 255, 255 } ? "true" : "false");
    xyprintf(8, 8 + 6 * graphicsEnvironment.GetMenuHeight(),
             "++Color{32, 64, 255} = Color{%d, %d, %d}",
             (++Color{ 32, 64, 255 })[0],
             (++Color{ 32, 64, 255 })[1],
             (++Color{ 32, 64, 255 })[2] );
    xyprintf(8, 8 + 7 * graphicsEnvironment.GetMenuHeight(),
             "--Color{0, 64, 255} = Color{%d, %d, %d}",
             (--Color{ 0, 64, 255 })[0],
             (--Color{ 0, 64, 255 })[1],
             (--Color{ 0, 64, 255 })[2]);
    setcolor(0x000090);
    xyprintf(8, 8 + 9 * graphicsEnvironment.GetMenuHeight(),
             "ע����������������ڸ���ͼ�����е�ʵ�ַ�ʽ���ƣ������ڱ�����Ĺ��������ò���ֻ������ϰ�ͼ��ѧϰ�ɹ����ã�");
    setcolor(0x009090);
    xyprintf(8, 8 + 10 * graphicsEnvironment.GetMenuHeight(),
             "       ����ͼ��������������ֻ��Բ����ʵ���ˣ�δ������ͼ�����м��룬������ϰ��ѧ֪ʶ��Ŀ���Ѿ��㹻��");
    setcolor(0x000000);
    xyprintf(8, 8 + 12 * graphicsEnvironment.GetMenuHeight(),
             "�뾶Ϊ10��Բ >= �뾶Ϊ8��Բ ? %s",
             Circle{ 10, 10, 10 } >= Circle{ 10, 10, 8 } ? "true" : "false");
    xyprintf(8, 8 + 13 * graphicsEnvironment.GetMenuHeight(),
             "�뾶Ϊ10��Բ > �뾶Ϊ8��Բ ? %s",
             Circle{ 10, 10, 10 } > Circle{ 10, 10, 8 } ? "true" : "false");
    xyprintf(8, 8 + 14 * graphicsEnvironment.GetMenuHeight(),
             "�뾶Ϊ10��Բ <= �뾶Ϊ8��Բ ? %s",
             Circle{ 10, 10, 10 } <= Circle{ 10, 10, 8 } ? "true" : "false");
    xyprintf(8, 8 + 15 * graphicsEnvironment.GetMenuHeight(),
             "�뾶Ϊ10��Բ < �뾶Ϊ8��Բ ? %s",
             Circle{ 10, 10, 10 } < Circle{ 10, 10, 8 } ? "true" : "false");
    xyprintf(8, 8 + 16 * graphicsEnvironment.GetMenuHeight(),
             "�뾶Ϊ10����Ϊ(10,10)��ɫΪ0xFFEECC������Բ == �뾶Ϊ10����Ϊ(10,10)��ɫΪ0xCCFFAA������Բ ? %s",
             Circle{ 10, 10, 10, 0xFFEEECC } == Circle{ 10, 10, 10, 0xCCFFAA } ? "true" :
             "false");
    xyprintf(8, 8 + 17 * graphicsEnvironment.GetMenuHeight(),
             "�뾶Ϊ10����Ϊ(10,10)��ɫΪ0xFFEECC������Բ != �뾶Ϊ10����Ϊ(10,10)��ɫΪ0xCCFFAA������Բ ? %s",
             Circle{ 10, 10, 10, 0xFFEEECC } != Circle{ 10, 10, 10, 0xCCFFAA } ? "true" :
             "false");
    Circle A = Circle{ 10, 10, 10, 0xFFEEECC };
    Circle B = A;
    xyprintf(8, 8 + 18 * graphicsEnvironment.GetMenuHeight(),
             "�����뾶Ϊ10����Ϊ(10,10)��ɫΪ0xFFEECC������Բ�� A ͨ�� ��=�� ����ΪԲ B�� A == B ? %s",
             A == B ? "true" : "false");
    xyprintf(8, 8 + 19 * graphicsEnvironment.GetMenuHeight(),
             "���뾶Ϊ10����Ϊ(10,10)��ɫΪ0xFFEECC������Բ�� A, A[0] = %d, A[1] = %d, �±�Խ�罫�׳��쳣",
             A[0],
             A[1]);
    setcolor(0x009000);
    xyprintf(8, 8 + 20 * graphicsEnvironment.GetMenuHeight(),
             "��������ز��Ե��˽�����������λ�õ����귵�ء�");
    setcolor(0x000000);

    mouse_msg msg;

    for (; is_run();
         delay_fps(
             REFRESH_RATE))
    {
        msg = getmouse(); // Get mouse clicks and position

        switch (msg.msg)
        {
            case mouse_msg_down:
                return;
                break;

            default:
                break;
        }
    }
}
