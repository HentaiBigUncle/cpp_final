#include "Player.h"
#include <iostream>
#include <algorithm> // for std::min

using namespace std;

// 計算總攻擊力
int Player::getTotalAttack() const {
    int totalAttack = attack;
    for (const auto& item : equippedItems) {
        totalAttack += item.attackBonus;
    }
    return totalAttack;
}

// 升級功能
void Player::levelUp() {
    ++level;
    maxHp += 10;  // 提升最大血量
    hp = maxHp;   // 恢復血量至最大值
    maxMp += 5;   // 提升最大魔力值
    mp = maxMp;   // 恢復魔力值
    attack += 3;  // 提升攻擊力
    defense += 2; // 提升防禦力
    cout << "You leveled up to level " << level << "!" << endl;
    cout << "Max HP: " << maxHp << ", Max MP: " << maxMp
        << ", Attack: " << attack << ", Defense: " << defense << endl;
}

// 防禦功能
void Player::defend(const Enemy& enemy) {
    int damage = max(0, enemy.attack - defense); // 計算減免後的傷害
    hp -= damage;
    cout << "You defended! Damage taken: " << damage << ". Your HP is now: " << hp << endl;
}

// 使用道具
void Player::useItem(Enemy& enemy) {
    displayItems(*this); // 顯示背包內的道具
    cout << "Choose an item to use (enter the item number): ";
    int choice;
    cin >> choice;
    useItem(*this, enemy, choice); // 調用全局 useItem 函數
}

// 使用技能
void Player::useSkill(Enemy& enemy) {
    displaySkills(); // 顯示技能列表
    cout << "Choose a skill to use (enter the skill number): ";
    int choice;
    cin >> choice;
    useSkill(*this, enemy, choice); // 調用全局 useSkill 函數
}

// 顯示玩家資訊
void displayPlayerInfo(const Player& player) {
    cout << "Role: " << player.role << "\n"
        << "Level: " << player.level << "\n"
        << "HP: " << player.hp << "/" << player.maxHp << "\n"
        << "MP: " << player.mp << "/" << player.maxMp << "\n"
        << "Attack: " << player.getTotalAttack() << "\n"
        << "Defense: " << player.defense << "\n"
        << "Coins: " << player.coins << endl;
    cout << "Equipped Items:" << endl;
    for (const auto& item : player.equippedItems) {
        cout << "- " << item.name << " (Attack: " << item.attackBonus
            << ", Defense: " << item.defenseBonus << ")" << endl;
    }
}
void Player::resetPlayer() {
    cout << "Returning to the character selection screen..." << endl;
    cout << "Choose your role: 1. Warrior 2. Mage 3. Archer\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        role = "Warrior";
        maxHp = 100;
        attack = 15;
        defense = 10;
    }
    else if (choice == 2) {
        role = "Mage";
        maxHp = 70;
        attack = 10;
        defense = 5;
    }
    else {
        role = "Archer";
        maxHp = 80;
        attack = 12;
        defense = 8;
    }

    level = 1;
    hp = maxHp;
    maxMp = 30;
    mp = maxMp;
    coins = 20;
    inventory.clear();
    for (int i = 0; i < 3; ++i) {
        equippedItems[i] = { "None", "No item equipped", 0, 0 };
    }
    cout << "You are now a " << role << "!" << endl;
}
