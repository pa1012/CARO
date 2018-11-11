#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<SFML/Audio.hpp>
#include <SFML/System.hpp>

struct caroRect {
	sf::RectangleShape rect;
	sf::Texture texture;
	string file;
	int posX, posY;
	sf::Vector2f vector;
};
struct caroSprite {
	sf::Sprite sprite;
	sf::Texture texture;
	string file;
	int X;
	int Y;
	bool alignCenter;
};

struct CaroMenu {
	vector<caroSprite> items;
};

struct CaroOption
{
	vector<caroSprite> items;
	sf::Text notification;
	sf::Text sizeOfGame;
	sf::String playerInput;
};

struct CaroPlay
{
	caroRect infomation, backgroundButton;
	vector<caroSprite> items;
	sf::Text score;
	sf::Text player1, player2, player, computer;
	sf::Text rule;
	sf::Text winNotification;
	//sf::RectangleShape box[50][50];
};

struct CaroSave {
	sf::Text asking;
	sf::Text name;
	sf::Text nameNoti;
	sf::RectangleShape boxName1, boxName2;
	caroSprite saveButton;
};

struct CaroLoad {
	sf::Text asking;
	sf::Text name;
	sf::Text nameNoti;
	sf::RectangleShape boxName1, boxName2;
	caroSprite loadButton;
};