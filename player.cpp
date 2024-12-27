#include "Player.h"
#include <iostream>
#include <algorithm> // for std::min

using namespace std;

// �p���`�����O
int Player::getTotalAttack() const {
    int totalAttack = attack;
    for (const auto& item : equippedItems) {
        totalAttack += item.attackBonus;
    }
    return totalAttack;
}

// �ɯť\��
void Player::levelUp() {
    ++level;
    maxHp += 10;  // ���ɳ̤j��q
    hp = maxHp;   // ��_��q�̤ܳj��
    maxMp += 5;   // ���ɳ̤j�]�O��
    mp = maxMp;   // ��_�]�O��
    attack += 3;  // ���ɧ����O
    defense += 2; // ���ɨ��m�O
    cout << "You leveled up to level " << level << "!" << endl;
    cout << "Max HP: " << maxHp << ", Max MP: " << maxMp
        << ", Attack: " << attack << ", Defense: " << defense << endl;
}

// ���m�\��
void Player::defend(const Enemy& enemy) {
    int damage = max(0, enemy.attack - defense); // �p���K�᪺�ˮ`
    hp -= damage;
    cout << "You defended! Damage taken: " << damage << ". Your HP is now: " << hp << endl;
}

// �ϥιD��
void Player::useItem(Enemy& enemy) {
    displayItems(*this); // ��ܭI�]�����D��
    cout << "Choose an item to use (enter the item number): ";
    int choice;
    cin >> choice;
    useItem(*this, enemy, choice); // �եΥ��� useItem ���
}

// �ϥΧޯ�
void Player::useSkill(Enemy& enemy) {
    displaySkills(); // ��ܧޯ�C��
    cout << "Choose a skill to use (enter the skill number): ";
    int choice;
    cin >> choice;
    useSkill(*this, enemy, choice); // �եΥ��� useSkill ���
}

// ��ܪ��a��T
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
