#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<SFML/Audio.hpp>
#include <SFML/System.hpp>

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
