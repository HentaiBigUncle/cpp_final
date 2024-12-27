#ifndef ENEMY_H
#define ENEMY_H

#include <string>

// 使用前向宣告避免循環依賴
class Player;

class Enemy {
public:
    std::string name;
    int hp;
    int attack;

    Enemy(const std::string& name, int hp, int attack);
    void showStats() const;
    void attackPlayer(Player& player); // 將方法聲明保留
};

#endif
