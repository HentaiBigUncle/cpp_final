#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for std::max
using namespace std;
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

    void setHp(int newHp); // 封装hp设置方法
    int getTotalAttack() const;
    void levelUp();
    void defend(const Enemy& enemy);
    void useItem(Enemy& enemy);
    void useSkill(Player& player,Enemy& enemy);
};

// 设置 HP
void Player::setHp(int newHp) {
    hp = std::min(newHp, maxHp); // 确保 hp 不超过 maxHp
    if (hp < 0) hp = 0;         // 确保 hp 不小于 0
}

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
    setHp(maxHp); // 升级时自动设置到最大 HP
    mp = maxMp;
    attack += 3;
    defense += 2;
    std::cout << "Level up! You are now level " << level << "." << std::endl;
}

// 防御
void Player::defend(const Enemy& enemy) {
    int damage = std::max(0, enemy.attack - defense);
    setHp(hp - damage); // 通过 setHp 更新 HP
    std::cout << "You defended! Damage taken: " << damage << ". HP: " << hp << std::endl;
}


// 显示玩家信息
void displayPlayerInfo(const Player& player) {
    std::cout << "================ Player Info ================" << std::endl;
    std::cout << "Role: " << player.role << std::endl;
    std::cout << "Level: " << player.level << std::endl;
    std::cout << "HP: " << player.hp << "/" << player.maxHp << std::endl;
    std::cout << "MP: " << player.mp << "/" << player.maxMp << std::endl;
    std::cout << "Attack: " << player.attack << std::endl;
    std::cout << "Defense: " << player.defense << std::endl;
    std::cout << "Coins: " << player.coins << std::endl;
    std::cout << "Total Attack (with items): " << player.getTotalAttack() << std::endl;
    std::cout << "Inventory: ";
    if (player.inventory.empty()) {
        std::cout << "None";
    } else {
        for (const auto& item : player.inventory) {
            std::cout << item.name << " ";
        }
    }
    std::cout << std::endl;
    std::cout << "=============================================" << std::endl;
}