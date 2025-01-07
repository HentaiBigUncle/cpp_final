#include "GameManager.h"
#include<conio.h>
#include<windows.h>

using namespace std;

void GameManager::level1(maze& m, Player& p, Item& i, vector<enemy>& en, battle& b, event& e, chest& c, trap& t, boss& bs)
{
	while (!p.getLevel1())
	{
		m.print_maze();
		m.move(c, e, p, en, b, t, bs);
		bs.dieCheck();
		if (bs.getDie())
		{
			p.changeLevel1();
			cout << "Congratulations! you pass level one" << endl;
		}
	}
}
void GameManager::level2(maze& m, Player& p, Item& i, vector<enemy>& en, battle& b, event& e, chest& c, trap& t, boss& bs)
{
	while (!p.getLevel2())
	{
		m.print_maze();
		m.move(c, e, p, en, b, t, bs);
		bs.dieCheck();
		if (bs.getDie())
		{
			p.changeLevel2();
			cout << "Congratulations! you pass level two" << endl;
		}
	}
}
void GameManager::level3(maze& m, Player& p, Item& i, vector<enemy>& en, battle& b, event& e, chest& c, trap& t, boss& bs)
{
	while (!p.getLevel3())
	{
		m.print_maze();
		m.move(c, e, p, en, b, t, bs);
		bs.dieCheck();
		if (bs.getDie())
		{
			p.changeLevel3();
			cout << "Congratulations! you pass level three" << endl;
		}
	}
}
void GameManager::level4(maze& m, Player& p, Item& i, vector<enemy>& en, battle& b, event& e, chest& c, trap& t, boss& bs)
{
	while (!p.getLevel4())
	{
		m.print_maze();
		m.move(c, e, p, en, b, t, bs);
		bs.dieCheck();
		if (bs.getDie())
		{
			p.changeLevel4();
			cout << "Congratulations! you pass level four" << endl;
		}
	}
}
void GameManager::openShop(shop& s, Player& p)
{
	char c;
	bool isShopping = true, isFirst = true;
	cout << "Welcome, is there any thing you want" << endl;
	cout << "Y/N" << endl;
	while (isShopping)
	{
		if (!isFirst)
		{
			cout << "Anything else you want to buy" << endl;
			cout << "Y/N" << endl;
		}
		while (!_kbhit()) {}
		c = _getch();
		system("cls");
		if (c == 'Y')
		{
			s.Instruction();
			int com = 0;
			cin >> com;
			while(com <= 0 || com >= 8)
			{
				cout << "Invalid choice" << endl;
				cin >> com;
			}
			s.purchaseEquipmentItems(com, p);
			isFirst = false;
		}
		else if (c == 'N')
		{
			isShopping = false;
		}
	}
	cout << "Glad to see you again" << endl;
}