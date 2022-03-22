
#include "Armor.h"

Armor::Armor() {
	name = "";
	defense = 0;
}
Armor::Armor(string in_name, int in_defense) {
	name = in_name;
	defense = in_defense;
}

string Armor::getArmorName() {
	return name;
}

int Armor::getArmorDefense() {
	return defense;
}

void Armor::setArmorDefense(int setDefense) {
	defense = setDefense;
}
void Armor::setArmorName(string setName) {
	name = setName;
}

