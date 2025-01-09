#pragma once
#include "character.h"
#include<iostream>
#include<cmath>
#include<string>

using namespace std;

character::character(int MaxHp, int MaxMp, int Atk, int mAtk,  int Dfs, int MDfs, string t) :
	maxHp(MaxHp), maxMp(MaxMp), atk(Atk), dfs(Dfs), magicalDfs(MDfs), magicalAtk(mAtk), type(t)
{
	setHp(maxHp);
	setMp(maxMp);
}
//set
void character::setHp(int h)
{
	hp = h;
}
void character::setMp(int m)
{
	mp = m;
}
//get
int character::getAtk() { return atk; }
int character::getDfs() { return dfs; }
int character::getMagicalDfs() { return magicalDfs; }
int character::getHp() { return hp; }
int character::getMp() { return mp; }
int character::getMagicalAtk() { return magicalAtk; }
string character::getType() { return type;}
int character::getMaxHp() { return maxHp; }
int character::getMaxMp() { return maxMp; }
bool character::getDie() { return isDie; }
//change

void character::changeAtk(int a)
{
	atk += a;
}
void character::changeMagicalAtk(int ma)
{
	magicalAtk += ma;
}
void character::changeDfs(int d)
{
	dfs += d;
}
void character::changeMaxHp(int h)
{
	maxHp += h;
}
void character::changeMaxMp(int m)
{
	maxMp += m;
}
void character::changeMagicDfs(int d)
{
	magicalDfs += d;
}
void character::changeHp(int h)
{
	hp = max(0, hp + h);
	hp = min(hp, maxHp);
}
void character::changeMp(int m)
{
	mp = max(0, mp + m);
	mp = min(mp, maxMp);
}

void character::minusMaxHp(int h)
{
	maxHp -= h;
}
void character::minusMaxMp(int m)
{
	maxMp -= m;
}
void character::minusAtk(int a)
{
	atk -= a;
}
void character::minusMatk(int ma)
{
	magicalAtk -= ma;
}
void character::minusDfs(int d)
{
	dfs -= d;
}
void character::minusMdfs(int m)
{
	magicalDfs -= m;
}

//need to classify mAtk and Atk
int character::ReceiveDamage(int damage, string type) 
{
	int _damage = 0;
	if (type == "magic")
	{
		_damage = max(0, damage - magicalDfs);
		cout << "You receive " << _damage << " magical damage" << endl;
	}
	else if (type == "atk")
	{
		_damage = max(0, damage - dfs);
		cout << "You receive " << _damage << " physical damage" << endl;
	}
	hp -= _damage;
	return _damage;
}
void character::dieCheck()
{
	if (hp <= 0)
		isDie = true;
}
void character::print()
{
	cout<< "MaxHp: " << maxHp << "\n"
		<< "Hp: " << hp << "\n"
		<< "MaxMp: " << maxMp << "\n"
		<<"Mp: "<<mp<<"\n"
		<< "Atk: " << atk << "\n"
		<<"MagicalAtk: "<<magicalAtk<<"\n"
		<< "Defense: " << dfs << "\n"
		<< "magicalDefense: " << magicalDfs << "\n";
}
