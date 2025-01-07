#pragma once
#include "Player.h"
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

Player::Player(int c, string n, character* ch) :
	coin(c), name(n), chara(ch)
{
	role = chara->getType();
}
//change
void Player::changeCoin(int c)
{
	coin = max(0, coin + c);
}
void Player::changeExp(int e)
{
	exp = max(0, exp + e);
	changeLv();
}
void Player::changeLv()
{
	while (exp >= maxExp)
	{
		lv += 1;
		exp -= maxExp;
		LevelStatsChange();
		maxExp += 50;
	}
}
//get
int Player::getCoin() { return coin; }
int Player::getLevel() { return lv; }
character* Player::getCharacter() { return chara; }
vector<Item> *Player::getInventor()
{
	return &inventory;
}
void Player::LevelStatsChange()
{
	chara->changeAtk(1);
	chara->changeMagicalAtk(1);
	chara->changeMaxHp(5);
	chara->changeMaxMp(1);
	chara->changeDfs(1);
	chara->changeMagicDfs(1);

	chara->setHp(chara->getMaxHp());
	chara->setMp(chara->getMaxMp());
}
void Player::receiveDamage(int damage, string str)
{
	if (str == "magic")
	{
		damage = max(0, damage - getCharacter()->getMagicalDfs());
		getCharacter()->changeHp(-damage);
		cout << "Player receive: " << damage << " magical damage" << endl;
	}
	else if (str == "atk")
	{
		damage = max(0, damage - getCharacter()->getDfs());
		getCharacter()->changeHp(-damage);
		cout << "Player receive: " << damage << " physical damage" << endl;
	}
}

void Player::getCoinExpByEnemy(enemy * e)
{
	coin += e->getCoin();
	changeExp(e->getExp());
}
void Player::print()
{
	cout << "Name: " << name <<" Type: " << role << " Level: " << lv <<" Exp: "<<exp<<"/"<<maxExp<< " Coin: " << coin << endl;
	chara->print();
}
Equipment* Player::getEquipment()
{
	return *equipment;
}
void Player::displayItems()
{
	for (int i = 0; i < inventory.size(); i++)
	{
		cout << i + 1 << ". " << inventory[i].getName() << " " << "Amount: " << endl;
		inventory[i].print();
	}
}
void Player::addHelmet(Equipment& e)
{
	helmet.push_back(e);
}
void Player::addArmor(Equipment& e)
{
	armor.push_back(e);
}
void Player::addHand_Armor(Equipment& e)
{
	hand_armor.push_back(e);
}
void Player::addLeg_Armor(Equipment& e)
{
	leg_armor.push_back(e);
}
void Player::addSword(Equipment& e)
{
	Sword.push_back(e);
}
void Player::addAmulet(Equipment& e)
{
	Amulet.push_back(e);
}

/*void Player::discardHelmet(Equipment& e)
{
	auto it = find(helmet->begin(), helmet->end(), e);
	int index = distance(helmet->begin(), it);
	helmet->erase(helmet->begin() + index);
}
void Player::discardArmor(Equipment& e)
{
	auto it = find(armor->begin(), armor->end(), e);
	int index = distance(armor->begin(), it);
	armor->erase(armor->begin() + index);
}
void Player::discardLeg_Armor(Equipment& e)
{
	auto it = find(leg_armor->begin(), leg_armor->end(), e);
	int index = distance(leg_armor->begin(), it);
	leg_armor->erase(leg_armor->begin() + index);
}
void Player::discardHand_Armor(Equipment& e)
{
	auto it = find(hand_armor->begin(), hand_armor->end(), e);
	int index = distance(hand_armor->begin(), it);
	hand_armor->erase(hand_armor->begin() + index);
}
void Player::discardSword(Equipment& e)
{
	auto it = find(Sword->begin(), Sword->end(), e);
	int index = distance(Sword->begin(), it);
	Sword->erase(Sword->begin() + index);
}
void Player::discardAmulet(Equipment& e)
{
	auto it = find(Amulet->begin(), Amulet->end(), e);
	int index = distance(Amulet->begin(), it);
	Amulet->erase(Amulet->begin() + index);
}*/

