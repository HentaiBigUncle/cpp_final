#include "shop.h"
#include<iostream>

using namespace std;

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
	shopSword.push_back(zenith);
}
void shop::assignShopAmulet()
{
	shopAmulet.push_back(heart_amulet);
	shopAmulet.push_back(magic_amulet);
	shopAmulet.push_back(dfs_amulet);
	shopAmulet.push_back(strength_amulet);
	shopAmulet.push_back(almighty_Amulet);
}
void shop::assignShopItems()
{
	shopItem.push_back(magicPotion);
	shopItem.push_back(healthPotion);
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
	system("cls");
	if (command == 1)
	{
		displayShopHelmet();
		while (isShop)
		{
			cout << "You have " << p.getCoin() << " coin" << endl;
			cin >> choice;
			if (choice > 0 && choice <= shopHelmet.size() + 1)
			{
				if (choice == shopHelmet.size() + 1)
				{
					isShop = false;
					break;
				}
				Equipment *eq = &shopHelmet[choice - 1];
				if (p.getCoin() >= eq->getGold())
				{
					p.addHelmet(eq);
					p.changeCoin(-eq->getGold());
					cout << "You buy " << eq->getName() << endl;
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
		displayShopArmor();
		while (isShop)
		{
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
				Equipment *eq = &shopArmor[choice - 1];
				if (p.getCoin() >= eq->getGold())
				{
					p.addArmor(eq);
					p.changeCoin(-eq->getGold());
					cout << "You buy " << eq->getName() << endl;
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
		displayShopLeg_Armor();
		while (isShop)
		{
			cout << "You have " << p.getCoin() << "$" << endl;
			cin >> choice;
			if (choice > 0 && choice <= shopLeg_Armor.size() + 1)
			{
				if (choice == shopLeg_Armor.size() + 1)
				{
					isShop = false;
					break;
				}
				Equipment* eq = &shopLeg_Armor[choice - 1];
				if (p.getCoin() >= eq->getGold())
				{
					p.addLeg_Armor(eq);
					p.changeCoin(-eq->getGold());
					cout << "You buy " << eq->getName() << endl;
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
		displayShopHand_Armor();
		while (isShop)
		{
			cout << "You have " << p.getCoin() << "$" << endl;
			cin >> choice;
			if (choice > 0 && choice <= shopHand_Armor.size() + 1)
			{
				if (choice == shopHand_Armor.size() + 1)
				{
					isShop = false;
					break;
				}
				Equipment *eq = &shopHand_Armor[choice - 1];
				if (p.getCoin() >= eq->getGold())
				{
					p.addHand_Armor(eq);
					p.changeCoin(-eq->getGold());
					cout << "You buy " << eq->getName() << endl;
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
		displayShopSword();
		while (isShop)
		{
			cout << "You have " << p.getCoin() << "$" << endl;
			cin >> choice;
			if (choice > 0 && choice <= shopSword.size() + 1)
			{
				if (choice == shopSword.size() + 1)
				{
					isShop = false;
					break;
				}
				Equipment* eq = &shopSword[choice - 1];
				if (p.getCoin() >= eq->getGold())
				{
					p.addSword(eq);
					p.changeCoin(-eq->getGold());
					cout << "You buy " << eq->getName() << endl;
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
		displayShopAmulet();
		while (isShop)
		{
			cout << "You have " << p.getCoin() << "$" << endl;
			cin >> choice;
			if (choice > 0 && choice <= shopAmulet.size() + 1)
			{
				if (choice == shopAmulet.size() + 1)
				{
					isShop = false;
					break;
				}
				Equipment *eq = &shopAmulet[choice - 1];
				if (p.getCoin() >= eq->getGold())
				{
					p.addAmulet(eq);
					p.changeCoin(-eq->getGold());
					cout << "You buy " << eq->getName() << endl;
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
		displayShopItems();
		while (isShop)
		{
			cout << "You have " << p.getCoin() << "coin" << endl;
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
					p.addItemToInventory(p, &item);
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
/*void shop::sellEquipment(Player& p)
{
	int n;
	bool isSell = true;
	while (isSell)
	{
		SellInstruction();
		cout << "7 = exit" << endl;
		cin >> n;
		if (n == 1)
		{
			int l = 0;
			if (p.getHelmet().empty())
			{
				cout << "no helmet to sell" << endl;
			}
			else
			{
				for (int i = 0; i < p.getHelmet().size(); i++)
				{
					cout << i + 1 << ". Name: " << p.getHelmet().at(i).getName() << " " << p.getHelmet().at(i).getGold() << " coin" << endl;
				}
				cout << "what helmet you want to sell" << endl;
				cout << p.getHelmet().size() + 1<< " = exit" << endl;
				while (true)
				{	
					cin >> l;
					if (l == p.getHelmet().size() + 1)
						break;
					if (l >= 1 && l <= p.getHelmet().size())
					{
						p.getHelmet().erase(p.getHelmet().begin() + l - 1);
						p.changeCoin(p.getHelmet().at(l - 1).getGold());
					}
					else
					{
						cout << "no such helmet" << endl;
					}
					if (p.getHelmet().empty())
					{
						cout << "no helmet to sell" << endl;
						break;
					}
				}
			}
		}
		else if (n == 2)
		{
			int l = 0;
			if (p.getArmor().empty())
			{
				cout << "no armor to sell" << endl;
			}
			else
			{
				for (int i = 0; i < p.getArmor().size(); i++)
				{
					cout << i + 1 << ". Name: " << p.getArmor().at(i).getName() << " " << p.getArmor().at(i).getGold() << " coin" << endl;
				}
				cout << p.getArmor().size() + 1 << " = exit" << endl;
				cout << "what armor you want to sell" << endl;
				while (true)
				{
					cin >> l;
					if (l == p.getArmor().size() + 1)
						break;
					if (l >= 1 && l <= p.getArmor().size())
					{
						p.getArmor().erase(p.getArmor().begin() + l - 1);
						p.changeCoin(p.getArmor().at(l - 1).getGold());
					}
					else
					{
						cout << "no such armor" << endl;
					}
					if (p.getArmor().empty())
					{
						cout << "no armor to sell" << endl;
						break;
					}
				}
			}
		}
		else if (n == 3)
		{
			int l = 0;
			if (p.getLeg_Armor().empty())
			{
				cout << "no leg armor to sell" << endl;
			}
			else
			{
				for (int i = 0; i < p.getLeg_Armor().size(); i++)
				{
					cout << i + 1 << ". Name: " << p.getLeg_Armor().at(i).getName() << " " << p.getLeg_Armor().at(i).getGold() << " coin" << endl;
				}
				cout << p.getLeg_Armor().size()  + 1<< " = exit" << endl;
				cout << "what leg armor you want to sell" << endl;
				while (true)
				{
					cin >> l;
					if (l == p.getLeg_Armor().size() + 1)
						break;
					if (l >= 1 && l <= p.getLeg_Armor().size())
					{
						p.getLeg_Armor().erase(p.getLeg_Armor().begin() + l - 1);
						p.changeCoin(p.getLeg_Armor().at(l - 1).getGold());
					}
					else
					{
						cout << "no such leg armor, enter again" << endl;
					}
					if (p.getLeg_Armor().empty())
					{
						cout << "no leg armor to sell" << endl;
						break;
					}
				}
			}
		}
		else if (n == 4)
		{
			int l = 0;
			if (p.getHand_Armor().empty())
			{
				cout << "no hand armor to sell" << endl;
			}
			else
			{
				for (int i = 0; i < p.getHand_Armor().size(); i++)
				{
					cout << i + 1 << ". Name: " << p.getHand_Armor().at(i).getName() << " " << p.getHand_Armor().at(i).getGold() << " coin" << endl;
				}
				cout << p.getHand_Armor().size()  + 1<< " = exit" << endl;
				cout << "what hand armor you want to sell" << endl;
				while (true)
				{				
					cin >> l;
					if (l == p.getHand_Armor().size() + 1)
						break;
					if (l >= 1 && l <= p.getHand_Armor().size())
					{
						p.getHand_Armor().erase(p.getHand_Armor().begin() + l - 1);
						p.changeCoin(p.getHand_Armor().at(l - 1).getGold());
					}
					else
					{
						cout << "no such hand armor, enter again" << endl;
					}
					if (p.getHand_Armor().empty())
					{
						cout << "no hand armor to sell" << endl;
						break;
					}
				}
			}
		}
		else if (n == 5)
		{
			int l = 0;
			if (p.getSword().empty())
			{
				cout << "no sword to sell" << endl;
			}
			else
			{
				for (int i = 0; i < p.getSword().size(); i++)
				{
					cout << i + 1 << ". Name: " << p.getSword().at(i).getName() << " " << p.getSword().at(i).getGold() << " coin" << endl;
				}
				cout << p.getSword().size() + 1<< " = exit" << endl;
				cout << "what sword you want to sell" << endl;
				while (true)
				{
					cin >> l;
					if (l == p.getSword().size() + 1)
						break;
					if (l >= 1 && l <= p.getSword().size())
					{
						p.getSword().erase(p.getSword().begin() + l - 1);
						p.changeCoin(p.getSword().at(l - 1).getGold());
					}
					else
					{
						cout << "no such sword, enter again" << endl;
					}
					if (p.getSword().empty())
					{
						cout << "no sword to sell" << endl;
						break;
					}
				}
			}
		}
		else if (n == 6)
		{
			if (p.getAmulet().empty())
			{
				cout << "no amulet to sell" << endl;
			}
			else
			{
				for (int i = 0; i < p.getAmulet().size(); i++)
				{
					cout << i + 1 << ". Name: " << p.getAmulet().at(i).getName() << " " << p.getAmulet().at(i).getGold() << " coin" << endl;
				}
				cout << p.getAmulet().size() + 1<< " = exit" << endl;
				cout << "what amulet you want to sell" << endl;
				while (true)
				{
					int l = 0;
					cin >> l;
					if (l == p.getAmulet().size() + 1)
						break;
					if (l >= 1 && l <= p.getAmulet().size())
					{
						p.getAmulet().erase(p.getAmulet().begin() + l - 1);
						p.changeCoin(p.getAmulet().at(l - 1).getGold());
					}
					else
					{
						cout << "no such amulet, enter again" << endl;
					}
					if (p.getAmulet().empty())
					{
						cout << "no amulet to sell" << endl;
						break;
					}
				}
			}
		}
		else if(n== 7)
		{
			break;
		}
		else
			cout << "wrong, enter again" << endl;
	}
}*/
/*void shop::sellItem(Player& p)
{
	int n = 0;
	bool isSell = true;
	if (p.getInventor().empty())
	{
		cout << "You didn't have item to sell" << endl;
		return;
	}
	cout << "what item you want to sell" << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << i + 1 << ". " << p.getInventor().at(i)->getName() << " " << p.getInventor().at(i)->getGold() << " coin" << endl;
	}
	cout << p.getInventor().size() + 1 << " to exit" << endl;
	while (isSell)
	{
		cin >> n;
		if (n == p.getInventor().size() + 1)
		{
			isSell = false;
			break;
		}
		if (n >= 1 && n <= p.getInventor().size())
		{
			p.getInventor().at(n - 1)->minusItemAmount();
			if (p.getInventor().at(n - 1)->getAmount() == 0)
			{
				p.getInventor().erase(p.getInventor().begin() + n - 1);
			}
			p.changeCoin(p.getInventor().at(n - 1)->getGold());
			if (p.getInventor().empty())
			{
				cout << "no more item to sell" << endl;
				break;
			}
		}
		else
		{
			cout << "no such Item, enter again" << endl;
		}
	}
}*/
/*void shop::sellItemEquipment(int command, Player& p)
{
	if (command == 1)
		sellEquipment(p);
	else if (command == 2)
		sellItem(p);
}*/
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
void shop::SellInstruction()
{
	cout << "What you want to sell" << endl;
	cout << "1. Helmet" << endl;
	cout << "2. Armor" << endl;
	cout << "3. Leg Armor" << endl;
	cout << "4. Hand Armor" << endl;
	cout << "5. Sword" << endl;
	cout << "6. Amulet" << endl;
}