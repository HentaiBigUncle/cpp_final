#include "battle.h"

void battle::StartBattle(enemy& e, Player& p)
{
	cout << "A wild " << e.getName() << " appear!" << endl;
	e.print();
	while (p.getCharacter()->getHp() > 0 && e.getHp() > 0)
	{
		cout << "--- Battle Menu---" << endl;
		cout << "1. Attack\n2. Use Skill\n3. Use Item\n4. Watch Stats\n";
		int choice;
		cin >> choice;

		switch (choice)
		{
			case 1:
			{
				cout << "You attacked the enemy!" << endl;
				e.ReceiveAttack(p.getCharacter()->getAtk(), "atk");
				e.ReceiveAttack(p.getCharacter()->getMagicalAtk(), "magic");
				if (e.getHp() <= 0)
				{
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
			}
			break;
			case 2:
			{
				cout << "You choose to use skill" << endl;
				p.getCharacter()->useSkill(e, p);
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
				else
				{
					cout << "You defeat the " << e.getName() << "!" << endl;
					p.changeCoin(e.getCoin());
					p.changeExp(e.getExp());
					cout << "You Receive " << e.getCoin() << " coin " << e.getExp() << " exp" << endl;
					e.dieCheck();
					return;
				}
				break;
			}
			case 3:
			{
				cout << "You choose to use Item" << endl;
				p.useItem(p, e);
				if (e.getHp() > 0)
				{
					p.getCharacter()->ReceiveDamage(e.getMagicAtk(), "magic");
					p.getCharacter()->ReceiveDamage(e.getAtk(), "atk");
				}
				break;
			}
			case 4:
			{
				cout << "You choose to watch your stats" << endl;
				p.getCharacter()->print();
				break;
			}
			default:
			{
				cout << "wrong choose" << endl;
			}
		}
	}
}
void battle::bossFight(boss& b, Player& p)
{
	cout << "you occur boss: " << b.getName() << endl;
	b.print();
	while (p.getCharacter()->getHp() > 0 && b.getHp() > 0)
	{
		cout << "--- Battle Menu---" << endl;
		cout << "1. Attack\n2. Use Skill\n3. Use Item\n4. Watch Stats\n";
		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "You attacked the enemy!" << endl;
			b.ReceiveAttack(p.getCharacter()->getAtk(), "atk");
			b.ReceiveAttack(p.getCharacter()->getMagicalAtk(), "magic");
			if (b.getHp() <= 0)
			{
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
		}
		break;
		case 2:
		{
			cout << "You choose to use skill" << endl;
			p.getCharacter()->useSkill(b, p);
			if (b.getHp() > 0)
				b.atk(p);
			else
			{
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
			break;
		}
		case 3:
		{
			cout << "You choose to use Item" << endl;
			p.useItem(p, b);
			if (b.getHp() > 0)
				b.atk(p);
			break;
		}
		case 4:
		{
			cout << "You choose to watch your stats" << endl;
			p.getCharacter()->print();
			break;
		}
		default:
		{
			cout << "wrong choose" << endl;
		}
		}
	}
}
