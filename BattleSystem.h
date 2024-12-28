#ifndef BATTLESYSTEM_H
#define BATTLESYSTEM_H

#include "Player.h"
#include "Enemy.h"
#include <map>
#include <string>

// 定义敌人数据结构
struct EnemyData {
    std::string name;
    int maxHp;
    int attack;
};

// 战斗系统相关函数
void battle(Player& player, Enemy& enemy);

// 初始化敌人数据
void initializeEnemyDatabase();

// 根据敌人名称查找对应的属性
EnemyData getEnemyData(const std::string& enemyName);

#endif
