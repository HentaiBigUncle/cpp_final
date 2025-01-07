#pragma once
#include "warrior.h"
#include<iostream>

using namespace std;

warrior::warrior(int mHp, int mMp, int a, int mAtk,  int d, int mDfs, string t) :
	character(mHp, mMp, a, mAtk,  d, mDfs, t)
{

}
void warrior::displaySkill(Player& p) const
{
	cout << "Available Skills:" << endl;
	cout << "1. Strong Attack" << endl;
	if (p.getLevel() >= 3)
		cout << "2. Heal Myself" << endl;
	if (p.getLevel() >= 5)
		cout << "3. Double Attack" << endl;
	if (p.getLevel() >= 10)
		cout << "4. Holy Attack" << endl;
}
void warrior::doubleAtk(enemy& e, Player& p) const
{
	if (p.getLevel() >= 3 && p.getCharacter()->getMp() >= 10)
	{
		e.ReceiveAttack(p.getCharacter()->getAtk() * 2, "atk");
		p.getCharacter()->changeMp(-10);
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
void warrior::strongAtk(enemy& e, Player& p) const
{
	if (p.getCharacter()->getMp() >= 5)
	{
		e.ReceiveAttack(20, "atk");
		p.getCharacter()->changeMp(-5);
	}
	else if (p.getCharacter()->getMp() < 5)
	{
		cout << "Not enough mp, choose again" << endl;
	}
}
void warrior::holySword(enemy& e, Player& p) const
{
	if (p.getCharacter()->getMp() >= 50)
	{
		e.ReceiveAttack(50 + p.getCharacter()->getAtk(), "atk");
		e.ReceiveAttack(25 + p.getCharacter()->getMagicalAtk(), "magic");
		p.getCharacter()->changeMp(-50);
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
void warrior::healMyself(Player& p) const
{
	if (p.getLevel() >= 3 && p.getCharacter()->getMp() >= 5)
	{
		p.getCharacter()->changeHp(20);
		p.getCharacter()->changeMp(-5);
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
void warrior::useSkill(enemy& e, Player& p) const
{
	int n = 0;
	bool isUse = false;
	cout << "choose skill you want to use. (5 = exit)" << endl;
	displaySkill(p);
	cin >> n;
	if (n == 1)
		strongAtk(e, p);
	else if (n == 2)
		healMyself(p);
	else if (n == 3)
		doubleAtk(e, p);
	else if (n == 4)
		holySword(e, p);
	else if (n == 5)
	{
		cout << "You choose to give up to use  skill" << endl;
	}
	else
		cout << "no such skill is available, choose again" << endl;
}
