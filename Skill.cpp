#include "Skill.h"
#include <iostream>

using namespace std;

void displaySkills() {
    cout << "Available Skills:" << endl;
    cout << "1. Fireball (Deal 30 magic damage)\n";
    cout << "2. Shield Bash (Deal 20 damage and reduce enemy attack by 5)\n";
    cout << "3. Heal (Restore 20 HP)\n";
}

void useSkill(Player& player, Enemy& enemy, int skillChoice) {
    switch (skillChoice) {
    case 1: // Fireball
        cout << "You cast Fireball!" << endl;
        enemy.hp -= 30;
        break;
    case 2: // Shield Bash
        cout << "You used Shield Bash!" << endl;
        enemy.hp -= 20;
        enemy.attack = max(0, enemy.attack - 5);
        break;
    case 3: // Heal
        cout << "You used Heal!" << endl;
        player.hp = min(player.hp + 20, player.maxHp);
        break;
    default:
        cout << "Invalid skill choice!" << endl;
    }
}
