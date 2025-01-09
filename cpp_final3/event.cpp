#include "event.h"
#include<iostream>
#include"ctime"

using namespace std;

void event::occurEvent(Player& p, battle& b, maze& m)
{
	cout << "Specail event happened" << endl;
	srand(time(NULL));
	int n = rand() % 6;
	if (n == 0)
	{
		cout << "you find a gold: ";
		int coin = rand() % 41 + 10;
		cout << "+" << coin << endl;
		p.changeCoin(coin);
	}
	else if (n == 1)
	{
		cout << "you find exp: ";
		int exp = rand() % 151 + 50;
		cout << "+" << exp << endl;
		p.changeExp(exp);
	}
	else if (n == 2)
	{
		int hurt = rand() % 5 + 1;
		p.getCharacter()->changeHp(-hurt);
		cout << "you hurt yourself " << "-" << hurt << " hp" << endl;
		p.getCharacter()->dieCheck();
		if (p.getCharacter()->getDie())
		{
			p.changeDeath();
			cout << "You die" << endl;
		}
	}
	else if (n == 3)
	{
		cout << "oh no you raid by slime" << endl;
		s.changeLv(p.getLevelOfMaze());
		b.StartBattle(s, p, m);
	}
	else if (n == 4)
	{
		cout << "oh no you raid by Skeleton" << endl;
		skele.changeLv(p.getLevelOfMaze());
		b.StartBattle(skele, p, m);
	}
	else if (n == 5)
	{
		cout << "oh no you raid by a zombie" << endl;
		z.changeLv(p.getLevelOfMaze());
		b.StartBattle(z, p, m);
	}
}