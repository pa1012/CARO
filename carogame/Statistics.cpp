#include "Statistics.h"

void saveView(string mode, int n, int xScore, int oScore, int playerIcon, string player1, string player2, int number, int turn, iii D[2500]) {
	stringstream str;

	str << "Data/Statistics" << mode << "/" << number << ".txt";
	string fileName = str.str();

	fstream fileOut(fileName.c_str());
	
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

void updatePVC(int winer , int n, int xScore, int oScore, int playerIcon, string player1, string player2, int number, int turn, iii D[2500]) {
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

void updatePVP(int winer, int n, int xScore, int oScore, int playerIcon, string player1, string player2, int number, int turn, iii D[2500]) {
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