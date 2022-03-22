#pragma once
#include "Player.h"
#include "Store.h"
#include "Weapon.h"
#include "Armor.h"

class Enemy {
public:
	Enemy(int round);

	int getHealth();
	int getAttack();
	int getDefense();

	void setHealth(int setHealth);
	void setAttack(int setAttack);
	void setDefense(int setDefense);

private:
	int health;
	int attack;
	int defense;
};