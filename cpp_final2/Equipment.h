#pragma once
#include<string>

using namespace std;

class Player;
class Equipment
{
protected:
	string name;
	string type;
	int addMaxHp;
	int addMaxMp;
	int addDfs;
	int addMagicalDFs;
	int addAtk;
	int addMagicalAtk;
	int gold;

public:
	Equipment(int, int, int, int, int, int, int, string, string);

	int getGold();
	string getName();
	string getType();
	void AddProperty(Player&);
	void MinusProperty(Player &);
	virtual void print();
};
