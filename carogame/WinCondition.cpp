#include "WinCondition.h"
#include "WinAnimation.h"

int checkWinPvP(int n, int k, int u, int v, bool B1[50][50], bool B2[50][50]) {

	int count1 = 0; int count2 = 0;
	int x1, y1, x2, y2;

	//incline left to right

	for (int i = 0; i < k; i++) {
		int x = u + i;
		int y = v + i;
		if (1 <= x && x <= n && 1 <= y && y <= n) {
			if (!B1[x][y]) count1++;
			if (!B2[x][y]) count2++;
		}
		else break;
	}
	x1 = u - 1; y1 = v - 1;
	x2 = u + k; y2 = v + k;
	if (x1 > 0 && y1 > 0 && x2 <= n && y2 <= n) {
		if (count2 == k && !B1[x1][y1] && !B1[x2][y2]) return 0;
		if (count1 == k && !B2[x1][y1] && !B2[x2][y2]) return 0;
	}
	if (count1 == k) return 1;
	if (count2 == k) return 2;

	//incline right to left
	count1 = 0; count2 = 0;
	for (int i = 0; i < k; i++) {
		int x = u + i;
		int y = v - i;
		if (1 <= x && x <= n && 1 <= y && y <= n) {
			if (!B1[x][y]) count1++;
			if (!B2[x][y]) count2++;
		}
		else break;
	}
	x1 = u - 1; y1 = v + 1;
	x2 = u + k; y2 = v - k;
	if (0 < x1 && x1 <= n && 0 < x2 && x2 <= n && 0 < y1 && y1 <= n && 0 < y2 && y2 <= n) {
		if (count2 == k && !B1[x1][y1] && !B1[x2][y2]) return 0;
		if (count1 == k && !B2[x1][y1] && !B2[x2][y2]) return 0;
	}
	if (count1 == k) return 1;
	if (count2 == k) return 2;

	//In a vertical line
	count1 = 0; count2 = 0;
	for (int i = 0; i < k; i++) {
		int x = u + i;
		int y = v;
		if (1 <= x && x <= n && 1 <= y && y <= n) {
			if (!B1[x][y]) count1++;
			if (!B2[x][y]) count2++;
		}
		else break;
	}
	x1 = u - 1; y1 = v;
	x2 = u + k; y2 = v;
	if (0 < x1 && x1 <= n && 0 < x2 && x2 <= n && 0 < y1 && y1 <= n && 0 < y2 && y2 <= n) {
		if (count2 == k && !B1[x1][y1] && !B1[x2][y2]) return 0;
		if (count1 == k && !B2[x1][y1] && !B2[x2][y2]) return 0;
	}
	if (count1 == k) return 1;
	if (count2 == k) return 2;

	//In a horizontal line 
	count1 = 0; count2 = 0;
	for (int i = 0; i < k; i++) {
		int x = u;
		int y = v + i;
		if (1 <= x && x <= n && 1 <= y && y <= n) {
			if (!B1[x][y]) count1++;
			if (!B2[x][y]) count2++;
		}
		else break;
	}
	x1 = u; y1 = v - 1;
	x2 = u; y2 = v + k;
	if (0 < x1 && x1 <= n && 0 < x2 && x2 <= n && 0 < y1 && y1 <= n && 0 < y2 && y2 <= n) {
		if (count2 == k && !B1[x1][y1] && !B1[x2][y2]) return 0;
		if (count1 == k && !B2[x1][y1] && !B2[x2][y2]) return 0;
	}
	if (count1 == k) return 1;
	if (count2 == k) return 2;
	return 0;
}

bool checkVertical(int n, int k, int u, int v, int icon, bool B[4][50][50]) {
	int countWin = 1;
	int count = 0;
	for (int i = 1; i <= k && u + i <= n; i++) {
		if (!B[3 - icon][u + i][v]) {
			count++;
			break;
		}
		else if (!B[icon][u + i][v]) {
			countWin++;
		}
		else break;
	}
	for (int i = 1; i <= k && u - i > 0; i++) {
		if (!B[3 - icon][u - i][v]) {
			count++;
			break;
		}
		else if (!B[icon][u - i][v]) {
			countWin++;
		}
		else break;
	}
	if (countWin >= k && count < 2) return true;
	return false;
}

