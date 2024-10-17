#pragma once

#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>

using namespace std;

void sleep(int x) {
    std::this_thread::sleep_for(std::chrono::milliseconds(x));
}

void clear() {
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
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

void gotoxy(short int x, short int y) {
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

int countStrings(string* options, int len, int offset) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum = sum + options[i].length() - offset;
    }
    return sum;
}

void display(string* options,int len,char split_fill) {
    int consolewidth = getTerminalSize_WIDTH();
    int uiTextSize = countStrings(options,len,0) + 5;
    int medium = (int)((consolewidth / 2) - (uiTextSize / 2));
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

void info(string data, short int x, short int y){
    gotoxy(x,y);
    cout << data;
    gotoxy(0,0);
}

void title_down(string title, char split_fill) {
    int consolewidth = getTerminalSize_WIDTH();
    int uiTextSize = title.length();
    int medium = (int)((consolewidth / 2) - (uiTextSize / 2)) - 1;
    margin(medium*2 + uiTextSize + 1, split_fill);

    cout << endl;
    margin(medium, ' ');
    cout << title;
}

void draw_popup(short int x, short int y, int width, int height, char fill){
    for (int _y = y; _y < y+height; _y++){
        for (int _x = x; _x < x+width; _x++){
            gotoxy(_x,_y);
            if (((_y == y) || (_y == y+height-1)) && ((_x == x) || (_x == x+width-1))) cout << "#";
            else if ((_x == x) || (_x == x+width-1)) cout << "|";
            else if ((_y == y) || (_y == y+height-1)) cout << "-";
            else cout << fill;
        }
    }
    
}

void title_up(string title, char split_fill) {
    int consolewidth = getTerminalSize_WIDTH();
    int uiTextSize = title.length();
    int medium = (int)((consolewidth / 2) - (uiTextSize / 2)) - 1;
    margin(medium, ' ');
    cout << title;
    cout << endl;
    margin(medium*2 + uiTextSize + 1, split_fill);

    
}

void TextAnim(int delay,string text){
    int mult = 1;
	for (int i = 0; i < text.size(); i++){
		cout << text[i];
        if (text[i] == ((string)".")[0]) mult = 50;
        else mult = 1;
		sleep(delay * mult);
	}
}

void TextAnimCenter(int delay,string text,int y){
    int mult = 1;
    gotoxy((int)(getTerminalSize_WIDTH() / 2) - (int)(text.size() / 2),y);
	for (int i = 0; i < text.size(); i++){
		cout << text[i];
        if (text[i] == ((string)".")[0]) mult = 50;
        else mult = 1;
		sleep(delay * mult);
	}
}

void draw_options(int x,int y, string* options, int len, int choiced) {
    for (int i = 0; i < len; i++) {
        gotoxy(x, y + i);
        if (i == choiced) cout << "*";
        else cout << " ";
        cout << " " << options[i];
    }
}