#pragma once
#include"character.h"
#include"enemy.h"

class enemy;

class warrior : public character
{
	bool isUse = false;
public:
	warrior(int = 20, int = 10 , int = 10 , int = 3 , int = 3 , int = 2 , string = "Warrior");
	void doubleAtk(enemy&, Player&) ;
	void healMyself(Player&) ;
	void holySword(enemy&, Player&) ;
	void strongAtk(enemy&, Player&) ;
	void ZenithHalf(enemy&, Player&);

	void displaySkill(Player&)  override;
	void useSkill(enemy&, Player&)  override;
};

