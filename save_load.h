#ifndef SAVE_LOAD_H
#define SAVE_LOAD_H

#include "player.h"
#include <vector>
#include <string>

// 存档
void saveGame(const Player& player);

// 读取存档
void loadGame(Player& player);

// 获取存档条目
std::vector<std::string> getSaveEntries();

#endif
