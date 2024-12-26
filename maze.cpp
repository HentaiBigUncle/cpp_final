#define _CRT_SECURE_NO_WARNINGS

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
#define range x + dir[i].first >= 1 && x + dir[i].first <= 9 && y + dir[i].second >= 1 && y + dir[i].second <= 9

vector<string> maps(11);
bool isuse[12][12], goal = false, win1 = false, win2 = false;
pair<int, int> dir[4] = {{0, 2}, {2, 0}, {0, -2}, {-2, 0 }};
int n;
int seed;
//problem here
void dfs(int y, int x, vector<string> &map)
{
	if(goal) return;
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
			 if (y + dir[i].second == 9 && x + dir[i].first == 9)
				maps[y + dir[i].second][x + dir[i].first] = 'B';
			 if (y + dir[i].second == 1 && x + dir[i].first == 1)
				 maps[y + dir[i].second][x + dir[i].first] = 'A';
			dfs(y + dir[i].second, x + dir[i].first, map);
			isuse[y + dir[i].second][x + dir[i].first] = 0;
		}
		if (n == 25)
		{
			goal = true;
			return;
		}
	}
	
}
void play()
{
	int xA = 1, yA = 1, xB = 9, yB = 9;
	bool correct, AonB = 0, BonA = 0;
	char c;
	while (!win1 || !win2)
	{
		correct = true;
		cout << "Player 1(A) control: w(up) a(left) s(down) d(right)\n";
		cout << "Player 2(B) control: 5(up) 1(left) 2(down) 3(right)\n";
		while (correct)
		{
			bool yes = false;
			while (!_kbhit()) {}
			c = _getch();
			system("cls");
			if (c == 'd' && maps[xA][yA + 1] != '#')
			{
				if (AonB)
				{
					maps[xA][yA + 1] = 'A';
					maps[xA][yA] = 'B';
					AonB = 0;
				}
				else if (BonA)
				{
					maps[xA][yA + 1] = 'A';
					maps[xA][yA] = 'B';
					BonA = 0;
				}
				else if (maps[xA][yA + 1] == 'B')
				{
					maps[xA][yA + 1] = 'S';
					maps[xA][yA] = ' ';
					AonB = 1;
				}
				else
				{
					maps[xA][yA + 1] = 'A';
					maps[xA][yA] = ' ';
				}
				yA += 1;
				correct = 0;
				yes = 1;
			}
			else if (c== 'w' && maps[xA - 1][yA] != '#')
			{
				if (AonB)
				{
					maps[xA - 1][yA] = 'A';
					maps[xA][yA] = 'B';
					AonB = 0;
				}
				else if (BonA)
				{
					maps[xA - 1][yA] = 'A';
					maps[xA][yA] = 'B';
					BonA = 0;
				}
				else if(maps[xA - 1][yA] == 'B')
				{
					maps[xA - 1][yA] = 'S';
					maps[xA][yA] = ' ';
					AonB = 1;
				}
				else
				{
					maps[xA - 1][yA] = 'A';
					maps[xA][yA] = ' ';
				}
				xA -= 1;
				correct = 0;
				yes = 1;
			}
			else if (c == 'a' && maps[xA][yA - 1] != '#')
			{
				if (AonB)
				{
					maps[xA][yA - 1] = 'A';
					maps[xA][yA] = 'B';
					AonB = 0;
				}
				else if (BonA)
				{
					maps[xA][yA - 1] = 'A';
					maps[xA][yA] = 'B';
					BonA = 0;
				}
				else if (maps[xA][yA - 1] == 'B')
				{
					maps[xA][yA - 1] = 'S';
					maps[xA][yA] = ' ';
					AonB = 1;
				}
				else
				{
					maps[xA][yA - 1] = 'A';
					maps[xA][yA] = ' ';
				}
				yA -= 1;
				correct = 0;
				yes = 1;
			}
			else if (c == 's' && maps[xA + 1][yA] != '#')
			{
				if (AonB)
				{
					maps[xA + 1][yA] = 'A';
					maps[xA][yA] = 'B';
					AonB = 0;
				}
				else if (BonA)
				{
					maps[xA + 1][yA] = 'A';
					maps[xA][yA] = 'B';
					BonA = 0;
				}
				else if (maps[xA + 1][yA] == 'B')
				{
					maps[xA + 1][yA] = 'S';
					maps[xA][yA] = ' ';
					AonB = 1;
				}
				else
				{
					maps[xA + 1][yA] = 'A';
					maps[xA][yA] = ' ';
				}
				xA += 1;
				correct = 0;
				yes = 1;
			}
			else if (c == '3' && maps[xB][yB + 1] != '#')
			{
				if (BonA)
				{
					maps[xB][yB + 1] = 'B';
					maps[xB][yB] = 'A';
					BonA = 0;
				}
				else if (AonB)
				{
					maps[xB][yB + 1] = 'B';
					maps[xB][yB] = 'A';
					AonB = 0;
				}
				else if (maps[xB][yB + 1] == 'A')
				{
					maps[xB][yB + 1] = 'S';
					maps[xB][yB] = ' ';
					BonA = 1;
				}
				else
				{
					maps[xB][yB + 1] = 'B';
					maps[xB][yB] = ' ';
				}
				yB += 1;
				correct = 0;
				yes = 1;
			}
			else if (c == '5' && maps[xB - 1][yB] != '#')
			{
				if (BonA)
				{
					maps[xB - 1][yB] = 'B';
					maps[xB][yB] = 'A';
					BonA = 0;
				}
				else if(AonB)
				{
					maps[xB - 1][yB] = 'B';
					maps[xB][yB] = 'A';
					AonB = 0;
				}
				else if (maps[xB - 1][yB] == 'A')
				{
					maps[xB - 1][yB] = 'S';
					maps[xB][yB] = ' ';
					BonA = 1;
				}
				else
				{
					maps[xB - 1][yB] = 'B';
					maps[xB][yB] = ' ';
				}
				xB -= 1;
				correct = 0;
				yes = 1;
			}
			else if (c == '1' && maps[xB][yB - 1] != '#')
			{
				if (BonA)
				{
					maps[xB][yB - 1] = 'B';
					maps[xB][yB] = 'A';
					BonA = 0;
				}
				else if(AonB)
				{
					maps[xB][yB - 1] = 'B';
					maps[xB][yB] = 'A';
					AonB = 0;
				}
				else if (maps[xB][yB - 1] == 'A')
				{
					maps[xB][yB - 1] = 'S';
					maps[xB][yB] = ' ';
					BonA = 1;
				}
				else
				{
					maps[xB][yB - 1] = 'B';
					maps[xB][yB] = ' ';
				}
				yB -= 1;
				correct = 0;
				yes = 1;
			}
			else if (c == '2' && maps[xB + 1][yB] != '#')
			{
				if (BonA)
				{
					maps[xB + 1][yB] = 'B';
					maps[xB][yB] = 'A';
					BonA = 0;
				}
				else if (AonB)
				{
					maps[xB + 1][yB] = 'B';
					maps[xB][yB] = 'A';
					AonB = 0;
				}
				else if (maps[xB + 1][yB] == 'A')
				{
					maps[xB + 1][yB] = 'S';
					maps[xB][yB] = ' ';
					BonA = 1;
				}
				else
				{
					maps[xB + 1][yB] = 'B';
					maps[xB][yB] = ' ';
				}
				xB += 1;
				correct = 0;
				yes = 1;
			}
			else if(!yes)
			{
				for (auto i : maps)
				{
					cout << i << endl;
				}
				cout << "wrong try again" << endl;
				cout << "Player 1(A) control: w(up) a(left) s(down) d(right)\n";
				cout << "Player 2(B) control: 5(up) 1(left) 2(down) 3(right)\n";
				correct = 1;
			}
		}
		if (xA == 9 && yA == 9)
		{
			win1 = true;
			break;
		}
		if (xB == 1 && yB == 1)
		{
			win2 = true;
			break;
		}
		for (auto i : maps)
		{
			cout << i << endl;
		}
	}
	if (win1 || win2)
		return;
}
void setUp(int &x, int &y)
{
	for (int i = 0; i < 11; i++)
	{
		if (i == 1 || i == 9) continue;
		maps[i] = "###########";
	}
	maps[1] = "#A#########";
	maps[9] = "#########B#";
	memset(isuse, false, sizeof(isuse));

	srand(seed++);
	while (x % 2 != 1)
		x = rand() % 9 + 1;
	while(y % 2 != 1)
		y = rand() % 9 + 1;
}
int main()
{
	int x, y, p1 = 0, p2 = 0;
	srand(time(NULL));
	seed = rand() % 100;
	int oneTurn = 1;
	while (oneTurn == 1)
	{
		win1 = false, win2 = false, goal = false;
		n = 0;
		x = 0, y = 0;
		setUp(x, y);
		dfs(x, y, maps);
		for (auto i : maps)
		{
			cout << i << endl;
		}
		play();
		for (auto i : maps)
		{
			cout << i << endl;
		}
		if (win1)
			cout << "player A win!!!" << endl;
		else if (win2)
			cout << "B win!!!" << endl;
		cout << "Player 1(A) control: w(up) a(left) s(down) d(right)\n";
		cout << "Player 2(B) control: 5(up) 1(left) 2(down) 3(right)\n";
		cout<<"Scores:"<<endl;
		cout << "want to play again ? 1 for yes, 0 for no" << endl;
		cin >> oneTurn; system("cls");
	}
	cout << "Thanks for playing" << endl;
	return 0;
}