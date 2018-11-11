#include "Statistics.h"
#include "LoadData.h"
#include "Init.h"

void saveView(string mode, int n, int xScore, int oScore, int playerIcon, string player1, string player2, int number, int turn, iii D[2500]) {
	stringstream str;

	str << "Data/Statistics/" << mode << "/" << number << ".txt";
	string fileName = str.str();
	cout << fileName << endl;
	ofstream fileOut(fileName.c_str());
	
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

void updatePVC(int winer , int n, int xScore, int oScore, int playerIcon, string player1, string player2, int turn, iii D[2500]) {
	ifstream fileIn("Data/Statistics/PVC/summary.txt");
	int countGame, numberOfPlayerWin, numberOfComputerWin, numberOfDraw;
	fileIn >> countGame;
	fileIn >> numberOfPlayerWin;
	fileIn >> numberOfComputerWin;
	fileIn >> numberOfDraw;
	//cout<< countGame << " " << numberOfPlayerWin << " " << numberOfComputerWin << " " << numberOfDraw<<endl;
	countGame++;
	if (winer == 3) numberOfDraw++;
	else
		if (winer == playerIcon) numberOfPlayerWin++;
		else numberOfComputerWin++;
	//cout << countGame << " " << numberOfWinX << " " << numberOfWinO << " " << numberOfDraw<<endl;
	ofstream fileOut("Data/Statistics/PVC/summary.txt");
	fileOut.clear();
	fileOut << countGame << " " << numberOfPlayerWin << " " << numberOfComputerWin << " " << numberOfDraw;
	saveView("PVC",n,xScore,oScore,playerIcon,player1,player2,countGame,turn,D);
}

void updatePVP(int winer, int n, int xScore, int oScore, int playerIcon, string player1, string player2, int turn, iii D[2500]) {
	ifstream fileIn("Data/Statistics/PVP/summary.txt");
	int countGame, numberOfWinX, numberOfWinO, numberOfDraw;
	fileIn >> countGame;
	fileIn >> numberOfWinX;
	fileIn >> numberOfWinO;
	fileIn >> numberOfDraw;

	countGame++;
	if (winer == 1) numberOfWinX++;
	if (winer == 2) numberOfWinO++;
	if (winer == 3) numberOfDraw++;

	ofstream fileOut("Data/Statistics/PVP/summary.txt");
	fileOut.clear();
	fileOut << countGame << " " << numberOfWinX << " " << numberOfWinO << " " << numberOfDraw;
	saveView("PVP", n, xScore, oScore, playerIcon, player1, player2, countGame, turn, D);
}

int Number(sf::Event event, sf::Text &number) {
	sf::String str = number.getString();
	int num = 0;
	if (str == "|") {
		str = "";
		num = 0;
	}
	else {
		for (int i = 0; i < str.getSize(); i++)
			num = num * 10 + str[i] - '0';
	}
	if (event.text.unicode == 8) {
		if (str.getSize())
			str.erase(str.getSize() - 1, str.getSize());
		number.setString(str);
		//number.setPosition((screenWidth - enterNumber.getGlobalBounds().width) / 2, 450);
		num /= 10;
		return num;
	}
	if (event.text.unicode != 13)
	{
		str += event.text.unicode;
		number.setString(str);
		//number.setPosition((screenWidth - enterNumber.getGlobalBounds().width) / 2, 450);
		num = num * 10 + event.text.unicode - '0';
		return num;
	}
	return num;
}

CaroStatistic initStatistic() {
	CaroStatistic stt;
	loadTexture("enternum1.png",stt.numberBox2.texture);
	initSprite(stt.numberBox2);
	return stt;
}

void initStatisticSprite(CaroStatistic &stt,int x,int &GAMES,const sf::Font &font, bool &chooseNumberSucceed) {
	chooseNumberSucceed = false;
	int countGame, numberOfWinX, numberOfWinO, numberOfDraw, numberOfPlayerWin, numberOfComputerWin;
	if (x == 0) {
		ifstream fileIn("Data/Statistics/PVP/summary.txt");
		fileIn >> countGame;
		fileIn >> numberOfWinX;
		fileIn >> numberOfWinO;
		fileIn >> numberOfDraw;
		GAMES = countGame;
	}
	else {
		ifstream fileIn("Data/Statistics/PVC/summary.txt");
		fileIn >> countGame;
		fileIn >> numberOfPlayerWin;
		fileIn >> numberOfComputerWin;
		fileIn >> numberOfDraw;
		GAMES = countGame;
	}
	stringstream str;

	str << countGame;
	stt.numberOfGame.setFont(font);
	stt.numberOfGame.setFillColor(sf::Color::White);
	stt.numberOfGame.setCharacterSize(30);
	stt.numberOfGame.setString("Games: " + str.str());
	stt.numberOfGame.setPosition((WINDOWN_WIDTH - stt.numberOfGame.getGlobalBounds().width) / 2, 50);

	str.str("");

	if (x == 1) {
		str << numberOfPlayerWin;
		stt.xWin.setString("Player Win: " + str.str());
	}
	else {
		str << numberOfWinX;
		stt.xWin.setString("X WIN: " + str.str());
	}
	stt.xWin.setFont(font);
	stt.xWin.setFillColor(sf::Color::White);
	stt.xWin.setCharacterSize(30);
	stt.xWin.setPosition((WINDOWN_WIDTH - stt.xWin.getGlobalBounds().width) / 2, 130);

	str.str("");
	if (x == 1) {
		str << numberOfComputerWin;
		stt.oWin.setString("Computer Win: " + str.str());
	}
	else {
		str << numberOfWinO;
		stt.oWin.setString("O WIN: " + str.str());
	}
	stt.oWin.setFont(font);
	stt.oWin.setFillColor(sf::Color::White);
	stt.oWin.setCharacterSize(30);
	stt.oWin.setPosition((WINDOWN_WIDTH - stt.oWin.getGlobalBounds().width) / 2, 210);

	str.str("");
	str << numberOfDraw;
	stt.draw.setFont(font);
	stt.draw.setFillColor(sf::Color::White);
	stt.draw.setCharacterSize(30);
	stt.draw.setString("DRAW: " + str.str());
	stt.draw.setPosition((WINDOWN_WIDTH - stt.draw.getGlobalBounds().width) / 2, 290);


	//enterNumber.setPosition((screenWidth - enterNumber.getGlobalBounds().width) / 2, 460);
	stt.enterNumber.setFont(font);
	stt.enterNumber.setFillColor(sf::Color::Black);
	stt.enterNumber.setCharacterSize(35);
	stt.enterNumber.setString("|");
	stt.enterNumber.setPosition((WINDOWN_WIDTH - stt.enterNumber.getGlobalBounds().width) / 2 - 1, 460);

	stt.numberBox2.sprite.setPosition((WINDOWN_WIDTH - stt.numberBox2.sprite.getLocalBounds().width) / 2, 460);

}

void InitForViewPVC(int num,bool &pcstate,int &sizeOfGame,int &xScore, int &oScore,int &playerIcon,sf::Text &player,int & turn,sf::RectangleShape box[50][50],iii D[2500],bool B[3][50][50],sf::Texture &bigXBoxText , sf::Texture &bigOBoxText) {
	pcstate = true;
	stringstream str;
	str << "Data/Statistics/PVC/" << num << ".txt";
	ifstream fileIn(str.str().c_str());

	if (fileIn.is_open()) {
		fileIn >> sizeOfGame;

		fileIn >> xScore >> oScore;

		fileIn >> playerIcon;

		char s[100];

		fileIn.ignore();

		fileIn.getline(s, 100);
		string r;
		r = s;
		player.setString(r);

		fileIn >> turn;
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

void InitForViewPVP(int num, bool &pcstate, int &sizeOfGame, int &xScore, int &oScore, int &playerIcon, sf::Text &player1,sf::Text &player2, int & turn, sf::RectangleShape box[50][50], iii D[2500], bool B1[50][50],bool B2[50][50], sf::Texture &bigXBoxText, sf::Texture &bigOBoxText) {
	pcstate = false;
	stringstream str;
	str << "Data/Statistics/PVP/" << num << ".txt";
	ifstream fileIn(str.str().c_str());

	if (fileIn.is_open()) {
		fileIn >> sizeOfGame;
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
		}
	}

}