#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int S[4][4];
int pcnt = 1000000;
int check()
{
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			if (S[i][j] != S[0][0])return 0;
		}
	}
	return 1;
}

int invert(int x, int y)
{
	S[x][y] = !S[x][y];//第一次忘记了写这行，太过专注于下面那几行有没有写对。

	if (x - 1 >= 0)
		S[x - 1][y] = !S[x - 1][y];
	if (x + 1 < 4)
		S[x + 1][y] = !S[x + 1][y];
	if (y - 1 >= 0)
		S[x][y - 1] = !S[x][y - 1];
	if (y + 1 < 4)
		S[x][y + 1] = !S[x][y + 1];
	return 1;

}
void dfs(int x, int y, int ccnt)
{
	if (check())
	{
		pcnt = min(ccnt, pcnt);
	}
	else {
		if (y >= 4)
			return;
		int nx = (x + 1) % 4;
		int ny = y + (x + 1) / 4;

		dfs(nx, ny, ccnt);
		invert(x, y);
		dfs(nx, ny, ccnt + 1);
		invert(x, y);

	}
}


int main()
{
	freopen("input.txt", "r", stdin);

	char ch;
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			cin >> ch;
			S[i][j] = ch == 'b' ? 1 : 0;
		}
	}
	dfs(0, 0, 0);
	if (pcnt<100000)
		cout << pcnt << endl;
	else {
		cout << "Impossible" << endl;//没写这行导致wa，没有认真看输出要求。
	}


	return 0;
}