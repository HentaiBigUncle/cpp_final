#pragma once
#include"boss.h"

class NamelessKing : public boss
{
public:
	NamelessKing(int = 500, int = 75, int = 50, int = 30, int = 20, int = 500, int = 5000, int = 1, string = "NamelessKing");
	void atk(Player&) override;
	void normalAtk(Player&);
	void Lightning(Player&);
	void Thrust(Player&);
	void WindWave(Player&);
	void DragonFire(Player&);
	void ThousandsLightBurn(Player&);
};