//get
bool Player::getLevel1() { return levelOneComplete; }
bool Player::getLevel2() { return levelTwoComplete; }
bool Player::getLevel3() { return levelThreeComplete; }
bool Player::getLevel4() { return levelFourComplete; }
int Player::getX() { return pX; }
int Player::getY() { return pY; }
bool Player::getDie() { return isDie; }
vector<Equipment> Player::getHelmet() { return helmet; }
vector<Equipment> Player::getArmor() { return armor; }
vector<Equipment> Player::getLeg_Armor() { return leg_armor; }
vector<Equipment> Player::getHand_Armor() { return hand_armor; }
vector<Equipment> Player::getSword() { return Sword; }
vector<Equipment> Player::getAmulet() { return Amulet; }

//change
void Player::changeLevel1() { levelOneComplete = true; }
void Player::changeLevel2() { levelTwoComplete = true; }
void Player::changeLevel3() { levelThreeComplete = true; }
void Player::changeLevel4() { levelFourComplete = true; }
void Player::changeX(int x) { pX += x; }
void Player::changeY(int y) { pY += y; }
void Player::changeDeath() { isDie = true; }
//display equipment
void Player::displayHelmet()
{
	if (helmet.size() == 0)
		cout << "No Helmet" << endl;
	else
	{
		for (int i = 0; i < helmet.size(); i++)
		{
			cout << i + 1 << ". ";
			helmet[i].print();
		}
	}
}
void Player::displayArmor()
{
	if (armor.size() == 0)
		cout << "No Armor" << endl;
	else
	{
		for (int i = 0; i < armor.size(); i++)
		{
			cout << i + 1 << ". ";
			armor[i].print();
		}
	}
}
void Player::displayLegArmor()
{
	if (leg_armor.size() == 0)
		cout << "No LegArmor" << endl;
	else
	{
		for (int i = 0; i < leg_armor.size(); i++)
		{
			cout << i + 1 << ". ";
			leg_armor[i].print();
		}
	}
}
void Player::displayHandArmor()
{
	if (hand_armor.size() == 0)
		cout << "No HandArmor" << endl;
	else
	{
		for (int i = 0; i < hand_armor.size(); i++)
		{
			cout << i + 1 << ". ";
			hand_armor[i].print();
		}
	}
}
void Player::displaySword()
{
	if (Sword.size() == 0)
		cout << "No Sword" << endl;
	else
	{
		for (int i = 0; i < Sword.size(); i++)
		{
			cout << i + 1 << ". ";
			Sword[i].print();
		}
	}
}
void Player::displayAmulet()
{
	if (Amulet.size() == 0)
		cout << "No Amulet" << endl;
	else
	{
		for (int i = 0; i < Amulet.size(); i++)
		{
			cout << i + 1 << ". ";
			Amulet[i].print();
		}
	}
}
//Equip
void Player::Equip(Player& p)
{
	int num = 0;
	cout << "What type of equipment you want to equip" << endl;
	cout << "1. Helmet" << endl;
	cout << "2. Armor" << endl;
	cout << "3. LegArmor" << endl;
	cout << "4. HandArmor" << endl;
	cout << "5. Sword" << endl;
	cout << "6. Amulet" << endl;
	cin >> num;
	if (num == 1)
		EquipHelmet(p);
	else if (num == 2)
		EquipArmor(p);
	else if (num == 3)
		EquipLegArmor(p);
	else if (num == 4)
		EquipHandArmor(p);
	else if (num == 5)
		EquipSword(p);
	else if (num == 6)
		EquipAmulet(p);
	else
		cout << "What are you doing, no such equipment" << endl;
}
void Player::EquipHelmet(Player& p)
{
	int n = 0;
	cout << "enter the number to equip helemt" << endl;
	displayHelmet();
	if (helmet.empty())
		return;
	while (true)
	{
		cout << "enter " << helmet.size() + 1 << " if you don't want to equip" << endl;
		cin >> n;
		if (n == helmet.size() + 1)
			break;
		if (n > helmet.size() || n < 1)
			cout << "no such helmet" << endl;
		else
		{
			if (equipment[0] == 0)
			{
				cout << "You equip " << helmet[n - 1].getName() << endl;
				equipment[0] = &helmet[n - 1];
				equipment[0]->AddProperty(p);
				break;
			}
			else
			{
				cout << "You unequip" << equipment[0]->getName() << endl;
				cout << "You equip " << helmet[n - 1].getName() << endl;
				equipment[0]->MinusProperty(p);
				equipment[0] = &helmet[n - 1];
				equipment[0]->AddProperty(p);
				break;
			}
		}
	}
}
void Player::EquipArmor(Player& p)
{
	int n = 0;
	cout << "enter the number to equip armor" << endl;
	displayArmor();
	if (armor.empty())
		return;
	while (true)
	{
		cout << "enter " << armor.size() + 1 << " if you don't want to equip" << endl;
		cin >> n;
		if (n == armor.size() + 1)
			break;
		if (n > armor.size() || n < 1)
			cout << "no such armor" << endl;
		else
		{
			if (equipment[1] == 0)
			{
				cout << "You equip " << armor[n - 1].getName() << endl;
				equipment[1] = &armor[n - 1];
				equipment[1]->AddProperty(p);
				break;
			}
			else
			{
				cout << "You unequip" << equipment[1]->getName() << endl;
				cout << "You equip " << armor[n - 1].getName() << endl;
				equipment[1]->MinusProperty(p);
				equipment[1] = &armor[n - 1];
				equipment[1]->AddProperty(p);
				break;
			}
		}
	}
}
void Player::EquipLegArmor(Player& p)
{
	int n = 0;
	cout << "enter the number to leg armor" << endl;
	displayLegArmor();
	if (leg_armor.empty())
		return;
	while(true)
	{
		cout << "enter " << leg_armor.size() + 1 << " if you don't want to equip" << endl;
		cin >> n;
		if (n == leg_armor.size() + 1)
			break;
		if (n > leg_armor.size() || n < 1)
			cout << "no such leg armor" << endl;
		else
		{
			if (equipment[2] == 0)
			{
				cout << "You equip " << leg_armor[n - 1].getName();
				equipment[2] = &leg_armor[n - 1];
				equipment[2]->AddProperty(p);
				break;
			}
			else
			{
				cout << "You unequip" << equipment[2]->getName() << endl;
				cout << "You equip " << leg_armor[n - 1].getName();
				equipment[2]->MinusProperty(p);
				equipment[2] = &leg_armor[n - 1];
				equipment[2]->AddProperty(p);
				break;
			}
		}
	}
}
void Player::EquipHandArmor(Player& p)
{
	int n = 0;
	cout << "enter the number to hand armor" << endl;
	displayHandArmor();
	if (hand_armor.empty())
		return;
	while (true)
	{
		cout << "enter " << hand_armor.size() + 1 <<" if you don't want to equip" << endl;
		cin >> n;
		if (n == hand_armor.size() + 1)
			break;
		if (n > hand_armor.size() || n < 1)
			cout << "no such hand armor" << endl;
		else
		{
			if (equipment[3] == 0)
			{
				cout << "You equip " << hand_armor[n - 1].getName() << endl;
				equipment[3] = &hand_armor[n - 1];
				equipment[3]->AddProperty(p);
				break;
			}
			else
			{
				cout << "You unequip" << equipment[3]->getName() << endl;
				cout << "You equip " << hand_armor[n - 1].getName() << endl;
				equipment[3]->MinusProperty(p);
				equipment[3] = &hand_armor[n - 1];
				equipment[3]->AddProperty(p);
				break;
			}
		}
	}
}
void Player::EquipSword(Player& p)
{
	int n = 0;
	cout << "enter the number to equip sword" << endl;
	displaySword();
	if (Sword.empty())
		return;
	while (true)
	{
		cout << "enter " << Sword.size() + 1 << " if you don't want to equip" << endl;
		cin >> n;
		if (n == Sword.size() + 1)
			break;
		if (n > Sword.size() || n < 1)
			cout << "no such Sword" << endl;
		else
		{
			if (equipment[4] == 0)
			{
				cout << "You equip " << Sword[n - 1].getName() << endl;
				equipment[4] = &Sword[n - 1];
				equipment[4]->AddProperty(p);
				break;
			}
			else
			{
				cout << "You unequip" << equipment[4]->getName() << endl;
				cout << "You equip " << Sword[n - 1].getName() << endl;
				equipment[4]->MinusProperty(p);
				equipment[4] = &Sword[n - 1];
				equipment[4]->AddProperty(p);
				break;
			}
		}
	}
}
void Player::EquipAmulet(Player& p)
{
	int n = 0;
	cout << "enter the number to amulet" << endl;
	displayAmulet();
	if (Amulet.empty())
		return;
	while (true)
	{
		cout << "enter " << Amulet.size() + 1 << " if you don't want to equip" << endl;
		cin >> n;
		if (n == Amulet.size() + 1)
			break;
		if (n > Amulet.size() || n < 1)
			cout << "no such amulet" << endl;
		else
		{
			if (equipment[5] == 0)
			{
				cout << "You equip " << Amulet[n - 1].getName() << endl;
				equipment[5] = &Amulet[n - 1];
				equipment[5]->AddProperty(p);
				break;
			}
			else
			{
				cout << "You unequip" << equipment[5]->getName() << endl;
				cout << "You equip " << Amulet[n - 1].getName() << endl;
				equipment[5]->MinusProperty(p);
				equipment[5] = &Amulet[n - 1];
				equipment[5]->AddProperty(p);
				break;
			}
		}
	}
}
void Player::addItem(Item& item)
{
	inventory.push_back(item);
}
void Player::displayItem()
{
	if (!inventory.empty())
	{
		for (int i = 0; i < inventory.size(); i++)
		{
			cout << i+1 << ". " << inventory[i].getName() << " Amount: " << inventory[i].getAmount() << endl;
			inventory[i].print();
		}
	}
	else
	{
		cout << "no item"<<endl;
	}
}

