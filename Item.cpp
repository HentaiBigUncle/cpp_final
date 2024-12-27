#include "Item.h"
#include <iostream>

using namespace std;

void displayItems(const Player& player) {
    cout << "Available Items in Inventory:" << endl;
    for (size_t i = 0; i < player.inventory.size(); ++i) {
        cout << i + 1 << ". " << player.inventory[i].name << " - " << player.inventory[i].description << endl;
    }
}

void useItem(Player& player, Enemy& enemy, int itemChoice) {
    if (itemChoice > 0 && itemChoice <= player.inventory.size()) {
        Item chosenItem = player.inventory[itemChoice - 1];
        if (chosenItem.attackBonus > 0) {
            enemy.hp -= chosenItem.attackBonus;
            cout << "You used " << chosenItem.name << " to attack the enemy! Enemy HP is now: " << enemy.hp << endl;
        }
        else if (chosenItem.name == "Potion") {
            player.hp = min(player.hp + 30, player.maxHp);
            cout << "You used " << chosenItem.name << " and restored 30 HP! Your HP is now: " << player.hp << endl;
        }
        player.inventory.erase(player.inventory.begin() + itemChoice - 1);
    }
    else {
        cout << "Invalid item choice!" << endl;
    }
}
