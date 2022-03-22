#include "Player.h"

Player::Player() {
	health = 10;
	attack = 3;
	defense = 1;
	coins = 100;
}

void Player::setHealth(int setHealth) {
	health = setHealth;
}

void Player::setAttack(int setAttack) {
	attack = setAttack;
}

void Player::setDefense(int setDefense) {
	defense = setDefense;
}

void Player::setCoins(int setCoins) {
	coins = setCoins;
}

int Player::getHealth() {
	return health;
}

int Player::getAttack() {
	return attack;
}

int Player::getDefense() {
	return defense;
}

int Player::getCoins() {
	return coins;
}

string Player::getArmor() {
	return armor.getArmorName();
}

string Player::getWeapon() {
	return weapon.getWeaponName();
}

void Player::addArmor(Armor armor_in) {
	armor.setArmorDefense(armor_in.getArmorDefense());
	armor.setArmorName(armor_in.getArmorName());
}

void Player::addWeapon(Weapon weapon_in) {
	weapon.setWeaponAttack(weapon_in.getWeaponAttack());
	weapon.setWeaponName(weapon_in.getWeaponName());
}

int Player::getWeaponAttack() {
	return weapon.getWeaponAttack();
}

int Player::getArmorDefense() {
	return armor.getArmorDefense();
}
