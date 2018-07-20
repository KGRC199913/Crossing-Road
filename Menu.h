#ifndef MENU_H_
#define MENU_H_

#include "MasterHeader.h"

#define KEY_UP 119
#define KEY_DOWN 115
#define ENTER 13

class Menu
{
	
private:
	static std::vector<std::string> s_options;
	static char s_pressKey;
	static int s_pointer;

	static void PushBackBeginOptions();
	static void PrintMenuOptions();
	//MENU's DECORATION METHOD

	static void DrawGameName();
	static void DrawMenuBox();

	static void PrintSubMenuOptions();
	static void PushBackDifficultiesMenu();
	static void DifficultiesBox();
	static void PushBackPlayAgainMenu();
	static void PlayAgainBox();
	static void PushBackAdjustSoundMenu();
	static void PrintAdjustSoundOptions(int music, int sfx);	
	static void AdjustSoundBox();
	
	Menu();
	~Menu();
public:
	static bool CreateLoopMenu(bool & loadGameFlag, int & music_volume, int & sfx_volume);
	// true = play again, false = not play again
	static bool DrawPlayAgainMenu();
	static int DrawDifficultiesMenu();
	static void  DrawAdjustSoundMenu(int &music, int &sfx);
};

#endif MENU_H_

