#pragma once
#include"enemy.h"
#include"Player.h"
#include<vector>
#include"boss.h"
#include"maze.h"
#include"boss.h"

using namespace std;

class boss;
class Player;
class maze;
class enemy;

class battle
{
public:
	void StartBattle(enemy&, Player&, maze&);
	void bossFight(boss&, Player&, maze&);
};

