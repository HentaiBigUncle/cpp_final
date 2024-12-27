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

    // 玩家基礎攻擊加上裝備加成
    int totalAttack = player.getTotalAttack();

    while (player.hp > 0 && enemy.hp > 0) {
        cout << "Choose an action: 1. Attack 2. Defend 3. Use Item 4. Use Skill" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: { // 普通攻擊
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
        case 2: { // 防禦
            cout << "You defended against the enemy's attack!" << endl;
            player.defend(enemy);
            break;
        }
        case 3: { // 使用道具
            player.useItem(enemy);
            break;
        }
        case 4: { // 使用技能
            player.useSkill(enemy);
            break;
        }
        default:
            cout << "Invalid action! The enemy attacks you!" << endl;
        }

        // 敵人反擊
        if (enemy.hp > 0) {
            enemy.attackPlayer(player);
        }
    }
}
