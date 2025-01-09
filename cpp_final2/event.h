#pragma once
#include"Player.h"
#include"Zombie.h"
#include"Skeleton.h"
#include"Slime.h"
#include"battle.h"
#include"maze.h"

class maze;
class battle;
class Slime;
class Skeleton;
class Zombie;
class Player;

class event
{
	Slime s;
	Skeleton skele;
	Zombie z;
public:
	void occurEvent(Player&, battle&, maze&);
};

