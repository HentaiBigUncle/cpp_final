#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Item.h"
#include "Enemy.h"
#include "Save_Load.h"
#include "Shop.h"
#include "BattleSystem.h"
#include "skill.h"
#include "BattleSystem.h"
#include "Chest.h"
#include "Trap.h"
using namespace std;
// 商店物品
std::vector<Item> shopItems = {
    {"Sword", "A sharp blade", 10, 0},
    {"Shield", "A sturdy shield", 0, 10},
    {"Potion", "Restores 50 HP", 0, 0}
};



// 初始化敵人
Enemy enemy = {"Goblin", 50, 50};

int main() {
    srand(time(NULL)); // 初始化隨機數生成器
    // 初始化敌人数据库
    initializeEnemyDatabase();
    std::cout << "Welcome to the RPG game!" << std::endl;
    std::cout << "Choose your role: 1. Warrior 2. Mage 3. Archer\n";
    int choice;
    std::cin >> choice;

    Player player;

    if (choice == 1) {
        player.role = "Warrior";
        player.maxHp = 100;
        player.attack = 15;
        player.defense = 10;
    } else if (choice == 2) {
        player.role = "Mage";
        player.maxHp = 70;
        player.attack = 10;
        player.defense = 5;
    } else {
        player.role = "Archer";
        player.maxHp = 80;
        player.attack = 12;
        player.defense = 8;
    }

    player.level = 1;
    player.hp = player.maxHp;
    player.maxMp = 30;
    player.mp = player.maxMp;
    player.coins = 20;

    while (true) {
        std::cout << "\n--- Main Menu ---" << std::endl;
        std::cout << "1. Save Game\n2. Load Game\n3. Display Player Info\n4. Go to Shop\n5. View Inventory\n6. Equip Item\n7. Battle Enemy\n8. Exit\n";
        int option;
        std::cin >> option;

        switch (option) {
        case 1:
            saveGame(player);
            std::cout << "Save game logic here.\n";
            break;
        case 2:
            loadGame(player);
            std::cout << "Load game logic here.\n";
            break;
        case 3:
            displayPlayerInfo(player);
            break;
        case 4:
            purchaseItem(player, shopItems);
            std::cout << "Shop logic here.\n";
            break;
        case 5:
            displayItems(player);
            break;
        case 6:
            equipItemFromInventory(player);
            std::cout << "Equip item logic here.\n";
            break;
        case 8:
            std::cout << "Goodbye!" << std::endl;
            return 0;
        case 7:{//(C++ 不允许从一个分支跳到另一个分支时跨越变量的初始化)
             // 获取敌人数据并创建敌人对象
            EnemyData goblinData = getEnemyData("Goblin");
            Enemy goblin(goblinData.name, goblinData.maxHp, goblinData.attack);
            battle(player, goblin);
            break;}
        case 10:
            triggerTrap(player);
            break;
        case 11:
            openChest(player);
            break;
        default:
            std::cerr << "Invalid option! Please try again." << std::endl;
        }
    }
}
        
