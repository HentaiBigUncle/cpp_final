#pragma once
#include"enemy.h"
#include"character.h"

class enchanter : public character
{
	bool isUse = false;
public:
	enchanter(int = 15, int = 25, int = 5, int = 13, int = 2, int = 4, string = "Enchanter");
	void heal(Player&);
	void MagicSpine(Player&, enemy&);
	void StrongMagicGun(Player&, enemy&);
	void MagicSaintSword(Player&, enemy&);
	void MilionMagic(Player&, enemy&);

	void displaySkill(Player&)  override;
	void useSkill(enemy&, Player&)  override;
};

