﻿#include "Menu.h"
#include "GUI.h"
#include "CCAR.h"
#include "CTRUCK.h"
#include "CBIRD.h"
#include "CDINOSAUR.h"
#include "CGAME.h"

std::vector<std::string> Menu::s_options;
char Menu::s_pressKey = ' ';
int Menu::s_pointer = 0;

Menu::Menu()
{
	Menu::s_pressKey = NULL;
	Menu::s_pointer = 0;
}

void Menu::PushBackBeginOptions() {
	std::vector<std::string> ops = { "NEW GAME", "LOAD GAME", "SETTINGS", "ABOUT US", "EXIT" };
	Menu::s_options.clear();
	Menu::s_options.insert(Menu::s_options.end(), ops.begin(), ops.end());
}

void Menu::PrintMenuOptions() {
	GUI::gotoXY(0, 0);
	PushBackBeginOptions();
	//GUI::clearConsoleScreen();
	DrawGameName();
	DrawMenuBox();
	/*DrawTree();
	DrawMan();
	DrawDinos();
	DrawBirds();
	DrawCloud();
	DrawCars();
	DrawTrucks();*/
	GUI::gotoXY(45, 30); std::cout << "BE SAFE PASSER!!!!";
	
	int coordY = 21;
	for (size_t i = 0; i < s_options.size(); ++i) {
		if (s_pointer == i) {
			GUI::gotoXY(46, coordY);  
			std::cout << ">> " << s_options[i] << " <<";
			coordY += 1;
		}
		else {
			GUI::gotoXY(46, coordY); 
			std::cout <<"   "<< s_options[i] << "   ";
			coordY += 1;
		}
	}
}

bool Menu::CreateLoopMenu(bool & loadGameFlag, sf::Music & music, int & sfx_volume) {
	while (true) {
		Menu::PrintMenuOptions();
		while (true) {
			s_pressKey = _getch();
			if (s_pressKey == KEY_UP) {
				if (s_pointer > 0)
					--s_pointer;
				else
					s_pointer = s_options.size() - 1;
				break;
			}
			if (s_pressKey == KEY_DOWN) {
				if ((size_t)s_pointer < s_options.size() - 1)
					++s_pointer;
				else
					s_pointer = 0;
				break;
			}
			if (s_pressKey == ENTER) {
				switch (s_pointer) {
				case 0: {
					GUI::clearConsoleScreen();
					return true;
				}

				case 1: {
					loadGameFlag = true;
					return true;
				}

				case 2: {
					GUI::clearConsoleScreen();
					Menu::DrawAdjustSoundMenu(music, sfx_volume);
					GUI::clearConsoleScreen();
					Menu::PrintMenuOptions();
					break;
				}

				case 3: {
					GUI::clearConsoleScreen();
					Menu::DrawTeamName();
					Menu::PrintMenuOptions();
					break;
				}

				case 4: {
					GUI::clearConsoleScreen();
					return false;
				}
				}
			}
		}
	}
}


