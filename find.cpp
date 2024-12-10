#include <windows.h>
#include <iostream>

int main() {
    POINT cursorPos; // 用于存储鼠标位置

    std::cout << "Press Ctrl + C to exit.\n";

    while (true) {
        // 获取鼠标位置
        if (GetCursorPos(&cursorPos)) {
            // 输出鼠标当前的位置
            std::cout << "Mouse Position: (" << cursorPos.x << ", " << cursorPos.y << ")\r";
            std::flush(std::cout); // 刷新输出，让坐标实时更新
        } else {
            std::cerr << "Failed to get cursor position.\n";
        }

        // 添加延迟以减少 CPU 占用
        Sleep(100);
    }

    return 0;
}
