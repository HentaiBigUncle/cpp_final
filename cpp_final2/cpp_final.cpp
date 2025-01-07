#pragma once
#include<iostream>
#include<vector>
#include"warrior.h"
#include"Slime.h"
#include"Skeleton.h"
#include"Zombie.h"
#include"Player.h"
#include"maze.h"
#include"StrongSkeleton.h"
#include"GameManager.h"
#include"battle.h"
#include"shop.h"
#include"trap.h"
#include"Almighty_Amulet.h"
#include"Leather_helmet.h"
#include"MagicPotion.h"

using namespace std;

//character c(maxHp, maxMp, atk, magicalAtk, dfs, magiclaDfs, type)
//enemy e(MaxHp, Atk, mAtk, Dfs, MDfs, c, e, level, t)
//maze m(int edge, char role)
//Player(int coin, string name, character)

//game maze 

MagicPotion mps;
GameManager GM;
StrongSkeleton strongSkeleton;
battle b;
trap t;
event et;
chest ct;
shop sh;
//enemy
Slime s;
Skeleton skely;
Zombie zombie;
//player character
warrior w1;
Player p(10, "You didn't enter any name", &w1);

//maze
maze m1(5, p);
maze m2(7, p);
maze m3(9, p);
maze m4(11, p);

vector<enemy> LevelOneEnemy;
vector<enemy> LevelTwoEnemy;
vector<enemy> LevelThreeEnemy;
vector<enemy> LevelFourEnemy;
Almighty_Amulet AA;
Leather_helmet lh;
Iron_Helmet Ih;
void setUp();
int main()
{
	setUp();
	m1.move(ct, et, p, LevelOneEnemy, b, t, strongSkeleton);

	return 0;
}
void setUp()
{
	//level1
	LevelOneEnemy.push_back(s);

	//level2
	LevelTwoEnemy.push_back(s);
	LevelTwoEnemy.push_back(skely);
	LevelTwoEnemy.push_back(zombie);
}
