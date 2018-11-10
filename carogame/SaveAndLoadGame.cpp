#include "SaveAndLoadGame.h"


bool enterName(sf::Text &name, sf::Event event) {
	sf::String str = name.getString();
	if (str == "| ") str = "";
	if (event.text.unicode == 8) {
		if (str.getSize())
			str.erase(str.getSize() - 1, str.getSize());
		name.setString(str);
		return true;
	}

	if (event.text.unicode == 13) return false;
	else {
		str += event.text.unicode;
		name.setString(str);
		return true;
	}
}

void loadGamePVP(int n, int xScore, int oScore, sf::Text player1, sf::Text player2, string name, int turn, bool B1[50][50], bool B2[50][50], bool &loadError, iii D[2500], sf::RectangleShape box[50][50], sf::Texture bigXBoxText, sf::Texture bigOBoxText) {
	stringstream str;
	str << "Data/PVP/" << name << ".txt";
	string fileName = str.str();

	ifstream fileIn(fileName.c_str());

	if (fileIn.good() != 1) {
		loadError = true;
		return;
	}
	if (fileIn.is_open()) {
		fileIn >> n;
		//cout << n << endl;
		fileIn >> xScore >> oScore;
		//cout << xScore << " " << oScore << endl;

		char s[100];

		fileIn.ignore();

		fileIn.getline(s, 100);
		string r;
		r = s;
		//cout << r << endl;
		player1.setString(r);

		fileIn.getline(s, 100);
		r = s;
		//cout << r << endl;
		player2.setString(r);

		fileIn >> turn;
		//cout << turn;
		for (int i = 1; i <= turn; i++)
		{
			fileIn >> D[i].first >> D[i].second.first >> D[i].second.second;
			int icon = D[i].first;
			int x = D[i].second.first;
			int y = D[i].second.second;
			if (icon == 1) {
				B1[x][y] = false;
				box[x][y].setTexture(&bigXBoxText);
			}
			else {
				B2[x][y] = false;
				box[x][y].setTexture(&bigOBoxText);
			}
			//S.push(make_pair(icon, make_pair(x, y)));
			//cout << D[i].first << " " << D[i].second.first << " " << D[i].second.second << endl;
		}
	}
}

void loadGamePVC(int n, int xScore, int oScore, sf::Text player, string name, int turn, int playerIcon, bool B1[50][50], bool B2[50][50], bool &loadError, iii D[2500], sf::RectangleShape box[50][50], sf::Texture bigXBoxText, sf::Texture bigOBoxText) {
	stringstream str;
	str << "Data/PVC/" << name << ".txt";
	string fileName = str.str();

	ifstream fileIn(fileName.c_str());

	if (fileIn.good() != 1) {
		loadError = true;
		return;
	}
	if (fileIn.is_open()) {
		fileIn >> n;
		//cout << n << endl;

		fileIn >> xScore >> oScore;
		//cout << xScore << " " << oScore << endl;

		fileIn >> playerIcon;
		//cout << playerIcon << endl;

		char s[100];

		fileIn.ignore();

		fileIn.getline(s, 100);
		string r;
		r = s;
		//cout << r << endl;
		player.setString(r);

		fileIn >> turn;
		//cout << turn;
		for (int i = 1; i <= turn; i++)
		{
			fileIn >> D[i].first >> D[i].second.first >> D[i].second.second;
			int icon = D[i].first;
			int x = D[i].second.first;
			int y = D[i].second.second;
			if (icon == 1) {
				B1[x][y] = false;
				box[x][y].setTexture(&bigXBoxText);
			}
			else {
				B2[x][y] = false;
				box[x][y].setTexture(&bigOBoxText);
			}
			//S.push(make_pair(icon, make_pair(x, y)));
			//cout << D[i].first << " " << D[i].second.first << " " << D[i].second.second << endl;
		}
	}
}

void saveGame(string mode, int n, int xScore, int oScore, int playerIcon, string player1, string player2, string name, int turn, iii D[2500]) {
	stringstream str;
	
	str << "Data/" << mode << "/" << name << ".txt";
	string fileName = str.str();

	fstream fileOut(fileName.c_str());
	if (fileOut.good() == 1) fileOut.clear();

	fileOut << n << endl;
	fileOut << xScore << " " << oScore << endl;

	if (mode == "PVP")
		fileOut << player1 << endl << player2 << endl;
	else
		fileOut << playerIcon << endl << player1 << endl;
	fileOut << turn << endl;
	for (int i = 1; i <= turn; i++)
		fileOut << D[i].first << " " << D[i].second.first << " " << D[i].second.second << endl;
	fileOut << 0;
}