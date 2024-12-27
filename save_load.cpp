#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "save_load.h"

using namespace std;

// 保存遊戲進度
void saveGame(const Player& player) {
    ofstream saveFile("save.txt", ios::app); // 追加模式
    if (saveFile.is_open()) {
        // 保存玩家基本信息
        saveFile << player.role << " " << player.level << " " << player.hp << " "
            << player.mp << " " << player.attack << " " << player.defense << " " << player.coins << " ";

        // 保存裝備物品
        for (int i = 0; i < 3; ++i) {
            saveFile << player.equippedItems[i].name << " "
                << player.equippedItems[i].attackBonus << " "
                << player.equippedItems[i].defenseBonus << " ";
        }

        // 保存背包物品
        saveFile << player.inventory.size() << " "; // 先保存背包物品數量
        for (const auto& item : player.inventory) {
            saveFile << item.name << " "
                << item.description << " "
                << item.attackBonus << " "
                << item.defenseBonus << " ";
        }

        saveFile << endl; // 每個存檔一行
        saveFile.close();
        cout << "Game saved successfully!" << endl;
    }
    else {
        cerr << "Failed to save the game!" << endl;
    }
}

// 加載遊戲進度
void loadGame(Player& player) {
    vector<string> saveEntries = getSaveEntries();
    if (saveEntries.empty()) {
        cerr << "No save entries found!" << endl;
        return;
    }

    // 顯示存檔選項
    cout << "Available save entries:" << endl;
    for (size_t i = 0; i < saveEntries.size(); ++i) {
        istringstream iss(saveEntries[i]);
        string role;
        iss >> role; // 讀取角色名稱
        cout << i + 1 << ". " << role << endl;
    }

    int choice;
    cout << "Enter the number of the save entry you want to load: ";
    cin >> choice;

    if (choice > 0 && choice <= saveEntries.size()) {
        istringstream iss(saveEntries[choice - 1]);
        iss >> player.role >> player.level >> player.hp >> player.mp >> player.attack >> player.defense >> player.coins;

        // 加載裝備物品
        for (int i = 0; i < 3; ++i) {
            iss >> player.equippedItems[i].name >> player.equippedItems[i].attackBonus >> player.equippedItems[i].defenseBonus;
            player.equippedItems[i].description = "No description available";
        }

        // 加載背包物品
        size_t inventorySize;
        iss >> inventorySize;
        player.inventory.clear();
        for (size_t i = 0; i < inventorySize; ++i) {
            Item item;
            iss >> item.name >> item.description >> item.attackBonus >> item.defenseBonus;
            player.inventory.push_back(item);
        }

        cout << "Game progress loaded successfully for " << player.role << "!" << endl;
    }
    else {
        cerr << "Invalid choice!" << endl;
    }
}

// 獲取所有存檔條目
vector<string> getSaveEntries() {
    vector<string> saveEntries;
    ifstream loadFile("save.txt");
    if (loadFile.is_open()) {
        string line;
        while (getline(loadFile, line)) { // 逐行讀取存檔信息
            if (!line.empty()) {
                saveEntries.push_back(line);
            }
        }
        loadFile.close();
    }
    else {
        cerr << "Failed to open save file!" << endl;
    }
    return saveEntries;
}
