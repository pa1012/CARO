#include "Base.h"

void updatePVC(int winer, int n, int xScore, int oScore, int playerIcon, string player1, string player2, int turn, iii D[2500]);
void updatePVP(int winer, int n, int xScore, int oScore, int playerIcon, string player1, string player2, int turn, iii D[2500]);
int Number(sf::Event event, sf::Text &number);

CaroStatistic initStatistic();
void initStatisticSprite(CaroStatistic &stt, int x, int &GAMES, const sf::Font &font, bool &chooseNumberSucceed);
void InitForViewPVC(int num, bool &pcstate, int &sizeOfGame, int &xScore, int &oScore, int &playerIcon, sf::Text &player, int & turn, sf::RectangleShape box[50][50], iii D[2500], bool B[3][50][50], sf::Texture &bigXBoxText, sf::Texture &bigOBoxText);
void InitForViewPVP(int num, bool &pcstate, int &sizeOfGame, int &xScore, int &oScore, int &playerIcon, sf::Text &player1, sf::Text &player2, int & turn, sf::RectangleShape box[50][50], iii D[2500], bool B1[50][50], bool B2[50][50], sf::Texture &bigXBoxText, sf::Texture &bigOBoxText);