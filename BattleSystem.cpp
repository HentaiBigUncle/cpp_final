#include "BattleSystem.h"
#include <iostream>
#include <map>
#include "skill.h"
#include "item.h"
using namespace std;

// 定义静态敌人数据库
static map<string, EnemyData> enemyDatabase;

void initializeEnemyDatabase() {
    enemyDatabase["Goblin"] = {"Goblin", 50, 10};
    enemyDatabase["Orc"] = {"Orc", 80, 15};
    enemyDatabase["Dragon"] = {"Dragon", 200, 30};
    // 添加更多敌人数据...
}

EnemyData getEnemyData(const string& enemyName) {
    if (enemyDatabase.find(enemyName) != enemyDatabase.end()) {
        return enemyDatabase[enemyName];
    } else {
        cerr << "Error: Enemy " << enemyName << " not found in database!" << endl;
        return {"Unknown", 0, 0};
    }
}

void displayBattleStatus(const Player& player, const Enemy& enemy) {
    cout << "\n--- Battle Status ---" << endl;
    cout << "Player HP: " << player.hp << "/" << player.maxHp
         << " | Attack: " << player.getTotalAttack() << endl;
    cout << "Enemy (" << enemy.name << ") HP: " << enemy.hp 
         << " | Attack: " << enemy.attack << endl;
    cout << "-----------------------------------" << endl;
}

void battle(Player& player, Enemy& enemy) {
    cout << "A wild " << enemy.name << " appears!" << endl;

    // 显示敌人初始状态
    enemy.showStats();

    while (player.hp > 0 && enemy.hp > 0) {
        cout << "\n--- Battle Menu ---" << endl;
        cout << "1. Attack\n2. Defend\n3. Use Item\n4. Use Skill\n";
        cout << "Your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: // 普通攻击
            cout << "You attacked the enemy!" << endl;
            enemy.hp -= player.getTotalAttack();
            cout << "Enemy HP: " << enemy.hp  << endl;
            break;

        case 2: // 防御
            cout << "You defended against the enemy's attack!" << endl;
            player.defend(enemy);
            break;

        case 3: // 使用道具
           useItem(player,enemy);
           break;
        case 4: { // 使用技能
            useSkill(player,enemy);
            break;
        }

        default: // 无效选择
            cout << "Invalid action! The enemy attacks you!" << endl;
        }

        // 检查敌人是否已被击败
        if (enemy.hp <= 0) {
            cout << "You defeated the " << enemy.name << "!" << endl;
            player.levelUp();
            return;
        }

        // 敌人攻击玩家
        cout << enemy.name << " attacks you!" << endl;
        enemy.attackPlayer(player);

        // 显示双方状态
        cout << "\n--- Current Status ---" << endl;
        cout << "Player HP: " << player.hp << "/" << player.maxHp
             << ", MP: " << player.mp << "/" << player.maxMp << endl;
        cout << enemy.name << " HP: " << enemy.hp  << endl;
    }

    // 检查战斗结果
    if (player.hp <= 0) {
        cout << "You have been defeated by the " << enemy.name << "!" << endl;
    }
}
