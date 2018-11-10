#include "PlayPvC.h"
long long  defense[7], attack[7];
long long attackVertical(int u, int v, int icon, int k,bool B[3][50][50] , int level,int n ) {

	long long sum = 0;
	int countCom = 0;
	int countPlayer = 0;
	for (int i = 1; i <= k && u + i <= n; i++) {
		if (!B[3 - icon][u + i][v]) {
			countCom++;
		}
		else if (!B[icon][u + i][v]) {
			countPlayer++;
			if (level == 3) sum -= 9;
			break;
		}
		//else if (level == 3 && u + i == n) sum--;
		else break;
	}
	for (int i = 1; i <= k && u - i > 0; i++) {
		if (!B[3 - icon][u - i][v]) {
			countCom++;
		}
		else if (!B[icon][u - i][v]) {
			countPlayer++;
			if (level == 3) sum -= 9;
			break;
		}
		//else if (level == 3 && u - i == 1) sum--;
		else break;
	}
	if (level == 3 && countPlayer == 0 && countCom == k - 2) return 100000;
	if (level == 3 && countPlayer == 1 && countCom == k - 1) return 10000000;
	if (countPlayer == 2) return 0;
	//if (level == 3) return sum + attack[countCom];
	sum -= defense[countPlayer + 1];
	sum += attack[countCom];
	return sum;
}

long long attackHorizontal(int u, int v, int icon, int k, bool B[3][50][50], int level, int n) {

	long long sum = 0;
	int countCom = 0;
	int countPlayer = 0;
	for (int i = 1; i <= k && v + i <= n; i++) {
		if (!B[3 - icon][u][v + i]) {
			countCom++;
		}
		else if (!B[icon][u][v + i]) {
			countPlayer++;
			if (level == 3) sum -= 9;
			break;
		}
		//else if (level == 3 && v + i == n) sum--;
		else break;
	}
	for (int i = 1; i <= k && v - i > 0; i++) {
		if (!B[3 - icon][u][v - i]) {
			countCom++;
		}
		else if (!B[icon][u][v - i]) {
			countPlayer++;
			if (level == 3) sum -= 9;
			break;
		}
		//else if (level == 3 && v - i == 1) sum--;
		else break;
	}
	if (level == 3 && countPlayer == 1 && countCom == k - 1) return 10000000;
	if (countPlayer == 2) return 0;
	//if (level == 3) return sum + attack[countCom];
	sum -= defense[countPlayer + 1];
	sum += attack[countCom];
	return sum;
}

long long attackCross(int u, int v, int icon, int k, bool B[3][50][50], int level, int n) {

	long long sum = 0;
	int countCom = 0;
	int countPlayer = 0;

	for (int i = 1; i <= k && u + i <= n && v + i <= n; i++) {
		if (!B[3 - icon][u + i][v + i]) {
			countCom++;
		}
		else if (!B[icon][u + i][v + i]) {
			countPlayer++;
			if (level == 3) sum -= 9;
			break;
		}
		//else if (level == 3 && (u + i == n || v + i == n)) sum--;
		else break;
	}

	for (int i = 1; i <= k && u - i > 0 && v - i > 0; i++) {
		if (!B[3 - icon][u - i][v - i]) {
			countCom++;
		}
		else if (!B[icon][u - i][v - i]) {
			countPlayer++;
			if (level == 3) sum -= 9;
			break;
		}
		//else if (level == 3 && (u - i == 1 || v - i == 1)) sum--;
		else break;
	}
	if (level == 3 && countPlayer == 1 && countCom == k - 1) return 10000000;
	if (countPlayer == 2) return 0;
	//if (level == 3) return sum + attack[countCom];
	sum -= defense[countPlayer + 1];
	sum += attack[countCom];
	return sum;

}

long long attackReverse(int u, int v, int icon, int k, bool B[3][50][50], int level, int n) {

	long long sum = 0;
	int countCom = 0;
	int countPlayer = 0;

	for (int i = 1; i <= k && u - i > 0 && v + i <= n; i++) {
		if (!B[3 - icon][u - i][v + i]) {
			countCom++;
		}
		else if (!B[icon][u - i][v + i]) {
			countPlayer++;
			if (level == 3) sum -= 9;
			break;
		}
		//else if (level == 3 && (u - i == 1 || v + i == n)) sum--;
		else break;
	}

	for (int i = 1; i <= k && u + i <= n && v - i > 0; i++) {
		if (!B[3 - icon][u + i][v - i]) {
			countCom++;
		}
		else if (!B[icon][u + i][v - i]) {
			countPlayer++;
			if (level == 3) sum -= 9;
			break;
		}
		//else if (level == 3 && (u + i == n || v - i == 1)) sum--;
		else break;
	}
	if (level == 3 && countPlayer == 1 && countCom == k - 1) return 10000000;
	if (countPlayer == 2) return 0;
	//if (level == 3) return sum + attack[countCom];
	sum -= defense[countPlayer + 1];
	sum += attack[countCom];
	return sum;
}