bool checkHorizontal(int n, int k, int u, int v, int icon, bool B[4][50][50]) {
	int countWin = 1;
	int count = 0;
	for (int i = 1; i <= k && v + i <= n; i++) {
		if (!B[3 - icon][u][v + i]) {
			count++;
			break;
		}
		else if (!B[icon][u][v + i]) {
			countWin++;
		}
		else break;
	}
	for (int i = 1; i <= k && v - i > 0; i++) {
		if (!B[3 - icon][u][v - i]) {
			count++;
			break;
		}
		else if (!B[icon][u][v - i]) {
			countWin++;
		}
		else break;
	}
	if (countWin >= k && count < 2) return true;
	return false;
}

bool checkCross(int n, int k, int u, int v, int icon, bool B[4][50][50]) {
	int countWin = 1;
	int count = 0;
	for (int i = 1; i <= k && v + i <= n && u + i <= n; i++) {
		if (!B[3 - icon][u + i][v + i]) {
			count++;
			break;
		}
		else if (!B[icon][u + i][v + i]) {
			countWin++;
		}
		else break;
	}
	for (int i = 1; i <= k && v - i > 0 && u - i > 0; i++) {
		if (!B[3 - icon][u - i][v - i]) {
			count++;
			break;
		}
		else if (!B[icon][u - i][v - i]) {
			countWin++;
		}
		else break;
	}
	if (countWin >= k && count < 2) return true;
	return false;
}

bool checkReverse(int n, int k, int u, int v, int icon, bool B[4][50][50]) {
	int countWin = 1;
	int count = 0;
	for (int i = 1; i <= k && v + i <= n && u - i > 0; i++) {
		if (!B[3 - icon][u - i][v + i]) {
			count++;
			break;
		}
		else if (!B[icon][u - i][v + i]) {
			countWin++;
		}
		else break;
	}
	for (int i = 1; i <= k && v - i > 0 && u + i <= n; i++) {
		if (!B[3 - icon][u + i][v - i]) {
			count++;
			break;
		}
		else if (!B[icon][u + i][v - i]) {
			countWin++;
		}
		else break;
	}
	if (countWin >= k && count < 2) return true;
	return false;
}

bool checkPC(int n, int k, int u, int v, int icon, bool B[4][50][50],sf::Texture blackXText, sf::Texture blackOText, const vector < vector< sf::RectangleShape>> &box) {

	if (checkVertical(n, k, u, v, icon,B)) {
		putVertical(n,u, v, icon,B,box,blackXText,blackOText);
		return true;
	}
	if (checkHorizontal(n, k, u, v, icon,B)) {
		putHorizontal(n, u, v, icon, B, box, blackXText, blackOText);
		return true;
	}
	if (checkCross(n, k, u, v, icon,B)) {
		putCross(n, u, v, icon, B, box, blackXText, blackOText);
		return true;
	}
	if (checkReverse(n, k, u, v, icon,B)) {
		putReverse(n, u, v, icon, B, box, blackXText, blackOText);
		return true;
	}
	return false;
}

void checkWinPC(int n, int turn, int winer,iii D[2510],int &winX, int &winY, bool B[4][50][50], sf::Texture blackXText, sf::Texture blackOText, const vector < vector< sf::RectangleShape>> &box) {

	int tempN = (n <= 3) ? 3 : (n <=6 ) ? 4 : 5;

	for (int i = 1; i <= turn && winer == 0; i++) {
		int x = D[i].second.first;
		int y = D[i].second.second;
		int icon = D[i].first;
		if (checkPC(n, 3, x, y, icon, B, blackXText, blackOText, box)) winer = icon;

		if (winer > 0) {
			winX = x;
			winY = y;
			return;
		}
	}
	if (winer == 0 && turn == n * n) {
		winer = 3;
		return;
	}
	return;
}