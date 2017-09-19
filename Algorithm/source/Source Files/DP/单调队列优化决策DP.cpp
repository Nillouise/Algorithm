//http://qscoj.cn/problem/165/

#include<iostream>
#include<list>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;

int A[10000 + 5];
int d[10000 + 5][2000 + 5];
int g[10000 + 5][2000 + 5];

int main()
{
	freopen("input.txt", "r", stdin);
	int N, M;
	cin >> N >> M;
	A[0] = 0;
	for (int i = 1; i <= N; i++)//这类区间问题，都是从1开始数比较好，因为多个位置0可以表示某些东西，比如说[0,0]区间表示起来就方便
	{
		scanf("%d", &A[i]);
	}
	sort(A + 1, A + N + 1);
	memset(d, 0, sizeof(d));
	memset(g, 0, sizeof(g));
	int MAX = 0;
	for (int i = 0; i <= M + 1; i++)g[N + 1][i] = N + 1;

	for (int i = N; i>0; i--)
	{
		for (int j = M; j>0; j--)
		{
			//			for(int k=N+1;k>i;k--)
			for (int k = g[i + 1][j]; k >= g[i][j + 1] && k>i; k--)
			{
				//				d[i][j] = max(d[i][j],d[k][j-1] + A[i]*(k-i));//k-i 我写成了k-j 
				if (d[i][j]<d[k][j - 1] + A[i] * (k - i))
				{
					g[i][j] = k;
					d[i][j] = d[k][j - 1] + A[i] * (k - i);
					MAX = max(d[i][j], MAX);
				}


			}
		}
	}

	cout << MAX << endl;

	return 0;
}
//我写的另一个版本
#include<iostream>
#include<list>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;

int A[10000 + 5];
int d[10000 + 5][2000 + 5];
int g[10000 + 5][2000 + 5];//决策G函数，用来储存决策

int main()
{
	int N, M;
	cin >> N >> M;
	A[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &A[i]);
	}
	sort(A + 1, A + N + 1);
	memset(d, 0, sizeof(d));
	memset(g, 0, sizeof(g));
	for (int i = 0; i <= M; i++)
	{
		g[0][i] = 0;
	}
	for (int i = 0; i <= N; i++)
	{
		g[i][M + 1] = i - 1;//因为决策时最大是上个位置是区间的结尾，当前位置是区间的开始
	}


	int MAX = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = M; j>0; j--)
		{
			//			for(int k = 0;k<i;k++)
			for (int k = g[i - 1][j]; k <= g[i][j + 1]; k++)//k代表的是上个区间的结尾。
			{
				if (d[i][j] < d[k][j - 1] + A[k + 1] * (i - k))
				{
					d[i][j] = d[k][j - 1] + A[k + 1] * (i - k);//为啥是k+1？因为d[i]根本不代表i位置放了商品
					g[i][j] = k;
					MAX = max(MAX, d[i][j]);
				}
			}


		}
	}

	cout << MAX << endl;

	return 0;
}



#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 10005, M = 2005;
int n, m, g[N][M];
long long f[N][M], c[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("ch.in", "r", stdin);
	freopen("ch.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i<n; i++)
		scanf("%d", &c[i]), g[i + 1][m + 1] = i;
	sort(c, c + n);
	for (int i = 1; i <= n; i++)
		for (int j = m; j; j--)
			for (int k = g[i - 1][j]; k <= g[i][j + 1] && k<i; k++)
				if (f[i][j]<f[k][j - 1] + c[k] * (i - k)) {
					f[i][j] = f[k][j - 1] + c[k] * (i - k);
					g[i][j] = k;
				}
	printf("%lld\n", f[n][m]);
	return 0;
}