long long defenseVertical(int u, int v, int icon, int k, bool B[3][50][50], int level, int n) {

	long long sum = 0;
	int countCom = 0;
	int countPlayer = 0;
	for (int i = 1; i <= k && u + i <= n; i++) {
		if (!B[3 - icon][u + i][v]) {
			countCom++;
			if (level == 3) sum--;
			break;
		}
		else if (!B[icon][u + i][v]) {
			countPlayer++;
		}
		//else if (level == 3 && u + i == n) sum--;
		else break;
	}
	for (int i = 1; i <= k && u - i > 0; i++) {
		if (!B[3 - icon][u - i][v]) {
			countCom++;
			if (level == 3) sum--;
			break;
		}
		else if (!B[icon][u - i][v]) {
			countPlayer++;
		}
		//else if (level == 3 && u - i == 1) sum--;
		else break;
	}
	if (level == 3 && countCom == 1 && countPlayer == k - 2) return 9;
	//if (level == 3 && countCom == 0 && countPlayer == k-2) return 1000;
	if (countCom == 2) return 0;
	sum += defense[countPlayer];
	return sum;
}

long long defenseHorizontal(int u, int v, int icon, int k, bool B[3][50][50], int level, int n) {

	long long sum = 0;
	int countCom = 0;
	int countPlayer = 0;
	for (int i = 1; i <= k && v + i <= n; i++) {
		if (!B[3 - icon][u][v + i]) {
			countCom++;
			if (level == 3) sum--;
			break;
		}
		else if (!B[icon][u][v + i]) {
			countPlayer++;
		}
		//else if (level == 3 && (v + i == n)) sum--;
		else break;
	}
	for (int i = 1; i <= k && v - i > 0; i++) {
		if (!B[3 - icon][u][v - i]) {
			countCom++;
			if (level == 3) sum--;
			break;
		}
		else if (!B[icon][u][v - i]) {
			countPlayer++;
		}
		//else if (level == 3 && v - i == 1) sum--;
		else break;
	}
	if (level == 3 && countCom == 1 && countPlayer == k - 2) return 9;
	//if (level == 3 && countCom == 0 && countPlayer == k-2) return 100000;
	if (countCom == 2) return 0;
	sum += defense[countPlayer];
	return sum;
}

long long defenseCross(int u, int v, int icon, int k, bool B[3][50][50], int level, int n) {

	long long sum = 0;
	int countCom = 0;
	int countPlayer = 0;

	for (int i = 1; i <= k && u + i <= n && v + i <= n; i++) {
		if (!B[3 - icon][u + i][v + i]) {
			countCom++;
			if (level == 3) sum--;
			break;
		}
		else if (!B[icon][u + i][v + i]) {
			countPlayer++;
		}
		//else if (level == 3 && (u + i == n || v + i == n)) sum--;
		else break;
	}

	for (int i = 1; i <= k && u - i > 0 && v - i > 0; i++) {
		if (!B[3 - icon][u - i][v - i]) {
			countCom++;
			if (level == 3) sum--;
			break;
		}
		else if (!B[icon][u - i][v - i]) {
			countPlayer++;
		}
		//else if (level == 3 && (u - i == 1 || v - i == 1)) sum--;
		else break;
	}
	if (level == 3 && countCom == 1 && countPlayer == k - 2) return 9;
	//if (level == 3 && countCom == 0 && countPlayer == k-2) return 100000;
	if (countCom == 2) return 0;
	sum += defense[countPlayer];
	return sum;
}

long long defenseReverse(int u, int v, int icon, int k, bool B[3][50][50], int level, int n) {

	long long sum = 0;
	int countCom = 0;
	int countPlayer = 0;
	for (int i = 1; i <= k && u - i > 0 && v + i <= n; i++) {
		if (!B[3 - icon][u - i][v + i]) {
			countCom++;
			if (level == 3) sum--;
			break;
		}
		else if (!B[icon][u - i][v + i]) {
			countPlayer++;
		}
		//else if (level == 3 && (u - i == 1 || v + i == n)) sum--;
		else break;
	}

	for (int i = 1; i <= k && u + i <= n && v - i > 0; i++) {
		if (!B[3 - icon][u + i][v - i]) {
			countCom++;
			if (level == 3) sum--;
			break;
		}
		else if (!B[icon][u + i][v - i]) {
			countPlayer++;
		}
		//else if (level == 3 && (u + i == n || v - i == 1)) sum--;
		else break;
	}
	if (level == 3 && countCom == 1 && countPlayer == k - 2) return 9;
	//if (level == 3 && countCom == 0 && countPlayer == k-2) return 100000;
	if (countCom == 2) return 0;
	sum += defense[countPlayer];
	return sum;
}

