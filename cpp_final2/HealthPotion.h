#pragma once
#include"Item.h"

class Player;
class enemy;
class HealthPotion : public Item
{
public:
	HealthPotion(int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 50, int = 0, int = 0, int = 20,  string = "HealthPotion");
	void useItem(Player&, enemy&) const override;
};
