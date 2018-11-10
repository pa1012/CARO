#include "Base.h"

caroSprite newCaroSprite(string file, int posX, int posY, bool centerAlign);
sf::Texture loadTexture(string file);
void loadTexture(string file, sf::Texture &texture);
void loadFont(string file, sf::Font &font);
void loadSound(string file, sf::SoundBuffer sound);
void loadMusic(string file, sf::Music &music);
void loadAllAssets(string files[], sf::Texture textures[], int no1);