ii findPosition(int icon, int n, int k,bool B[3][50][50], int level) {
	ii res = make_pair(0, 0);
	long long Max = 0;
	long long MaxSum = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (B[1][i][j] && B[2][i][j]) {
				long long attackScore = attackVertical(i, j, icon, k,B,level,n) + attackHorizontal(i, j, icon, k,B,level,n) + attackCross(i, j, icon, k,B,level,n) + attackReverse(i, j, icon, k,B,level,n);
				long long defenseScore = defenseVertical(i, j, icon, k,B,level,n) + defenseHorizontal(i, j, icon, k,B,level,n) + defenseCross(i, j, icon, k,B,level,n) + defenseReverse(i, j, icon, k,B,level,n);
				long long temporaryScore = attackScore > defenseScore ? attackScore : defenseScore;
				long long sum = attackScore + defenseScore;
				/*if (level == 3 && Max == temporaryScore) {
					if (MaxSum < sum) {
						MaxSum = sum;
						res = make_pair(i, j);
					}
				}*/
				if (Max < temporaryScore) {
					Max = temporaryScore;
					res = make_pair(i, j);
				}
			}
	return res;
}

void playLevel(int icon, int n, int k, int level,stack <iii> S, stack <iii>Save,bool B[3][50][50],iii D[2500],int turn) {
	if (level == 1) {
		attack[0] = 0;
		attack[1] = 10;
		attack[2] = 100;
		attack[3] = 1000;
		attack[4] = 10000;
		attack[5] = 100000;
		attack[6] = 1000000;

		defense[0] = 0;
		defense[1] = 10;
		defense[2] = 100;
		defense[3] = 1000;
		defense[4] = 10000;
		defense[5] = 100000;
		defense[6] = 1000000;
	}
	if (level == 2) {
		attack[0] = 0;
		attack[1] = 9;
		attack[2] = 54;
		attack[3] = 162;
		attack[4] = 1458;
		attack[5] = 13112;
		attack[6] = 118008;

		defense[0] = 0;
		defense[1] = 3;
		defense[2] = 27;
		defense[3] = 81;
		defense[4] = 729;
		defense[5] = 6561;
		defense[6] = 59049;
	}
	if (level == 3) {
		attack[0] = 0;
		attack[1] = 3;
		attack[2] = 24;
		attack[3] = 192;
		attack[4] = 1536;
		attack[5] = 12288;
		attack[6] = 98304;

		defense[0] = 0;
		defense[1] = 1;
		defense[2] = 9;
		defense[3] = 81;
		defense[4] = 729;
		defense[5] = 6561;
		defense[6] = 59049;
	}
	ii pos = findPosition(icon, n, k,B,level);
	//cout << pos.first << " " << pos.second << endl;
	S.push(make_pair(3 - icon, make_pair(pos.first, pos.second)));
	Save.push(make_pair(3 - icon, make_pair(pos.first, pos.second)));
	B[3 - icon][pos.first][pos.second] = false;
	turn++;
	D[turn] = make_pair(3 - icon, make_pair(pos.first, pos.second));
}

void doIt(bool &undostate, int icon,stack <iii> S, stack <iii> Save , sf::RectangleShape box[50][50],bool B[3][50][50],int turn, int winer, sf::Text winNoti,sf::Text player,sf::Texture bigXBoxText, sf::Texture bigOBoxText,sf::Texture emptyText) {

	if (!S.empty()) {
		int u = S.top().second.first;
		int v = S.top().second.second;
		if (S.top().first == 1) {
			box[u][v].setTexture(&bigXBoxText);
		}
		else
		{
			box[u][v].setTexture(&bigOBoxText);
		}
		S.pop();
	}
	if (!S.empty()) {
		int u = S.top().second.first;
		int v = S.top().second.second;
		if (S.top().first == 1) {
			box[u][v].setTexture(&bigXBoxText);
		}
		else
		{
			box[u][v].setTexture(&bigOBoxText);
		}
		S.pop();
	}

	if (undostate && !Save.empty()) {
		int x = Save.top().second.first;
		int y = Save.top().second.second;
		box[x][y].setTexture(&emptyText);
		//undostate = false;
		B[1][x][y] = true;
		B[2][x][y] = true;
		Save.pop();
		turn--;
	}
	if (undostate && !Save.empty()) {
		int x = Save.top().second.first;
		int y = Save.top().second.second;
		box[x][y].setTexture(&emptyText);
		undostate = false;
		B[1][x][y] = true;
		B[2][x][y] = true;
		Save.pop();
		turn--;
	}

	if (winer > 0) {

		if (winer == icon) {
			sf::String text;
			text = player.getString() + " Win";
			winNoti.setString(text);
		}
		else
			if (winer == 3 - icon) {
				winNoti.setPosition(180, 232);
				winNoti.setString("Computer Win");
			}
			else
			{
				winNoti.setString("DRAW!");
				winNoti.setPosition(250, 232);
			}
		//cout << winer;
	}

}