#pragma once
#include "warrior.h"
#include<iostream>

using namespace std;

warrior::warrior(int mHp, int mMp, int a, int mAtk,  int d, int mDfs, string t) :
	character(mHp, mMp, a, mAtk,  d, mDfs, t)
{

}
void warrior::displaySkill(Player& p) 
{
	cout << "Available Skills:" << endl;
	cout << "1. Strong Attack" << endl;
	if (p.getLevel() >= 3)
		cout << "2. Heal Myself" << endl;
	if (p.getLevel() >= 5)
		cout << "3. Double Attack" << endl;
	if (p.getLevel() >= 10)
		cout << "4. Holy Attack" << endl;
	if (p.getLevel() >= 15)
		cout << "5. Zenith Half" << endl;
}
void warrior::doubleAtk(enemy& e, Player& p) 
{
	if (p.getLevel() >= 5 && p.getCharacter()->getMp() >= 10)
	{
		e.ReceiveAttack(p.getCharacter()->getAtk() * 2, "atk");
		e.ReceiveAttack(p.getCharacter()->getMagicalAtk() * 2, "magic");
		p.getCharacter()->changeMp(-10);
		isUse = true;
	}
	else if(p.getLevel() < 3)
	{
		cout << "Not enough level, choose again" << endl;
	}
	else if (p.getCharacter()->getMp() < 10)
	{
		cout << "Not enough mp, choose again" << endl;
	}
}
void warrior::strongAtk(enemy& e, Player& p) 
{
	if (p.getCharacter()->getMp() >= 5)
	{
		e.ReceiveAttack(getAtk() * 2, "atk");
		p.getCharacter()->changeMp(-5);
		cout << "You use Strong Attack" << endl;
		isUse = true;
	}
	else if (p.getCharacter()->getMp() < 5)
	{
		cout << "Not enough mp, choose again" << endl;
	}
}
void warrior::holySword(enemy& e, Player& p) 
{
	if (p.getCharacter()->getMp() >= 25 && p.getLevel() >= 10)
	{
		e.ReceiveAttack(25 + p.getCharacter()->getAtk() * 2, "atk");
		e.ReceiveAttack(25 + p.getCharacter()->getMagicalAtk(), "magic");
		p.getCharacter()->changeMp(-25);
		cout << "You use Holy Sword" << endl;
		isUse = true;
	}
	else if (p.getLevel() < 10)
	{
		cout << "Not enough level, choose again" << endl;
	}
	else if (p.getCharacter()->getMp() < 25)
	{
		cout << "Not enough mp, choose again" << endl;
	}
}
void warrior::healMyself(Player& p) 
{
	if (p.getLevel() >= 3 && p.getCharacter()->getMp() >= 5)
	{
		p.getCharacter()->changeHp(getAtk() * 2);
		p.getCharacter()->changeMp(-5);
		cout << "You heal yourself + " << getAtk() * 2 << endl;
		isUse = true;
	}
	else if (p.getLevel() < 3)
	{
		cout << "Not enough level, choose again" << endl;
	}
	else if (p.getCharacter()->getMp() < 5)
	{
		cout << "Not enough mp, choose again" << endl;
	}
}
void warrior::ZenithHalf(enemy& e, Player& p)
{
	if (p.getLevel() >= 15 && p.getCharacter()->getMp() >= 50)
	{
		e.ReceiveAttack(50 + p.getCharacter()->getAtk() * 4, "atk");
		e.ReceiveAttack(25 + p.getCharacter()->getMagicalAtk() * 4, "magic");
		p.getCharacter()->changeMp(-50);
		cout << "You use Zenith Half" << endl;
		isUse = true;
	}
	else if (p.getLevel() < 15)
	{
		cout << "Not enough level, choose again" << endl;
	}
	else if (p.getCharacter()->getMp() < 50)
	{
		cout << "Not enough mp, choose again" << endl;
	}
}
void warrior::useSkill(enemy& e, Player& p) 
{
	int n = 0;
	isUse = false;
	while (!isUse)
	{
		cout << "choose skill you want to use. (6 = exit)" << endl;
		displaySkill(p);
		cin >> n;
		if (n == 1)
		{
			strongAtk(e, p);
		}
		else if (n == 2)
		{
			healMyself(p);
		}
		else if (n == 3)
		{
			doubleAtk(e, p);
		}
		else if (n == 4)
		{
			holySword(e, p);
		}
		else if (n == 5)
		{
			ZenithHalf(e, p);
		}
		else if (n == 6)
		{
			cout << "You choose to give up to use  skill" << endl;
			break;
		}
		else
			cout << "no such skill is available, choose again" << endl;
	}
}
