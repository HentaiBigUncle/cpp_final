#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <iostream>
using namespace std;

class Enemy {
public:
    string name;
    int hp;
    int attack;

    Enemy(string enemyName, int enemyHP, int enemyAttack);
    void showStats();
};

#endif // ENEMY_H
