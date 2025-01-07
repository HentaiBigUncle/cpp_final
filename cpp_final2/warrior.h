#pragma once
#include"character.h"
#include"enemy.h"

class enemy;

class warrior : public character
{
public:
	warrior(int = 20, int = 10 , int = 10 , int = 3 , int = 3 , int = 2 , string = "Warrior");
	void doubleAtk(enemy&, Player&) const;
	void healMyself(Player&) const;
	void holySword(enemy&, Player&) const;
	void strongAtk(enemy&, Player&) const;

	void displaySkill(Player&) const override;
	void useSkill(enemy&, Player&) const override;
};

