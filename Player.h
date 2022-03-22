#pragma once
#include "Store.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Armor.h"

using namespace std;

class Player {
public:
	Player();

	int getHealth();
	int getAttack();
	int getDefense();
	int getCoins();
	int getWeaponAttack();
	int getArmorDefense();
	string getArmor();
	string getWeapon();

	void addArmor(Armor armor_in);
	void addWeapon(Weapon weapon_in);

	void setHealth(int setHealth);
	void setAttack(int setAttack);
	void setDefense(int setDefense);
	void setCoins(int setCoins);

private:
	int base_attack = 1;
	int base_health = 10;
	int base_defense = 0;
	int health;
	int attack;
	int defense;
	int coins;
	
	Armor armor;
	Weapon weapon;
};
