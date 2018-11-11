#include "WinAnimation.h"

using namespace std;

// PVC
void putVertical(int n,int u, int v, int  icon , bool B[4][50][50],sf::RectangleShape box[50][50],sf::Texture &blackXText, sf::Texture &blackOText) {
	for (int i = 0; i <= 6 && u + i <= n; i++)
	{
		if (B[icon][u + i][v]) break;
		if (!B[icon][u + i][v]) {
			if (icon == 1) box[u + i][v].setTexture(&blackXText);
			else box[u + i][v].setTexture(&blackOText);
		}
	}
	for (int i = 0; i <= 6 && u - i > 0; i++)
	{
		if (B[icon][u - i][v]) break;
		if (!B[icon][u - i][v]) {
			if (icon == 1) box[u - i][v].setTexture(&blackXText);
			else box[u - i][v].setTexture(&blackOText);
		}
	}
}

void putHorizontal(int n,int u, int v, int icon, bool B[4][50][50], sf::RectangleShape box[50][50], sf::Texture &blackXText, sf::Texture &blackOText) {

	for (int i = 0; i <= 6 && v + i <= n; i++)
	{
		if (B[icon][u][v + i]) break;
		if (!B[icon][u][v + i]) {
			if (icon == 1) box[u][v + i].setTexture(&blackXText);
			else box[u][v + i].setTexture(&blackOText);
		}
	}
	for (int i = 0; i <= 6 && v - i > 0; i++)
	{
		if (B[icon][u][v - i]) break;
		if (!B[icon][u][v - i]) {
			if (icon == 1) box[u][v - i].setTexture(&blackXText);
			else box[u][v - i].setTexture(&blackOText);
		}
	}

}

void putCross(int n, int u, int v, int icon, bool B[4][50][50], sf::RectangleShape box[50][50], sf::Texture &blackXText, sf::Texture &blackOText) {

	for (int i = 0; i <= 6 && u + i <= n && v + i <= n; i++)
	{
		if (B[icon][u + i][v + i]) break;
		if (!B[icon][u + i][v + i]) {
			if (icon == 1) box[u + i][v + i].setTexture(&blackXText);
			else box[u + i][v + i].setTexture(&blackOText);
		}
	}
	for (int i = 0; i <= 6 && u - i > 0 && v - i > 0; i++)
	{
		if (B[icon][u - i][v - i]) break;
		if (!B[icon][u - i][v - i]) {
			if (icon == 1) box[u - i][v - i].setTexture(&blackXText);
			else box[u - i][v - i].setTexture(&blackOText);
		}
	}

}

void putReverse(int n, int u, int v, int icon, bool B[4][50][50], sf::RectangleShape box[50][50], sf::Texture &blackXText, sf::Texture &blackOText) {

	for (int i = 0; i <= 6 && u - i > 0 && v + i <= n; i++)
	{
		if (B[icon][u - i][v + i]) break;
		if (!B[icon][u - i][v + i]) {
			if (icon == 1) box[u - i][v + i].setTexture(&blackXText);
			else box[u - i][v + i].setTexture(&blackOText);
		}
	}
	for (int i = 0; i <= 6 && u + i <= n && v - i > 0; i++)
	{
		if (B[icon][u + i][v - i]) break;
		if (!B[icon][u + i][v - i]) {
			if (icon == 1) box[u + i][v - i].setTexture(&blackXText);
			else box[u + i][v - i].setTexture(&blackOText);
		}
	}

}

// PVP
void Cross(int n, int u, int v, int k, bool B1[50][50], bool B2[50][50], sf::RectangleShape box[50][50], sf::Texture &blackXText, sf::Texture &blackOText) {
	int count1 = 0, count2 = 0;
	for (int i = 0; i < k && u + i <= n && v + i <= n; i++) {
		if (!B1[u + i][v + i]) count1++;
		if (!B2[u + i][v + i]) count2++;
	}
	if (count1 == k)
	{
		for (int i = 0; i < k; i++)
			box[u + i][v + i].setTexture(&blackXText);
		return;
	}
	if (count2 == k)
	{
		for (int i = 0; i < k; i++)
			box[u + i][v + i].setTexture(&blackOText);
		return;
	}

	count1 = 0; count2 = 0;
	for (int i = 0; i < k && u - i > 0 && v - i > 0; i++) {
		if (!B1[u - i][v - i]) count1++;
		if (!B2[u - i][v - i]) count2++;
	}
	if (count1 == k)
	{
		for (int i = 0; i < k; i++)
			box[u - i][v - i].setTexture(&blackXText);
		return;
	}
	if (count2 == k)
	{
		for (int i = 0; i < k; i++)
			box[u - i][v - i].setTexture(&blackOText);
		return;
	}
}

