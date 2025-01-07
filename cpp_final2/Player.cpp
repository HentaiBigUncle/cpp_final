#pragma once
#include "Player.h"
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

Player::Player(int c, string n, character ch) :
	coin(c), name(n), chara(&ch)
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
map<string, Item>* Player::getInventor()
{
	return inventory;
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
	int i = 1;
	for (map<string, Item>::iterator it = inventory->begin(); it != inventory->end(); it++)
	{
		cout << i++ << ". " << "name: " << it->first << " amount: " << it->second.getAmount() << endl;
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
//display equipment
void Player::displayHelmet()
{
	if (helmet.size() == 0)
		cout << "No Helmet" << endl;
	else
	{
		for (int i = 0; i < helmet.size(); i++)
		{
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
	cin >> n;
	if (n > helmet.size() || n < 1)
		cout << "no such helmet" << endl;
	else
	{
		if (equipment[0] == 0)
		{
			equipment[0] = &helmet[n - 1];
			equipment[0]->AddProperty(p);
		}
		else
		{
			equipment[0]->MinusProperty(p);
			equipment[0] = &helmet[n - 1];
			equipment[0]->AddProperty(p);
		}
	}
	
}
void Player::EquipArmor(Player& p)
{
	int n = 0;
	cout << "enter the number to equip armor" << endl;
	displayArmor();
	cin >> n;
	if (n > armor.size() || n < 1)
		cout << "no such armor" << endl;
	else
	{
		if (equipment[1] == 0)
		{
			equipment[1] = &armor[n - 1];
			equipment[1]->AddProperty(p);
		}
		else
		{
			equipment[1]->MinusProperty(p);
			equipment[1] = &armor[n - 1];
			equipment[1]->AddProperty(p);
		}
	}
}
void Player::EquipLegArmor(Player& p)
{
	int n = 0;
	cout << "enter the number to leg armor" << endl;
	displayLegArmor();
	cin >> n;
	if (n > leg_armor.size() || n < 1)
		cout << "no such leg armor" << endl;
	else
	{
		if (equipment[2] == 0)
		{
			equipment[2] = &leg_armor[n - 1];
			equipment[2]->AddProperty(p);
		}
		else
		{
			equipment[2]->MinusProperty(p);
			equipment[2] = &leg_armor[n - 1];
			equipment[2]->AddProperty(p);
		}
	}
}
void Player::EquipHandArmor(Player& p)
{
	int n = 0;
	cout << "enter the number to hand armor" << endl;
	displayHandArmor();
	cin >> n;
	if (n > hand_armor.size() || n < 1)
		cout << "no such hand armor" << endl;
	else
	{
		if (equipment[3] == 0)
		{
			equipment[3] = &hand_armor[n - 1];
			equipment[3]->AddProperty(p);
		}
		else
		{
			equipment[3]->MinusProperty(p);
			equipment[3] = &hand_armor[n - 1];
			equipment[3]->AddProperty(p);
		}
	}
}
void Player::EquipSword(Player& p)
{
	int n = 0;
	cout << "enter the number to equip sword" << endl;
	displaySword();
	cin >> n;
	if (n > Sword.size() || n < 1)
		cout << "no such Sword" << endl;
	else
	{
		if (equipment[4] == 0)
		{
			equipment[4] = &Sword[n - 1];
			equipment[4]->AddProperty(p);
		}
		else
		{
			equipment[4]->MinusProperty(p);
			equipment[4] = &Sword[n - 1];
			equipment[4]->AddProperty(p);
		}
	}
}
void Player::EquipAmulet(Player& p)
{
	int n = 0;
	cout << "enter the number to amulet" << endl;
	displayAmulet();
	cin >> n;
	if (n > Amulet.size() || n < 1)
		cout << "no such amulet" << endl;
	else
	{
		if (equipment[5] == 0)
		{
			equipment[5] = &Amulet[n - 1];
			equipment[5]->AddProperty(p);
		}
		else
		{
			equipment[5]->MinusProperty(p);
			equipment[5] = &Amulet[n - 1];
			equipment[5]->AddProperty(p);
		}
	}
}
void Player::displayItem()
{
	int i = 0;
	for (map<string, Item>::iterator it = inventory->begin(); it != inventory->end(); it++)
	{
		cout << i++ << ". " << it->first <<"Amount: "<<it->second.getAmount()<< endl;
		it->second.print();
	}
}

void Player::useItem(Player& p, enemy& e)
{
	displayItem();
	string str;
	bool isUse = false;
	while (!isUse)
	{
		cout << "enter the name of the item" << endl;
		cin >> str;
		for (map<string, Item>::iterator it = inventory->begin(); it != inventory->end(); it++)
		{
			if (it->first == str)
			{
				it->second.useItem(p, e);
				it->second.minusItemAmount();
				if (it->second.getAmount() == 0)
				{
					inventory->erase(it);
				}
				isUse = true;
			}
		}
		if (!isUse)
			cout << "No such item" << endl;
	}
}
