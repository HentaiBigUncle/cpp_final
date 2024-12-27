#include "Enemy.h"

// Constructor
Enemy::Enemy(string enemyName, int enemyHP, int enemyAttack)
    : name(enemyName), hp(enemyHP), attack(enemyAttack) {}

// Display enemy stats
void Enemy::showStats() {
    cout << "Enemy: " << name << ", HP: " << hp << ", Attack: " << attack << endl;
}
