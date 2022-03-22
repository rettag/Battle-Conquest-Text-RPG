#pragma once
#include "Player.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class Game {
public:
	Game();

	void Titlemenu();
	void Clearmenu();
	void Stats();

	int getRound();
	bool getPlaying();
	bool getWonLastRound();
	void setWonRound(bool set);
	void addRound();
	void PlayRound();
	int SelectMove();

	void InStore();

	int getCoins();

	


private:

	bool isPlaying = true;
	int round;
	Player hero;
	Store store;
	bool won_last_round = false;
};
