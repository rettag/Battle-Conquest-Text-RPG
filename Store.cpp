#include "Store.h"

Store::Store() {
	Weapons.push_back(Weapon("WoodSword", 1));
	Weapons.push_back(Weapon("SlingShot", 2));
	Weapons.push_back(Weapon("SpitBall", 3));
	Weapons.push_back(Weapon("RazorBlade", 5));
	Weapons.push_back(Weapon("RubySword", 8));
	Weapons.push_back(Weapon("Glock", 10));
	Weapons.push_back(Weapon("SteelAxe", 15));
	Weapons.push_back(Weapon("PointySpear", 20));
	Weapons.push_back(Weapon("YourMama", 30));

	WeaponPrice.push_back(100);
	WeaponPrice.push_back(300);
	WeaponPrice.push_back(400);
	WeaponPrice.push_back(700);
	WeaponPrice.push_back(1000);
	WeaponPrice.push_back(1500);
	WeaponPrice.push_back(2500);
	WeaponPrice.push_back(4000);
	WeaponPrice.push_back(7000);

	Armors.push_back(Armor("Cotten", 1));
	Armors.push_back(Armor("Leather", 2));
	Armors.push_back(Armor("Copper", 3));
	Armors.push_back(Armor("Silver", 5));
	Armors.push_back(Armor("Chainmill", 8));
	Armors.push_back(Armor("Gold", 10));
	Armors.push_back(Armor("Paltium", 15));
	Armors.push_back(Armor("Opal", 20));
	Armors.push_back(Armor("DarkMatter", 30));

	ArmorPrice.push_back(100);
	ArmorPrice.push_back(300);
	ArmorPrice.push_back(400);
	ArmorPrice.push_back(700);
	ArmorPrice.push_back(1000);
	ArmorPrice.push_back(1500);
	ArmorPrice.push_back(2500);
	ArmorPrice.push_back(4000);
	ArmorPrice.push_back(7000);
}

void Store::PrintStore() {
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << "   _____ _______ ____  _____  ______" << endl;
	cout << "  / ____|__   __/ __ \\|  __ \\|  ____" << endl;
	cout << " | (___    | | | |  | | |__) | |__ " << endl;
	cout << "  \\___ \\   | | | |  | |  _  /|  __|" << endl;
	cout << "  ____) |  | | | |__| | | \\ \\| |____" << endl;
	cout << " |_____/   |_|  \\____/|_|  \\_\\______|" << endl;
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl << endl;
	for (int i = 0; i < Weapons.size(); i++) {
		cout << Weapons[i].getWeaponName() << " Attack: +" << Weapons[i].getWeaponAttack() << " Coins: " << WeaponPrice[i] << endl;
	}
	for (int i = 0; i < Armors.size(); i++) {
		cout << Armors[i].getArmorName() << " Defense: +" << Armors[i].getArmorDefense() << " Coins: " << ArmorPrice[i] << endl;
	}
	cout << endl;
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl << endl;
}

string Store::Purchase(string item) {
	for (int i = 0; i < Weapons.size(); i++) {
		if (item == Weapons[i].getWeaponName()) {
			return "Weapon";
		}
	}
	for (int i = 0; i < Armors.size(); i++) {
		if (item == Armors[i].getArmorName()) {
			return "Armor";
		}
	}
	return "Nothing";
}

Weapon Store::getWeapon(string item) {
	for (int i = 0; i < Weapons.size(); i++) {
		if (item == Weapons[i].getWeaponName()) {
			return Weapons[i];
		}
	}
}

int Store::getWeaponPrice(string item) {
	for (int i = 0; i < Weapons.size(); i++) {
		if (item == Weapons[i].getWeaponName()) {
			return WeaponPrice[i];
		}
	}
}

Armor Store::getArmor(string item) {
	for (int i = 0; i < Armors.size(); i++) {
		if (item == Armors[i].getArmorName()) {
			return Armors[i];
		}
	}
}

int Store::getArmorPrice(string item) {
	for (int i = 0; i < Armors.size(); i++) {
		if (item == Armors[i].getArmorName()) {
			return ArmorPrice[i];
		}
	}
}

void Store::removeArmor(string item) {
	for (int i = 0; i < Armors.size(); i++) {
		if (item == Armors[i].getArmorName()) {
			Armors.erase(Armors.begin() + i);
			ArmorPrice.erase(ArmorPrice.begin() + i);
		}
	}
}

void Store::removeWeapon(string item) {
	for (int i = 0; i < Weapons.size(); i++) {
		if (item == Weapons[i].getWeaponName()) {
			Weapons.erase(Weapons.begin() + i);
			WeaponPrice.erase(WeaponPrice.begin() + i);
		}
	}
}