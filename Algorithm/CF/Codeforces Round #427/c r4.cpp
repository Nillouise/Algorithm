//这题挺重要的
#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>//这个sqrt要用
#include<queue>
using namespace std;
typedef long long LL;
LL n, q, c;

LL initG[105][105];
LL icntG[200][200];
LL cntG[200][200];

LL GG[11][105][105];

vector<LL> initG2[105][105];
LL solve2(int x1, int y1, int x2, int y2, LL t)
{
	t %= c + 1;
	LL init = GG[t][x2][y2] - GG[t][x1 - 1][y2] - GG[t][x2][y1 - 1] + GG[t][x1 - 1][y1 - 1];
	LL num = cntG[x2][y2] - cntG[x1 - 1][y2] - cntG[x2][y1 - 1] + cntG[x1 - 1][y1 - 1];


	return init;
}

int main()
{
	ios::sync_with_stdio(false);

	cin >> n >> q >> c;

	for (size_t i = 0; i < n; i++)
	{
		int x, y, init;
		cin >> x >> y >> init;
		//initG[x + 1][y + 1] += init;
		//icntG[x + 1][y + 1]++;
		initG[x][y] += init;
		initG2[x][y].push_back(init);
		icntG[x][y]++;
	}

	//这里要加到102，因为原本是1开头
	for (int i = 1; i < 100 + 1; i++)
	{
		for (int j = 1; j < 100 + 1; j++)
		{
			cntG[i][j] = icntG[i][j] + cntG[i - 1][j] + cntG[i][j - 1] - cntG[i - 1][j - 1];
		}
	}

	for (int t = 0; t < 10 + 1; t++)
	{
		for (int i = 1; i < 100 + 1; i++)
		{
			for (int j = 1; j < 100 + 1; j++)
			{
				GG[t][i][j] = initG[i][j] + GG[t][i - 1][j] + GG[t][i][j - 1] - GG[t][i - 1][j - 1];
			}
		}
		for (int i = 1; i < 100 + 1; i++)
		{
			for (int j = 1; j < 100 + 1; j++)
			{
				if (icntG[i][j] != 0)
				{
					initG[i][j] = 0;
					for (auto &a : initG2[i][j])
					{
						a++;
						a %= c + 1;
						initG[i][j] += a;
					}
				}
			}
		}
	}


	for (size_t i = 0; i < q; i++)
	{
		LL x1, y1, x2, y2, t;
		cin >> t >> x1 >> y1 >> x2 >> y2;
		cout << solve2(x1, y1, x2, y2, t) << endl;
	}






	return 0;
}