void Menu::DrawGameName() {
	std::cout << R"abcd(
                        ____     __                       __                  
                       /\  _`\  /\ \                     /\ \__  __           
                       \ \ \/\_\\ \ \___      __      ___\ \ ,_\/\_\    ___   
                        \ \ \/_/_\ \  _ `\  /'__`\   / __`\ \ \/\/\ \  /'___\ 
                         \ \ \L\ \\ \ \ \ \/\ \L\.\_/\ \L\ \ \ \_\ \ \/\ \__/ 
                          \ \____/ \ \_\ \_\ \__/.\_\ \____/\ \__\\ \_\ \____\
                           \/___/   \/_/\/_/\/__/\/_/\/___/  \/__/ \/_/\/____/
			            ____                         __                   
			           /\  _`\                      /\ \                  
			           \ \ \L\ \    ___      __     \_\ \                 
			            \ \ ,  /   / __`\  /'__`\   /'_` \                
			             \ \ \\ \ /\ \L\ \/\ \L\.\_/\ \L\ \               
			              \ \_\ \_\ \____/\ \__/.\_\ \___,_\              
			               \/_/\/ /\/___/  \/__/\/_/\/__,_ /      
)abcd";
	std::cout << std::endl;
}

void Menu::DrawTeamName() {
	std::cout << R"abcd(
                     


                               *                 *@@@@@*
                                         *      *@@@@@@@*     *
                                    *           *@@@@@@@*   
                                                 *@@@@@*  *
                         
                                      |\___/|
                                   *  )     (      *   
                               *     =\     /=
                                       )===(       *
                                      /     \
                                      |     | NEKO~NEKO TEAM
                                     /       \  
                                     \       /
                              _/\_/\_/\__  _/_/\_/\_/\_/\_/\_
                              |  |  |  |( (  |  |  |  |  |  |
                              |  |  |  | ) ) |  |  |  |  |  |  

                                   THANKS FOR PLAYING!!
)abcd";
	if (_getch());
}

void Menu::DrawMenuBox() {


	for (int coordX = 44; coordX < 61; ++coordX) {
		GUI::gotoXY(coordX, 20); std::cout << char(BOX_HORIZONTAL_ASCII);
		GUI::gotoXY(coordX, 26); std::cout << char(BOX_HORIZONTAL_ASCII);
	}

	for (int coordY = 21; coordY <= 25; ++coordY) {
		GUI::gotoXY(44, coordY); std::cout << char(BOX_VERTICAL_ASCII);
		GUI::gotoXY(61, coordY); std::cout << char(BOX_VERTICAL_ASCII);
	}

	GUI::gotoXY(61, 20); std::cout << char(BOX_TOP_RIGHT_CORNER_ASCII);
	GUI::gotoXY(61, 26); std::cout << char(BOX_BOTTOM_RIGHT_CORNER_ASCII);
	GUI::gotoXY(44, 20); std::cout << char(BOX_TOP_LEFT_CORNER_ASCII);
	GUI::gotoXY(44, 26); std::cout << char(BOX_BOTTOM_LEFT_CORNER_ASCII);

}


void Menu::PrintSubMenuOptions()
{
	int coordY = 14;
	for (size_t i = 0; i < s_options.size(); ++i) {
		if (s_pointer == i) {
			GUI::gotoXY(43, coordY); 
			std::cout << ">> " << s_options[i]<< " <<" ;
			coordY += 1;
		}
		else {
			GUI::gotoXY(43, coordY); 
			std::cout << "   " << s_options[i] << "   ";
			coordY += 1;
		}
	}
}

void Menu::PushBackDifficultiesMenu()
{
	std::vector<std::string> ops = { "NORMAL", "HARDCORE", "LUNATIC" };
	Menu::s_options.clear();
	Menu::s_options.insert(Menu::s_options.end(), ops.begin(), ops.end());
}

void Menu::DifficultiesBox()
{
	for (int coordX = 42; coordX < 57; coordX++)
	{
		GUI::gotoXY(coordX, 13); std::cout << char(BOX_HORIZONTAL_ASCII);
		GUI::gotoXY(coordX, 18); std::cout << char(BOX_HORIZONTAL_ASCII);
	}
	for (int coordY = 14; coordY <= 17; coordY++)
	{
		GUI::gotoXY(41, coordY); std::cout << char(BOX_VERTICAL_ASCII);
		GUI::gotoXY(57, coordY); std::cout << char(BOX_VERTICAL_ASCII);
	}
	GUI::gotoXY(57, 13); std::cout << char(BOX_TOP_RIGHT_CORNER_ASCII);
	GUI::gotoXY(57, 18); std::cout << char(BOX_BOTTOM_RIGHT_CORNER_ASCII);
	GUI::gotoXY(41, 13); std::cout << char(BOX_TOP_LEFT_CORNER_ASCII);
	GUI::gotoXY(41, 18); std::cout << char(BOX_BOTTOM_LEFT_CORNER_ASCII);
}

int Menu::DrawDifficultiesMenu() {
	PushBackDifficultiesMenu();
	while (true) {
		DifficultiesBox();
		PrintSubMenuOptions();
		while (true) {
			s_pressKey = _getch();
			if (s_pressKey == KEY_UP) {
				if (s_pointer > 0)
					--s_pointer;
				else
					s_pointer = s_options.size() - 1;
				break;
			}
			if (s_pressKey == KEY_DOWN) {
				if ((size_t)s_pointer < s_options.size() - 1)
					++s_pointer;
				else
					s_pointer = 0;
				break;
			}
			if (s_pressKey == ENTER) {
				return s_pointer;
			}
		}
	}
}

void Menu::PushBackPlayAgainMenu()
{
	CGAME* cg = CGAME::getInstance();
	std::string option1String = cg->wonPreviousLevel() ? "NEXT LEVEL" : "PLAY AGAIN";
	std::vector<std::string> ops = { option1String, "EXIT" };
	Menu::s_options.clear();
	Menu::s_options.insert(Menu::s_options.end(), ops.begin(), ops.end());
}

void Menu::PlayAgainBox()
{
	for (int coordX = 42; coordX < 61; coordX++)
	{
		GUI::gotoXY(coordX, 13); std::cout << char(BOX_HORIZONTAL_ASCII);
		GUI::gotoXY(coordX, 16); std::cout << char(BOX_HORIZONTAL_ASCII);
	}
	for (int coordY = 14; coordY <= 15; coordY++)
	{
		GUI::gotoXY(42, coordY); std::cout << char(BOX_VERTICAL_ASCII);
		GUI::gotoXY(61, coordY); std::cout << char(BOX_VERTICAL_ASCII);
	}
	GUI::gotoXY(61, 13); std::cout << char(BOX_TOP_RIGHT_CORNER_ASCII);
	GUI::gotoXY(61, 16); std::cout << char(BOX_BOTTOM_RIGHT_CORNER_ASCII);
	GUI::gotoXY(42, 13); std::cout << char(BOX_TOP_LEFT_CORNER_ASCII);
	GUI::gotoXY(42, 16); std::cout << char(BOX_BOTTOM_LEFT_CORNER_ASCII);
}

bool Menu::DrawPlayAgainMenu()
{
	PushBackPlayAgainMenu();
	while (true) {
		PlayAgainBox();
		PrintSubMenuOptions();
		while (true) {
			s_pressKey = _getch();
			if (s_pressKey == KEY_UP) {
				if (s_pointer > 0)
					--s_pointer;
				else
					s_pointer = s_options.size() - 1;
				break;
			}
			if (s_pressKey == KEY_DOWN) {
				if ((size_t)s_pointer < s_options.size() - 1)
					++s_pointer;
				else
					s_pointer = 0;
				break;
			}
			if (s_pressKey == ENTER) {
				switch (s_pointer) {
				case 0: {
					GUI::clearConsoleScreen();
					return true;
				}

				case 1: {
					GUI::clearConsoleScreen();
					return false;
				}
				}
			}
		}
	}
}

Menu::~Menu() {}


void Menu::PushBackAdjustSoundMenu()
{
	std::vector<std::string> ops = { "MUSIC: ", "SFX:   ", "BACK" };
	Menu::s_options.clear();
	Menu::s_options.insert(Menu::s_options.end(), ops.begin(), ops.end());
}

void Menu::PrintAdjustSoundOptions(sf::Music & music, int sfx)
{
	int coordY = 14;
	int musicVol = music.getVolume();
	for (size_t i = 0; i < s_options.size(); ++i) {
		if (s_pointer == i) {
			GUI::gotoXY(43, coordY);
			if (i == 0) {
				std::cout << s_options[i] << " << " << musicVol << " >> ";
				coordY += 1;
			}
			else if (i == 1) {
				std::cout << s_options[i] << " << " << sfx << " >> ";
				coordY += 1;
			}
			else {
				std::cout << " <<  " << s_options[i] << " >> ";
				coordY += 1;
			}
		}
		else {
			GUI::gotoXY(43, coordY);
			if (i == 0) {
				std::cout << s_options[i] << "    " << musicVol << "    ";
				coordY += 1;
			}
			else if (i == 1) {
				std::cout << s_options[i] << "    " << sfx << "    ";
				coordY += 1;
			}
			else {
				std::cout << "     " << s_options[i] << "    ";
				coordY += 1;
			}
		}
	}
}

void Menu::DrawAdjustSoundMenu(sf::Music & music, int &sfx)
{
	PushBackAdjustSoundMenu();
	s_pointer = 0;
	int musicVol = music.getVolume();
	while (true) {
		AdjustSoundBox();
		PrintAdjustSoundOptions(music, sfx);
		while (true) {
			s_pressKey = _getch();
			if (s_pressKey == KEY_UP) {
				if (s_pointer > 0)
					--s_pointer;
				else
					s_pointer = s_options.size() - 1;
				break;
			}
			if (s_pressKey == KEY_DOWN) {
				if ((size_t)s_pointer < s_options.size() - 1)
					++s_pointer;
				else
					s_pointer = 0;
				break;
			}
			if (s_pressKey == KEY_RIGHT) {
				if (s_pointer == 0) {
					if (musicVol < 100) {
						++musicVol;
						music.setVolume(musicVol);
					}
						
				}
				else if (s_pointer == 1) {
					if (sfx < 100)
						++sfx;
				}
				break;
			}
			if (s_pressKey == KEY_LEFT) {
				if (s_pointer == 0) {
					if (musicVol > 0) {
						--musicVol;
						music.setVolume(musicVol);
					}
				}
				else if (s_pointer == 1) {
					if (sfx > 0)
						--sfx;
				}
				break;
			}
			if (s_pressKey == ENTER && s_pointer == 2) {
				return;
			}
		}
	}
}

void Menu::AdjustSoundBox()
{
	for (int coordX = 42; coordX < 65; coordX++)
	{
		GUI::gotoXY(coordX, 13); std::cout << char(BOX_HORIZONTAL_ASCII);
		GUI::gotoXY(coordX, 18); std::cout << char(BOX_HORIZONTAL_ASCII);
	}
	for (int coordY = 14; coordY <= 17; coordY++)
	{
		GUI::gotoXY(41, coordY); std::cout << char(BOX_VERTICAL_ASCII);
		GUI::gotoXY(65, coordY); std::cout << char(BOX_VERTICAL_ASCII);
	}
	GUI::gotoXY(65, 13); std::cout << char(BOX_TOP_RIGHT_CORNER_ASCII);
	GUI::gotoXY(65, 18); std::cout << char(BOX_BOTTOM_RIGHT_CORNER_ASCII);
	GUI::gotoXY(41, 13); std::cout << char(BOX_TOP_LEFT_CORNER_ASCII);
	GUI::gotoXY(41, 18); std::cout << char(BOX_BOTTOM_LEFT_CORNER_ASCII);
}