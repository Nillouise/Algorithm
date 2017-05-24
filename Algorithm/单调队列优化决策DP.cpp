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
	for (int i = 1; i <= N; i++)
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
				//				d[i][j] = max(d[i][j],d[k][j-1] + A[i]*(k-i));//k-i Œ“–¥≥…¡Àk-j 
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