void Player::useItem(Player& p, enemy& e)
{
	displayItem();
	if (inventory.empty())
	{
		cout << "No item to use" << endl;
		return;
	}
	int n = 0;
	while (true)
	{
		cout << "enter the number of the item (" <<inventory.size() + 1<<" = exit" << endl;
		cin >> n;
		if (n == inventory.size() + 1)
			return;
		if (n >= 1 && n <= inventory.size())
		{
			inventory[n - 1].useItem(p, e);
			inventory[n - 1].minusItemAmount();
			if (inventory[n - 1].getAmount() == 0)
			{
				inventory.erase(inventory.begin() + n - 1);
			}
			break;
		}
		else
		{
			cout << "wrong number, enter again!" << endl;
		}
	}
}
void Player::displayEquipment()
{
	bool haveEquipment = false;
	if (equipment[0] != 0)
	{
		cout << "Helmet: ";
		equipment[0]->print();
		haveEquipment = true;
	}
	if (equipment[1] != 0)
	{
		cout<<"Armor: ";
		equipment[1]->print();
		haveEquipment = true;
	}
	if (equipment[2] != 0)
	{
		cout << "LegArmor: ";
		equipment[2]->print();
		haveEquipment = true;
	}
	if (equipment[3] != 0)
	{
		cout << "Hand Armor: ";
		equipment[3]->print();
		haveEquipment = true;
	}
	if (equipment[4] != 0)
	{
		cout << "Sword: ";
		equipment[4]->print();
		haveEquipment = true;
	}
	if (equipment[5] != 0)
	{
		cout << "Amulet: ";
		equipment[5]->print();
		haveEquipment = true;
	}
	if (!haveEquipment)
		cout << "No Equipment is equipped" << endl;
}
int Player::getLevelOfMaze()
{
	return level;
}
void Player::changeLevelOfMaze()
{
	level += 1;
}