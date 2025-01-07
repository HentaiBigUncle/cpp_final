#include "chest.h"
#include<vector>
#include<ctime>

using namespace std;

Item chest::generateItem()
{
	vector<Item> possibleItem =
	{
		//healthPotion,
		magicPotion
	};
	srand(time(NULL));
	int randIndex = rand() % possibleItem.size();
	return possibleItem[randIndex];
}
Equipment chest::generateEquipment()
{
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
	srand(time(NULL));
	int randIndex = rand() % possibleEquipment.size();
	return possibleEquipment[randIndex];
}
void chest::OpenChest(Player& p)
{
	cout << "You found a chest! Opening it..." << endl;
	int rewardType = rand() % 4;// 0 = coin, 1 = exp, 2 = item, 3 = equipment
	switch (rewardType)
	{
		case 0:
		{
			int coin = rand() % 41 + 10;
			p.changeCoin(coin);
			cout << "You found " << coin << " coins in the chest!" << endl;
			break;
		}
		case 1:
		{
			int exp = rand() % 101 + 50;
			p.changeExp(exp);
			cout << "You found " << exp << " exp in the chest!" << endl;
			break;
		}
		case 2:
		{
			Item newItem = generateItem();
			cout << "You found " << newItem.getName() << endl;
			newItem.addItemToInventory(p, newItem);
			break;
		}
		case 3:
		{
			Equipment newEquipment = generateEquipment();
			cout << "You found " << newEquipment.getName() << endl;
			if (newEquipment.getType() == "Helmet")
				p.addHelmet(newEquipment);
			else if (newEquipment.getType() == "Armor")
				p.addArmor(newEquipment);
			else if (newEquipment.getType() == "LegArmor")
				p.addLeg_Armor(newEquipment);
			else if (newEquipment.getType() == "Hand_Armor")
				p.addHand_Armor(newEquipment);
			else if (newEquipment.getType() == "Amulet")
				p.addAmulet(newEquipment);
			else if(newEquipment.getType() == "Sword")
			break;
		}
		default:
			break;
	}
}