#include "BattleSystem.h"
#include <iostream>
#include <map>

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

void battle(Player& player, Enemy& enemy) {
    cout << "A wild " << enemy.name << " appears!" << endl;

    // 显示敌人初始状态
    enemy.showStats();

    int totalAttack = player.getTotalAttack();

    while (player.hp > 0 && enemy.hp > 0) {
        cout << "\n--- Battle Menu ---" << endl;
        cout << "1. Attack\n2. Defend\n3. Use Item\n4. Use Skill\n";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "You attacked the enemy!" << endl;
            enemy.hp -= totalAttack;
            if (enemy.hp <= 0) {
                cout << "You defeated the " << enemy.name << "!" << endl;
                player.levelUp();
                return;
            }
            break;
        case 2:
            cout << "You defended against the enemy's attack!" << endl;
            player.defend(enemy);
            break;
        case 3:
            player.useItem(enemy);
            break;
        case 4:
            player.useSkill(enemy);
            break;
        default:
            cout << "Invalid action! The enemy attacks you!" << endl;
        }

        // 敌人攻击玩家
        if (enemy.hp > 0) {
            enemy.attackPlayer(player);
        }
    }
}
