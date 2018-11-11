#include "Base.h"

bool enterName(sf::Text &name, sf::Event event);
void loadGamePVP(int &n, int &xScore, int &oScore, sf::Text &player1, sf::Text &player2, const string &name, int &turn, bool B1[50][50], bool B2[50][50], bool &loadError, iii D[2500], sf::RectangleShape box[50][50], sf::Texture &bigXBoxText, sf::Texture &bigOBoxText);
void loadGamePVC(int &n, int &xScore, int &oScore, sf::Text &player, const string &name, int &turn, int &playerIcon, bool B[3][50][50], bool &loadError, iii D[2500], sf::RectangleShape box[50][50], sf::Texture &bigXBoxText, sf::Texture &bigOBoxText);
void saveGame(string mode, int n, int xScore, int oScore, int playerIcon, string player1, string player2, string name, int turn, iii D[2500]);

CaroSave initSave(const sf::Font &font);

void initSaveSprite(CaroSave &save, const sf::Font &font);

CaroLoad initLoad(const sf::Font &font);

void initLoadSprite(CaroLoad &load, const sf::Font &font);