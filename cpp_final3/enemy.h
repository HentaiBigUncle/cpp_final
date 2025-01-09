#pragma once
#include<iostream>
#include<string>

using namespace std;

class enemy
{
protected:
	string type;
	int maxHp;
	int hp;
	int atk;
	int magicalAtk;
	int magicalDfs;//magical defense
	int dfs;//physical defence
	//stats
	
	int coin, exp, lv;
	bool isDie = false;
	int arithmeticParameterToLevelChange(int);
	int arithmeticParameterToCoinExp(int);
	void LevelStatsChange();
	void changeCoinExp();
public:
	enemy(int, int, int, int, int, int ,int ,int, string);
	void ReceiveAttack(int, string);
	//set
	void setHp(int);
	//change
	void changeMaxHp(int);
	void changeDfs(int);
	void changeMagicDfs(int);
	void changeAtk(int);
	void changeMagicalAtk(int);
	void changeLevel(int);
	//get
	int getCoin();
	int getExp();
	int getHp();
	int getMagicAtk();
	int getAtk();
	bool getDie();
	int getMaxHp();
	string getName();

	void changeLv(int);
	void dieCheck();
	void print();
};

