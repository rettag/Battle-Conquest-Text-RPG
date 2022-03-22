#pragma once
#include "Game.h"
#include "windows.h"
using namespace std;

Game::Game() {
	isPlaying = true;
	round = 0;
}

//Title Menu
void Game::Titlemenu() {
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << " ____       _______ _______ _      ______    _____ ____  _   _  ____  _    _ ______  _____ _______" << endl;
	cout << "|  _ \\   /\\|__   __|__   __| |    |  ____|  / ____/ __ \\| \\ | |/ __ \\| |  | |  ____|/ ____|__   __|" << endl;
	cout << "| |_) | /  \\  | |     | |  | |    | |__    | |   | |  | |  \\| | |  | | |  | | |__  | (___    | |" << endl;
	cout << "|  _ < / /\\ \\ | |     | |  | |    |  __|   | |   | |  | | . ` | |  | | |  | |  __|  \\___ \\   | |" << endl;
	cout << "| |_) / ____ \\| |     | |  | |____| |____  | |___| |__| | |\   | |__| | |__| | |____ ____) |  | |" << endl;
	cout << "|____/_/    \\_\\_|     |_|  |______|______|  \\_____\\____/|_| \\_| \\___\\_\\____/|______|_____/   |_|" << endl;
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << "-----------------------------------Created By, Rett Graham----------------------------------------" << endl << endl;
	cout << "                              [1] Start Your Endless Conquest                                     " << endl;
	cout << "                                          [0] Quit                                                " << endl;
}

//Clears Console
void Game::Clearmenu() {
	cout << "\x1B[2J\x1B[H";
}

//Returns if game is still being played
bool Game::getPlaying() {
	return isPlaying;
}

//Prints the Hero's Health, Attack, Defense, Armor, Weapon
void Game::Stats() {
	cout << "----Your Hero's Status----" << endl;
	cout << "Health: " << hero.getHealth() << endl;
	cout << "Attack: " << hero.getAttack() << endl;
	cout << "Defense: " << hero.getDefense() << endl;
	if (hero.getArmor() != "") {
		cout << "Armor: " << hero.getArmor() << endl;
	}
	if (hero.getWeapon() != "") {
		cout << "Weapon: " << hero.getWeapon() << endl;
	}
	cout << "--------------------------" << endl;
}

void Game::addRound() {
	++round;
}

int Game::getRound() {
	return round;
}

void Game::InStore() {
	store.PrintStore();
	cout << endl;
	cout << "Enter an item you wish to buy, if not press [exit] to fight:" << endl;
	string input;
	cin >> input;
	if (input == "exit") {
		return;
	}
	else {
		string object = store.Purchase(input);

		if (object == "Weapon") {
			if (hero.getCoins() >= store.getWeaponPrice(input)) {
				hero.setAttack(hero.getAttack() + store.getWeapon(input).getWeaponAttack() - hero.getWeaponAttack());
				hero.addWeapon(store.getWeapon(input));
				hero.setCoins(hero.getCoins() - store.getWeaponPrice(input));
				PlaySound(L"newitem.wav", NULL, SND_ASYNC);
				cout << "Congrats you bought " << store.getWeapon(input).getWeaponName() << "!" << endl;
				cout << "Attack increased by: " << store.getWeapon(input).getWeaponAttack() << "!" << endl;
				store.removeWeapon(input);
			}
			else {
				cout << "Not enough funds" << endl;
				return;
			}

		}
		else if (object == "Armor") {
			if (hero.getCoins() >= store.getArmorPrice(input)) {
				hero.setDefense(hero.getDefense() + store.getArmor(input).getArmorDefense() - hero.getArmorDefense());
				hero.addArmor(store.getArmor(input));
				hero.setCoins(hero.getCoins() - store.getArmorPrice(input));
				PlaySound(L"newitem.wav", NULL, SND_ASYNC);
				cout << "Congrats you bought " << store.getArmor(input).getArmorName() << "!" << endl;
				cout << "Defense increased by: " << store.getArmor(input).getArmorDefense() << "!" << endl;
				store.removeArmor(input);
			}
			else {
				cout << "Not enough funds" << endl;
				return;
			}
		}
		else {
			cout << "Not an item. Get Ready To Fight." << endl << endl;
		}
		return;
	}
}

