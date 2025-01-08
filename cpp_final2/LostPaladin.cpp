#include "LostPaladin.h"

LostPaladin::LostPaladin(int MaxHp, int Atk, int mAtk, int Dfs, int MDfs, int c, int e, int level, string t) :
	boss(MaxHp, Atk, mAtk, Dfs, MDfs, c, e, level, t)
{

}
void LostPaladin::atk(Player& p)
{
	srand(time(NULL));
	int n = rand() % 4;
	if (n == 0)
		normalAtk(p);
	else if (n == 1)
		SaintSwordAtk(p);
	else if (n == 2)
		ExGalibon(p);
	else if (n == 3)
		heal();
}
void LostPaladin::normalAtk(Player& p)
{
	cout << "Lost Paladin use normal attack" << endl;
	p.receiveDamage(getAtk(), "atk");
}
void LostPaladin::SaintSwordAtk(Player& p)
{
	cout << "Lost Paladin use SaintSword Attack" << endl;
	p.receiveDamage(getAtk() + 10, "atk");
	p.receiveDamage(getMagicAtk() * 2, "magic");
}
void LostPaladin::ExGalibon(Player& p)
{
	cout << "Lost Paladin use ExGalibon" << endl;
	p.receiveDamage(getAtk() * 3, "atk");
	p.receiveDamage(getMagicAtk() * 2, "magic");
}
void LostPaladin::heal()
{
	hp += 10;
	cout << "Lost Paladin heal 10 hp" << endl;
}