#include "Weapon.h"

Weapon::Weapon() {
	name = "";
	attack = 0;
}
Weapon::Weapon(string in_name, int in_attack) {
	name = in_name;
	attack = in_attack;
}

string Weapon::getWeaponName() {
	return name;
}

int Weapon::getWeaponAttack() {
	return attack;
}

void Weapon::setWeaponAttack(int setAttack) {
	attack = setAttack;
}
void Weapon::setWeaponName(string setName) {
	name = setName;
}