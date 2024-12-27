#include <iostream>
#include <cstdlib>
#include <ctime>
#include "chest.h"

using namespace std;

// 隨機生成裝備
Item generateRandomItem() {
    vector<Item> possibleItems = {
        {"Sword", "A powerful sword", 10, 0},
        {"Shield", "A sturdy shield", 0, 10},
        {"Helmet", "A helmet to protect your head", 5, 5},
        {"Potion", "Restores 30 HP", 0, 0},
        {"Magic Amulet", "Increases MP by 20", 0, 0}
    };
    int randomIndex = rand() % possibleItems.size();
    return possibleItems[randomIndex];
}

// 開啟寶箱功能實現
void openChest(Player& player) {
    cout << "You found a chest! Opening it..." << endl;

    // 隨機生成獎勵類型
    int rewardType = rand() % 3; // 0: 金錢, 1: 裝備, 2: 恢復 HP
    switch (rewardType) {
    case 0: { // 金錢
        int gold = rand() % 51 + 10; // 隨機獲得 10-60 金幣
        player.coins += gold;
        cout << "You found " << gold << " coins in the chest!" << endl;
        break;
    }
    case 1: { // 裝備
        Item newItem = generateRandomItem();
        player.inventory.push_back(newItem);
        cout << "You found a " << newItem.name << " in the chest!" << endl;
        cout << "Description: " << newItem.description << endl;
        break;
    }
    case 2: { // 恢復 HP
        int healAmount = rand() % 31 + 10; // 隨機恢復 10-40 HP
        player.hp += healAmount;
        cout << "You found a healing potion in the chest! Restored " << healAmount << " HP!" << endl;
        break;
    }
    }
}
