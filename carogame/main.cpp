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
#include "Play.h"
#include "PlayPvC.h"
#include "SaveAndLoadGame.h"
#include "WinAnimation.h"
using namespace std;

const int MAXN = 50;

typedef pair <int, int> ii;
typedef pair<int, ii> iii;
enum GameState {
	SPLASH, MENU, PLAY, END, CHOOSE_SIZE, CHOOSEMODE, STATISTIC, SAVE, WIN, LOAD, VIEW, ABOUTUS
};

void initForGamePVP(const int & sizeOfGame,int & winer,bool & drawableInit,bool B1[50][50],bool B2[50][50],int & turn,stack <iii> &S, stack <iii> &Save,sf::RectangleShape box[MAXN][MAXN],sf::Texture &emptyText) {
	turn = 0;
	drawableInit = true;
	winer = 0;
	while (!S.empty())
	{
		S.pop();
	}
	while (!Save.empty())
	{
		Save.pop();
	}
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++) {
			box[i][j].setTexture(&emptyText);
			box[i][j].setOutlineColor(sf::Color::Black);
			box[i][j].setOutlineThickness(1.0f);
			B1[i][j] = true;
			B2[i][j] = true;
		}
}

void initForGamePVC(const int & sizeOfGame, int & winer, bool & drawableInit, bool B[3][50][50], int & turn, stack <iii> &S, stack <iii> &Save, sf::RectangleShape box[MAXN][MAXN], sf::Texture &emptyText) {
	turn = 0;
	drawableInit = true;
	winer = 0;
	while (!S.empty())
	{
		S.pop();
	}
	while (!Save.empty())
	{
		Save.pop();
	}
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++) {
			box[i][j].setTexture(&emptyText);
			box[i][j].setOutlineColor(sf::Color::Black);
			box[i][j].setOutlineThickness(1.0f);
		}
	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < MAXN; i++)
			for (int j = 0; j < MAXN; j++) B[k][i][j] = true;
	}
}

