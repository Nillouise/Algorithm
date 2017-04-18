#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<stack>
#include<set>
#include<functional>
#include<queue>
using namespace std;
const int maxn = 350 + 5;
const int INF = 10000000;
int N;
int dp[maxn][maxn];
int A[maxn][maxn];

int dfs(int x, int y)
{
	if (dp[x][y] > -1)return dp[x][y];
	if (x >= N || y >= N)return 0;

	int r = max(dfs(x + 1, y), dfs(x + 1, y + 1));
	dp[x][y] = r + A[x][y];
	return dp[x][y];
}

int main()
{
	freopen("input.txt", "r", stdin);
	while (cin >> N&&N != 0)
	{
		memset(dp, -1, sizeof(dp));
		//		for (size_t i = 0; i < N; i++)//这里并不是单纯的计数，还要兼顾坐标，不能以0开始
		for (size_t i = 0; i < N; i++)
		{
			//			for (size_t j = 0; j < N; j++) //这里我有搞错成N
			for (size_t j = 0; j <= i; j++)//这里要等于，因为坐标问题
			{
				cin >> A[i][j];
			}
		}
		cout << dfs(0, 0) << endl;
	}


	return 0;
}