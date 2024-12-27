#include <iostream>
#include <vector>
#include <string>

class Enemy {
public:
    int attack = 10;
};

class Item {
public:
    std::string name;
    int attackBonus = 0;
    int defenseBonus = 0;
};

// 玩家结构体
class Player {
public:
    std::string role;
    int level = 1;
    int hp = 100;
    int maxHp = 100;
    int mp = 50;
    int maxMp = 50;
    int attack = 10;
    int defense = 5;
    int coins = 0;
    std::vector<Item> inventory;
    Item equippedItems[3];

    int getTotalAttack() const;
    void levelUp();
    void defend(const Enemy& enemy);
    void useItem(Enemy& enemy);
    void useSkill(Enemy& enemy);
};

// 获取总攻击力
int Player::getTotalAttack() const {
    int totalAttack = attack;
    for (const auto& item : equippedItems) {
        totalAttack += item.attackBonus;
    }
    return totalAttack;
}

// 升级
void Player::levelUp() {
    ++level;
    maxHp += 10;
    maxMp += 5;
    hp = maxHp;
    mp = maxMp;
    attack += 3;
    defense += 2;
    std::cout << "Level up! You are now level " << level << "." << std::endl;
}

// 防御
void Player::defend(const Enemy& enemy) {
    int damage = std::max(0, enemy.attack - defense);
    hp -= damage;
    std::cout << "You defended! Damage taken: " << damage << ". HP: " << hp << std::endl;
}

// 使用道具
void Player::useItem(Enemy& enemy) {
    std::cout << "Using item on enemy." << std::endl;
}

// 使用技能
void Player::useSkill(Enemy& enemy) {
    std::cout << "Using skill on enemy." << std::endl;
}

// 显示玩家信息
void displayPlayerInfo(const Player& player) {
    std::cout << "Role: " << player.role << ", Level: " << player.level << std::endl;
    std::cout << "HP: " << player.hp << "/" << player.maxHp
              << ", MP: " << player.mp << "/" << player.maxMp << std::endl;
}


