#include "Base.h"

typedef pair <int, int> ii;
typedef pair<int, ii> iii;
int checkWinPvP(int n, int k, int u, int v, bool B1[50][50], bool B2[50][50]);
void checkWinPC(int n, int turn, int winer, iii D[2510], int &winX, int &winY, bool B[4][50][50], sf::Texture blackXText, sf::Texture blackOText, sf::RectangleShape box[50][50]);