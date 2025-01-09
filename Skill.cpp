#include "Skill.h"
#include <iostream>
#include <algorithm> // for std::min and std::max

using namespace std;

// 显示技能列表
void displaySkills() {
    cout << "Available Skills:" << endl;
    cout << "1. Fireball (Deal 30 magic damage, Cost: 10 MP)\n";
    cout << "2. Shield Bash (Deal 20 damage and reduce enemy attack by 5, Cost: 15 MP)\n";
    cout << "3. Heal (Restore 20 HP, Cost: 20 MP)\n";
}

// 使用技能
void useSkill(Player& player, Enemy& enemy) {
    displaySkills();

    cout << "Choose a skill to use: ";
    int skillChoice;
    cin >> skillChoice;

    int mpCost = 0;

    // 检查技能选择并设置 MP 消耗
    switch (skillChoice) {
    case 1: // Fireball
        mpCost = 10;
        break;
    case 2: // Shield Bash
        mpCost = 15;
        break;
    case 3: // Heal
        mpCost = 20;
        break;
    default:
        cout << "Invalid skill choice!" << endl;
        return;
    }

    // 检查 MP 是否足够
    if (player.mp < mpCost) {
        cout << "Not enough MP to use this skill!" << endl;
        return;
    }

    // 消耗 MP
    player.mp -= mpCost;

    // 使用技能效果
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
    }

    // 显示技能使用后的状态
    cout << "Skill used! Remaining MP: " << player.mp << "/" << player.maxMp << endl;
}
