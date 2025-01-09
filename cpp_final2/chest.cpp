#include "chest.h"
#include<vector>
#include<ctime>

using namespace std;

Item chest::generateItem()
{
	vector<Item> possibleItem =
	{
		healthPotion,
		magicPotion
	};
	srand(time(nullptr));
	int randIndex = rand() % possibleItem.size();
	return possibleItem[randIndex];
}
/*Equipment chest::generateEquipment()
{

}*/
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
			p.addItemToInventory(p, &newItem);
			break;
		}
		case 3:
		{
			srand(time(nullptr));
			int randIndex = rand() % possibleEquipment.size();
			Equipment* newEquipment = &possibleEquipment[randIndex];
			cout << "You found " << newEquipment->getName() << endl;
			if (newEquipment->getType() == "Helmet")
				p.addHelmet(newEquipment);
			else if (newEquipment->getType() == "Armor")
				p.addArmor(newEquipment);
			else if (newEquipment->getType() == "LegArmor")
				p.addLeg_Armor(newEquipment);
			else if (newEquipment->getType() == "Hand_Armor")
				p.addHand_Armor(newEquipment);
			else if (newEquipment->getType() == "Amulet")
				p.addAmulet(newEquipment);
			else if (newEquipment->getType() == "Sword")
				p.addSword(newEquipment);
			break;
		}
		default:
			break;
	}
}