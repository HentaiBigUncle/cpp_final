#pragma once
#include<iostream>
#include<vector>
#include"warrior.h"
#include"Slime.h"
#include"Skeleton.h"
#include"Zombie.h"
#include"Player.h"
#include"maze.h"
#include"StrongSkeleton.h"
#include"GameManager.h"
#include"battle.h"
#include"shop.h"
#include"trap.h"
#include"Almighty_Amulet.h"
#include"Leather_helmet.h"
#include"MagicPotion.h"
#include"NamelessKing.h"
#include"Pontif_Salivon.h"
#include"LostPaladin.h"
#include"DarkKnight.h"
#include"GiantBat.h"
#include"EvilPriest.h"
#include"SalivonCultist.h"
#include"DiamondCrystalMob.h"
#include"GoldenFlower.h"
#include"LostKinght.h"
#include"stone_Knight.h"
#include"MagicSnake.h"
#include"dragonSlayer.h"
#include"Paladin.h"
#include"enchanter.h"
#include<conio.h>
#include<windows.h>
#include"Leather_Armor.h"
#include"Leather_hand_armor.h"
#include"Leather_Leg_Armor.h"
#include"Wood_Sword.h"

using namespace std;

//character c(maxHp, maxMp, atk, magicalAtk, dfs, magiclaDfs, type)
//enemy e(MaxHp, Atk, mAtk, Dfs, MDfs, c, e, level, t)
//maze m(int edge, char role)
//Player(int coin, string name, character)

//boss
StrongSkeleton strongSkeleton;
LostPaladin lostPaladin;
Pontif_Salivon pontif;
NamelessKing namelessKing;
//game maze 


GameManager GM;
battle b;
trap t;
event et;
chest ct;
shop sh;
//enemy
Slime slime;
Skeleton skely;
Zombie zombie;
SalivonCultist salivonCultist;
MagicSnake magicSnake;
DiamondCrystalMob diamondCrystal;
LostKinght lostKnight;
DarkKnight darkKnight;
stone_knight stoneKnight;
GoldenFlower goldenFlower;
GiantBat giantBat;
EvilPriest evilPriest;
dragonSlayer DragonSlayer;
Paladin paladin;

//player character
warrior w1;
enchanter e1;

vector<enemy> LevelOneEnemy;
vector<enemy> LevelTwoEnemy;
vector<enemy> LevelThreeEnemy;
vector<enemy> LevelFourEnemy;
Almighty_Amulet AA;
//initial equipment
Heart_Amulet heart;
Leather_helmet lh;
Leather_Armor la;
Leather_hand_armor lha;
Leather_Leg_Armor lla;
Wood_Sword wss;

Iron_Helmet Ih;

MagicPotion mps;
HealthPotion hpp;
void setUpLevel1();
void SetUpLevel2();
void setUpLevel3();
void SetUpLevel4();

