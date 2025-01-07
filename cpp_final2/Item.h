#pragma once
#include<string>
#include"enemy.h"
#include"Player.h"
using namespace std;
//class Player;
class Enemy;

class Item
{
protected:
	string name;
	int atkBonus;
	int mAtkBonus;
	int dfsBonus;
	int mDfsBonus;
	int MaxHpBonus;
	int MaxMpBonus;
	int heal;
	int mp;
	int damage;
	int amount = 1;
	int round;
	int gold;
public:
	Item(int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0,  int = 0, string = "");

	virtual void  useItem(Player&, enemy&) const;
	void minusItemAmount();
	int getGold() const;
	void addItemToInventory(Player&, Item&);
	string getName();
	int getAmount();
	void print();
};
