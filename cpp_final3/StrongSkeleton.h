#pragma once
#include"boss.h"

class StrongSkeleton : public boss
{
public:
	StrongSkeleton(int  = 15, int = 10, int = 1, int = 2, int = 1, int = 40, int = 300, int = 1, string = "StrongSkeleton");
	void atk(Player&) override;
	void normalAtk(Player&);
	void strongAtk(Player&);
	void specialAtk(Player&);
};

