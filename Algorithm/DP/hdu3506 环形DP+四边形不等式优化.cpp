#include<iostream>
#include<list>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
long long INF = 1000000000L;
long long v[2000 + 5];
long long DP[2000 + 5][2000 + 5];
int g[2000 + 5][2000 + 5];

int main()
{
#ifdef LOCAL 
	cout << "fdsfsd" << endl;
#endif 
	freopen("input.txt", "r", stdin);


	int n;
	while (cin >> n)
	{
		v[0] = 0;
		//这是个环，把前端元素复制一遍到后端构成环 
		for (int i = 0; i <= 2 * n; i++)
		{
			for (int j = 0; j <= 2 * n; j++)
			{
				DP[i][j] = INF;
				if (i == j)DP[i][j] = 0;
				g[i][j] = i;
			}
		}
		//		memset(g,0,sizeof(g));//初始化忘记删这一行 
		for (int i = 1; i <= n; i++)
		{
			cin >> v[i];
			v[i] += v[i - 1];
		}
		for (int i = 1; i <= n; i++)
		{
			//构造环的前缀和 
			v[i + n] = v[i] - v[i - 1] + v[n + i - 1];
		}

		for (int len = 1; len<n; len++)
		{
			for (int i = 1; i + len <= 2 * n; i++)
			{
				int j = i + len;
				/*
				for(int k=i;k<j;k++)
				{
				DP[i][j]=min(DP[i][j],DP[i][k]+DP[k+1][j]+ v[j]-v[i-1]);
				}*/

				for (int k = g[i][j - 1]; k <= g[i + 1][j]; k++)
				{
					if (DP[i][j]>DP[i][k] + DP[k + 1][j] + v[j] - v[i - 1])
					{
						DP[i][j] = DP[i][k] + DP[k + 1][j] + v[j] - v[i - 1];
						g[i][j] = k;
					}
				}
			}
		}
		//这是个环，开始不一定是在1这个地方。		
		//		cout<<DP[1][n]<<endl;
		long long MIN = INF;
		for (int i = 1; i <= n; i++)
		{
			MIN = min(MIN, DP[i][i + n - 1]);
		}
		cout << MIN << endl;
	}

	return 0;
}