int Game::SelectMove() {
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << "-------------------------------------------Select A Move------------------------------------------" << endl << endl;
	cout << "                                            [0] Attack                                            " << endl;
	cout << "                                            [1] Dodge                                             " << endl;
	string move;
	cin >> move;
	while (stoi(move) != 0 && stoi(move) != 1) {
		cout << "That is not a move. Select again" << endl;
		cin >> move;
	}
	return stoi(move);
}

void Game::PlayRound() {
	Enemy boss = Enemy(round);
	int HeroStartHealth = hero.getHealth();
	int HeroStartDefense = hero.getDefense();

	while (hero.getHealth() > 0) {
		cout << "----Enemy Stats----" << endl;
		cout << "Health: " << boss.getHealth() << endl;
		cout << "Attack: " << boss.getAttack() << endl;
		cout << "Defense: " << boss.getDefense() << endl << endl;
		cout << "----Your  Stats----" << endl;
		cout << "Health: " << hero.getHealth() << endl;
		cout << "Attack: " << hero.getAttack() << endl;
		cout << "Defense: " << hero.getDefense() << endl << endl;
		
		
		int move = SelectMove();
		Clearmenu();
		PlaySound(L"Battle.wav", NULL, SND_ASYNC);
		if (move == 0) {
			//Hero Attacking
			int possibleAttack = rand() % 101;
			if (possibleAttack < 95) {
				cout << "You Attacked! ";
				if (boss.getDefense() - hero.getAttack() < 0) {
					int leftover = -1 * (boss.getDefense() - hero.getAttack());
					boss.setDefense(0);
					boss.setHealth(boss.getHealth() - leftover);
				}
				else if (boss.getDefense() > 0) {
					boss.setDefense(boss.getDefense() - hero.getAttack());
				}
				else {
					boss.setHealth(boss.getHealth() - hero.getAttack());
				}
				cout << "Damage: " << hero.getAttack() << endl << endl;
			}
			else {
				cout << "You Missed Your Attack!" << endl << endl;
			}
			
			if (boss.getHealth() <= 0) {
				cout << "Enemy Was Defeated! Great Job Warrior!" << endl;
				hero.setCoins(hero.getCoins() + (100 * (round + round)));
				cout << "You recevied: " << (100 * (round + round)) << " coins!" << endl;
				hero.setHealth(HeroStartHealth);
				hero.setDefense(HeroStartDefense);
				setWonRound(true);
				break;
			}
			//Boss Attacking
			possibleAttack = rand() % 101;
			if (possibleAttack < 80) {
				cout << "Enemy Attacked! ";
				if (hero.getDefense() - boss.getAttack() < 0) {
					int leftover = -1 * (hero.getDefense() - boss.getAttack());
					hero.setDefense(0);
					hero.setHealth(hero.getHealth() - leftover);	
				}
				else if (hero.getDefense() > 0) {
					hero.setDefense(hero.getDefense() - boss.getAttack());
				}
				else {
					hero.setHealth(hero.getHealth() - boss.getAttack());
				}
				cout << "Damage: " << boss.getAttack() << endl << endl;
			}
			else {
				cout << "Enemy Missed Its Attack!" << endl << endl;
			}
		}
		else {
			cout << "You Dodged Enemy's Attack!" << endl << endl;
		}

		if (hero.getHealth() < 0) {
			cout << "Enemy has defeated you!" << endl << endl;
			hero.setHealth(HeroStartHealth);
			hero.setDefense(HeroStartDefense);
			isPlaying = false;
			break;
		}
	}
}

bool Game::getWonLastRound() {
	return won_last_round;
}

void Game::setWonRound(bool set) {
	won_last_round = set;
}

int Game::getCoins() {
	return hero.getCoins();
}