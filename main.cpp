#include "Player.h"
#include "Store.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Armor.h"
#include "Game.h"

#include "windows.h"

#include <iostream>
using namespace std;

#include "Game.h"

int main() {
	Game game;

	string input;
	while (true) {
		game.Titlemenu();
		cin >> input;
		if (stoi(input) != 0 && stoi(input) != 1) {
			cout << "Invalid Choice. Please choose a different option" << endl;
		}
		else if (stoi(input) == 1) {
			break;
		}
		else {
			cout << "-----------------------------------------Goodbye!-------------------------------------------------" << endl;
			return 0;
		}
	}
	game.Clearmenu();
	cout << "You Enter The Area. Get Ready To Fight The Waves Warrior!" << endl << endl;

	while (game.getPlaying()) {
		cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
		cout << "                                     Coin Balance: " << game.getCoins() <<  "                     " << endl;
		cout << "---------------------------------------- Options--------------------------------------------------" << endl << endl;
		cout << "                                        [0] Store                                                 " << endl;
		cout << "                                        [1] Battle                                                " << endl << endl;

		string input;
		cin >> input;
		while (stoi(input) != 1 && stoi(input) != 0) {
			cout << "Incorrect input. Please try again." << endl;
			cin >> input;
		}
		game.Clearmenu();
		if (stoi(input) == 0) {
			game.InStore();
			cout << "Welcome back from the store. Get ready to battle!" << endl << endl;
		}
		else {
			game.Clearmenu();
			game.addRound();
			bool play = PlaySound(L"background.wav", NULL, SND_ASYNC);
			cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
			cout << "------------------------------------------Round " << game.getRound() << "-------------------------------------------------" << endl;
			cout << "------------------------------------------Battle!-------------------------------------------------" << endl << endl;
			game.PlayRound();

			if (game.getWonLastRound()) {
				PlaySound(L"win.wav", NULL, SND_ASYNC);
				cout << endl;
				cout << "Round " << game.getRound() << " Won!" << endl;
				cout << "Ready For The Next Round?" << endl << endl;
				game.setWonRound(false);
			}
			else {
				break;
			}
		}

	}

	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << "   _____          __  __ ______    ______      ________ _____  _ " << endl;
	cout << "  / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\| |" << endl;
	cout << " | |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) | |" << endl;
	cout << " | | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  /| |" << endl;
	cout << " | |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\|_|" << endl;
	cout << "  \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_(_)" << endl;
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl << endl;
	cout << "Thanks for playing! You survived " << game.getRound() << " Rounds" << endl << endl;
	game.Stats();
	PlaySound(L"win.wav", NULL, SND_SYNC);

	return 0;
}