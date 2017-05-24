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
		//���Ǹ�������ǰ��Ԫ�ظ���һ�鵽��˹��ɻ� 
		for (int i = 0; i <= 2 * n; i++)
		{
			for (int j = 0; j <= 2 * n; j++)
			{
				DP[i][j] = INF;
				if (i == j)DP[i][j] = 0;
				g[i][j] = i;
			}
		}
		//		memset(g,0,sizeof(g));//��ʼ������ɾ��һ�� 
		for (int i = 1; i <= n; i++)
		{
			cin >> v[i];
			v[i] += v[i - 1];
		}
		for (int i = 1; i <= n; i++)
		{
			//���컷��ǰ׺�� 
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
		//���Ǹ�������ʼ��һ������1����ط���		
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