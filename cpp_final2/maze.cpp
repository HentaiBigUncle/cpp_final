#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include "maze.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<string>
#include<cstring>
#include<map>
#include<iomanip>
#include<cctype>
#include<vector>
#include<functional>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<queue>
#include<list>
#include<conio.h>
#include<windows.h>
#include<fstream>

using namespace std;
#define range x + dir[i].first >= 1 && x + dir[i].first <= edge - 2 && y + dir[i].second >= 1 && y + dir[i].second <= edge - 2

maze::maze(int _edge, Player& p) :
	edge(_edge)
{
	calculateEdge();
	making_maze();
	generateChest(p);
	generateEnemy(p);
	generateEvents(p);
	generateTrap(p);
}
void maze::dfs(int y, int x, vector<string>& map)
{
	if (goal) return;
	for (int i = 0; i < 4; i++)
	{
		if (range && !isuse[y + dir[i].second][x + dir[i].first])
		{
			n++;
			isuse[y + dir[i].second][x + dir[i].first] = 1;
			maps[y + dir[i].second][x + dir[i].first] = ' ';
			if (i == 0)
				maps[y + dir[i].second - 1][x + dir[i].first] = ' ';
			else if (i == 1)
				maps[y + dir[i].second][x + dir[i].first - 1] = ' ';
			else if (i == 2)
				maps[y + dir[i].second + 1][x + dir[i].first] = ' ';
			else if (i == 3)
				maps[y + dir[i].second][x + dir[i].first + 1] = ' ';
			if (y + dir[i].second == edge - 2 && x + dir[i].first ==  edge - 2)
				maps[y + dir[i].second][x + dir[i].first] = 'B';

			if (y + dir[i].second == 1 && x + dir[i].first == 1)
				maps[y + dir[i].second][x + dir[i].first] = 'P';

			dfs(y + dir[i].second, x + dir[i].first, map);
			//isuse[y + dir[i].second][x + dir[i].first] = 0;
		}
		if (n == real_edge)
		{
			goal = true;
			return;
		}
	}
}
void maze::setUp(int &x, int&y)
{
	for (int i = 0; i < edge; i++)
	{
		if (i == 1 || i == edge - 2) continue;
		for (int j = 0; j < edge; j++)
		{
			maps[i] += "#";
		}
	}
	for (int i = 0; i < edge; i++)
	{
		if (i == 1)
		{
			maps[1] += 'P';
			continue;
		}
		maps[1] += "#";
	}
	for (int i = 0; i < edge; i++)
	{
		if (i == edge - 2)
		{
			maps[edge - 2] += "B";
			continue;
		}
		maps[edge - 2] += "#";
	}
	memset(isuse, false, sizeof(isuse));

	srand(seed++);
	while (x % 2 != 1)
		x = rand() % (edge - 2) + 1;
	while (y % 2 != 1)
		y = rand() %  (edge - 2) + 1;
}
void maze::making_maze()
{
	int x = 0, y = 0;
	n = 0;
	maps.assign(edge, "");
	
	srand(time(NULL));
	seed = rand() % 100;
	setUp(x, y);
	dfs(x, y, maps);
}
void maze::calculateEdge()
{
	real_edge = ((edge - 2) / 2 + 1) * ((edge - 2) / 2 + 1);
}
void maze::print_instruction()
{
	cout << "Control: w(up) a(left) s(down) d(right) z(check stats)" << endl;
}
void maze::print_maze()
{
	for (auto i : maps)
	{
		cout << i << endl;
	}
}
void maze::generateChest(Player& p)
{
	int limit = 1 + 2 * (p.getLevel() - 1);
	srand(time(NULL));
	int x = 0, y = 0;
	while (limit != 0)
	{
		x = rand() % (edge - 2) + 1;
		y = rand() % (edge - 2) + 1;
		if (maps[y][x] != ' ')
		{
			chests[y][x] = true;
			limit -= 1;
		}
	}
}
void maze::generateEnemy(Player& p)
{
	int limit = 1 + 2 * (p.getLevel() - 1);
	srand(time(NULL));
	int x = 0, y = 0;
	while (limit != 0)
	{
		x = rand() % (edge - 2) + 1;
		y = rand() % (edge - 2) + 1;
		if (maps[y][x] != ' ')
		{
			enemies[y][x] = true;
			limit -= 1;
		}
	}
}
void maze::generateTrap(Player& p)
{
	int limit = 1 + p.getLevel() - 1;
	srand(time(NULL));
	int x = 0, y = 0;
	while (limit != 0)
	{
		x = rand() % (edge - 2) + 1;
		y = rand() % (edge - 2) + 1;
		if (maps[y][x] != ' ')
		{
			traps[y][x] = true;
			limit -= 1;
		}
	}
}
void maze::generateEvents(Player& p)
{
	int limit = 1 + p.getLevel() - 1;
	srand(time(NULL));
	int x = 0, y = 0;
	while (limit != 0)
	{
		x = rand() % (edge - 2) + 1;
		y = rand() % (edge - 2) + 1;
		if (maps[y][x] != ' ')
		{
			events[y][x] = true;
			limit -= 1;
		}
	}
}
void maze::check(int x, int y, chest& c, event& e, Player& p, enemy& ene, battle& b, trap& t, boss& bs)
{ 
	if (chests[y][x])
	{
		chests[y][x] = false;
		c.OpenChest(p);
	}
	else if (enemies[y][x])
	{
		enemies[y][x] = false;
		b.StartBattle(ene, p);
	}
	else if (events[y][x])
	{
		events[y][x] = false;
		e.occurEvent(p);
	}
	else if (traps[y][x])
	{
		traps[y][x] = false;
		t.triggerTrap(p);
	}
	else if (p.getX() == edge - 2 && p.getY() - 2)
	{
		b.bossFight(bs, p);
	}
	else
	{
		cout << "Nothing here." << endl;
	}
}
void maze::move(chest& ch, event& e, Player& p , enemy& ene, battle& b, trap& t, boss& bs)
{
	char c;
	while (!bs.getDie() && !p.getDie())
	{
		print_instruction();
		while (!_kbhit()) {}
		c = _getch();
		system("cls");
		if (c == 'd' && maps[p.getY()][p.getX() + 1] != '#')
		{
			maps[p.getY()][p.getX() + 1] = 'P';
			check(p.getX() + 1, p.getY(), ch, e, p, ene, b, t, bs);
			p.changeX(1);
		}
		else if (c == 'w' && maps[p.getY() - 1][p.getX()] != '#')
		{
			maps[p.getY() - 1][p.getX()] = 'P';
			check(p.getX(), p.getY() - 1, ch, e, p, ene, b, t, bs);
			p.changeY(-1);
		}
		else if (c == 'a' && maps[p.getY()][p.getX() - 1] != '#')
		{
			maps[p.getY()][p.getX() - 1] = 'P';
			check(p.getX() - 1, p.getY(), ch, e, p, ene, b, t, bs);
			p.changeX(-1);
		}
		else if (c == 's' && maps[p.getY() + 1][p.getX()] != '#')
		{
			maps[p.getY() + 1][p.getX()] = 'P';
			check(p.getX(), p.getY() + 1, ch, e, p, ene, b, t, bs);
			p.changeY(1);
		}
		else if (c == 'z')
		{
			p.print();
		}
		else
		{
			print_maze();
			cout << "wrong try again" << endl;
		}
	}
}