void InitialEquip(Player& p)
{
	p.inventory[0] = &hpp;
	p.inventory[1] = &mps;
	/*p.equipment[0] = &lh;
	p.equipment[0]->AddProperty(p);
	p.addHelmet(&lh);
	p.equipment[1] = &la;
	p.equipment[1]->AddProperty(p);
	p.addArmor(&la);
	p.equipment[2] = &lla;
	p.equipment[2]->AddProperty(p);
	p.addLeg_Armor(&lla);
	p.equipment[3] = &lha;
	p.equipment[3]->AddProperty(p);
	p.addHand_Armor(&lha);
	p.equipment[4] = &wss;
	p.equipment[4]->AddProperty(p);
	p.addSword(&wss);
	p.equipment[5] = &heart;
	p.equipment[5]->AddProperty(p);
	p.addAmulet(&heart);*/
}
int main()
{
	Player p(10, "You didn't enter any name", &w1);

	string str;
	cout << "Welcome to the RPG Cave Game" << endl;
	cout << "please enter your name" << endl;
	getline(cin, str);
	if (str == "")
	{
		str = "You didn't enter any name";
	}
	p.changeName(str);
	cout << "Enter any char to continue" << endl;
	char ss;
	if (!_kbhit()) {}
	ss = _getch();
	system("cls");
	int choose = 0;
	cout << "enter the character you want" << endl;
	cout << "1. warrior" << endl;
	w1.print();
	cout << "2. enchanter" << endl;
	e1.print();
	while (true)
	{
		cin >> choose;
		if (choose >= 1 && choose <= 2)
		{
			if (choose == 1)
			{
				cout << "You choose warrior" << endl;
				p.changeCharacter(&w1);
				p.changeType("Warrior");
			}
			else if (choose == 2)
			{
				cout << "You choose enchanter" << endl;
				p.changeCharacter(&e1);
				p.changeType("Enchanter");
			}
			break;
		}
		else
		{
			cout << "no such character, choose again" << endl;
		}
	}
	cout << "enter any char to continue" << endl;
	if (!_kbhit()) {}
	ss = _getch();
	system("cls");

	cout << "Hello " << p.getName() << endl;
	cout << "These are your stats" << endl;
	p.print();

	InitialEquip(p);
	/*cout << "enter any char to continue" << endl;
	if (!_kbhit()) {}
	ss = _getch();
	system("cls");
	cout << "Here is your initial Equipment" << endl;
	p.displayEquipment();*/


	cout << "enter any char to continue" << endl;
	if (!_kbhit()) {}
	ss = _getch();
	system("cls");

	cout << "Here is yout initial item" << endl;
	p.displayItem();

	cout << "Enter any char to continue to level 1" << endl;
	while (!_kbhit()) {}
	ss = _getch();
	system("cls");
	
	//maze
	maze m1(5, p);
	//level1
	setUpLevel1();
	GM.level1(m1, p, LevelOneEnemy, b, et, ct, t, strongSkeleton);
	//level2
	
	if (!p.getDie())
	{
		GM.openShop(sh, p);
		maze m2(7, p);
		SetUpLevel2();
		GM.level2(m2, p, LevelTwoEnemy, b, et, ct, t, lostPaladin);
		if(p.getDie())
			GM.openShop(sh, p);
	}
	//level3
	if (!p.getDie())
	{
		maze m3(9, p);
		setUpLevel3();
		GM.level3(m3, p, LevelThreeEnemy, b, et, ct, t, pontif);
		if(p.getDie())
			GM.openShop(sh, p);
	}
	//level4
	if (!p.getDie())
	{
		maze m4(11, p);
		SetUpLevel4();
		GM.level4(m4, p, LevelFourEnemy, b, et, ct, t, namelessKing);
	}
	return 0;
}

void setUpLevel1()
{
	LevelOneEnemy.push_back(slime);
}
void SetUpLevel2()
{
	slime.changeLv(2);
	skely.changeLv(2);
	zombie.changeLv(2);
	giantBat.changeLv(2);
	magicSnake.changeLv(2);
	goldenFlower.changeLv(2);

	LevelTwoEnemy.push_back(slime);
	LevelTwoEnemy.push_back(skely);
	LevelTwoEnemy.push_back(zombie);
	LevelTwoEnemy.push_back(giantBat);
	LevelTwoEnemy.push_back(magicSnake);
	LevelTwoEnemy.push_back(goldenFlower);
}
void setUpLevel3()
{
	stoneKnight.changeLv(3);
	evilPriest.changeLv(3);
	salivonCultist.changeLv(3);
	diamondCrystal.changeLv(3);

	LevelThreeEnemy.push_back(stoneKnight);
	LevelThreeEnemy.push_back(evilPriest);
	LevelThreeEnemy.push_back(salivonCultist);
	LevelThreeEnemy.push_back(diamondCrystal);
}
void SetUpLevel4()
{
	darkKnight.changeLv(4);
	lostKnight.changeLv(4);
	DragonSlayer.changeLv(4);
	paladin.changeLv(4);

	LevelFourEnemy.push_back(darkKnight);
	LevelFourEnemy.push_back(lostKnight);
	LevelFourEnemy.push_back(DragonSlayer);
	LevelFourEnemy.push_back(paladin);
}