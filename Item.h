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
    int attackBonus=0;
    int defenseBonus=0;

    // 道具結構體的建構函數
    Item(const std::string& name = "", const std::string& description = "", int attackBonus = 0, int defenseBonus = 0)
        : name(name), description(description), attackBonus(attackBonus), defenseBonus(defenseBonus) {}
};

// 函數宣告
void displayItems(const Player& player);          // 顯示玩家的物品清單
void addItemToInventory(Player& player, const Item& item); // 添加道具到玩家的物品欄
void useItem(Player& player, Enemy& enemy);       // 修改後的 `useItem` 函數

#endif
