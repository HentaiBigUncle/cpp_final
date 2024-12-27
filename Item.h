#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>

// �e�m�ŧi Player ���c
struct Player;

// �D�㵲�c
struct Item {
    std::string name;
    std::string description;
    int attackBonus;
    int defenseBonus;
};

// �禡�ŧi
void displayItems(Player& player);
void addItemToInventory(Player& player, const Item& item);

#endif