int main()
{

#pragma region DECLARE VARIABLES
	bool B1[MAXN][MAXN], B2[MAXN][MAXN], B[3][MAXN][MAXN];
	bool playstate = true;
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
	bool playMusic = false;
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
	bool backgroundOn = true , soundOn = false;
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
	

	
	//Sprites

	/*sf::Sprite gameName, ppMode, pcMode, pc1, pc2, pc3, resumeGame, statistics;
	sf::Sprite chooseSize, numberBox, numberBox2, chooseIcon, xBox, oBox, start;
	sf::Sprite sound, undo, back;
	sf::Sprite win, continuePlay;
	sf::Sprite exitBox;
	sf::Sprite save, load, aboutUs;
	sf::Sprite scoreBoard;
	sf::Sprite saveButton;
	sf::Sprite loadButton;*/
	sf::Sprite logo, ppMode, pcMode;

	sf::RectangleShape box[50][50];
	

	//Fonts

	sf::Font font;

	//Text
	/*sf::Text player1, player2, rule1, rule2, rule3;
	sf::String playInput;
	sf::Text playText, notification;
	sf::Text winNoti;
	sf::Text player, computer;
	sf::Text score;
	sf::Text asking, name, nameNoti;
	sf::Text pvc, numberOfGame, xWin, oWin, draw, enterNumber;
	sf::Text rule[9];*/

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
	loadTexture("bigxbox.png", bigXBoxText);
	loadTexture("bigobox.png", bigOBoxText);
	loadTexture("blackxbox.png", blackXText);
	loadTexture("blackobox.png", blackOText);
	loadTexture("empty.png", emptyText);
	loadTexture("ppmode.png", ppModeText);
	loadTexture("pcmode.png", pcModeText);
	CaroPlay play = initPlay();
	CaroSave save = initSave(font);
	CaroLoad load = initLoad(font);
	//ppMode
	int posXppMode = (WINDOWN_WIDTH - ppModeWidth) / 2;
	ppMode.setTexture(ppModeText);
	ppMode.setPosition(posXppMode, 135);

	//pcMode
	pcMode.setTexture(pcModeText);
	pcMode.setPosition(posXppMode, 263);

	//logo
	loadTexture("logoText.png", logoText);
	initSpriteInCenter(logo, logoText);
	
	
	while (playstate)
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
				playstate = false;
			}
			else
			if (state == MENU && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{

				if (menu.items[1].sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
					state = CHOOSE_SIZE;
					initOptionSprite(option,font);
					chooseIconSucceed = false;
					chooseSizeSucceed = false;
					sizeOfGame = 0;
					enter = false;
				}
				if (menu.items[5].sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
					state = CHOOSE_SIZE;
					pcstate = true;
					level = 1;
					initOptionSprite(option,font);
					chooseIconSucceed = false;
					chooseSizeSucceed = false;
					sizeOfGame = 0;
					enter = false;
				}
				if (menu.items[6].sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
					state = CHOOSE_SIZE;
					pcstate = true;
					level = 2;
					initOptionSprite(option,font);
					chooseIconSucceed = false;
					chooseSizeSucceed = false;
					sizeOfGame = 0;
					enter = false;
				}
				if (menu.items[7].sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
					state = CHOOSE_SIZE;
					pcstate = true;
					level = 3;
					initOptionSprite(option,font);
					chooseIconSucceed = false;
					chooseSizeSucceed = false;
					sizeOfGame = 0;
					enter = false;
				}
				if (resume && menu.items[3].sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
					state = PLAY;
					resume = true;
				}
				if (menu.items[9].sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
					state = LOAD;
					initLoadSprite(load,font);
					enter = false;
					loadPC = false;
					chooseModeToLoad = false;
					enterNameFile = true;
					enterNameSucceed = false;
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
						option.items[5].sprite.setTexture(smallOText);
						chooseIconSucceed = true;
					}
					if (option.items[6].sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
					{
						state = PLAY;
						drawableInit = true;
						initPlaySprite(play,font,window,sizeOfGame,false);
						if (pcstate)
						initForGamePVC(sizeOfGame, winer, drawableInit, B, turn, S, Save, box, emptyText);
						else initForGamePVP(sizeOfGame, winer, drawableInit, B1,B2, turn, S, Save, box, emptyText);
						turn = 0;
						playerTurn = true;
						enter = false, enteragain = false, chooseSizeSucceed = false;
						winer = 0;
						player1Turn = true; player2Turn = false;
						undostate = false;
						u = 0; v = 0;
						boxSize = 0; board = 0;
						playMusic = false;
						resume = false;
						chooseIconSucceed = false;
						winX = 0; winY = 0;
						xScore = 0; oScore = 0;
					}
				}

				if (!chooseSizeSucceed && event.type == sf::Event::TextEntered) {
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
			else 
			if (state == PLAY) {
				if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
				{
					for (i = 1; i <= sizeOfGame && winer == 0; i++)
						for (j = 1; j <= sizeOfGame && winer == 0; j++)
						{
							if (B[1][i][j] && B[2][i][j] && B1[i][j] && B2[i][j] && box[i][j].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
								u = i;
								v = j;
								click.play();
								if (!pcstate) {
									if (player1Turn) B1[u][v] = false;
									else B2[u][v] = false;
									S.push(make_pair(player1Turn ? 1 : 2, make_pair(u, v)));
									Save.push(make_pair(player1Turn ? 1 : 2, make_pair(u, v)));
									turn++;
									D[turn] = make_pair(player1Turn ? 1 : 2, make_pair(u, v));
									player1Turn = !player1Turn;
									//cout << turn << endl;
								}
								if (pcstate) {
									B[playerIcon][u][v] = false;
									S.push(make_pair(playerIcon, make_pair(u, v)));
									Save.push(make_pair(playerIcon, make_pair(u, v)));
									turn++;
									D[turn] = make_pair(playerIcon, make_pair(u, v));
									if (winer == 0) 
										checkWinPC(sizeOfGame,turn,winer,D,winX,winY,B,blackXText,blackOText,box);
									if (winer > 0) {
										clock.restart();
										if (winer == 1) xScore++; else oScore++;
										updatePVC(winer,sizeOfGame,xScore,oScore,playerIcon,play.player.getString(),play.computer.getString(),turn,D);
									}
									if (winer == 0) {
										if (sizeOfGame <= 3) playLevel(playerIcon, sizeOfGame, 3, level,S,Save,B,D,turn);
										else if (sizeOfGame <= 6) playLevel(playerIcon, sizeOfGame, 4, level, S, Save, B, D, turn);
										else playLevel(playerIcon, sizeOfGame, 5, level, S, Save, B, D, turn);
										clock.restart();
									}
								}
								break;
							}
						}

					if (play.items[5].sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
						undostate = true;
					}

					if (!pcstate && !undostate && winer == 0)
					{
						for (int i = turn; i >= 1 && winer == 0; i--) {
							int x = D[i].second.first;
							int y = D[i].second.second;
							//cout << x << " " << y << endl;
							if (sizeOfGame <= 3) winer = checkWinPvP(sizeOfGame, 3, x, y,B1,B2);
							else if (sizeOfGame <= 6) winer = checkWinPvP(sizeOfGame, 4, x, y,B1,B2);
							else winer = checkWinPvP(sizeOfGame, 5, x, y,B1,B2);
							winX = x;
							winY = y;
							if (winer > 0) {
								clock.restart();
								if (winer == 1) xScore++; else oScore++;
								updatePVP(winer,sizeOfGame,xScore,oScore,playerIcon,play.player1.getString(),play.player2.getString(),turn,D);
							}
						}
					}

					if (pcstate && !undostate  && winer == 0) {
						checkWinPC(sizeOfGame,turn,winer,D,winX,winY,B,blackXText,blackOText,box);
						if (winer > 0) {
							clock.restart();
							if (winer == 2) oScore++; else xScore++;
							updatePVC(winer, sizeOfGame, xScore, oScore, playerIcon, play.player.getString(), play.computer.getString(), turn, D);
						}
					}

					if (play.items[2].sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
						if (playMusic) {
							playMusic = false;
							music.pause();
						}
						else {
							playMusic = true;
							music.play();
						}
					}

					if (play.items[4].sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
						state = MENU;
						resume = true;
						music.pause();
						playMusic = false;
					}

					if (clock.getElapsedTime().asSeconds() >= 1.0f && pcstate && winer > 0 && play.items[9].sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
						still = true;
						initPlaySprite(play,font,window,sizeOfGame,still);
						pcstate = true;
						initForGamePVC(sizeOfGame, winer, drawableInit, B, turn,S,Save,box,emptyText);
						turn = 0;
						winer = 0;
						playerTurn = true;
						undostate = false;
						playMusic = false;
						resume = false;
					}

					if (clock.getElapsedTime().asSeconds() >= 1.0f && !pcstate && winer > 0 && play.items[9].sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
						still = true;
						initPlaySprite(play,font,window,sizeOfGame,still);
						pcstate = false;
						playerIcon = 0;
						player1Turn = true;
						initForGamePVP(sizeOfGame,winer,drawableInit,B1,B2,turn,S,Save,box,emptyText);
						turn = 0;
						winer = 0;
						player1Turn = true; 
						undostate = false;
						playMusic = false;
						resume = false;
					}
					else
						if (clock.getElapsedTime().asSeconds() >= 1.0f && winer > 0 && play.items[10].sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
							still = false;
							winer = 0; sizeOfGame = 0;
							state = MENU;
							resume = false;
							playerIcon = 0;
							pcstate = false;
						}
						else
							if (winer == 0)
							{
								if (turn == sizeOfGame * sizeOfGame) {
									winer = 3;
									if (pcstate) updatePVC(winer, sizeOfGame, xScore, oScore, playerIcon, play.player.getString(), play.computer.getString(), turn, D);
										else updatePVP(winer, sizeOfGame, xScore, oScore, playerIcon, play.player1.getString(), play.player2.getString(), turn, D);
								}
							}

					if (!pcstate && play.player1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
						play.player1.setString("| ");
						enterTextPlayer1 = true;
					}
					if (!pcstate && play.player2.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
						play.player2.setString("| ");
						enterTextPlayer2 = true;
					}
					if (pcstate && play.player.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
						play.player.setString("| ");
						enterTextPlayer = true;
					}
					if (play.items[6].sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
						state = SAVE;
						initSaveSprite(save,font);
						loadPC = false;
						chooseModeToLoad = false;
						enterNameFile = true;
						enterNameSucceed = false;
					}
					if (play.backgroundButton.rect.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
						backgroundOn = !backgroundOn;
					}

				}
				if (event.type == sf::Event::TextEntered) {
					if (enterTextPlayer1) enterTextPlayer1 = enterName(play.player1, event);
					if (enterTextPlayer2) enterTextPlayer2 = enterName(play.player2, event);
					if (enterTextPlayer)  enterTextPlayer = enterName(play.player, event);
				}
			}
			else 
			if (state == SAVE) {
				if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
					if (save.boxName1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
						enter = true;
						enterNameFile = true;
					}
					if (save.saveButton.sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
						state = PLAY;
						if (!pcstate) saveGame("PVP",sizeOfGame,xScore,oScore,playerIcon,play.player1.getString(),play.player2.getString(),save.name.getString(),turn,D);
						else {
							saveGame("PVC", sizeOfGame, xScore, oScore, playerIcon, play.player.getString(), play.computer.getString(), save.name.getString(), turn, D);;
							pcstate = true;
						}
					}
				}
				if (enterNameFile && event.type == sf::Event::TextEntered) {
					enterNameFile = enterName(save.name, event);
				}
				if (!enterNameFile) {
					enterNameSucceed = true;
				}
			}
			else 
			if (state == LOAD) {
				if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
					if (!chooseModeToLoad) {
						if (ppMode.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
							loadPC = false;
							chooseModeToLoad = true;
						}
						if (pcMode.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
							loadPC = true;
							chooseModeToLoad = true;
						}
					}
					else {
						if (load.boxName1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
							enter = true;
							enterNameFile = true;
						}
						if (load.loadButton.sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
							state = PLAY;
							if (!loadPC) {
								loadGamePVP(sizeOfGame,xScore,oScore,play.player1,play.player2,load.name.getString(),turn,B1,B2,loadError,D,box,bigXBoxText,bigOBoxText);
								if (!loadError) {
									initForGamePVP(sizeOfGame, winer, drawableInit, B1, B2, turn, S, Save, box, emptyText);
									loadGamePVP(sizeOfGame, xScore, oScore, play.player1, play.player2, load.name.getString(), turn, B1, B2, loadError, D, box, bigXBoxText, bigOBoxText);
									state = PLAY;
									drawableInit = true;
								}
								else {
									state = LOAD;
									initLoadSprite(load, font);
									enter = false;
									loadPC = false;
									chooseModeToLoad = false;
									enterNameFile = true;
									enterNameSucceed = false;
								}
							}
							else {
								loadGamePVC(sizeOfGame,xScore,oScore,play.player,load.name.getString(),turn,playerIcon,B,loadError,D,box,bigXBoxText,bigOBoxText);
								if (!loadError) {
									initForGamePVC(sizeOfGame, winer, drawableInit, B, turn, S, Save, box, emptyText);
									pcstate = true;
									loadGamePVC(sizeOfGame, xScore, oScore, play.player, load.name.getString(), turn, playerIcon, B, loadError, D, box, bigXBoxText, bigOBoxText);
									state = PLAY;
									drawableInit = true;
							}
							else {
									state = LOAD;
									initLoadSprite(load, font);
									enter = false;
									loadPC = false;
									chooseModeToLoad = false;
									enterNameFile = true;
									enterNameSucceed = false;
								}
							}
						}
					}
				}
				if (enterNameFile && event.type == sf::Event::TextEntered) {
					enterNameFile = enterName(load.name, event);
				}
				if (!enterNameFile) {
					enterNameSucceed = true;
				}
			}
		}

		//LOGIC
		if (state == MENU)
		{
			if (!resume) {
				initMenuSprite(menu);
				initOptionSprite(option, font);
				initPlaySprite(play, font,window,sizeOfGame,still);
			}
		}
		else 
		if (state == PLAY) {
			stringstream text;
			text << xScore << " : " << oScore;
			play.score.setString(text.str());
			play.score.setPosition(600 + (200 - play.score.getGlobalBounds().width) / 2, 468);
			boxSize = screenHeight / sizeOfGame;
			board = sizeOfGame * boxSize;
			play.infomation.rect.setSize(sf::Vector2f((WINDOWN_WIDTH - board), screenHeight));
			play.infomation.rect.setPosition(600, 0);
			X = 0, Y = (screenHeight - board) / 2;
			if (drawableInit) {
				cout << turn << endl;
				for (i = 1; i <= sizeOfGame; i++)
				{
					for (j = 1; j <= sizeOfGame; j++)
					{
						box[i][j].setSize(sf::Vector2f(boxSize, boxSize));
						box[i][j].setPosition(X, Y);
						box[i][j].setFillColor(WHITE);
						box[i][j].setOutlineThickness(1.0f);
						box[i][j].setOutlineColor(BLACK);
						X = X + boxSize;
					}
					Y = Y + boxSize;
					X = 0;
				}
				drawableInit = false;
			}

			//PvC
			if (pcstate) {
				if (playerIcon == 1) {
					play.player.setPosition(684, 50);
					play.computer.setPosition(684, 140);
				}
				else {
					play.player.setPosition(684, 140);
					play.computer.setPosition(684, 50);
				}

				
				doIt(undostate, playerIcon, S, Save, box, B, turn, winer, play.winNotification, play.player, bigXBoxText, bigOBoxText, emptyText);
				
				//Time delay computer play 
				if (turn % 2 == 0) {
					int x = D[turn].second.first;
					int y = D[turn].second.second;
					if (clock.getElapsedTime().asSeconds() >= 0.5f) {
						if (D[turn].first == 1) {
							if (winer > 0 && winer != 3) box[x][y].setTexture(&blackXText);
							else box[x][y].setTexture(&bigXBoxText);
						}
						else {
							if (winer > 0 && winer != 3) box[x][y].setTexture(&blackOText);
							else box[x][y].setTexture(&bigOBoxText);
						}
					}
					else box[x][y].setTexture(&emptyText);
				}
				if (turn % 2 == 1 && winer > 0) {
					if (D[turn].first == 1) {
						box[D[turn].second.first][D[turn].second.second].setTexture(&blackXText);
					}
					else box[D[turn].second.first][D[turn].second.second].setTexture(&blackOText);
				}
			}

			//PvP
			if (!pcstate) {
				//Undo
				if (undostate && !Save.empty()) {
					int x = Save.top().second.first;
					int y = Save.top().second.second;
					box[x][y].setTexture(&emptyText);
					undostate = false;
					turn--;
					if (Save.top().first == 1) {
						B1[x][y] = true;
						B2[x][y] = true;
						player1Turn = true;
					}
					else {
						B2[x][y] = true;
						B1[x][y] = true;
						player1Turn = false;
					}
					Save.pop();
				}

				if (player1Turn) {
					play.player1.setStyle(sf::Text::Underlined);
					play.player2.setStyle(sf::Text::Regular);
				}
				else {
					play.player1.setStyle(sf::Text::Regular);
					play.player2.setStyle(sf::Text::Underlined);
				}

				while (!S.empty()) {
					int u = S.top().second.first;
					int v = S.top().second.second;
					if (S.top().first == 1) {
						box[u][v].setTexture(&bigXBoxText);
					}
					else
					{
						box[u][v].setTexture(&bigOBoxText);
					}
					S.pop();
				}
				if (winer > 0) {
					//Animation win 

					if (winer != 3) {
						int tempN = (sizeOfGame <= 3) ? 3 : (sizeOfGame <= 6) ? 4 : 5;
						putAnimationWin(sizeOfGame, winX, winY, tempN, B1, B2, box, blackXText, blackOText);
					}

					if (winer == 1) {
						sf::String str;
						str = play.player1.getString() + " Win";
						play.winNotification.setString(str);
					}
					else
						if (winer == 2) {
							sf::String str;
							str = play.player2.getString() + " Win";
							play.winNotification.setString(str);
						}
						else
						{
							play.winNotification.setString("DRAW!");
							play.winNotification.setPosition(250, 232);
						}
					
				}
			}
			if (winer > 0)
				play.winNotification.setPosition((600 - play.winNotification.getGlobalBounds().width) / 2, 232);
		}
		else
		if (state == SAVE) {
			save.saveButton.sprite.setPosition((screenWidth - save.saveButton.sprite.getGlobalBounds().width) / 2, 550);
			save.asking.setString("Enter a name to save: ");
			save.asking.setPosition((WINDOWN_WIDTH - save.asking.getGlobalBounds().width) / 2, 114);
			save.name.setPosition((WINDOWN_WIDTH - save.name.getGlobalBounds().width) / 2, 220);
			if (enterNameSucceed) {
				save.nameNoti.setString("Your file game is :" + save.name.getString() + ".txt");
				save.nameNoti.setPosition((WINDOWN_WIDTH - save.nameNoti.getGlobalBounds().width) / 2, 275);
			}
		}
		else
		if (state == LOAD) {
			if (loadError) {
				load.nameNoti.setString("Not found. Enter again!");
				load.nameNoti.setPosition((WINDOWN_WIDTH - load.nameNoti.getGlobalBounds().width) / 2, 275);
			}
			load.asking.setString("Enter a name to load: ");
			load.asking.setPosition((screenWidth - load.asking.getGlobalBounds().width) / 2, 114);
			load.name.setPosition((screenWidth - load.name.getGlobalBounds().width) / 2, 220);
			if (enterNameSucceed && !loadError) {
				load.nameNoti.setString("The game you want to play: " + load.name.getString());
				load.nameNoti.setPosition((screenWidth - load.nameNoti.getGlobalBounds().width) / 2, 275);
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
		case CHOOSE_SIZE:
			drawOption(window, option, pcstate, enter, chooseSizeSucceed, chooseIconSucceed);
			break;
		case PLAY:
			drawPlay(window,play,playMusic,backgroundOn, sizeOfGame, pcstate);
			for (int i = 1; i <= sizeOfGame; i++)
				for (int j = 1; j <= sizeOfGame; j++)
					window.draw(box[i][j]);
			if (winer > 0) {
				if (clock.getElapsedTime().asSeconds() >= 1.0f) {
					window.draw(play.items[8].sprite);
					window.draw(play.items[9].sprite);
					window.draw(play.items[10].sprite);
					window.draw(play.winNotification);
				}
			}
			break;
		case SAVE:
			window.draw(save.asking);
			if (!enter) window.draw(save.boxName1);
			else {
				window.draw(save.boxName2);
				window.draw(save.name);
			}
			if (enterNameSucceed) {
				window.draw(save.nameNoti);
				window.draw(save.saveButton.sprite);
			}
			break;
		case LOAD:
			if (!chooseModeToLoad) {
				window.draw(pcMode);
				window.draw(ppMode);
			}
			else {
				window.draw(load.asking);
				if (!enter) window.draw(load.boxName1);
				else {
					window.draw(load.boxName2);
					window.draw(load.name);
				}
				if (enterNameSucceed) {
					window.draw(load.nameNoti);
					window.draw(load.loadButton.sprite);
				}
			}
			break;
		}

		window.display();
	}
	return 0;
}