#pragma once
#include "HealthPotion.h"

HealthPotion::HealthPotion(int mHp , int mMp , int atk , int mAtk , int mDfs , int r , int dfs , int _heal , int _mp,  int _damage, int _gold, string n) :
	Item(mHp, mMp, atk, mAtk, mDfs, r, dfs, _heal, _mp, _damage, _gold, n)
{

}
void HealthPotion::useItem(Player& p, enemy& e)
{
	if (amount == 0)
	{
		cout << "You didn't have any Health Potion" << endl;
	}
	else
	{
		p.getCharacter()->changeHp(heal);
		cout << "You heal " << heal << " hp" << endl;
	}
}