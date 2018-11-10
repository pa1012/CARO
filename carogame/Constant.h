#pragma once
using namespace std;

const sf::Color WHITE = sf::Color::White;
const sf::Color BLACK = sf::Color::Black;
const int WINDOWN_WIDTH = 800;
const int WINDOWN_HEIGHT = 600;
const int MAX_BOARD_GAME_SIZE = 50;
const int MENU_ITEMS_COUNT = 10;
const int OPTION_ITEMS_COUNT = 7;

const string MENU_FILES[] = { 
	"Menu/gameName.png", 
	"Menu/ppMode.png", 
	"Menu/pcMode.png", 
	"Menu/resumeGame.png", 
	"Menu/statistics.png",
	"Menu/pc1.png",
	"Menu/pc2.png",
	"Menu/pc3.png",
	"Menu/aboutUs.png",
	"Menu/load.png",
};
/*
	Menu:
	0: gameName;
	1: ppMode;
	2: pcMode;
	3: resumeGame;
	4: statistics;
	5: pc1;
	6: pc2;
	7: pc3;
	8: about us;
	9: load 
*/
const int MENU_POSX[] = {
	0, 0, 0, 0, 0, 278, 366, 454, 54, 576
};

const int MENU_POSY[] = {
	30, 135, 263, 441, 519, 360, 360, 360, 519, 519
};

const bool MENU_ALIGN_CENTER[] = {
	true, true, true, true, true, false, false, false, false
};

const string OPTION_FILES[] = {
	"choosesize.png",
	"enternum.png",
	"enternum1.png",
	"chooseicon.png",
	"xbox.png",
	"obox.png",
	"start.png",
};

/*
	0:chooseSize;
	1:numberBox;
	2: numberBox2;

	3:chooseIcon;
	4:xBox;
	5:oBox;
	6:start;
*/

const int OPTION_POSX[] = {
	216, 327, 327, 290, 290, 451,330
};

const int OPTION_POSY[] = {
	108, 219, 219, 360, 408,408,517
};

const bool OPTION_ALIGN_CENTER[] = {
	true,true, true, true,false, false,true
};