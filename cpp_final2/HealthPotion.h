#pragma once
#include"Item.h"

class maze;
class Player;
class enemy;
class HealthPotion : public Item
{
public:
	HealthPotion(int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 20, int = 0, int = 0, int = 50,  string = "HealthPotion");
	void useItem(Player&, enemy&) override;
};
