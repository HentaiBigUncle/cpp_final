#pragma once
#include<iostream>
#include"character.h"
#include<string>
#include<vector>
#include"enemy.h"
#include"Equipment.h"
#include"maze.h"
#include<map>
#include"Item.h"
using namespace std;

class maze;
class Equipment;
class Item;
class character;

class Player
{
	character* chara = NULL;
	int lv = 1;//level
	int coin;
	int exp = 0;
	int level = 1;
	int maxExp = 100;
	string role, name;
	bool isDie = false;

	vector<Equipment*> helmet;
	vector<Equipment*> armor;
	vector<Equipment*> leg_armor;
	vector<Equipment*> hand_armor;
	vector<Equipment*> Sword;
	vector<Equipment*> Amulet;
	void LevelStatsChange();
	void changeLv();

	//position
	int pX = 1, pY = 1;
	//level
	bool levelOneComplete = false;
	bool levelTwoComplete = false;
	bool levelThreeComplete = false;
	bool levelFourComplete = false;
public:
	Item* inventory[2] = {};
	Equipment* equipment[6] = {};//helmet, armor, leg, hand, sword, amulet
	Player(int, string, character*);
	//get
	int getLevelOfMaze();
	int getLevel();
	int getCoin();
	bool getDie();
	string getName();
	character* getCharacter();
	//change
	void changeLevelOfMaze();
	void changeExp(int);
	void changeCoin(int);

	void receiveDamage(int, string);
	
	void getCoinExpByEnemy(enemy*);

	void addItemToInventory(Player& p, Item* item);
	void addHelmet(Equipment*);
	void addArmor(Equipment*);
	void addLeg_Armor(Equipment*);
	void addHand_Armor(Equipment*);
	void addSword(Equipment*);
	void addAmulet(Equipment*);

	/*void discardHelmet(Equipment&);
	void discardArmor(Equipment&);
	void discardHand_Armor(Equipment&);
	void discardLeg_Armor(Equipment&);
	void discardSword(Equipment&);
	void discardAmulet(Equipment&);*/

	vector<Equipment*> getHelmet();
	vector<Equipment*> getArmor();
	vector<Equipment*> getLeg_Armor();
	vector<Equipment*> getHand_Armor();
	vector<Equipment*> getSword();
	vector<Equipment*> getAmulet();

	void displayHelmet();
	void displayArmor();
	void displayLegArmor();
	void displayHandArmor();
	void displaySword();
	void displayAmulet();

	void addItem(Item*);
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
	void resetXandY();

	void changeName(string);
	void changeType(string);
	void changeCharacter(character*);
	void changeLevel1();
	void changeLevel2();
	void changeLevel3();
	void changeLevel4();
	void changeDeath();

	void displayItem();
	void displayEquipment();
	void useItems(Player&, enemy&, maze&);
	void print();
};

