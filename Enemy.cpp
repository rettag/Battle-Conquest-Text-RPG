#include "Enemy.h"

Enemy::Enemy(int round) {
	health = (rand() % round) * 2;
	health += 1;
	defense = (rand() % round) * 2;
	defense += 1;
	attack = (rand() % round) * 2;
	attack += 1;
}

int Enemy::getHealth() {
	return health;
}

int Enemy::getAttack() {
	return attack;
}

int Enemy::getDefense() {
	return defense;
}

void Enemy::setHealth(int setHealth) {
	health = setHealth;
}

void Enemy::setAttack(int setAttack) {
	attack = setAttack;
}

void Enemy::setDefense(int setDefense) {
	defense = setDefense;
}
