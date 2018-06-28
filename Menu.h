#ifndef MENU_H_
#define MENU_H_

#include "MasterHeader.h"

class Menu
{
private:
	std::vector<std::string> _options;
	char _pressKey;
	int _pointer;

	//MENU's DECORATION METHOD
	void DrawGameName();
	void DrawBox();
	void DrawMan();
	void DrawDinos();
	void DrawBirds();
	void DrawCars();
	void DrawTrucks();
	void DrawTree();
	void DrawCloud();
public:
	Menu();
	Menu& PushBackBeginOptions();
	void PrintMenuOptions();
	void CreateLoopMenu();
	~Menu();
};

#endif MENU_H_