#include "StrongSkeleton.h"

using namespace std;

StrongSkeleton::StrongSkeleton(int MaxHp, int Atk, int mAtk, int Dfs, int MDfs, int c, int e, int level, string t) :
	boss(MaxHp, Atk, mAtk, Dfs, MDfs, c, e, level, t)
{

}
void StrongSkeleton::atk(Player& p)
{
	srand(time(NULL));
	int n = rand() % 3;
	if (n == 0)
	{
		normalAtk(p);
	}
	else if (n == 1)
	{
		strongAtk(p);
	}
	else if (n == 2)
	{
		specialAtk(p);
	}
}
void StrongSkeleton::strongAtk(Player& p)
{
	cout << "Strong Skeleton use strong attack" << endl;
	p.receiveDamage(getAtk() + 5, "atk");
}
void StrongSkeleton::specialAtk(Player& p)
{
	cout << "Strong Skeleton use special attack" << endl;
	p.receiveDamage(getAtk() * 2, "atk");
}
void StrongSkeleton::normalAtk(Player& p)
{
	cout << "Strong Skeelton use normal attack" << endl;
	p.receiveDamage(getAtk(), "atk");
	p.receiveDamage(getMagicAtk(), "magic");
}