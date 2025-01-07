#pragma once
#include"Item.h"

class Player;
class enemy;
class MagicPotion : public Item
{
public:
	MagicPotion(int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 20, int = 0, int = 20,  string = "MagicPotion");
	void useItem(Player&, enemy&) const override;
};

