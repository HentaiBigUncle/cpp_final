#pragma once
#include<iostream>
#include<vector>
#include"warrior.h"
#include"Slime.h"
#include"Player.h"
#include"maze.h"
#include"StrongSkeleton.h"
#include"GameManager.h"

using namespace std;

//character c(maxHp, maxMp, atk, magicalAtk, dfs, magiclaDfs, type)
//enemy e(MaxHp, Atk, mAtk, Dfs, MDfs, c, e, level, t)
//maze m(int edge, char role)
//Player(int coin, string name, character)

GameManager GM;
StrongSkeleton strongSkeleton;
warrior w1;
Slime s;
Player p(10, "You didn't enter any name", w1);
event ent;
chest ct;
maze m1(5, p);
maze m2(7, p);
maze m3(9, p);
maze m4(11, p);

int main()
{
	p.print();
	return 0;
}