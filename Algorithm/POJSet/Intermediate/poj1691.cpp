//dfs一定有出口的，不要忘记加出口
#include <iostream>
#include <cstdio>
#include <cstring>
#include<string>
#include <algorithm>
#include<sstream>
#include<cmath>
using namespace std;

int rect[15][4];
int color[15];
int N;
const int INF = 10000;
short G[15][15];
int inn[15];
int relate(int i, int j)
{
	if (rect[i][3] == rect[j][1])
	{
		if (rect[i][0] >= rect[j][0] && rect[i][0] < rect[j][2])//这是左交点的，所以也可以等于别人的左交点
		{
			return 1;
		}
		else if (rect[i][2] > rect[j][0] && rect[i][2] <= rect[j][2])//这是右交点的，所以也可以等于别人的右交点
		{
			return 1;
		}
	}
	return 0;
}

void initG()
{
	memset(G, 0, sizeof(G));
	memset(inn, 0, sizeof(inn));
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			if (i == j)continue;
			if (relate(i, j))
			{
				G[i][j] = 1;
			}
		}
	}
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			if (i == j)continue;
			if (G[i][j] == 1)
			{
				inn[j]++;
			}
		}
	}

}

int dfs(int brush)
{
	int Tinn[15];
	memcpy(Tinn, inn, sizeof(inn));
	int finish = 1;
	//这句是出口，dfs居然忘了加出口。
	for (size_t i = 0; i < N; i++)
	{
		if (inn[i] != -1)
		{
			finish = 0;
			break;
		}
	}
	if (finish == 1)return 0;

	int MIN = INF;

	for (int co = 1; co <= 20; co++)
	{
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			if (inn[i] == 0 && color[i] == co)
			{
				cnt++;
				break;
			}
		}
		if (cnt > 0)
		{
			for (int i = 0; i < N; i++)
			{
				//				if (inn[i] == 0 && color[i] == co)
				if (Tinn[i] == 0 && color[i] == co)//在原图上改，不然会修改掉inn
				{
					inn[i] = -1;
					for (size_t jj = 0; jj < N; jj++)
					{
						if (G[i][jj] == 1)
						{
							inn[jj]--;
						}
					}
				}
			}
			MIN = min(MIN, dfs(co) + (brush == co ? 0 : 1));
			memcpy(inn, Tinn, sizeof(inn));
		}
	}
	return MIN;
}

int main() {
	freopen("input.txt", "r", stdin);

	int M;
	cin >> M;
	while (M--)
	{
		cin >> N;
		for (size_t i = 0; i < N; i++)
		{
			cin >> rect[i][1] >> rect[i][0] >> rect[i][3] >> rect[i][2];
			cin >> color[i];
		}
		initG();

		cout << dfs(0) << endl;
	}


	return 0;
}