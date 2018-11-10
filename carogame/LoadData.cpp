#include "LoadData.h"

string path(string file) {
	return "Data/" + file;
}

caroSprite newCaroSprite(string file, int posX, int posY, bool alignCenter) {
	caroSprite newSprite;
	newSprite.file = file;
	newSprite.X = posX;
	newSprite.Y = posY;
	newSprite.alignCenter = alignCenter;
	return  newSprite;
}

sf::Texture loadTexture(string file) {
	sf::Texture texture;
	if (texture.loadFromFile(path(file)) != -1) return texture;
	return texture;
}

void loadTexture(std::string file, sf::Texture &texture) {
	if (texture.loadFromFile(path(file)) == -1) return;
}

void loadFont(string file, sf::Font &font) {
	if (font.loadFromFile(path(file)) == 0) return;
}

void loadSound(string file, sf::SoundBuffer sound) {
	if (sound.loadFromFile(path(file)) == 0) return;
}

void loadMusic(string file, sf::Music &music) {
	if (music.openFromFile(path(file)) == 0) return;
}

void loadAllAssets(string files[], sf::Texture textures[], int no1) {
	for (int i = 0; i < no1; i++) {
		loadTexture(files[i], textures[i]);
	}
}