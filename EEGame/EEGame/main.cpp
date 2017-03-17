///////////////////////////////////////////////////////////
// EEGame TFG Research Project for Emotiv Insight - 2017 //
// Carlos Aniorte Llanes                                 //
// carlos.aniortellanes@gmail.com                        //
///////////////////////////////////////////////////////////
#include <iostream>
#include "Game.h"

using namespace std;

int main(int argc, char *argv[]){

	Game* gameInstance = new Game;
	
	gameInstance->init();
	gameInstance->run();
	gameInstance->clean();

	return 0;
}