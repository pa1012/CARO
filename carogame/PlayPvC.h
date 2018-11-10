#include "Base.h"

void playLevel(int icon, int n, int k, int level, stack <iii> S, stack <iii>Save, bool B[3][50][50], iii D[2500], int turn);
void doIt(bool &undostate, int icon, stack <iii> S, stack <iii> Save, sf::RectangleShape box[50][50], bool B[3][50][50], int turn, int winer, sf::Text winNoti, sf::Text player, sf::Texture bigXBoxText, sf::Texture bigOBoxText, sf::Texture emptyText);