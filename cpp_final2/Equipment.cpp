#pragma once
#include "Equipment.h"
#include<iostream>
#include"Player.h"

using namespace std;

Equipment::Equipment(int hp, int mp, int dfs, int mDfs, int atk, int mAtk, int _gold, string n, string t) :
	type(t), addAtk(atk), addDfs(dfs), addMagicalAtk(mAtk), addMagicalDFs(mDfs), addMaxHp(hp), addMaxMp(mp), name(n), gold(_gold)
{
	
}
void Equipment::AddProperty(Player& p)
{
	p.getCharacter()->changeAtk(addAtk);
	p.getCharacter()->changeDfs(addDfs);
	p.getCharacter()->changeMagicalAtk(addMagicalAtk);
	p.getCharacter()->changeMagicDfs(addMagicalDFs);
	p.getCharacter()->changeMaxHp(addMaxHp);
	p.getCharacter()->changeMaxMp(addMaxMp);
}
void Equipment::MinusProperty(Player& p)
{
	p.getCharacter()->changeAtk(-addAtk);
	p.getCharacter()->changeDfs(-addDfs);
	p.getCharacter()->changeMagicalAtk(-addMagicalAtk);
	p.getCharacter()->changeMagicDfs(-addMagicalDFs);
	p.getCharacter()->changeMaxHp(-addMaxHp);
	p.getCharacter()->changeMaxMp(-addMaxMp);
}
void Equipment::print()
{
	cout << "name: " << name<<endl;
	if (addMaxHp)
	{
		cout << "+" << addMaxHp << " AddMaxHp\n";
	}
	if (addMaxMp)
	{
		cout << "+" << addMaxMp << " AddMaxMp\n";
	}
	if (addAtk)
	{
		cout << "+" << addAtk << " AddAttack\n";
	}
	if (addMagicalAtk)
	{
		cout << "+" << addMagicalAtk << " AddMagicalAttack\n";
	}
	if (addDfs)
	{
		cout << "+" << addDfs << " AddDefense\n";
	}
	if (addMagicalDFs)
	{
		cout << "+" << addMagicalDFs << " AddMagicalDefense\n";
	}
}
int Equipment::getGold()
{
	return gold;
}
string Equipment::getName() { return name; }