#include <iostream>
#include <cstdlib>
#include <ctime>
#include "chest.h"

using namespace std;

// �H���ͦ��˳�
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

// �}���_�c�\���{
void openChest(Player& player) {
    cout << "You found a chest! Opening it..." << endl;

    // �H���ͦ����y����
    int rewardType = rand() % 3; // 0: ����, 1: �˳�, 2: ��_ HP
    switch (rewardType) {
    case 0: { // ����
        int gold = rand() % 51 + 10; // �H����o 10-60 ����
        player.coins += gold;
        cout << "You found " << gold << " coins in the chest!" << endl;
        break;
    }
    case 1: { // �˳�
        Item newItem = generateRandomItem();
        player.inventory.push_back(newItem);
        cout << "You found a " << newItem.name << " in the chest!" << endl;
        cout << "Description: " << newItem.description << endl;
        break;
    }
    case 2: { // ��_ HP
        int healAmount = rand() % 31 + 10; // �H����_ 10-40 HP
        player.hp += healAmount;
        cout << "You found a healing potion in the chest! Restored " << healAmount << " HP!" << endl;
        break;
    }
    
}
