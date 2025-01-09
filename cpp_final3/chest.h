#pragma once
#include"Player.h"
#include"HealthPotion.h"
#include"MagicPotion.h"
#include"Stone_helmet.h"
#include"Stone_Armor.h"
#include"Stone_Leg_Armor.h"
#include"Stone_Hand_Armor.h"
#include"Iron_Helmet.h"
#include"Iron_Armor.h"
#include"Iron_Leg_Armor.h"
#include"Iron_Hand_Armor.h"
#include"Gold_Helmet.h"
#include"Gold_Armor.h"
#include"Gold_Leg_Armor.h"
#include"Gold_Hand_Armor.h"
#include"Diamond_Helmet.h"
#include"Diamond_Armor.h"
#include"Diamond_Leg_Armor.h"
#include"Diamond_Hand_Armor.h"
#include"Leather_helmet.h"
#include"Leather_Armor.h"
#include"Leather_Leg_Armor.h"
#include"Leather_hand_armor.h"
#include"Wood_Sword.h"
#include"Stone_Sword.h"
#include"Iron_Sword.h"
#include"Gold_Sword.h"
#include"Diamond_Sword.h"
#include"Magic_Amulet.h"
#include"Heart_Amulet.h"
#include"Dfs_Amulet.h"
#include"Strength_Amulet.h"

class HealthPotion;
class MagicPotion;

class Item;
class Player;
class Leather_helmet;
class Leather_Armor;
class Leather_Leg_Armor;
class Leather_hand_armor;
class Stone_helmet;
class Stone_Armor;
class Stone_Leg_Armor;
class Stone_Hand_Armor;
class Iron_Helmet;
class Iron_Armor;
class Iron_Leg_Armor;
class Iron_Hand_Armor;
class Gold_Helmet;
class Gold_Armor;
class Gold_Leg_Armor;
class Gold_Hand_Armor;
class Diamond_Helmet;
class Diamond_Armor;
class Diamond_Leg_Armor;
class Diamond_Hand_Armor;
class Wood_Sword;
class Stone_Sword;
class Iron_Sword;
class Gold_Sword;
class Diamond_Sword;
class Magic_Amulet;
class Heart_Amulet;
class Dfs_Amulet;
class Strength_Amulet;

class chest
{

private:
	//leather
	Leather_helmet leather_helmet;
	Leather_Armor leather_Armor;
	Leather_Leg_Armor leather_leg_armor;
	Leather_hand_armor leather_hand_armor;
	//stone
	Stone_helmet stone_helmet;
	Stone_Armor stone_armor;
	Stone_Leg_Armor stone_leg_armor;
	Stone_Hand_Armor stone_hand_armor;
	//iron
	Iron_Helmet iron_helmet;
	Iron_Armor iron_armor;
	Iron_Leg_Armor iron_leg_armor;
	Iron_Hand_Armor iron_hand_armor;
	//gold
	Gold_Helmet gold_helmet;
	Gold_Armor gold_armor;
	Gold_Leg_Armor gold_leg_armor;
	Gold_Hand_Armor gold_hand_armor;
	//diamond
	Diamond_Helmet diamond_helmet;
	Diamond_Armor diamond_armor;
	Diamond_Leg_Armor diamond_leg_armor;
	Diamond_Hand_Armor diamond_hand_armor;
	//sword
	Wood_Sword wood_swrod;
	Stone_Sword stone_sword;
	Iron_Sword iron_sword;
	Gold_Sword gold_sword;
	Diamond_Sword diamond_sword;
	//Amulet
	Heart_Amulet heart_amulet;
	Magic_Amulet magic_amulet;
	Strength_Amulet strength_amulet;
	Dfs_Amulet dfs_amulet;

	//Items
	HealthPotion healthPotion;
	MagicPotion magicPotion;
	vector<Equipment> possibleEquipment =
	{
		leather_helmet,
		leather_Armor,
		leather_leg_armor,
		leather_hand_armor,
		stone_helmet,
		stone_armor,
		stone_leg_armor,
		stone_hand_armor,
		iron_helmet,
		iron_armor,
		iron_leg_armor,
		iron_hand_armor,
		gold_helmet,
		gold_armor,
		gold_leg_armor,
		gold_hand_armor,
		diamond_helmet,
		diamond_armor,
		diamond_leg_armor,
		diamond_hand_armor,
		wood_swrod,
		stone_sword,
		iron_sword,
		gold_sword,
		diamond_sword,
		heart_amulet,
		magic_amulet,
		strength_amulet,
		dfs_amulet,
	};
public:
	void OpenChest(Player&);
	Item generateItem();
	//Equipment generateEquipment();
};

