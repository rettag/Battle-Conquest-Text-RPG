#pragma once
#include <string>

using namespace std;

class Weapon {
public:
	Weapon();
	Weapon(string in_name, int in_attack);

	string getWeaponName();
	int getWeaponAttack();

	void setWeaponAttack(int setAttack);
	void setWeaponName(string setName);

private:
	int attack;
	string name;
};