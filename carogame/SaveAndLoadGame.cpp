#include "SaveAndLoadGame.h"
#include "LoadData.h"
#include "Init.h"

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

void loadGamePVP(int &n, int &xScore, int &oScore, sf::Text &player1, sf::Text &player2,const string &name, int &turn, bool B1[50][50], bool B2[50][50], bool &loadError, iii D[2500], sf::RectangleShape box[50][50], sf::Texture &bigXBoxText, sf::Texture &bigOBoxText) {
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

void loadGamePVC(int &n, int &xScore, int &oScore, sf::Text &player,const string &name, int &turn, int &playerIcon, bool B[3][50][50], bool &loadError, iii D[2500], sf::RectangleShape box[50][50], sf::Texture &bigXBoxText, sf::Texture &bigOBoxText) {
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
				B[1][x][y] = false;
				box[x][y].setTexture(&bigXBoxText);
			}
			else {
				B[2][x][y] = false;
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
	cout << fileName << endl;
	ofstream fileOut(fileName.c_str());
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

CaroSave initSave(const sf::Font &font) {
	CaroSave save;
	loadTexture("saveButton.png", save.saveButton.texture);
	initSprite(save.saveButton);
	return save;
}

void initSaveSprite(CaroSave &save , const sf::Font &font) {
	save.nameNoti.setCharacterSize(30);
	save.nameNoti.setFont(font);
	save.nameNoti.setFillColor(sf::Color::White);
	save.nameNoti.setString("");
	save.nameNoti.setPosition((WINDOWN_WIDTH - save.nameNoti.getGlobalBounds().width) / 2, 265);

	save.asking.setCharacterSize(30);
	save.asking.setFont(font);
	save.asking.setFillColor(sf::Color::White);
	save.asking.setString("Enter a name to save:");
	save.asking.setPosition((WINDOWN_WIDTH - save.asking.getGlobalBounds().width) / 2, 144);

	save.name.setCharacterSize(30);
	save.name.setFont(font);
	save.name.setFillColor(sf::Color::Black);
	save.name.setString("| ");
	save.name.setPosition((WINDOWN_WIDTH - save.name.getGlobalBounds().width) / 2, 220);

	save.boxName1.setSize(sf::Vector2f(300, 40));
	save.boxName1.setFillColor(sf::Color::Black);
	save.boxName1.setOutlineThickness(1.0f);
	save.boxName1.setOutlineColor(sf::Color::White);
	save.boxName1.setPosition((WINDOWN_WIDTH - 300) / 2, 216);

	save.boxName2.setSize(sf::Vector2f(300, 40));
	save.boxName2.setFillColor(sf::Color::White);
	save.boxName2.setOutlineThickness(1.0f);
	save.boxName2.setOutlineColor(sf::Color::White);
	save.boxName2.setPosition((WINDOWN_WIDTH - 300) / 2, 216);

	save.saveButton.sprite.setPosition((WINDOWN_WIDTH - save.saveButton.sprite.getGlobalBounds().width) / 2, 550);
	save.saveButton.sprite.setTexture(save.saveButton.texture);

}

CaroLoad initLoad(const sf::Font &font) {
	CaroLoad load;
	loadTexture("loadButton.png", load.loadButton.texture);
	initSprite(load.loadButton);
	return load;
}

void initLoadSprite(CaroLoad &load, const sf::Font &font) {
	load.nameNoti.setCharacterSize(30);
	load.nameNoti.setFont(font);
	load.nameNoti.setFillColor(sf::Color::White);
	load.nameNoti.setString("");
	load.nameNoti.setPosition((WINDOWN_WIDTH - load.nameNoti.getGlobalBounds().width) / 2, 265);

	load.asking.setCharacterSize(30);
	load.asking.setFont(font);
	load.asking.setFillColor(sf::Color::White);
	load.asking.setString("Enter a name to load:");
	load.asking.setPosition((WINDOWN_WIDTH - load.asking.getGlobalBounds().width) / 2, 144);

	load.name.setCharacterSize(30);
	load.name.setFont(font);
	load.name.setFillColor(sf::Color::Black);
	load.name.setString("| ");
	load.name.setPosition((WINDOWN_WIDTH - load.name.getGlobalBounds().width) / 2, 220);

	load.boxName1.setSize(sf::Vector2f(300, 40));
	load.boxName1.setFillColor(sf::Color::Black);
	load.boxName1.setOutlineThickness(1.0f);
	load.boxName1.setOutlineColor(sf::Color::White);
	load.boxName1.setPosition((WINDOWN_WIDTH - 300) / 2, 216);

	load.boxName2.setSize(sf::Vector2f(300, 40));
	load.boxName2.setFillColor(sf::Color::White);
	load.boxName2.setOutlineThickness(1.0f);
	load.boxName2.setOutlineColor(sf::Color::White);
	load.boxName2.setPosition((WINDOWN_WIDTH - 300) / 2, 216);

	load.loadButton.sprite.setPosition((WINDOWN_WIDTH - load.loadButton.sprite.getGlobalBounds().width) / 2, 550);
	load.loadButton.sprite.setTexture(load.loadButton.texture);
}