void Reverse(int n, int u, int v, int k, bool B1[50][50], bool B2[50][50], sf::RectangleShape box[50][50], sf::Texture &blackXText, sf::Texture &blackOText) {
	int count1 = 0, count2 = 0;
	for (int i = 0; i < k && u - i > 0 && v + i <= n; i++) {
		if (!B1[u - i][v + i]) count1++;
		if (!B2[u - i][v + i]) count2++;
	}
	if (count1 == k)
	{
		for (int i = 0; i < k; i++)
			box[u - i][v + i].setTexture(&blackXText);
		return;
	}
	if (count2 == k)
	{
		for (int i = 0; i < k; i++)
			box[u - i][v + i].setTexture(&blackOText);
		return;
	}

	count1 = 0; count2 = 0;
	for (int i = 0; i < k && u + i <= n && v - i > 0; i++) {
		if (!B1[u + i][v - i]) count1++;
		if (!B2[u + i][v - i]) count2++;
	}
	if (count1 == k)
	{
		for (int i = 0; i < k; i++)
			box[u + i][v - i].setTexture(&blackXText);
		return;
	}
	if (count2 == k)
	{
		for (int i = 0; i < k; i++)
			box[u + i][v - i].setTexture(&blackOText);
		return;
	}
}

void Vertical(int n, int u, int v, int k, bool B1[50][50], bool B2[50][50], sf::RectangleShape box[50][50], sf::Texture &blackXText, sf::Texture &blackOText) {

	int count1 = 0, count2 = 0;

	for (int i = 0; i < k && u - i > 0; i++) {
		if (!B1[u - i][v]) count1++;
		if (!B2[u - i][v]) count2++;
	}
	if (count1 == k)
	{
		for (int i = 0; i < k; i++)
			box[u - i][v].setTexture(&blackXText);
		return;
	}
	if (count2 == k)
	{
		for (int i = 0; i < k; i++)
			box[u - i][v].setTexture(&blackOText);
		return;
	}

	count1 = 0; count2 = 0;
	for (int i = 0; i < k && u + i <= n; i++) {
		if (!B1[u + i][v]) count1++;
		if (!B2[u + i][v]) count2++;
	}
	if (count1 == k)
	{
		for (int i = 0; i < k; i++)
			box[u + i][v].setTexture(&blackXText);
		return;
	}
	if (count2 == k)
	{
		for (int i = 0; i < k; i++)
			box[u + i][v].setTexture(&blackOText);
		return;
	}
}

void Horizontal(int n, int u, int v, int k, bool B1[50][50], bool B2[50][50], sf::RectangleShape box[50][50], sf::Texture &blackXText, sf::Texture &blackOText) {
	int count1 = 0, count2 = 0;
	for (int i = 0; i < k && v + i <= n; i++) {
		if (!B1[u][v + i]) count1++;
		if (!B2[u][v + i]) count2++;
	}
	if (count1 == k)
	{
		for (int i = 0; i < k; i++)
			box[u][v + i].setTexture(&blackXText);
		return;
	}
	if (count2 == k)
	{
		for (int i = 0; i < k; i++)
			box[u][v + i].setTexture(&blackOText);
		return;
	}

	count1 = 0; count2 = 0;
	for (int i = 0; i < k && v - i > 0; i++) {
		if (!B1[u][v - i]) count1++;
		if (!B2[u][v - i]) count2++;
	}
	if (count1 == k)
	{
		for (int i = 0; i < k; i++)
			box[u][v - i].setTexture(&blackXText);
		return;
	}
	if (count2 == k)
	{
		for (int i = 0; i < k; i++)
			box[u][v - i].setTexture(&blackOText);
		return;
	}
}

void putAnimationWin(int n, int u, int v, int k, bool B1[50][50], bool B2[50][50], sf::RectangleShape box[50][50],sf::Texture &blackXText, sf::Texture& blackOText) {
	Cross(n, u, v, k, B1, B2, box, blackXText, blackOText);
	Reverse(n, u, v, k, B1, B2, box, blackXText, blackOText);
	Vertical(n, u, v, k, B1, B2, box, blackXText, blackOText);
	Horizontal(n, u, v, k, B1, B2, box, blackXText, blackOText);
}