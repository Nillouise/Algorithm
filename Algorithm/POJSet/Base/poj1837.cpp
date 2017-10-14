#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<stack>
#include<set>
#include<functional>
#include<queue>
using namespace std;
const int maxn = 1000;
int C, G;
int hook[30];
int gram[30];
int d[30][15000];

int dfs(int g, int balance)
{
	if (g >= G)return 0;
	if (d[g][balance] != -1)return d[g][balance];
	int r = 0;
	for (size_t i = 0; i < C; i++)
	{
		//		r += dfs(g + 1, balance + hook[i] * gram[g]);//忘记这行其实作用是补锅的
		r += dfs(g + 1, balance - hook[i] * gram[g]);
	}
	d[g][balance] = r;
	return d[g][balance];
}


int main()
{

	freopen("input.txt", "r", stdin);
	while (cin >> C >> G&&C != 0 && G != 0)
	{
		for (size_t i = 0; i < C; i++)
			cin >> hook[i];
		for (int i = 0; i < G; i++)
			cin >> gram[i];
		memset(d, -1, sizeof(d));
		//忘记边界没有东西
		for (size_t i = 0; i < C; i++)
		{
			d[G - 1][7500 + hook[i] * gram[G - 1]] = 1;
		}
		cout << dfs(0, 7500) << endl;
	}


	return 0;
}

//这是别人做的，思路很好
int dp[30][15000];
int main()
{

	freopen("input.txt", "r", stdin);
	while (cin >> C >> G&&C != 0 && G != 0)
	{
		int hook[30];
		int gram[30];

		for (size_t i = 0; i < C; i++)
			cin >> hook[i];
		for (int i = 1; i <= G; i++)//这里不用gram[0]，因为dp哪里会用0表示没有东西
			cin >> gram[i];
		memset(dp, 0, sizeof(dp));

		dp[0][7500] = 1;//0代表不放东西，那就确实是平衡的，平衡就是7500，因为会有负数

		for (size_t i = 1; i <= G; i++)
		{
			for (size_t j = 0; j < 15000; j++)
			{
				for (size_t k = 0; k < C; k++)
				{
					dp[i][j] += dp[i - 1][j - gram[i] * hook[k]];//这里有更好的方法，可以优化掉 k
				}
			}
		}


		cout << dp[G][7500] << endl;
	}


	return 0;
}