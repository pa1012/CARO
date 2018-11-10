#include "Init.h";
#include "LoadData.h";
//#include "DataStruct.h";

using namespace std;

CaroOption initOption();

void initOptionSprite(CaroOption &option, sf::Font &font);

void drawOption(sf::RenderWindow &window, CaroOption &option, bool pcstate,bool enter,bool chooseSizeSucceed, bool chooseIconSucceed);

int enterSizeOfGame(const sf::Event &event, sf::Text &input);