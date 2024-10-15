#pragma once
#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>

using namespace std;

void sleep(int x) {
    std::this_thread::sleep_for(std::chrono::milliseconds(x));
}

void SetConsoleFontSize(int fontSize) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX fontInfo = { 0 };
    fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
    fontInfo.dwFontSize.X = 0;
    fontInfo.dwFontSize.Y = fontSize;
    SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
}

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

int getTerminalSize_WIDTH() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    return columns;
}

int getTerminalSize_HEIGHT() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    rows = csbi.srWindow.Right - csbi.srWindow.Top + 1;
    return rows;
}

void margin(int len,char fill) {
    for (int i = 0; i < len; i++) {
        cout << fill;
    }
}
void split(int len,string* options, char fill) {
    cout << "*";
    for (int i = 0; i < len; i++) {
        margin(options[i].length() + 2, fill);
    }
    for (int i = 0; i < len-1; i++) {
        cout << fill;
    }
    cout << "*";
}
// 120x30

int countStrings(string* options, int len, int offset) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum = sum + options[i].length() - offset;
    }
    return sum;
}

void display(string* options,int len,char split_fill) {
    int consolewidth = getTerminalSize_WIDTH();
    int uiTextSize = countStrings(options,len,3);
    int medium = (int)((consolewidth / 2) - (uiTextSize / 2));

    for (int i = 0; i < len; i++) {
        medium -= options[i].length() - 3;
    }
    margin(medium, split_fill);
    split(len, options, '-');
    margin(medium-6, split_fill);
    cout << endl;
    margin(medium, ' ');
    cout << "| ";
    for (int i = 0; i < len; i++) {
        cout << options[i] << " | ";
    }
    cout << endl;
    margin(medium, split_fill);
    split(len, options, '-');
    margin(medium-6, split_fill);
}

void title(string title, char split_fill) {
    int consolewidth = getTerminalSize_WIDTH();
    int uiTextSize = title.length();
    int medium = (int)((consolewidth / 2) - (uiTextSize / 2));
    margin(medium*2 + uiTextSize + 1, split_fill);

    cout << endl;
    margin(medium, ' ');
    cout << title;
}