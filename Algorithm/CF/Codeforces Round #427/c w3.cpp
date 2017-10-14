﻿//这时最蠢的，妄图用一个复杂度巨高的算法通过，还花了不少时间写这个算法，
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

struct star
{
	LL init;
	int x, y;

	bool operator <(star s2)const
	{
		return y < s2.y;
	}
};

LL getbright(star s, LL t)
{
	LL b = s.init + t;
	b %= c + 1;//光的亮度是0到c，所以c+1才是范围
	return b;
}
vector<star> v[200];
LL solve(int x1, int y1, int x2, int y2, LL t)
{
	LL cnt = 0;
	for (int i = x1; i <= x2; i++)
	{
		for (auto a : v[i])
		{
			if (a.y < y1)continue;
			if (a.y > y2)break;

			cnt += getbright(a, t);
		}
	}
	return cnt;
}

LL GG[11][105][105];
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
		star s;
		cin >> s.x >> s.y >> s.init;
		v[s.x].push_back(s);
	}
	for (int i = 0; i < 200; i++)
	{
		sort(v[i].begin(), v[i].end());
	}

	for (int t = 0; t <= 10; t++)
	{
		for (int i = 1; i < 101; i++)
		{
			for (int j = 1; j < 101; j++)
			{

				//GG[t][j][j] = solve(0, 0, i, j, t);
				if (i == 2 && j == 2)
				{
					int a = 0;
				}
				//GG[t][j][j] = solve(1, 1, i, j, t);
				GG[t][i][j] = solve(1, 1, i, j, t);
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