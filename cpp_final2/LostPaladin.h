#pragma once
#include"boss.h"

using namespace std;

class LostPaladin : public boss 
{
public:
	LostPaladin(int = 75, int = 20, int = 10, int = 5, int = 5, int = 100, int = 1000, int = 1, string = "LostPaladin");
	void atk(Player&) override;
	void normalAtk(Player&);
	void ExGalibon(Player&);
	void SaintSwordAtk(Player&);
	void heal();
};

