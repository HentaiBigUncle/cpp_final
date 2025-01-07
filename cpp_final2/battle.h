#pragma once
#include"enemy.h"
#include"Player.h"
#include<vector>
#include"boss.h"

using namespace std;

class Player;
class enemy;

class battle
{
public:
	void StartBattle(enemy&, Player&);
	void bossFight(boss&, Player&);
};

