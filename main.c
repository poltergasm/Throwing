#include <windows.h>
#include <stdio.h>

INPUT ip;

void mouseClick()
{
    ip.type = INPUT_MOUSE;
    ip.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &ip, sizeof(INPUT));

    ZeroMemory(&ip,sizeof(INPUT));
    ip.type = INPUT_MOUSE;
    ip.mi.dwFlags  = MOUSEEVENTF_LEFTUP;
    SendInput(1, &ip, sizeof(INPUT));
}

int main()
{
    // we go to sleep a lot here because
    // sometimes these windows calls trip over themselves
    while(1) {
        if (GetAsyncKeyState(0x4C)) {
            // select Hanzo
            SetCursorPos(758, 897);
            Sleep(10);
            mouseClick();

            // click continue
            Sleep(10);
            SetCursorPos(963, 1007);
            Sleep(10);
            mouseClick();
        }

        Sleep(50);
    }
}