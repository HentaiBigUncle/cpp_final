#include "Item.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <algorithm> // 为了使用 std::min

using namespace std;

// 显示玩家物品
void displayItems(const Player& player) {
    cout << "Available Items in Inventory:" << endl;

    if (player.inventory.empty()) {
        cout << "Your inventory is empty!" << endl;
        return;
    }

    // 遍历并展示物品列表
    for (size_t i = 0; i < player.inventory.size(); ++i) {
        const Item& item = player.inventory[i];
        cout << i + 1 << ". " << item.name 
             << " - " << item.description 
             << " (Attack Bonus: " << item.attackBonus 
             << ", Defense Bonus: " << item.defenseBonus << ")" << endl;
    }
}

void useItem(Player& player, Enemy& enemy) {
    displayItems(player);

    // 获取用户选择
    int itemChoice;
    cout << "Choose an item to use (Enter the number): ";
    cin >> itemChoice;

    // 检查选择是否有效
    if (itemChoice > 0 && itemChoice <= static_cast<int>(player.inventory.size())) {
        Item chosenItem = player.inventory[itemChoice - 1];

        // 应用物品效果
        if (chosenItem.attackBonus > 0) {
            enemy.hp -= chosenItem.attackBonus;
            cout << "You used " << chosenItem.name 
                 << " to attack the enemy! Enemy HP is now: " 
                 << enemy.hp << endl;
        } else if (chosenItem.name == "Potion") {
            player.hp = min(player.hp + 30, player.maxHp);
            cout << "You used " << chosenItem.name 
                 << " and restored 30 HP! Your HP is now: " 
                 << player.hp << endl;
        }

        // 移除使用过的物品
        player.inventory.erase(player.inventory.begin() + itemChoice - 1);
    } else {
        cout << "Invalid item choice!" << endl;
    }
}
