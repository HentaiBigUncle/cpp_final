#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>

// 前置宣告 Player 結構
struct Player;

// 道具結構
struct Item {
    std::string name;
    std::string description;
    int attackBonus;
    int defenseBonus;
};

// 函式宣告
void displayItems(Player& player);
void addItemToInventory(Player& player, const Item& item);

#endif
