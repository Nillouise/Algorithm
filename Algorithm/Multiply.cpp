#include "Multiply.h"
#include<cmath>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;
int d[100][100][3];

int dfs(int i, int j, int c)
{
	if (d[i][j][c] != 0)
		return d[i][j][c];
	if (c == 0)
	{
		if (i == j)
		{
			d[i][j][0] = 1;
			return 1;
		}
		else {
			for (int k = i; k < j; k++)
			{
				d[i][j][0] += dfs(i, k, 0)*dfs(k + 1, j, 2) + dfs(i, k, 1)*dfs(k + 1, j, 2) + dfs(i, k, 2)*dfs(k + 1, j,0);
			}
			return d[i][j][c];
		}
	}
	else if(c==1)
	{
		if (i == j)
		{
			d[i][j][1] = 1;
			return 1;
		}
		else {
			for (int k = i; k < j; k++)
			{
				d[i][j][1] += dfs(i, k, 0)*dfs(k + 1, j, 0) + dfs(i, k, 0)*dfs(k + 1, j, 1) + dfs(i, k, 1)*dfs(k + 1, j, 1);
			}
			return d[i][j][1];
		}
	}
	else
	{
		if (i == j)
		{
			d[i][j][2] = 1;
			return 1;
		}
		else {
			for (int k = i; k < j; k++)
			{
				d[i][j][2] += dfs(i, k, 1)*dfs(k + 1, j, 0) + dfs(i, k, 2)*dfs(k + 1, j, 1) + dfs(i, k, 2)*dfs(k + 1, j, 2);
			}
			return d[i][j][2];
		}
	}
}


//character 0 to 'a',1 to 'b',2 to 'c'
int Multiply::run()
{
	int m;
	int character;
	cout << "序列长度:";
	cin >> m;
	cout << "生成结果，a是0，b是1，c是2:";
	cin>> character;
	cout << dfs(0, m-1, character);
	return 0;
}
