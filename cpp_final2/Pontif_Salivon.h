#pragma once
#include"boss.h"

class Pontif_Salivon : public boss
{
public:
	Pontif_Salivon(int = 250, int = 30, int =20 , int = 15, int = 20, int = 250, int = 2500, int = 1, string = "Pontif_Salivon");
	void atk(Player&) override;
	void normalAtk(Player&);
	void PhantonStrike(Player&);
	void MagicalWave(Player&);
	void FireAttack(Player&);
	void TripleMelee(Player&);
};

