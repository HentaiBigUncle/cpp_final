#pragma once
#include "Item.h"
#include<iostream>

using namespace std;

Item::Item(int mHp, int mMp, int atk,int mAtk, int mDfs, int r,  int dfs, int _heal, int _mp, int _damage, int _gold, string n) :
	mAtkBonus(mAtk), mDfsBonus(mDfs), round(r), MaxHpBonus(mHp), MaxMpBonus(mMp), atkBonus(atk), dfsBonus(dfs), heal(_heal), damage(_damage), name(n), mp(_mp), gold(_gold)
{
	
}

void Item::print()
{
	cout << "Name: " << name<<endl;
	if (MaxHpBonus != 0)
	{
		cout << " MaxHpBonus: " << MaxHpBonus<<endl;
	}
	if (MaxMpBonus != 0)
	{
		cout << " MaxMpBonus" << MaxMpBonus<<endl;
	}
	if (atkBonus != 0)
	{
		cout << " AtkBonus: " << atkBonus<<endl;
	}
	if (mAtkBonus != 0)
	{
		cout << "MagicalAttackBonus: " << mAtkBonus << endl;
	}
	if (dfsBonus != 0)
	{
		cout << " DfsBonus: " << dfsBonus<<endl;
	}
	if (mDfsBonus != 0)
	{
		cout << " MagicalDfsBonus: " << mDfsBonus<<endl;
	}
	if (heal != 0)
	{
		cout << " Heal: " << heal<<endl;
	}
	if (damage != 0)
	{
		cout << " Damage: " << damage<<endl;
	}
	if (round != 0)
	{
		cout << " Round: " << round;
	}
	cout << endl;
}
void Item::addItemToInventory(Player& p, Item& i)
{
	if (p.getInventor() == NULL)
	{
		p.getInventor()->insert(make_pair(i.name, i));
	}
	else
	{
		auto it = p.getInventor()->find(i.name);
		if (it != p.getInventor()->end())
		{
			it->second.amount++;
		}
		else
		{
			p.getInventor()->insert(make_pair(i.name, i));
		}
	}
}
void Item::useItem(Player&,enemy&) const{}
string Item::getName()
{
	return name;
}
int Item::getAmount() { return amount; }
void Item::minusItemAmount()
{
	amount -= 1;
}
int Item::getGold() const
{
	return gold;
}