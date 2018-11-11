#pragma once
#include "Base.h"

void initSprite(caroSprite &caroSprite);
void initSpriteInCenter(sf::Sprite &sprite, sf::Texture &texture);
void initText(sf::Text &text, sf::Font &font, sf::Color color, sf::String input, int posX, int posY, int size,bool center);
void initRectangle(sf::RectangleShape &rectangle, sf::Color outlineColor, sf::Color fillColor);
void initRectangle(sf::RectangleShape &rectangle, sf::Color outlineColor,const sf::Texture &texture);
//void initBoardGame(int size, sf::Color outlineColor, sf::Texture emptyTexture, sf::RectangleShape box[50][50]);
//void setStringForPlayer(sf::Text player, sf::Text player1, sf::Text player2);
void initRectangle(sf::RectangleShape &rectangle, sf::Vector2f vector, sf::Color color, const sf::Window &window, int posY);
void updateText(sf::Text &text,const sf::String &string);