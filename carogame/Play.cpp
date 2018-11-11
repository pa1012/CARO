#include "Play.h"

CaroPlay initPlay(){
	caroSprite playItems[PLAY_ITEMS_COUNT];

	for (int i = 0; i < PLAY_ITEMS_COUNT; i++) {
		playItems[i] = newCaroSprite(PLAY_FILES[i], PLAY_POSX[i], PLAY_POSY[i], PLAY_ALIGN_CENTER[i]);
	}
	CaroPlay play;
	vector<caroSprite> items(playItems, playItems + sizeof(playItems) / sizeof(caroSprite));

	play.items = items;

	for (int i = 0; i < PLAY_ITEMS_COUNT; i++)
	{
		loadTexture(play.items[i].file, play.items[i].texture);
	}

	loadTexture("background.png", play.infomation.texture);
	
	return play;
}

void initPlaySprite(CaroPlay &play, sf::Font &font , const sf::RenderWindow &window,const int& sizeOfGame,bool still) {
	for (int i = 0; i < PLAY_ITEMS_COUNT; i++) {
		initSprite(play.items[i]);
	}
	sf::String playerInput;
	playerInput = "|";
	if (sizeOfGame <= 3) initText(play.rule, font, WHITE, "3 in a line to win.", 615, 550, 21, false);
	else if (sizeOfGame <= 6) initText(play.rule, font, WHITE, "4 in a line to win.", 615, 550, 21, false);
	else initText(play.rule, font, WHITE, "5 in a line to win.", 615, 550, 21, false);
	if (!still) {
		initText(play.player1, font, WHITE, "Player 1", 684, 50, 20, false);
		initText(play.player2, font, WHITE, "Player 2", 684, 140, 20, false);
		initText(play.player, font, WHITE, "Player", 684, 50, 20, false);
		initText(play.computer, font, WHITE, "Computer", 684, 140, 20, false);
	}
	initText(play.score, font, WHITE, "0 : 0", 0, 140, 30, true);
	initText(play.winNotification, font, WHITE, "", 0, 232, 35, true);
	initRectangle(play.infomation.rect, BLACK, play.infomation.texture);
	play.infomation.rect.setPosition(600, 0);
	play.infomation.rect.setSize(sf::Vector2f(200, 600));
	initRectangle(play.backgroundButton.rect, sf::Vector2f(20, 20), WHITE, window, 0);
}

void drawPlay(sf::RenderWindow &window, const CaroPlay &play ,const bool &playMusic, const bool& backgroundOn, const int& sizeOfGame, const bool& pcstate) {
	if (backgroundOn) window.draw(play.infomation.rect);
	window.draw(play.backgroundButton.rect);
	if (playMusic) window.draw(play.items[2].sprite);
	else window.draw(play.items[3].sprite);
	window.draw(play.items[5].sprite);
	window.draw(play.items[4].sprite);
	window.draw(play.items[6].sprite);
	window.draw(play.items[0].sprite);
	window.draw(play.items[1].sprite);
	window.draw(play.items[7].sprite);
	window.draw(play.score);
	if (!pcstate) {
		window.draw(play.player1);
		window.draw(play.player2);
	}
	else {
		window.draw(play.player);
		window.draw(play.computer);
	}
	window.draw(play.rule);

}