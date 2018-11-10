#include "Menu.h";


//load Texture for menu sprite
CaroMenu initMenu() {
	caroSprite menuItems[MENU_ITEMS_COUNT];

	for (int i = 0; i < MENU_ITEMS_COUNT; i++) {
		menuItems[i] = newCaroSprite(MENU_FILES[i], MENU_POSX[i], MENU_POSY[i], MENU_ALIGN_CENTER[i]);
	}

	CaroMenu menu;
	vector<caroSprite> items(menuItems, menuItems + sizeof(menuItems) / sizeof(caroSprite));

	menu.items = items;

	for (int i = 0; i < MENU_ITEMS_COUNT; i++)
	{
		loadTexture(menu.items[i].file, menu.items[i].texture);
	}
	return menu;
}

//Fill texture for sprites in menu
void initMenuSprite(CaroMenu &menu) {
	for (int i = 0; i < MENU_ITEMS_COUNT; i++)
	{
		initSprite(menu.items[i]);
	}
}

//draw all item in menu
void drawMenu(sf::RenderWindow &window, CaroMenu menu) {
	for (int i = 0; i < MENU_ITEMS_COUNT; i++) {
		//cout << menu.items[i].sprite.getTexture() << " " << menu.items[i].X << " " << menu.items[i].Y <<endl;
		window.draw(menu.items[i].sprite);
	}
}

