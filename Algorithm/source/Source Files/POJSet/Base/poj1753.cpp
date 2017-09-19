//！=和=！a 混挠
//coverse忘记判断边界
//把converse x y，写成converse x2,y2了，这是由于上下文干扰加我不留心导致的
//没有看题目考虑 Impossible 的情况
//impossible 没有定义成常量INF
//没有考虑边界情况有没有被check 到
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int m[4][4];
const int INF = 10000;
int minGold = INF;


void coverse(int x, int y)
{
	if (x - 1 >= 0)
		m[x - 1][y] = !m[x - 1][y];
	if (x + 1<4)
		m[x + 1][y] = !m[x + 1][y];
	m[x][y] = !m[x][y];
	if (y - 1 >= 0)
		m[x][y - 1] = !m[x][y - 1];
	if (y + 1<4)
		m[x][y + 1] = !m[x][y + 1];


}

int check()
{
	for (int i = 0; i<4; i++)
		for (int j = 0; j<4; j++)
		{
			if (m[i][j] != m[0][0])
				return 0;
		}
	return 1;

}

int dfs(int x, int y, int cnt)
{
	if (check())
	{
		minGold = min(cnt, minGold);
		return 0;
	}
	if (x >= 4 || y >= 4)
		return 0;
	int x2 = (x + 1) % 4;
	int y2 = (y)+(x + 1) / 4;
	dfs(x2, y2, cnt);
	coverse(x, y);
	dfs(x2, y2, cnt + 1);
	coverse(x, y);

	//if (x == 0 && y == 1)
	//	for (int i = 0; i<4; i++)
	//	{

	//		for (int j = 0; j<4; j++)
	//			cout << m[i][j] << " ";
	//		cout << endl;
	//	}
	return 0;
}

int main()
{
	for (int i = 0; i<4; i++)
		for (int j = 0; j<4; j++)
		{
			char c;
			cin >> c;
			m[i][j] = (c == 'b' ? 0 : 1);
		}
	dfs(0, 0, 0);
	if (minGold == INF)
		cout << "Impossible" << endl;
	else
		cout << minGold << endl;
	return 0;
}
