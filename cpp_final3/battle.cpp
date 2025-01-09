#include "battle.h"
#include"conio.h"
#include"Windows.h"

void battle::StartBattle(enemy& e, Player& p, maze& m)
{
	system("cls");
	cout << "A wild " << e.getName() << " appear!" << endl;
	e.print();
	bool first = false;
	while (p.getCharacter()->getHp() > 0 && e.getHp() > 0)
	{
		if (first)
		{
			char c;
			cout << "enter any char to continue" << endl;
			if(!_kbhit()){}
			c = _getch();
			system("cls");
		}
		cout << "--- Battle Menu---" << endl;
		cout << "1. Attack\n2. Use Skill\n3. Use Item\n4. Watch Stats and enemy hp\n";
		int choice;
		cin >> choice;

		switch (choice)
		{
			case 1:
			{
				system("cls");
				cout << "You attacked the enemy!" << endl;
				e.ReceiveAttack(p.getCharacter()->getAtk(), "atk");
				e.ReceiveAttack(p.getCharacter()->getMagicalAtk(), "magic");
				if (e.getHp() <= 0)
				{
					system("cls");
					cout << "Level: " << p.getLevelOfMaze() << endl;
					m.print_maze();
					cout << "You defeat the " << e.getName() << "!" << endl;
					p.changeCoin(e.getCoin());
					p.changeExp(e.getExp());
					cout << "You Receive " << e.getCoin() << " coin " << e.getExp() << " exp" << endl;
					e.dieCheck();
					return;
				}
				if (e.getHp() > 0)
				{
					p.getCharacter()->ReceiveDamage(e.getMagicAtk(), "magic");
					p.getCharacter()->ReceiveDamage(e.getAtk(), "atk");
				}
				if (p.getCharacter()->getHp() <= 0)
				{
					p.getCharacter()->dieCheck();
					p.changeDeath();
					cout << "You die" << endl;
					return;
				}
				first = true;
				break;
			}
			case 2:
			{
				system("cls");
				cout << "You choose to use skill" << endl;
				p.getCharacter()->useSkill(e, p);
				if (e.getHp() > 0)
				{
					p.getCharacter()->ReceiveDamage(e.getMagicAtk(), "magic");
					p.getCharacter()->ReceiveDamage(e.getAtk(), "atk");
				}
				else
				{
					system("cls");
					cout << "Level: " << p.getLevelOfMaze() << endl;
					m.print_maze();
					cout << "You defeat the " << e.getName() << "!" << endl;
					p.changeCoin(e.getCoin());
					p.changeExp(e.getExp());
					cout << "You Receive " << e.getCoin() << " coin " << e.getExp() << " exp" << endl;
					e.dieCheck();
					return;
				}
				 if (p.getCharacter()->getHp() <= 0)
				{
					p.getCharacter()->dieCheck();
					p.changeDeath();
					cout << "You die" << endl;
					return;
				}
				 first = true;
				break;
			}
			case 3:
			{
				system("cls");
				cout << "You choose to use Item" << endl;
				p.useItems(p, e, m);
				if (e.getHp() > 0)
				{
					p.getCharacter()->ReceiveDamage(e.getMagicAtk(), "magic");
					p.getCharacter()->ReceiveDamage(e.getAtk(), "atk");
				}
				if (p.getCharacter()->getHp() <= 0)
				{
					p.getCharacter()->dieCheck();
					p.changeDeath();
					cout << "You die" << endl;
					return;
				}
				first = true;
				break;
			}
			case 4:
			{
				system("cls");
				cout << "You choose to watch your stats and enemy" << endl;
				p.getCharacter()->print();
				e.print();
				first = true;
				break;
			}
			default:
			{
				cout << "wrong choose" << endl;
				first = true;
			}
		}
	}
}
void battle::bossFight(boss& b, Player& p, maze& m)
{
	system("cls");
	cout << "you occur boss: " << b.getName() << endl;
	b.print();
	bool first = false;
	while (p.getCharacter()->getHp() > 0 && b.getHp() > 0)
	{
		if (first)
		{
			char c;
			cout << "enter any char to continue" << endl;
			if (!_kbhit()) {}
			c = _getch();
			system("cls");
		}
		cout << "--- Battle Menu---" << endl;
		cout << "1. Attack\n2. Use Skill\n3. Use Item\n4. Watch Stats and enemy hp\n";
		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			system("cls");
			cout << "You attacked the boss!" << endl;
			b.ReceiveAttack(p.getCharacter()->getAtk(), "atk");
			b.ReceiveAttack(p.getCharacter()->getMagicalAtk(), "magic");
			if (b.getHp() <= 0)
			{
				system("cls");
				cout << "Level: " << p.getLevelOfMaze() << endl;
				m.print_maze();
				cout << "You defeat " << b.getName() << "!" << endl;
				p.changeCoin(b.getCoin());
				p.changeExp(b.getExp());
				cout << "You receive " << b.getCoin() << endl;
				cout << "You receive " << b.getExp() << endl;
				b.dieCheck();
				return;
			}
			if(b.getHp() > 0)
				b.atk(p);
			if (p.getCharacter()->getHp() <= 0)
			{
				p.getCharacter()->dieCheck();
				p.changeDeath();
				cout << "You die" << endl;
				return;
			}
			first = true;
			break;
		}
		case 2:
		{
			system("cls");
			cout << "You choose to use skill" << endl;
			p.getCharacter()->useSkill(b, p);
			if (b.getHp() > 0)
				b.atk(p);
			else
			{
				system("cls");
				cout << "Level: " << p.getLevelOfMaze() << endl;
				m.print_maze();
				cout << "You defeat " << b.getName() << "!" << endl;
				p.changeCoin(b.getCoin());
				p.changeExp(b.getExp());
				cout << "You receive " << b.getCoin() << endl;
				cout << "You receive " << b.getExp() << endl;
				b.dieCheck();
				return;
			}
			 if (p.getCharacter()->getHp() <= 0)
			{
				p.getCharacter()->dieCheck();
				p.changeDeath();
				cout << "You die" << endl;
				return;
			}
			 first = true;
			break;
		}
		case 3:
		{
			system("cls");
			cout << "You choose to use Item" << endl;
			p.useItems(p, b, m);
			if (b.getHp() > 0)
				b.atk(p);
			if (p.getCharacter()->getHp() <= 0)
			{
				p.getCharacter()->dieCheck();
				p.changeDeath();
				cout << "You die" << endl;
				return;
			}
			first = true;
			break;
		}
		case 4:
		{
			system("cls");
			cout << "You choose to watch your stats and boss" << endl;
			p.getCharacter()->print();
			b.print();
			first = true;
			break;
		}
		default:
		{
			cout << "wrong choose" << endl;
			first = true;
		}
		}
	}
}
