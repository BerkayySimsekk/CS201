#include "PandemicSimulator.h"

#include <iostream>

int main() {
 PandemicSimulator ps("cityGridFile.txt");

ps.displayCityState(0);
cout << endl;

ps.displayCityState(1);
cout << endl;

ps.displayCityState(2);
cout << endl;

ps.simulateBlock(0, 0);
ps.simulateBlock(4, 4);
ps.simulateBlock(0, 4);
ps.simulateBlock(1, 2);
ps.simulateBlock(3, 1);
cout << endl;

ps.displayCityState(3);
cout << endl;

ps.displayCityState(4);
cout << endl;

ps.displayCityState(5);
cout << endl;

ps.simulatePandemic();

return 0;

}
