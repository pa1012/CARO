#include "Base.h"

bool enterName(sf::Text &name, sf::Event event);
void loadGamePVP(int n, int xScore, int oScore, sf::Text player1, sf::Text player2, string name, int turn, bool B1[50][50], bool B2[50][50], bool &loadError, iii D[2500], sf::RectangleShape box[50][50], sf::Texture bigXBoxText, sf::Texture bigOBoxText);
void loadGamePVC(int n, int xScore, int oScore, sf::Text player, string name, int turn, int playerIcon, bool B1[50][50], bool B2[50][50], bool &loadError, iii D[2500], sf::RectangleShape box[50][50], sf::Texture bigXBoxText, sf::Texture bigOBoxText);
void saveGame(string mode, int n, int xScore, int oScore, int playerIcon, string player1, string player2, string name, int turn, iii D[2500]);