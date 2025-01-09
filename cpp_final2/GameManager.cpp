#include "GameManager.h"
#include<conio.h>
#include<windows.h>

using namespace std;

void GameManager::level1(maze& m, Player& p, vector<enemy>& en, battle& b, event& e, chest& c, trap& t, boss& bs)
{
	if (p.getLevel1())
		return;
	m.move(c, e, p, en, b, t, bs);
	bs.dieCheck();
	if (bs.getDie())
	{
		p.changeLevel1();
		cout << "Congratulations! you pass level one" << endl;
		p.changeLevelOfMaze();
	}
}
void GameManager::level2(maze& m, Player& p, vector<enemy>& en, battle& b, event& e, chest& c, trap& t, boss& bs)
{
	if (p.getLevel2())
		return;
	if (!p.getLevel1())
	{
		p.resetXandY();
		m.move(c, e, p, en, b, t, bs);
		bs.dieCheck();
		if (bs.getDie())
		{
			p.changeLevel2();
			cout << "Congratulations! you pass level two" << endl;
			p.changeLevelOfMaze();
		}
	}
}
void GameManager::level3(maze& m, Player& p, vector<enemy>& en, battle& b, event& e, chest& c, trap& t, boss& bs)
{
	if (p.getLevel3())
		return;
	if (!p.getLevel2())
	{
		p.resetXandY();
		m.move(c, e, p, en, b, t, bs);
		bs.dieCheck();
		if (bs.getDie())
		{
			p.changeLevel3();
			cout << "Congratulations! you pass level three" << endl;
			p.changeLevelOfMaze();
		}
	}
}
void GameManager::level4(maze& m, Player& p, vector<enemy>& en, battle& b, event& e, chest& c, trap& t, boss& bs)
{
	if (p.getLevel4())
		return;
	if (!p.getLevel3())
	{
		p.resetXandY();
		m.move(c, e, p, en, b, t, bs);
		bs.dieCheck();
		if (bs.getDie())
		{
			p.changeLevel4();
			cout << "Congratulations! you pass level four" << endl;
			cout << "Thanks for playing" << endl;
			p.changeLevelOfMaze();
		}
	}
}
void GameManager::openShop(shop& s, Player& p)
{
	char c;
	bool isShopping = true, isFirst = true;
	cout << "enter any char to open shop" << endl;
	char ss;
	while (!_kbhit()) {}
	ss = _getch();
	system("cls");

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
		if (c == 'Y' || c == 'y')
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
		else if (c == 'N' || c == 'n')
		{
			isShopping = false;
			break;
		}
	}
	cout << "Glad to see you again" << endl;
	cout << "enter any char to continue to "<<p.getLevelOfMaze()<< endl;
	while (!_kbhit()) {}
	ss = _getch();
	system("cls");
}