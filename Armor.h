#pragma once
#include <string>

using namespace std;

class Armor {
public:
	Armor();
	Armor(string in_name, int in_defense);

	string getArmorName();
	int getArmorDefense();
	
	void setArmorDefense(int setDefense);
	void setArmorName(string setName);


private:
	int defense;
	string name;
};