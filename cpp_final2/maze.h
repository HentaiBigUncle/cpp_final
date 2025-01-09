#pragma once
#include<vector>
#include<string>
#include"Player.h"
#include"chest.h"
#include"event.h"
#include"enemy.h"
#include"battle.h"
#include"trap.h"
#include"boss.h"

using namespace std;

class boss;
class trap;
class Player;
class event;
class chest;
class enemy;
class battle;

class maze
{
	vector<string> maps;
	bool isuse[25][25], goal = false;
	pair<int, int> dir[4] = { {0, 2}, {2, 0}, {0, -2}, {-2, 0 } };
	int n;
	int seed;
	int edge;
	int real_edge;

	bool chests[25][25];
	bool events[25][25];
	bool enemies[25][25];
	bool traps[25][25];

	void making_maze();
public:
	maze(int, Player&);
	void dfs(int, int, vector<string>&);
	void setUp(int&, int&);
	void calculateEdge();

	void generateChest(Player&);
	void generateEvents(Player&);
	void generateEnemy(Player&);
	void generateTrap(Player&);
	enemy generateRandomEnemy(vector<enemy>&);

	void check(int,int, chest&, event&, Player&, enemy&, battle&, trap&, boss&, maze &);

	void move(chest&, event&, Player&, vector<enemy>&, battle&, trap&, boss&, maze&);
	

	void print_instruction();
	void print_maze();
}; 
