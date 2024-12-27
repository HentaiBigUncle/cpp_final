#include "BattleSystem.h"
#include "Skill.h"
#include "Item.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void battle(Player& player) {
    srand(time(NULL));
    Enemy enemy("Goblin", 50, 10);
    cout << "A wild " << enemy.name << " appears!" << endl;
    enemy.showStats();

    // ���a��¦�����[�W�˳ƥ[��
    int totalAttack = player.getTotalAttack();

    while (player.hp > 0 && enemy.hp > 0) {
        cout << "Choose an action: 1. Attack 2. Defend 3. Use Item 4. Use Skill" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: { // ���q����
            cout << "You attacked the enemy!" << endl;
            enemy.hp -= totalAttack;
            cout << "Enemy HP is now: " << enemy.hp << endl;

            if (enemy.hp <= 0) {
                cout << "You defeated the " << enemy.name << "!" << endl;
                player.levelUp();
                return;
            }
            break;
        }
        case 2: { // ���m
            cout << "You defended against the enemy's attack!" << endl;
            player.defend(enemy);
            break;
        }
        case 3: { // �ϥιD��
            player.useItem(enemy);
            break;
        }
        case 4: { // �ϥΧޯ�
            player.useSkill(enemy);
            break;
        }
        default:
            cout << "Invalid action! The enemy attacks you!" << endl;
        }

        // �ĤH����
        if (enemy.hp > 0) {
            enemy.attackPlayer(player);
        }
    }
}
