#pragma once
#include "enemy.h"
#include<iostream>
#include<cmath>

using namespace std;

enemy::enemy(int MaxHp, int Atk, int mAtk, int Dfs, int MDfs, int c, int e, int level, string t) :
	maxHp(MaxHp) ,atk(Atk), dfs(Dfs), magicalDfs(MDfs), magicalAtk(mAtk), coin(c), exp(e), type(t)
{
	setHp(maxHp);
	changeLv(level);
}
//set
void enemy::setHp(int h)
{
	hp = h;
}
//change
void enemy::changeAtk(int a)
{
	atk += a;
}
void enemy::changeMagicalAtk(int ma)
{
	magicalAtk += ma;
}
void enemy::changeDfs(int d)
{
	dfs += d;
}
void enemy::changeMaxHp(int h)
{
	maxHp += h;
}
void enemy::changeMagicDfs(int d)
{
	dfs += d;
}
//get
int enemy::getCoin()
{
	return coin;
}
int enemy::getExp()
{
	return exp;
}
string enemy::getName()
{
	return type;
}
int enemy::getHp()
{
	return hp;
}
bool enemy::getDie()
{
	return isDie;
}

void enemy::ReceiveAttack(int damage, string str)
{
	if (str == "magic")
	{
		damage = max(0, damage - magicalDfs);
		hp -= damage;
		cout << "enemy receive: " << damage << " magical damage" << endl;
	}
	else if (str == "atk")
	{
		damage = max(0, damage - dfs);
		hp -= damage;
		cout << "enemy receive: " << damage << " physical damage" << endl;
	}
}
void enemy::dieCheck()
{
	if (hp <= 0)
		isDie = true;
}
void enemy::changeLv(int level)
{
	lv = level;
	LevelStatsChange();
	changeCoinExp();
}
void enemy::changeLevel(int l)
{
	lv = l;
}

void enemy::LevelStatsChange()
{
	changeAtk(1 * arithmeticParameterToLevelChange(lv - 1));
	changeMagicalAtk(1 * arithmeticParameterToLevelChange(lv - 1));
	changeMaxHp(5 * arithmeticParameterToLevelChange(lv - 1));
	changeDfs(1 * arithmeticParameterToLevelChange(lv - 1));
	changeMagicDfs(1 * arithmeticParameterToLevelChange(lv - 1));
}
void enemy::changeCoinExp()
{
	if (lv >= 2)
	{
		coin += 10 * arithmeticParameterToCoinExp(lv - 1);
		exp += 20 * arithmeticParameterToCoinExp(lv - 1);
	}
}
int enemy::arithmeticParameterToCoinExp(int level)
{
	return static_cast<int>(110 + pow(8, level)) / 45;
}
int enemy::arithmeticParameterToLevelChange(int level)
{
	return static_cast<int>(level * 25 + 110 + pow(5, level)) / 50;
}
void enemy::print()
{
	cout << "Type: " << type << " Level: " << lv << " Hp: " <<hp<< " Coin: " << coin << " Exp: " << exp << endl;
}
int enemy::getAtk()
{
	return atk;
}
int enemy::getMagicAtk()
{
	return magicalAtk;
}