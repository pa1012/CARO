#include "Base.h"

void putVertical(int n, int u, int v, int  icon, bool B[4][50][50], sf::RectangleShape box[50][50], sf::Texture blackXText, sf::Texture blackOText);
void putHorizontal(int n, int u, int v, int  icon, bool B[4][50][50], sf::RectangleShape box[50][50], sf::Texture blackXText, sf::Texture blackOText);
void putCross(int n, int u, int v, int  icon, bool B[4][50][50], sf::RectangleShape box[50][50], sf::Texture blackXText, sf::Texture blackOText);
void putReverse(int n, int u, int v, int  icon, bool B[4][50][50], sf::RectangleShape box[50][50], sf::Texture blackXText, sf::Texture blackOText);

void Vertical(int n, int u, int v, int  icon, bool B1[50][50], bool B2[50][50], sf::RectangleShape box[50][50], sf::Texture &blackXText, sf::Texture &blackOText);
void Horizontal(int n, int u, int v, int  icon, bool B1[50][50], bool B2[50][50], sf::RectangleShape box[50][50], sf::Texture &blackXText, sf::Texture &blackOText);
void Cross(int n, int u, int v, int  icon, bool B1[50][50], bool B2[50][50], sf::RectangleShape box[50][50], sf::Texture &blackXText, sf::Texture &blackOText);
void Reverse(int n, int u, int v, int  icon, bool B1[50][50], bool B2[50][50], sf::RectangleShape box[50][50], sf::Texture &blackXText, sf::Texture &blackOText);

void putAnimationWin(int n, int u, int v, int k, bool B1[50][50], bool B2[50][50], sf::RectangleShape box[50][50], sf::Texture &blackXText, sf::Texture &blackOText);