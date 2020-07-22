#include <windows.h>
#include <iostream>
#include <thread>

void PressMouseKey(const unsigned int delay) {

    //Press button
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);

    std::this_thread::sleep_for(std::chrono::milliseconds(delay));

    //Release button
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

void ChangeState(bool &var) {
    system("cls");
    var = !var;

    if (var == false) {
        system("color 04");
        std::cout << "Press CAPS_LOCK to change the state.\nCURRENT STATE: OFF";
    }
    else {
        system("color 02");
        std::cout << "Press CAPS_LOCK to change the state.\nCURRENT STATE: ON";
    }
}

int main() {
    unsigned int delay;
    std::cout << "Delay? (in milliseconds. Minimum - 1)\n";
    std::cin >> delay;
    std::cout << "\n";

    bool enable = true;
    ChangeState(enable);

    while (true) {

        if (GetAsyncKeyState(VK_CAPITAL) &1) {

            ChangeState(enable);

            while (enable == true) {

                PressMouseKey(delay);

                if (GetAsyncKeyState(VK_CAPITAL) &1) ChangeState(enable);
            }
        }
    }
}