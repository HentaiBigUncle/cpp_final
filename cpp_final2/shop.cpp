#include "shop.h"

shop::shop()
{
	assignShopHelmet();
	assignShopArmor();
	assignShopLeg_Armor();
	assignShopHand_Armor();
	assignShopSword();
	assignShopAmulet();
	assignShopItems();
}
//assign
void shop::assignShopHelmet()
{
	shopHelmet.push_back(leather_helmet);
	shopHelmet.push_back(stone_helmet);
	shopHelmet.push_back(iron_helmet);
	shopHelmet.push_back(gold_helmet);
	shopHelmet.push_back(diamond_helmet);
}
void shop::assignShopArmor()
{
	shopArmor.push_back(leather_Armor);
	shopArmor.push_back(stone_armor);
	shopArmor.push_back(iron_armor);
	shopArmor.push_back(gold_armor);
	shopArmor.push_back(diamond_armor);
}
void shop::assignShopLeg_Armor()
{
	shopLeg_Armor.push_back(leather_leg_armor);
	shopLeg_Armor.push_back(stone_leg_armor);
	shopLeg_Armor.push_back(iron_leg_armor);
	shopLeg_Armor.push_back(gold_leg_armor);
	shopLeg_Armor.push_back(diamond_leg_armor);
}
void shop::assignShopHand_Armor()
{
	shopHand_Armor.push_back(leather_hand_armor);
	shopHand_Armor.push_back(stone_hand_armor);
	shopHand_Armor.push_back(iron_hand_armor);
	shopHand_Armor.push_back(gold_hand_armor);
	shopHand_Armor.push_back(diamond_hand_armor);
}
void shop::assignShopSword()
{
	shopSword.push_back(wood_sword);
	shopSword.push_back(stone_sword);
	shopSword.push_back(iron_sword);
	shopSword.push_back(gold_sword);
	shopSword.push_back(diamond_sword);
}
void shop::assignShopAmulet()
{
	shopAmulet.push_back(heart_amulet);
	shopAmulet.push_back(magic_amulet);
	shopAmulet.push_back(dfs_amulet);
	shopAmulet.push_back(strength_amulet);
}
void shop::assignShopItems()
{
	shopItem.push_back(magicPotion);
}
//display
void shop::displayShopHelmet()
{
	for (size_t i = 0; i < shopHelmet.size(); i++)
	{
		cout << i + 1 << ". " <<"Cost "<<shopHelmet[i].getGold()<<"$" << endl;
		shopHelmet[i].print();
		if (i == shopHelmet.size() - 1)
			cout << i + 2 << ". Not want to buy" << endl;
	}
	cout << "what you want to buy?" << endl;
}
void shop::displayShopArmor()
{
	for (size_t i = 0; i < shopArmor.size(); i++)
	{
		cout << i + 1 << ". " << "Cost " << shopArmor[i].getGold() << "$" << endl;
		shopArmor[i].print();
		if (i == shopArmor.size() - 1)
			cout << i + 2 << ". Not want to buy" << endl;
	}
	cout << "what you want to buy?" << endl;
}
void shop::displayShopLeg_Armor()
{
	for (size_t i = 0; i < shopLeg_Armor.size(); i++)
	{
		cout << i + 1 << ". " << "Cost " << shopLeg_Armor[i].getGold() << "$" << endl;
		shopLeg_Armor[i].print();
		if (i == shopLeg_Armor.size() - 1)
			cout << i + 2 << ". Not want to buy" << endl;
	}
	cout << "what you want to buy?" << endl;
}
void shop::displayShopHand_Armor()
{
	for (size_t i = 0; i < shopHand_Armor.size(); i++)
	{
		cout << i + 1 << ". " << "Cost " << shopHand_Armor[i].getGold() << "$" << endl;
		shopHand_Armor[i].print();
		if (i == shopHand_Armor.size() - 1)
			cout << i + 2 << ". Not want to buy" << endl;
	}
	cout << "what you want to buy?" << endl;
}
void shop::displayShopSword()
{
	for (size_t i = 0; i < shopSword.size(); i++)
	{
		cout << i + 1 << ". " << "Cost " << shopSword[i].getGold() << "$" << endl;
		shopSword[i].print();
		if (i == shopSword.size() - 1)
			cout << i + 2 << ". Not want to buy" << endl;
	}
	cout << "what you want to buy?" << endl;
}
void shop::displayShopAmulet()
{
	for (size_t i = 0; i < shopAmulet.size(); i++)
	{
		cout << i + 1 << ". " << "Cost " << shopAmulet[i].getGold() << "$" << endl;
		shopAmulet[i].print();
		if (i == shopAmulet.size() - 1)
			cout << i + 2 << ". Not want to buy" << endl;
	}
	cout << "what you want to buy?" << endl;
}
void shop::displayShopItems()
{
	for (size_t i = 0; i < shopItem.size(); i++)
	{
		cout << i + 1 << ". " << "Cost " << shopItem[i].getGold() << "$" << endl;
		shopItem[i].print();
		if (i == shopItem.size() - 1)
			cout << i + 2 << ". Not want to buy" << endl;
	}
	cout << "what you want to buy?" << endl;
}
//purchase
void shop::purchaseEquipmentItems(int command, Player& p)
{
	int choice = 0;
	bool isShop = true;
	if (command == 1)
	{
		while (isShop)
		{
			displayShopHelmet();
			cout << "You have " << p.getCoin() << " coin" << endl;
			cin >> choice;
			if (choice > 0 && choice <= shopHelmet.size() + 1)
			{
				if (choice == shopHelmet.size() + 1)
				{
					isShop = false;
					break;
				}
				Equipment eq = shopHelmet[choice - 1];
				if (p.getCoin() >= eq.getGold())
				{
					p.addHelmet(eq);
					p.changeCoin(-eq.getGold());
					cout << "You buy " << eq.getName() << endl;
				}
				else
				{
					cout << "not enough money" << endl;
				}
			}
			else
			{
				cout << "Invalid choice!" << endl;
				cout << "choose again" << endl;
			}
		}
	}
	else if (command == 2)
	{
		while (isShop)
		{
			displayShopArmor();
			cout << "You have " << p.getCoin() << "$" << endl;
			cin >> choice;
			if (choice > 0 && choice <= shopArmor.size() + 1)
			{
				if (choice == shopArmor.size() + 1)
				{
					isShop = false;
					break;
				}
				if (choice == shopArmor.size() + 1)
				{
					isShop = false;
					break;
				}
				Equipment eq = shopArmor[choice - 1];
				if (p.getCoin() >= eq.getGold())
				{
					p.addArmor(eq);
					p.changeCoin(-eq.getGold());
					cout << "You buy " << eq.getName() << endl;
				}
				else
				{
					cout << "not enough money" << endl;
				}
			}
			else
			{
				cout << "Invalid choice!" << endl;
				cout << "choose again" << endl;
			}
		}
	}
	else if (command == 3)
	{
		while (isShop)
		{
			displayShopLeg_Armor();
			cout << "You have " << p.getCoin() << "$" << endl;
			cin >> choice;
			if (choice > 0 && choice <= shopLeg_Armor.size() + 1)
			{
				if (choice == shopLeg_Armor.size() + 1)
				{
					isShop = false;
					break;
				}
				Equipment eq = shopLeg_Armor[choice - 1];
				if (p.getCoin() >= eq.getGold())
				{
					p.addLeg_Armor(eq);
					p.changeCoin(-eq.getGold());
					cout << "You buy " << eq.getName() << endl;
				}
				else
				{
					cout << "not enough money" << endl;
				}
			}
			else
			{
				cout << "Invalid choice!" << endl;
				cout << "choose again" << endl;
			}
		}
	}
	else if (command == 4)
	{
		while (isShop)
		{
			displayShopHand_Armor();
			cout << "You have " << p.getCoin() << "$" << endl;
			cin >> choice;
			if (choice > 0 && choice <= shopHand_Armor.size() + 1)
			{
				if (choice == shopHand_Armor.size() + 1)
				{
					isShop = false;
					break;
				}
				Equipment eq = shopHand_Armor[choice - 1];
				if (p.getCoin() >= eq.getGold())
				{
					p.addHand_Armor(eq);
					p.changeCoin(-eq.getGold());
					cout << "You buy " << eq.getName() << endl;
				}
				else
				{
					cout << "not enough money" << endl;
				}
			}
			else
			{
				cout << "Invalid choice!" << endl;
				cout << "choose again" << endl;
			}
		}
	}
	else if (command == 5)
	{
		while (isShop)
		{
			displayShopSword();
			cout << "You have " << p.getCoin() << "$" << endl;
			cin >> choice;
			if (choice > 0 && choice <= shopSword.size() + 1)
			{
				if (choice == shopSword.size() + 1)
				{
					isShop = false;
					break;
				}
				Equipment eq = shopSword[choice - 1];
				if (p.getCoin() >= eq.getGold())
				{
					p.addSword(eq);
					p.changeCoin(-eq.getGold());
					cout << "You buy " << eq.getName() << endl;
				}
				else
				{
					cout << "not enough money" << endl;
				}
			}
			else
			{
				cout << "Invalid choice!" << endl;
				cout << "choose again" << endl;
			}
		}
	}
	else if (command == 6)
	{
		while (isShop)
		{
			displayShopAmulet();
			cout << "You have " << p.getCoin() << "$" << endl;
			cin >> choice;
			if (choice > 0 && choice <= shopAmulet.size() + 1)
			{
				if (choice == shopAmulet.size() + 1)
				{
					isShop = false;
					break;
				}
				Equipment eq = shopAmulet[choice - 1];
				if (p.getCoin() >= eq.getGold())
				{
					p.addAmulet(eq);
					p.changeCoin(-eq.getGold());
					cout << "You buy " << eq.getName() << endl;
				}
				else
				{
					cout << "not enough money" << endl;
				}
			}
			else
			{
				cout << "Invalid choice!" << endl;
				cout << "choose again" << endl;
			}
		}
	}
	else if (command == 7)
	{
		while (isShop)
		{
			displayShopItems();
			cin >> choice;
			if (choice > 0 && choice <= shopItem.size() + 1)
			{
				if (choice == shopItem.size() + 1)
				{
					isShop = false;
					break;
				}
				Item item = shopItem[choice - 1];
				if (p.getCoin() >= item.getGold())
				{
					item.addItemToInventory(p, item);
					p.changeCoin(-item.getGold());
					cout << "You buy " << item.getName() << endl;
				}
				else
				{
					cout << "not enough money" << endl;
				}
			}
			else
			{
				cout << "Invalid choice!" << endl;
				cout << "choose again" << endl;
			}
		}
	}
}
void shop::Instruction()
{
	cout << "What you want" << endl;
	cout << "1. Helmet" << endl;
	cout << "2. Armor" << endl;
	cout << "3. Leg Armor" << endl;
	cout << "4. Hand Armor" << endl;
	cout << "5. Sword" << endl;
	cout << "6. Amulet" << endl;
	cout << "7. Item" << endl;
}