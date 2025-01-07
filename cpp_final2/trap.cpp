#include "trap.h"
#include<ctime>

void trap::triggerTrap(Player& player)
{
	cout << "Oh no! it's a trap" << endl;
	srand(time(NULL));
	int type = rand() % 5;
	switch (type)
	{
		case 0:
		{
			int damage = 5;
			player.getCharacter()->changeHp(-damage);
			cout << "Oh No, you step on the spine: -" << damage << "hp" << endl;
			player.getCharacter()->dieCheck();
		}
		case 1:
		{
			int damage = 7;
			player.getCharacter()->changeHp(-damage);
			cout << "Oh No, you are hurt by throwing knife: -" << damage << "hp" << endl;
			player.getCharacter()->dieCheck();
		}
		case 2:
		{
			int damage = 1;
			player.getCharacter()->changeHp(-damage);
			cout << "Oh No, you accidently fall down: -" << damage << "hp" << endl;
			player.getCharacter()->dieCheck();
		}
		case 3:
		{
			int damage = 15;
			player.getCharacter()->changeHp(-damage);
			cout << "Oh No, you fall into the lava: -" << damage << "hp" << endl;
			player.getCharacter()->dieCheck();
		}
		case 4:
		{
			int damage = 10;
			player.getCharacter()->changeHp(-damage);
			cout << "Oh No, you are hurt by sharp knife: -" << damage << "hp" << endl;
			player.getCharacter()->dieCheck();
		}
	}
}