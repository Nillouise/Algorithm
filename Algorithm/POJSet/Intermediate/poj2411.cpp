//Flog直线等步长踩稻子(array),找出踩过最多的一条Flog路径
//Memory 172K Time: 47 Ms
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n, m;
//int dp[2][2048];//计数问题可能答案很大，要用long long
long long dp[2][2048];
int update(int cur, int a, int b)
{
	if (b&(1 << m))
	{
		dp[cur][b ^ (1 << m)] += dp[1 - cur][a];
	}
	return 0;
}



int main()
{
	//	freopen("input.txt", "r", stdin);

	while (cin >> n >> m&&n != 0 && m != 0)
	{
		if (n < m)swap(n, m);
		memset(dp, 0, sizeof(dp));
		//这是因为（0,0）这个坐标时，只能不放为1，其他状态都是0，这个状态就行了
		dp[1][(1 << m) - 1] = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				memcpy(dp, dp[1], sizeof(dp[1]));
				memset(dp[1], 0, sizeof(dp[1]));
				for (int k = 0; k < (1 << m); k++)
				{
					update(1, k, k << 1);
					//这里测i是因为第一行不能竖放
					if (i && !(k&(1 << (m - 1))))update(1, k, (k << 1) | (1 << m) | 1);
					//这里测j是因为第一列不能横放
					if (j && !(k & 1))update(1, k, (k << 1) ^ 3);
				}
			}
		}
		cout << dp[1][(1 << m) - 1] << endl;

	}


}