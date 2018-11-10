#include<SFML/Graphics.hpp>
#include<iostream>
#include<SFML/Audio.hpp>
#include <SFML/System.hpp>
#include<stack>
#include<deque>
#include<sstream>
#include<fstream>
#include <array>
#include "LoadData.h"
#include "Init.h"
#include "WinCondition.h"
#include "Menu.h"
#include "DataStruct.h"
#include "Options.h"
#include "Statistics.h"

using namespace std;

const int MAXN = 50;

typedef pair <int, int> ii;
typedef pair<int, ii> iii;
enum GameState {
	SPLASH, MENU, PLAY, END, CHOOSE_SIZE, CHOOSEMODE, STATISTIC, SAVE, WIN, LOAD, VIEW, ABOUTUS
};
int main()
{
#pragma region DECLARE VARIABLES
	bool B1[MAXN][MAXN], B2[MAXN][MAXN], B[3][MAXN][MAXN];
	bool play = true;
	int screenWidth = 800, screenHeight = 600;
	int alpha = 0;
	bool turnOffSplash = false;
	int mouseX = 0, mouseY = 0;
	int sizeOfGame = 0;
	bool enter = false, enteragain = false, chooseSizeSucceed = false;
	bool pcstate = false, drawableInit = false;
	int boxSize = 0, board = 0;
	int X, Y, i, j, u = 0, v = 0;
	bool player1Turn = true, player2Turn = false;
	bool undostate = false;
	int winer = 0;
	int gameNameWidth = 248, gameNameHeight = 67;
	int ppModeWidth = 245;
	bool playMusic;
	bool resume = false;
	int playerIcon = 0;
	bool chooseIconSucceed = false;
	bool playerTurn = true;
	int level = 0;
	int turn = 0;
	long long attack[7] = { 0,3,27,99,729,6561,59049 };
	long long defense[7] = { 0,9,54,162,1458,13112,118008 };
	int winX, winY;
	bool enterTextPlayer1 = false, enterTextPlayer2 = false, enterTextPlayer = false;
	int xScore = 0, oScore = 0;
	bool still = false; //continue play
	bool enterNameFile = false;
	bool enterNameSucceed = false;
	bool loadError = false;
	bool chooseModeToLoad, loadPC;
	int GAMES = 0;
	bool chooseNumberSucceed = false;
	bool backgroundOn = true;
	bool chooseRuleSucceed = false;
	iii D[MAXN * MAXN];
	stack <iii> S, Save;
	GameState state = SPLASH;
#pragma endregion

#pragma region DECLARE GRAPHICS
	//Texture
	sf::Texture logoText;
	sf::Texture gameNameText, ppModeText, pcModeText, pc1Text, pc2Text, pc3Text, resumeGameText, statisticsText;
	sf::Texture chooseSizeText, numberBoxText, numberBox2Text, chooseIconText, xBoxText, oBoxText, startText;
	sf::Texture soundOnText, soundOffText, undoText, backText, bigXBoxText, bigOBoxText, emptyText;
	sf::Texture winText, continueplayText, exitBoxText;
	sf::Texture smallXText, smallOText;
	sf::Texture blackXText, blackOText;
	sf::Texture saveText, loadText, aboutUsText;
	sf::Texture scoreText;
	sf::Texture saveButtonText;
	sf::Texture loadButtonText;
	sf::Texture background;
	sf::Texture textures[] = { logoText, gameNameText, ppModeText, pcModeText, pc1Text, pc2Text, pc3Text, resumeGameText, statisticsText, chooseSizeText, numberBoxText, numberBox2Text, chooseIconText, xBoxText, oBoxText, startText, soundOnText, soundOffText, undoText, backText, bigXBoxText, bigOBoxText, emptyText, winText, continueplayText, exitBoxText, smallXText, smallOText, blackXText, blackOText, saveText, loadText, aboutUsText, scoreText, saveButtonText, loadButtonText, background };

	string textureFiles[] = { "logoText.png",
								"gameNameText.png", "ppModeText.png", "pcModeText.png", "pc1Text.png", "pc2Text.png", "pc3Text.png", "resumeGameText.png", "statisticText.png",
								"chooseSizeText.png", "numberBoxText.png", "numberBoxText2.png", "chooseIconText.png", "xBoxText.png", "oBoxText.png", "startText.png",
								"soundOnText.png", "soundOffText.png", "undoText.png", "backText.png", "bigXBoxText.png", "bigOBoxText.png", "emptyText.png",
								"winText.png", "continueplayText.png", "exitText.png",
								"smallXText.png", "smallOText.png",
								"blackXText.png", "blackOText.png",
								"saveText.png", "loadText.png", "aboutUsText.png",
								"scoreText.png",
								"saveButtonText.png",
								"loadButtonText.png",
								"background.png" };
	//Sprites

	sf::Sprite gameName, ppMode, pcMode, pc1, pc2, pc3, resumeGame, statistics;
	sf::Sprite chooseSize, numberBox, numberBox2, chooseIcon, xBox, oBox, start;
	sf::Sprite sound, undo, back;
	sf::Sprite win, continuePlay;
	sf::Sprite exitBox;
	sf::Sprite save, load, aboutUs;
	sf::Sprite scoreBoard;
	sf::Sprite saveButton;
	sf::Sprite loadButton;
	sf::Sprite logo;

	//Shape
	sf::RectangleShape gameBoard, information;
	sf::RectangleShape boxName1, boxName2;
	sf::RectangleShape backgroundButton;
	sf::RectangleShape box[50][50];

	//Fonts

	sf::Font font;

	//Text
	sf::Text player1, player2, rule1, rule2, rule3;
	sf::String playInput;
	sf::Text playText, notification;
	sf::Text winNoti;
	sf::Text player, computer;
	sf::Text score;
	sf::Text asking, name, nameNoti;
	sf::Text pvc, numberOfGame, xWin, oWin, draw, enterNumber;
	sf::Text rule[9];

	//Sound
	sf::SoundBuffer soundBuffer;
	sf::Sound click;
	sf::Music music;

#pragma endregion

	//Creation
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Game");
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);


	loadFont("VNI-Avo.TTF", font);
	loadSound("click.wav", soundBuffer);
	loadMusic("music.ogg", music);


	//sound
	click.setBuffer(soundBuffer);
	music.setLoop(true);

	//Event
	sf::Event event;

	//clock
	sf::Clock clock;
	clock.restart();

	//Load all data
	CaroMenu menu = initMenu();
	CaroOption option = initOption();
	loadTexture("smallxbox.png",smallXText);
	loadTexture("smallobox.png",smallOText);
	//logo
	loadTexture("logoText.png", logoText);
	initSpriteInCenter(logo, logoText);
	
	while (play)
	{
		logo.setColor(sf::Color(225, 225, 225, alpha));
		if (alpha <= 100) {
			alpha++;
		}
		else if (state == SPLASH) {
			state = MENU;
			initMenuSprite(menu);
		}
	
		//EVENT

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				play = false;
			}
			else
			if (state == MENU && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{

				if (menu.items[1].sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
					state = CHOOSE_SIZE;
					initOptionSprite(option,font);
				}
				if (menu.items[5].sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
					state = CHOOSE_SIZE;
					pcstate = true;
					level = 1;
					initOptionSprite(option,font);
				}
				if (menu.items[6].sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
					state = CHOOSE_SIZE;
					pcstate = true;
					level = 2;
					initOptionSprite(option,font);
				}
				if (menu.items[7].sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
					state = CHOOSE_SIZE;
					pcstate = true;
					level = 3;
					initOptionSprite(option,font);
				}
				if (resume && menu.items[3].sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
					state = PLAY;
					resume = true;
				}
				if (menu.items[9].sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
					state = LOAD;
					enter = false;
					enterNameFile = true;
				}
				if (menu.items[4].sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
					state = STATISTIC;
					chooseModeToLoad = false;
					loadPC = false;
				}
				if (menu.items[8].sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
					state = ABOUTUS;
				}
			}
			else 
			if (state == CHOOSE_SIZE) {
				//cout << string(option.sizeOfGame.getString()) << endl;
				if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
					if (!enter && option.items[1].sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
						enter = true;
					}
					if (chooseSizeSucceed && option.items[4].sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
						playerIcon = 1;
						option.items[4].sprite.setTexture(smallXText);
						chooseIconSucceed = true;
					}
					if (chooseSizeSucceed && option.items[5].sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
						playerIcon = 2;
						option.items[5].sprite.setTexture(smallXText);
						chooseIconSucceed = true;
					}
					if (option.items[6].sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
					{
						state = PLAY;
						//initGameSprite();
					}
				}

				if ( event.type == sf::Event::TextEntered) {
					if (event.text.unicode == 13) {
						if (sizeOfGame > 20 || sizeOfGame < 3) {
							updateText(option.sizeOfGame, "|");
							sizeOfGame = 0;
						}
						else {
							chooseSizeSucceed = true;
							updateText(option.notification, "The size of gameboard: " + option.sizeOfGame.getString() + "x" + option.sizeOfGame.getString() + ".");
						}
					}
					else 
						sizeOfGame = enterSizeOfGame(event, option.sizeOfGame);
					cout << sizeOfGame << endl;
				}
			}


		}

		// RENDERING
		window.clear();
		switch (state)
		{
		case SPLASH:
			window.draw(logo);
			break;
		case MENU:
			drawMenu(window, menu);
			break;
		case CHOOSE_SIZE :
			drawOption(window, option,pcstate,enter,chooseSizeSucceed,chooseIconSucceed);
			break;
			
		}
		window.display();
	}
	return 0;
}