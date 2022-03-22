#pragma once
#include "Weapon.h"
#include "Armor.h"
#include "Player.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Store {
public:
	Store();
	void PrintStore();
	string Purchase(string item);
	Weapon getWeapon(string item);
	Armor getArmor(string item);
	int getWeaponPrice(string item);
	int getArmorPrice(string item);
	void removeWeapon(string item);
	void removeArmor(string item);

private:
	vector<Weapon> Weapons;
	vector<int> WeaponPrice;
	vector<Armor> Armors;
	vector<int> ArmorPrice;
};