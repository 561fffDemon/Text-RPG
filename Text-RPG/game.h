#pragma once

#include "engine.h"
#include <windows.h>

using namespace std;

struct Weapon
{
	float Damage;
	int Durability;
	int TakeMana;
	string Name;
	string Description;
};
struct Player
{
	float HP;
	float Defence;
	float Mana;
	Weapon FirstWeapon;
	Weapon SecondWeapon;
};

void main_game(){
	Weapon StarterWeapon;
	StarterWeapon.Damage = 5;
	StarterWeapon.Durability = -1;
	StarterWeapon.Name = (string)"Fists";
	StarterWeapon.Description = (string)"A usual weapon (Fists), dont have any ablities.";

	Player plr;
	plr.HP = 100.0;
	plr.Defence = 50.0;
	plr.Mana = 100.0;
	plr.FirstWeapon = StarterWeapon;

	clear();
	
	gotoxy(0, 8);
	title_up((string)("History"), '-');

	/*for (int i = 50; i < 65; i++){
		gotoxy(29, i);
		if (i == 50){cout << "#";}
		else{cout << "|";}
	}*/
	
	gotoxy(5, 10);
	TextAnim(25, (string)"In the kingdom of Eberon, the Golden Age reigned, marked by unprecedented peace and prosperity. Behind this facade of prosperity, however, lurked an ancient threat long forgotten and buried in the annals of history.");
	sleep(250);
	gotoxy(5, 11);
	TextAnim(25, (string)"The Shadow, once a powerful evil, was sealed by ancient mages and brave warriors.");
	gotoxy(5, 12);
	TextAnim(25, (string)"Over time, the seals weakened, and the Shadow began to yearn for freedom. Its followers, ghosts and undead, prowl the land, wreaking havoc and destruction.");
	sleep(250);
	gotoxy(5, 13);
	TextAnim(25, (string)"A prophecy carved on the walls of a long-abandoned temple foretold that only chosen heroes could defeat the Shadow and save Eberon. This prophecy summoned a group of strangers to help...");
	sleep(250);
	clear();
	gotoxy(0, 8);

	title_up((string)("History"), '-');
	gotoxy((getTerminalSize_WIDTH()/2) - 3, 11);
	cout << "Aranar";
	TextAnimCenter(25, (string)"A noble warrior whose right hand was cursed and possessed inexplicable power. Fate had bound him to the prophecy since his birth, marking him as one of the chosen.",12);
	gotoxy((getTerminalSize_WIDTH()/2) - 3, 15);
	cout << "Elaina";
	TextAnimCenter(25, (string)"An elven mage who dedicated her life to the study of ancient knowledge and the mysteries of magic. She believed that the key to defeating the Shadow lay in forgotten texts and artifacts.",16);
	gotoxy((getTerminalSize_WIDTH()/2) - 3, 18);
	cout << "Thorn";
	TextAnimCenter(25, (string)"A cunning and charming thief whose connections in the underworld gave him access to hidden information and inaccessible treasures. Although his motives were selfish, he felt an inexplicable connection to the prophecy.",19);
	gotoxy((getTerminalSize_WIDTH()/2) - 3, 21);
	cout << "Astra";
	TextAnimCenter(25, (string)"A healer who drew strength from nature itself. Her connection to the spirit world gave her the ability to see the world through the eyes of spirits and communicate with them.",22);
	TextAnimCenter(25, (string)"She believed that Shadow could be defeated not only by force, but also by compassion and understanding.",23);
	
	clear();
	gotoxy(0, 8);
	title_up((string)("History"), '-');

	gotoxy(5, 10);
	TextAnim(25, (string)"Fate brought these four together, and they found themselves bound together not only by prophecy, but also by a common goal to protect Eberon from an ancient evil.");
	gotoxy(5, 11);
	TextAnim(25, (string)"As they traveled through the kingdom, they encountered dangerous monsters, uncovered eerie secrets, and discovered powerful artifacts that could aid them in their mission.");
	gotoxy(5, 12);
	TextAnim(25, (string)"Their journey led them to a long-forgotten dungeon where they were to battle the Shadow himself. The heroes knew that this battle would determine the fate of Eberon.");
	gotoxy(5, 13);
	TextAnim(25, (string)"They were to use all their courage, strength and wisdom to defeat evil and bring peace back to the kingdom.");

	gotoxy(5, 15);
	TextAnim(25, (string)"The heroes discover an ancient artifact that once belonged to a powerful dark magician.");
	gotoxy(5, 16);
	TextAnim(25, (string)"The artifact emits a sinister aura, and the heroes decide to destroy it before it falls into the wrong hands.");
	gotoxy(5, 17);
	TextAnim(25, (string)"However, their quest brings them into contact with a cult that worships the dark magician. The cultists believe the artifact is the key to resurrecting their master, and they obtaining it.");
	gotoxy(5, 18);
	TextAnim(25, (string)"The heroes must battle cultists, explore dark dungeons, and uncover the secrets of a lost civilization in order to destroy the artifact and prevent the return of the dark mage.");
	
	while (true) {

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
		gotoxy((getTerminalSize_WIDTH() / 2) - (int)(test[option].size() / 2), 5);
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

