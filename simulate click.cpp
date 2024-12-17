#include <windows.h>
#include <iostream>
#include <thread>

// 定义鼠标移动的两个位置
 // 亲测弹窗需要点击的地方

// 移动鼠标到指定位置的函数
void moveMouseTo(POINT point) {
    SetCursorPos(point.x, point.y);
    std::cout << "Mouse moved to: (" << point.x << ", " << point.y << ")\n";
}

// 模拟鼠标左键单击的函数
void leftClick() {
    // 按下左键
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // 模拟按下的持续时间
    // 松开左键
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
    std::cout << "Left click performed.\n";
}

int main() {
    POINT pointA = {856, 629};
    std::cout << "Please input the point u wantto click.(double int,'-1' is default value)\n";
    int a , b;std::cin >> a;
    if( a != -1 ){
        std::cin >> b;
        pointA = {a, b};
    }
    std::cout << "Mouse movement and click program started.\n";
    while (true) {
        moveMouseTo(pointA);// 移动到点 A
        leftClick(); // 执行左键单击
        std::this_thread::sleep_for(std::chrono::seconds(30*60)); // 等待 30 分钟
    }

    return 0;
}
