#pragma once
#include<iostream>
#include"enemy.h"
#include<string>
#include"Player.h"

using namespace std;

class enemy;
class Player;

class character
{
protected:
	string type;
	int maxHp;
	int hp;
	int maxMp;
	int mp;
	int atk;
	int magicalAtk;
	int magicalDfs;//magical defense
	int dfs;//physical defence
	bool isDie = false;
public:
	character(int = 0 , int = 0 , int = 0 , int = 0 , int = 0, int = 0, string = "");
	int ReceiveDamage(int, string);
	//set
	void setHp(int);
	void setMp(int);
	//get
	int getAtk();
	int getHp();
	int getMp();
	int getDfs();
	int getMagicalAtk();
	int getMagicalDfs();
	int getMaxHp();
	int getMaxMp();
	bool getDie();
	string getType();
	//change
	void changeMaxHp(int);
	void changeMaxMp(int);
	void changeDfs(int);
	void changeMagicDfs(int);
	void changeAtk(int);
	void changeMagicalAtk(int);
	void changeHp(int);
	void changeMp(int);

	void minusMaxHp(int);
	void minusMaxMp(int);
	void minusDfs(int);
	void minusMdfs(int);
	void minusAtk(int);
	void minusMatk(int);

	void dieCheck();
	void display(Player&) { cout << "hee"; }
	virtual void displaySkill(Player&) const {};
	virtual void useSkill(enemy&, Player&) const {};
	void print();
};

