#include "Enemy.h"
#include "Player.h"
#include <iostream>
using namespace std;

Enemy::Enemy(const std::string& name, int hp, int attack)
    : name(name), hp(hp), attack(attack) {}

void Enemy::showStats() const {
    cout << "Enemy: " << name << "\nHP: " << hp << "\nAttack: " << attack << endl;
}

void Enemy::attackPlayer(Player& player) {
    player.hp -= attack;
    cout << name << " attacks! Player's HP is now: " << player.hp << endl;
}
