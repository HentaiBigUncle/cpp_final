#pragma once
#include"enemy.h"
#include"Player.h"
#include"time.h"

class Player;

class boss : public enemy
{
public:
	boss(int, int, int, int, int, int, int, int, string);
	virtual void atk(Player&) {};
};

