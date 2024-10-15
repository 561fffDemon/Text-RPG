#pragma once

#include "engine.h"
#include <windows.h>

using namespace std;

void menu() {
	int option = 0;

	HWND console = GetConsoleWindow();
	RECT r;
	string test[3]{ "Quit", "Start", "Quests" };
	string Title = "Statistics";

	SetConsoleFontSize(16);
	setlocale(LC_ALL, "Russian");

	GetWindowRect(console, &r);

	MoveWindow(console, 0, 0, 1920, 1080, TRUE);
	SetWindowPos(console, 0, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	display(test, 3, '-');
	gotoxy(0, 50);
	title(Title, '-');
	bool quit = false;
	while (!quit) {
		gotoxy((getTerminalSize_WIDTH() / 2) - 15, 5);
		cout << "Choiced: " << test[option] << "    ";
		if (GetKeyState(VK_RIGHT) & 0x8000)
		{
			option++;
			if (option >= 3) option = 0;
			sleep(150);
		}
		if (GetKeyState(VK_LEFT) & 0x8000)
		{
			option--;
			if (option <= -1) option = 2;
			sleep(150);
		}
		if (GetKeyState(VK_RETURN) & 0x8000)
		{
			switch (option) {
			case 0:
				quit = !quit;
				break;
			}
		}
	}
}
