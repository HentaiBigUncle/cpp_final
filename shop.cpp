#include <iostream>
#include "shop.h"

std::vector<Item> createShopItems() {
    return {
        {"Sword", "Increase attack by 10", 10, 0},
        {"Shield", "Increase defense by 15", 0, 15},
        {"Potion", "Increase HP by 20", 0, 0},
        {"Magic Stone", "Increase MP by 25", 0, 0},
        {"Boots", "Increase attack and defense by 5", 5, 5}
    };
}

void displayShopItems(const std::vector<Item>& shopItems) {
    std::cout << "Shop Items:" << std::endl;
    for (size_t i = 0; i < shopItems.size(); ++i) {
        std::cout << i + 1 << ". " << shopItems[i].name << " - " << shopItems[i].description << std::endl;
        std::cout << "  Attack Bonus: " << shopItems[i].attackBonus << std::endl;
        std::cout << "  Defense Bonus: " << shopItems[i].defenseBonus << std::endl;
    }
}

void purchaseItem(Player& player, const std::vector<Item>& shopItems) {
    displayShopItems(shopItems);
    std::cout << "Enter the number of the item you want to purchase: ";
    int choice;
    std::cin >> choice;

    if (choice > 0 && choice <= shopItems.size()) {
        const Item& item = shopItems[choice - 1];
        player.inventory.push_back(item);
        std::cout << "You have purchased " << item.name << "!" << std::endl;
    }
    else {
        std::cerr << "Invalid choice!" << std::endl;
    }
}

void displayInventory(const Player& player) {
    if (player.inventory.empty()) {
        std::cout << "Your inventory is empty." << std::endl;
        return;
    }

    std::cout << "Your Inventory:" << std::endl;
    for (size_t i = 0; i < player.inventory.size(); ++i) {
        const Item& item = player.inventory[i];
        std::cout << i + 1 << ". " << item.name << " - " << item.description << std::endl;
        std::cout << "  Attack Bonus: " << item.attackBonus << std::endl;
        std::cout << "  Defense Bonus: " << item.defenseBonus << std::endl;
    }
}

void equipItemFromInventory(Player& player) {
    displayInventory(player);
    std::cout << "Enter the number of the item you want to equip: ";
    int choice;
    std::cin >> choice;

    if (choice > 0 && choice <= player.inventory.size()) {
        const Item& item = player.inventory[choice - 1];
        std::cout << "Choose a slot to equip the item (1-3): ";
        int slot;
        std::cin >> slot;

        if (slot >= 1 && slot <= 3) {
            player.equippedItems[slot - 1] = item;
            std::cout << "You have equipped " << item.name << " in slot " << slot << "!" << std::endl;
        }
        else {
            std::cerr << "Invalid slot choice!" << std::endl;
        }
    }
    else {
        std::cerr << "Invalid choice!" << std::endl;
    }
}
