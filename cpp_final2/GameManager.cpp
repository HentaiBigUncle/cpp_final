#include "GameManager.h"
#include<conio.h>
#include<windows.h>

using namespace std;

void GameManager::level1(maze& m, Player& p, vector<enemy>& en, battle& b, event& e, chest& c, trap& t, boss& bs)
{
	if (p.getLevel1())
		return;
	m.move(c, e, p, en, b, t, bs, m);
	bs.dieCheck();
	if (bs.getDie())
	{
		p.changeLevel1();
		cout << "Congratulations! "<<p.getName()<<", you pass level one" << endl;
		p.changeLevelOfMaze();
	}
}
void GameManager::level2(maze& m, Player& p, vector<enemy>& en, battle& b, event& e, chest& c, trap& t, boss& bs)
{
	if (p.getLevel2())
		return;
	if (p.getLevel1())
	{
		p.resetXandY();
		m.move(c, e, p, en, b, t, bs, m);
		bs.dieCheck();
		if (bs.getDie())
		{
			p.changeLevel2();
			cout << "Congratulations! "<<p.getName()<<", you pass level two" << endl;
			p.changeLevelOfMaze();
		}
	}
}
void GameManager::level3(maze& m, Player& p, vector<enemy>& en, battle& b, event& e, chest& c, trap& t, boss& bs)
{
	if (p.getLevel3())
		return;
	if (p.getLevel2())
	{
		p.resetXandY();
		m.move(c, e, p, en, b, t, bs, m);
		bs.dieCheck();
		if (bs.getDie())
		{
			p.changeLevel3();
			cout << "Congratulations! "<<p.getName()<<", you pass level three" << endl;
			p.changeLevelOfMaze();
		}
	}
}
void GameManager::level4(maze& m, Player& p, vector<enemy> &en, battle& b, event &e, chest& c, trap &t, boss& bs)
{
	if (p.getLevel4())
		return;
	if (p.getLevel3())
	{
		p.resetXandY();
		m.move(c, e, p, en, b, t, bs, m);
		bs.dieCheck();
		if (bs.getDie())
		{
			p.changeLevel4();
			cout << "Congratulations! "<<p.getName()<<", you pass level four" << endl;
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
	if (!_kbhit()) {}
	c = _getch();
	system("cls");
	cout << "Welcome"<<p.getName()<<", is there any thing you want" << endl;
	cout << "1 = shop 2 = exit" << endl;
	while (isShopping)
	{
		if (!isFirst)
		{
			system("cls");
			cout << "Anything else you want to buy" << endl;
			cout << "1 = shop, 2 = exit" << endl;
		}
		if(!_kbhit()){}
		c = _getch();
		system("cls");
		if (c == '1')
		{
			s.Instruction();
			cout << "please enter number" << endl;
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
		/*else if (c == '2')
		{
			cout << "please enter number" << endl;
			cout << "1. sell equipment" << endl;
			cout << "2. sell item" << endl;
			int com = 0;
			cin >> com;
			while (com <= 0 || com >= 3)
			{
				cout << "Invalid choice" << endl;
				cin >> com;
			}
			s.sellItemEquipment(com, p);
			isFirst = false;
		}*/
		else if (c == '2')
		{
			isShopping = false;
			break;
		}
	}
	cout << "Glad to see you again" << endl;
	cout << "enter any char to continue to level" << p.getLevelOfMaze() << endl;
	if (!_kbhit()) {}
	c = _getch();
	system("cls");
}