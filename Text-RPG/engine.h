#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

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
    cout << "|";
    for (int i = 0; i < len; i++) {
        margin(options[i].length() + 2, fill);
    }
    for (int i = 0; i < len-1; i++) {
        cout << fill;
    }
    cout << "|";
}
// 120x30

int countStrings(string* options, int len, int offset) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum = sum + options[i].length() - offset;
    }
    return sum;
}

void display(string* options,int len) {
    int consolewidth = getTerminalSize_WIDTH();
    int uiTextSize = countStrings(options,len,3);
    int medium = (int)((consolewidth / 2) - (uiTextSize / 2));

    for (int i = 0; i < len; i++) {
        medium -= options[i].length() - 3;
    }
    margin(medium, ' ');
    split(len, options, '-');
    cout << endl;
    margin(medium, ' ');
    cout << "| ";
    for (int i = 0; i < len; i++) {
        cout << options[i] << " | ";
    }
    cout << endl;
    margin(medium, ' ');
    split(len, options, '-');
}