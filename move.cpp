#include <windows.h>
#include <iostream>
#include <thread>

// 定义鼠标移动的两个位置
POINT pointA = {856, 629}; // 第一个位置 (屏幕坐标)
POINT pointB = {500, 500}; // 第二个位置 (屏幕坐标)

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
    std::cout << "Mouse movement and click program started.\n";
    
    while (true) {
        // 移动到点 A
        moveMouseTo(pointA);
        leftClick(); // 执行左键单击
        std::this_thread::sleep_for(std::chrono::seconds(30)); // 等待 10 秒

        // 移动到点 B
        moveMouseTo(pointB);
        leftClick(); // 执行左键单击
        std::this_thread::sleep_for(std::chrono::seconds(30)); // 等待 10 秒
    }

    return 0;
}
