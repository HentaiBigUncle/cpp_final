#pragma once
#include<iostream>
#include"character.h"
#include<string>
#include<vector>
#include"enemy.h"
#include"Equipment.h"

#include<map>
#include"Item.h"
using namespace std;

class Equipment;
class Item;
class character;

class Player
{
	character* chara = NULL;
	map<string, Item> *inventory = NULL;
	int lv = 1;//level
	int coin;
	int exp = 0;
	int maxExp = 100;
	string role, name;
	bool isDie = false;

	Equipment *equipment[6] = {};//helmet, armor, leg, hand, sword, amulet
	vector<Equipment> helmet;
	vector<Equipment> armor;
	vector<Equipment> leg_armor;
	vector<Equipment> hand_armor;
	vector<Equipment> Sword;
	vector<Equipment> Amulet;
	void LevelStatsChange();
	void changeLv();

	//position
	int pX, pY;
	//level
	bool levelOneComplete = false;
	bool levelTwoComplete = false;
	bool levelThreeComplete = false;
	bool levelFourComplete = false;
public:
	Player(int, string, character);
	//get
	int getLevel();
	int getCoin();
	bool getDie();
	character* getCharacter();
	//change
	void changeExp(int);
	void changeCoin(int);
	void displayItems();
	void receiveDamage(int, string);

	Equipment *getEquipment();
	map<string, Item> *getInventor();
	
	void getCoinExpByEnemy(enemy*);

	void addHelmet(Equipment&);
	void addArmor(Equipment&);
	void addLeg_Armor(Equipment&);
	void addHand_Armor(Equipment&);
	void addSword(Equipment&);
	void addAmulet(Equipment&);

	/*void discardHelmet(Equipment&);
	void discardArmor(Equipment&);
	void discardHand_Armor(Equipment&);
	void discardLeg_Armor(Equipment&);
	void discardSword(Equipment&);
	void discardAmulet(Equipment&);*/

	vector<Equipment> getHelmet();
	vector<Equipment> getArmor();
	vector<Equipment> getLeg_Armor();
	vector<Equipment> getHand_Armor();
	vector<Equipment> getSword();
	vector<Equipment> getAmulet();

	void displayHelmet();
	void displayArmor();
	void displayLegArmor();
	void displayHandArmor();
	void displaySword();
	void displayAmulet();

	void Equip(Player&);
	void EquipHelmet(Player& );
	void EquipArmor(Player&);
	void EquipLegArmor(Player&);
	void EquipHandArmor(Player&);
	void EquipSword(Player&);
	void EquipAmulet(Player&);

	bool getLevel1();
	bool getLevel2();
	bool getLevel3();
	bool getLevel4();

	int getX();
	int getY();
	void changeX(int);
	void changeY(int);

	void changeLevel1();
	void changeLevel2();
	void changeLevel3();
	void changeLevel4();

	void displayItem();
	void useItem(Player&, enemy&);
	void print();
};

