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
             "Point(100, 200)[0] = %d, Point(100, 200)[1] = %d, 下标越界将抛出异常",
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
             "注：由于运算符重载在各个图形类中的实现方式类似，且它在本程序的功能中作用不大，只是起到练习和检查学习成果作用，");
    setcolor(0x009090);
    xyprintf(8, 8 + 10 * graphicsEnvironment.GetMenuHeight(),
             "       所以图形类的运算符重载只在圆形中实现了，未在其他图形类中加入，对于练习已学知识的目的已经足够。");
    setcolor(0x000000);
    xyprintf(8, 8 + 12 * graphicsEnvironment.GetMenuHeight(),
             "半径为10的圆 >= 半径为8的圆 ? %s",
             Circle{ 10, 10, 10 } >= Circle{ 10, 10, 8 } ? "true" : "false");
    xyprintf(8, 8 + 13 * graphicsEnvironment.GetMenuHeight(),
             "半径为10的圆 > 半径为8的圆 ? %s",
             Circle{ 10, 10, 10 } > Circle{ 10, 10, 8 } ? "true" : "false");
    xyprintf(8, 8 + 14 * graphicsEnvironment.GetMenuHeight(),
             "半径为10的圆 <= 半径为8的圆 ? %s",
             Circle{ 10, 10, 10 } <= Circle{ 10, 10, 8 } ? "true" : "false");
    xyprintf(8, 8 + 15 * graphicsEnvironment.GetMenuHeight(),
             "半径为10的圆 < 半径为8的圆 ? %s",
             Circle{ 10, 10, 10 } < Circle{ 10, 10, 8 } ? "true" : "false");
    xyprintf(8, 8 + 16 * graphicsEnvironment.GetMenuHeight(),
             "半径为10坐标为(10,10)颜色为0xFFEECC不填充的圆 == 半径为10坐标为(10,10)颜色为0xCCFFAA不填充的圆 ? %s",
             Circle{ 10, 10, 10, 0xFFEEECC } == Circle{ 10, 10, 10, 0xCCFFAA } ? "true" :
             "false");
    xyprintf(8, 8 + 17 * graphicsEnvironment.GetMenuHeight(),
             "半径为10坐标为(10,10)颜色为0xFFEECC不填充的圆 != 半径为10坐标为(10,10)颜色为0xCCFFAA不填充的圆 ? %s",
             Circle{ 10, 10, 10, 0xFFEEECC } != Circle{ 10, 10, 10, 0xCCFFAA } ? "true" :
             "false");
    Circle A = Circle{ 10, 10, 10, 0xFFEEECC };
    Circle B = A;
    xyprintf(8, 8 + 18 * graphicsEnvironment.GetMenuHeight(),
             "将“半径为10坐标为(10,10)颜色为0xFFEECC不填充的圆” A 通过 “=” 拷贝为圆 B， A == B ? %s",
             A == B ? "true" : "false");
    xyprintf(8, 8 + 19 * graphicsEnvironment.GetMenuHeight(),
             "“半径为10坐标为(10,10)颜色为0xFFEECC不填充的圆” A, A[0] = %d, A[1] = %d, 下标越界将抛出异常",
             A[0],
             A[1]);
    setcolor(0x009000);
    xyprintf(8, 8 + 20 * graphicsEnvironment.GetMenuHeight(),
             "运算符重载测试到此结束，在任意位置点击鼠标返回。");
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
