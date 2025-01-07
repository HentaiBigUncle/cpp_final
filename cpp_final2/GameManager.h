#pragma once
#include"enemy.h"
#include"Player.h"
#include"Item.h"
#include"Equipment.h"
#include"chest.h"
#include"event.h"
#include"battle.h"
#include"maze.h"
#include"trap.h"
#include"boss.h"
#include"shop.h"

class shop;
class boss;
class enemy;
class trap;
class Player;
class Item;
class event;
class battle;
class chest;
class maze;

using namespace std;

class GameManager
{
public:
	void level1(maze&, Player&, Item&, vector<enemy> &, battle&, event&, chest&, trap&, boss&);
	void level2(maze&, Player&, Item&, vector<enemy>&, battle&, event&, chest&, trap&, boss&);
	void level3(maze&, Player&, Item&, vector<enemy>&, battle&, event&, chest&, trap&, boss&);
	void level4(maze&, Player&, Item&, vector<enemy>&, battle&, event&, chest&, trap&, boss&);
	void openShop(shop&, Player&);
};

