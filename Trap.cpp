#include "Trap.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void triggerTrap(Player& player) {
    srand(time(NULL)); // ��l���H���ƥͦ���
    int trapDamage = rand() % 15 + 5; // �H������ 5 �� 20 �I
    player.hp -= trapDamage;

    cout << "You triggered a trap! You lost " << trapDamage << " HP." << endl;

    if (player.hp <= 0) {
        cout << "You fell unconscious due to the trap!" << endl;
        cout << "Returning to the character selection screen..." << endl;

        // ���m���a���A
        cout << "Choose your role again: 1. Warrior 2. Mage\n";
        int choice;
        cin >> choice;

        player.role = choice == 1 ? "Warrior" : "Mage";
        player.level = 1;
        player.maxHp = choice == 1 ? 100 : 70;
        player.hp = player.maxHp;
        player.maxMp = choice == 1 ? 30 : 50;
        player.mp = player.maxMp;
        player.attack = choice == 1 ? 15 : 10;
        player.defense = choice == 1 ? 10 : 5;
        player.coins = 20;
        player.inventory.clear(); // �M�ŭI�]
        for (int i = 0; i < 3; ++i) {
            player.equippedItems[i] = { "None", "No item equipped", 0, 0 };
        }

        cout << "You have been revived as a " << player.role << "!" << endl;
        cout << "HP: " << player.hp << "/" << player.maxHp << endl;
    }
    else {
        cout << "Your HP is now: " << player.hp << "/" << player.maxHp << endl;
    }
}
