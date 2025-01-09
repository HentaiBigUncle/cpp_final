#include "Pontif_Salivon.h"

Pontif_Salivon::Pontif_Salivon(int MaxHp, int Atk, int mAtk, int Dfs, int MDfs, int c, int e, int level, string t) :
	boss(MaxHp, Atk, mAtk, Dfs, MDfs, c, e, level, t)
{

}
void Pontif_Salivon::atk(Player& p)
{
	srand(time(NULL));
	int n = rand() % 5;
	if (n == 0)
		normalAtk(p);
	else if (n == 1)
		PhantonStrike(p);
	else if (n == 2)
		MagicalWave(p);
	else if (n == 3)
		TripleMelee(p);
	else if (n == 4)
		FireAttack(p);
}
void Pontif_Salivon::normalAtk(Player& p)
{
	cout << "Pontif_Salivon use normal attack" << endl;
	p.receiveDamage(getAtk(), "atk");
}
void Pontif_Salivon::PhantonStrike(Player& p)
{
	cout << "Pontif_Salivon use phanton attack" << endl;
	p.receiveDamage(getAtk() * 2, "atk");
	p.receiveDamage(getMagicAtk() * 2, "magic");
}
void Pontif_Salivon::MagicalWave(Player& p)
{
	cout << "Pontif_Salivon use magic wave" << endl;
	p.receiveDamage(getMagicAtk(), "magic");
}
void Pontif_Salivon::TripleMelee(Player& p)
{
	cout << "Pontif_Salivon use triple attack" << endl;
	p.receiveDamage(getAtk() * 3, "atk");
}
void Pontif_Salivon::FireAttack(Player& p)
{
	cout << "Pontif_Salivon use FireAttack" << endl;
	p.receiveDamage(getAtk() * 2, "atk");
	p.receiveDamage(getMagicAtk() / 3, "magic");
}