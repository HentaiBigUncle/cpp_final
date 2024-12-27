#ifndef ITEM_H
#define ITEM_H

#include <string>

// 前向宣告以避免循環依賴
struct Player;
class Enemy;

// 道具結構
struct Item {
    std::string name;
    std::string description;
    int attackBonus;
    int defenseBonus;

    Item(const std::string& name = "", const std::string& description = "", int attackBonus = 0, int defenseBonus = 0)
        : name(name), description(description), attackBonus(attackBonus), defenseBonus(defenseBonus) {}
};

// 函數宣告
void displayItems(const Player& player);
void addItemToInventory(Player& player, const Item& item);
void useItem(Player& player, Enemy& enemy, int itemChoice);

#endif
