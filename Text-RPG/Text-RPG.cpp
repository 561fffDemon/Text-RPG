#include <iostream>
#include "engine.h"

using namespace std;

int main(){
	setlocale(LC_ALL,"Russian");
	const int len = 4;
	string test_options[len]{"Настройки", "Начать игру", "Квесты", "Выход"};
	display(test_options,len);
	cout << endl;
	string test_options1[len]{ "Settings", "Start game", "Quests", "Quit" };
	display(test_options1, len);
}