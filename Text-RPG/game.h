#pragma once

#include "engine.h"
#include <windows.h>

using namespace std;

void main_game(){
	clear();
	
	gotoxy(0, 8);
	title_up((string)("Abilities"), '-');

	gotoxy(0, 50);
	title_down((string)("Statistics"), '-');
	for (int i = 50; i < 65; i++){
		gotoxy(29, i);
		if (i == 50){cout << "#";}
		else{cout << "|";}
	}

	while (true){
		
	}
}

void menu() {
	setlocale(LC_ALL, "Russian");
	int option = 0;

	HWND console = GetConsoleWindow();
	RECT r;
	string test[3]{ "Quit", "Start game", "Settings" };
	string Title = "Authors";

	SetConsoleFontSize(16);

	GetWindowRect(console, &r);

	MoveWindow(console, 0, 0, 1920, 1080, TRUE);
	SetWindowPos(console, 0, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	
	display(test, 3, '-');
	gotoxy(0, 50);
	title_down(Title, '-');
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
			case 1:
				main_game();
				break;
			}
		}
	}
}

