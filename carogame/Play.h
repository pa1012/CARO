#include "Init.h";
#include "LoadData.h";

using namespace std;

CaroPlay initPlay();
void initPlaySprite(CaroPlay &play, sf::Font &font,const sf::RenderWindow &window,const int &sizeOfGame,bool still);
void drawPlay(sf::RenderWindow &window, const CaroPlay &play,const bool &playMusic,const bool& backgroundOn,const int& sizeOfGame,const bool& pcstate);void drawPlay(sf::RenderWindow &window,const bool &playMusic,const bool& backgroundOn,const int& sizeOfGame,const bool& pcstate);