#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Item.h"
#include "Skill.h"

// 玩家結構體
struct Player {
    std::string role;       // 玩家角色
    int level;              // 等級
    int hp;                 // 當前血量
    int maxHp;              // 最大血量
    int mp;                 // 魔力值
    int maxMp;              // 最大魔力值
    int attack;             // 基礎攻擊力
    int defense;            // 防禦力
    int coins;              // 金幣數量
    std::vector<Item> inventory; // 背包內的道具
    Item equippedItems[3];  // 已裝備道具

    // 方法
    int getTotalAttack() const; // 計算總攻擊力
    void levelUp();             // 升級
    void defend(const Enemy& enemy); // 防禦
    void useItem(Enemy& enemy);      // 使用道具
    void useSkill(Enemy& enemy);     // 使用技能

    // 重置玩家狀態（在血量歸零後使用）
    void resetPlayer();
};

void displayPlayerInfo(const Player& player);

#endif
