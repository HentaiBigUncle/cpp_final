#ifndef SHOP_H
#define SHOP_H

#include <vector>
#include "player.h"

// 创建商店道具
std::vector<Item> createShopItems();

// 显示商店道具
void displayShopItems(const std::vector<Item>& shopItems);

// 购买道具
void purchaseItem(Player& player, const std::vector<Item>& shopItems);

// 查看背包
void displayInventory(const Player& player);

// 装备道具
void equipItemFromInventory(Player& player);

#endif
