#include "enchanter.h"

enchanter::enchanter(int mHp, int mMp, int a, int mAtk, int d, int mDfs, string t) :
	character(mHp, mMp, a, mAtk, d, mDfs, t)
{

}
void enchanter::displaySkill(Player& p) 
{
	cout << "Available Skills:" << endl;
	cout << "1. Magic Spine" << endl;
	if (p.getLevel() >= 3)
		cout << "2. Heal Myself" << endl;
	if (p.getLevel() >= 5)
		cout << "3. Strong Magic Gun" << endl;
	if (p.getLevel() >= 10)
		cout << "4. Magic Saint Sword" << endl;
	if (p.getLevel() >= 15)
		cout << "5. Milion Magic" << endl;
}
void enchanter::useSkill(enemy& e, Player& p) 
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
			MagicSpine(p, e);
		}
		else if (n == 2)
		{
			heal(p);
		}
		else if (n == 3)
		{
			StrongMagicGun(p, e);
		}
		else if (n == 4)
		{
			MagicSaintSword(p, e);
		}
		else if (n == 5)
		{
			MilionMagic(p, e);
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
void enchanter::heal(Player& p)
{
	if (p.getLevel() >= 3 && p.getCharacter()->getMp() >= 5)
	{
		p.getCharacter()->changeHp(getMagicalAtk() * 2);
		p.getCharacter()->changeMp(-5);
		cout << "You heal yourself + " << getMagicalAtk() * 2 << endl;
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
void enchanter::MagicSpine(Player& p, enemy& e)
{
	if (p.getCharacter()->getMp() >= 5)
	{
		e.ReceiveAttack(p.getCharacter()->getMagicalAtk() * 2, "magic");
		p.getCharacter()->changeMp(-5);
		cout << "You use Magic Spine" << endl;
		isUse = true;
	}
	else if (p.getCharacter()->getMp() < 5)
	{
		cout << "Not enough mp, choose again" << endl;
	}
}
void enchanter::StrongMagicGun(Player& p, enemy& e)
{
	if (p.getLevel() >= 5 && p.getCharacter()->getMp() >= 10)
	{
		e.ReceiveAttack(p.getCharacter()->getMagicalAtk() * 3, "magic");
		e.ReceiveAttack(p.getCharacter()->getAtk() / 2, "atk");
		p.getCharacter()->changeMp(-10);
		cout << "You use Strong Magic Gun" << endl;
		isUse = true;
	}
	else if (p.getLevel() < 5)
	{
		cout << "Not enough level, choose again" << endl;
	}
	else if (p.getCharacter()->getMp() < 10)
	{
		cout << "Not enough mp, choose again" << endl;
	}
}
void enchanter::MagicSaintSword(Player& p, enemy& e)
{
	if (p.getLevel() >= 10 && p.getCharacter()->getMp() >= 20)
	{
		e.ReceiveAttack(p.getCharacter()->getMagicalAtk() * 3, "magic");
		e.ReceiveAttack(p.getCharacter()->getAtk() * 2, "atk");
		p.getCharacter()->changeMp(-20);
		cout << "You use Magic Saint Sword" << endl;
		isUse = true;
	}
	else if (p.getLevel() < 10)
	{
		cout << "Not enough level, choose again" << endl;
	}
	else if (p.getCharacter()->getMp() < 20)
	{
		cout << "Not enough mp, choose again" << endl;
	}
}
void enchanter::MilionMagic(Player& p, enemy& e)
{
	if (p.getLevel() >= 15 && p.getCharacter()->getMp() >= 50)
	{
		e.ReceiveAttack(p.getCharacter()->getMagicalAtk() * 10, "magic");
		p.getCharacter()->changeMp(-50);
		cout << "You use Milion Magic" << endl;
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
