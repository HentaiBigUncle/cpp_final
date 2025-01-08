#include "NamelessKing.h"

NamelessKing::NamelessKing(int MaxHp, int Atk, int mAtk, int Dfs, int MDfs, int c, int e, int level, string t) :
	boss(MaxHp, Atk, mAtk, Dfs, MDfs, c, e, level, t)
{

}
void NamelessKing::atk(Player& p)
{
	srand(time(NULL));
	int n = rand() % 6;
	if (n == 0)
		normalAtk(p);
	else if (n == 1)
		Lightning(p);
	else if (n == 2)
		Thrust(p);
	else if (n == 3)
		WindWave(p);
	else if (n == 4)
		DragonFire(p);
	else if (n == -5)
		ThousandsLightBurn(p);
}
void NamelessKing::normalAtk(Player& p)
{
	cout << "NamelessKing use normal attack" << endl;
	p.receiveDamage(getAtk(), "atk");
}
void NamelessKing::Lightning(Player& p)
{
	cout << "NamelessKing use lightning" << endl;
	p.receiveDamage(getMagicAtk() * 2, "magic");
}
void NamelessKing::Thrust(Player& p)
{
	cout << "NamelessKing vuse thurst" << endl;
	p.receiveDamage(getMagicAtk() / 4, "magic");
	p.receiveDamage(getAtk() * 2.5, "atk");
}
void NamelessKing::WindWave(Player& p)
{
	cout << "NamelessKing use wind wave" << endl;
	p.receiveDamage(getAtk() / 5, "atk");
}
void NamelessKing::DragonFire(Player& p)
{
	cout << "NamelessKing use dragon fire" << endl;
	p.receiveDamage(getMagicAtk() * 3, "magic");
}
void NamelessKing::ThousandsLightBurn(Player& p)
{
	cout << "NamelessKing use thousands light burn" << endl;
	p.receiveDamage(getMagicAtk() * 10, "magic");
}