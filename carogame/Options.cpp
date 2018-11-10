#include "Options.h"

CaroOption initOption() {
	caroSprite optionItems[OPTION_ITEMS_COUNT];

	for (int i = 0; i < OPTION_ITEMS_COUNT; i++) {
		optionItems[i] = newCaroSprite(OPTION_FILES[i], OPTION_POSX[i], OPTION_POSY[i],OPTION_ALIGN_CENTER[i]);
	}
	CaroOption option;
	vector<caroSprite> items(optionItems, optionItems + sizeof(optionItems) / sizeof(caroSprite));

	option.items = items;

	for (int i = 0; i < OPTION_ITEMS_COUNT; i++)
	{
		loadTexture(option.items[i].file, option.items[i].texture);
	}

	return option;
}

void initOptionSprite(CaroOption &option , sf::Font &font) {
	for (int i = 0; i < OPTION_ITEMS_COUNT; i++) {
		initSprite(option.items[i]);
	}
	sf::String playerInput;
	playerInput = "|";
	initText(option.sizeOfGame, font, sf::Color::Black, playerInput, 365, 219,40,true);
	initText(option.notification, font, sf::Color::White, "", 252, 280,20,true);
}

void drawOption(sf::RenderWindow &window, CaroOption &option, bool pcstate, bool enter, bool chooseSizeSucceed, bool chooseIconSucceed) {
	window.draw(option.items[0].sprite);
	if (!enter) window.draw(option.items[1].sprite);
	else {
		window.draw(option.items[2].sprite);
		window.draw(option.sizeOfGame);
	}
	if (chooseSizeSucceed) {
		window.draw(option.notification);

	}
	if (pcstate)
	{
		window.draw(option.items[3].sprite);
		window.draw(option.items[4].sprite);
		window.draw(option.items[5].sprite);
	}
	if (!pcstate && chooseSizeSucceed) {
		window.draw(option.items[6].sprite);
	}
	if (pcstate && chooseIconSucceed && chooseSizeSucceed) {
		window.draw(option.items[6].sprite);
	}
}

int enterSizeOfGame(const sf::Event &event, sf::Text &input) {
	sf::String str = input.getString();

	int num = 0;

	if (str == "|") {
		str = "";
		num = 0;
	}
	else {
		for (int i = 0; i < str.getSize(); i++)
			num = num * 10 + str[i] - '0';
	}

	if (event.text.unicode == 8) {
		if (num == 0) return num;
		if (str.getSize())
			str.erase(str.getSize() - 1, str.getSize());
		num /= 10;
		updateText(input, str);
		return num;
	}

	if (event.text.unicode != 13)
	{
		str += event.text.unicode;
		num = num * 10 + event.text.unicode - '0';
	}
	updateText(input,str);
	return num;
}