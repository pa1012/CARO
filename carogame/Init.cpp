#include "Init.h"
#include "LoadData.h"

void initSprite(caroSprite &caroSprite) {
	caroSprite.sprite.setTexture(caroSprite.texture);
	if (caroSprite.alignCenter) {
		caroSprite.X = (WINDOWN_WIDTH - caroSprite.sprite.getGlobalBounds().width) / 2;
	}
	caroSprite.sprite.setPosition(caroSprite.X, caroSprite.Y);
}

void initSpriteInCenter(sf::Sprite &sprite, sf::Texture &texture) {
	sprite.setTexture(texture);
	int posX = (WINDOWN_WIDTH - sprite.getGlobalBounds().width) / 2;
	int posY = (WINDOWN_HEIGHT - sprite.getGlobalBounds().height) / 2;
	sprite.setPosition(posX, posY);
}

void initText(sf::Text &text, sf::Font &font, sf::Color color, sf::String input, int posX, int posY, int size,bool center) {
	text.setString(input);
	text.setFillColor(color);
	text.setCharacterSize(size);
	text.setFont(font);
	if (center) {
		posX = (WINDOWN_WIDTH - text.getGlobalBounds().width)/ 2;
	}
	text.setPosition(posX, posY);
}

void initRectangle(sf::RectangleShape &rectangle, sf::Color outlineColor, sf::Color fillColor) {
	rectangle.setFillColor(fillColor);
	rectangle.setOutlineThickness(1.0f);
	rectangle.setOutlineColor(outlineColor);
}

void initRectangle(sf::RectangleShape &rectangle, sf::Color outlineColor,const sf::Texture &texture) {
	rectangle.setOutlineColor(outlineColor);
	rectangle.setOutlineThickness(1.0f);
	rectangle.setTexture(&texture);
}

void initBoardGame(int size, sf::Color outlineColor, sf::Texture emptyTexture, sf::RectangleShape box[50][50]) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			box[i][j].setTexture(&emptyTexture);
			box[i][j].setOutlineColor(outlineColor);
			box[i][j].setOutlineThickness(1.0f);
		}
	}
}

void setStringForPlayer(sf::Text player, sf::Text player1, sf::Text player2) {
	player.setString("Player");
	player1.setString("Player 1");
	player2.setString("Player 2");
}

void initRectangle(sf::RectangleShape &rectangle, sf::Vector2f vector, sf::Color color,const sf::Window &window, int posY) {
	rectangle.setSize(vector);
	rectangle.setFillColor(color);
	rectangle.setPosition(window.getSize().x - rectangle.getGlobalBounds().width, posY);
}

void updateText(sf::Text &text , const sf::String &string) {
	text.setString(string);
	int posX = (WINDOWN_WIDTH - text.getGlobalBounds().width) / 2;
	text.setPosition(posX, text.getPosition().y);
}

