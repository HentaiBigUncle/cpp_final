#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "shop.h"
#include "save_load.h"
#include "Trap.h"
#include "BattleSystem.h"
#include "Item.h"
#include "skill.h"
using namespace std;

int main() {
    srand(time(NULL)); // 初始化隨機數生成器

    cout << "Welcome to the RPG game!" << endl;
    cout << "Choose your role: 1. Warrior 2. Mage 3. Archer\n";
    int choice;
    cin >> choice;

    Player player;

    if (choice == 1) {
        player.role = "Warrior";
        player.maxHp = 100;
        player.attack = 15;
        player.defense = 10;
    }
    else if (choice == 2) {
        player.role = "Mage";
        player.maxHp = 70;
        player.attack = 10;
        player.defense = 5;
    }
    else {
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
        cout << "\n--- Main Menu ---" << endl;
        cout << "1. Save Game\n2. Load Game\n3. Display Player Info\n4. Go to Shop\n5. View Inventory\n6. Equip Item\n7. Exit\n";
        int option;
        cin >> option;

        switch (option) {
        case 1:
            saveGame(player);
            break;
        case 2:
            loadGame(player);
            break;
        case 3:
            displayPlayerInfo(player);
            break;
        case 4:
            purchaseItem(player, shopItems);
            break;
        case 5:
            displayInventory(player);
            break;
        case 6:
            equipItemFromInventory(player);
            break;
        case 7:
            cout << "Goodbye!" << endl;
            return 0;
        case 8:
            openChest(player);
            break;
        case 9:
            break;
            battle(player, enemy)
        case 10:
            triggerTrap(player);
            break;
        default:
            cerr << "Invalid option! Please try again." << endl;
        }
    }
}
