#include<iostream>
#include<list>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int n, m;
int tree[13][13];
long long DP[13][13][1 << 13];


int main()
{
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> tree[i][j];
			}
		}
		memset(DP, 0, sizeof(DP));
		DP[0][m][0] = 1;

		for (int i = 1; i <= n; i++)
		{
			//这里把上一行所有的状态复制进 i=0的格子里 
			//这里stat直接隔绝了首位是1的情况，也就是墙有线的情况 
			for (int stat = 0; stat<(1 << m); stat++)
			{
				if (stat&(1 << m))
				{
					continue;
				}
				else {
					DP[i][0][stat << 1] = DP[i - 1][m][stat];
				}
			}
			for (int j = 1; j <= m; j++)
			{
				int down = 1 << (j - 1);
				int right = 1 << j;
				for (int stat = 0; stat<(1 << (m + 1)); stat++)
				{
					if (tree[i][j])//有树 
					{
						if ((down&stat) && (right&stat))
						{
							DP[i][j][stat] += DP[i][j - 1][stat^right^down];
						}
						else if (!(down&stat) && !(right&stat))
						{
							//							DP[i][j][stat]+=DP[i][j-1][stat&down&right];
							//这里是|不是&，&是清0 
							DP[i][j][stat] += DP[i][j - 1][stat | down | right];
						}
						else
						{
							//							int b = 0;//这里long long 才行，中间变量又忘记要一致
							long long b = 0;
							b += DP[i][j - 1][stat];
							b += DP[i][j - 1][stat^right^down];
							DP[i][j][stat] += b;
						}
					}
					else {
						if (stat&right || stat&down)
						{
							DP[i][j][stat] = 0;
						}
						else {
							DP[i][j][stat] = DP[i][j - 1][stat];
						}
					}
				}
			}
		}
		printf("Case %d: ", t);
		printf("There are %I64d ways to eat the trees.\n", DP[n][m][0]);
	}
	return 0;
}