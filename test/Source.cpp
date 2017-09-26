#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;
typedef long long LL;
const int MAXN = 1e5+5;//者甩出这里exponent的奇怪规范
const int MAXX = 10 + 5;
const LL MOD = 1e9 + 7;
vector<int> tree[MAXN];
LL n, m, k, x;
LL dp[MAXN][MAXX][3];
int dfs(int c,int fa)
{
	dp[c][0][0] = k-1;
	dp[c][1][1] = 1;//注意这里是写这个树有多少个vault，包括这个root节点
	dp[c][0][2] = m - k;

	for (int i = 0; i < tree[c].size(); i++)
	{
		int y = tree[c][i];
		if (y == fa)continue;
		dfs(y, c);
		static LL nxt[MAXX][3];
		//memcpy(nxt, dp[c], sizeof(tmp));
		memset(nxt, 0, sizeof(nxt));

		for (int j = 0; j <= x; j++)
		{
			for (int s1 = 0; s1 < 3; s1++)//上面两个循环构成父状态
			{
				//if (nxt[j][s1] == 0)continue;//不能判断这个修改的背包
				if (dp[c][j][s1] == 0)continue;//当父状态是0时，不可能更新后面的父状态
				for (int k = 0; k <= x; k++)
				{
					if (k + j > x) break;//子节点的数量+父节点的数量不可能超过总数量
					for (int  s2 = 0; s2 < 3; s2++)//上面两个循环构成子树状态
					{
						//if (nxt[k][s2] == 0)continue;
						if (dp[y][k][s2] == 0)continue;//当子状态是0时，不可能更新父状态
						if (s1 == 0 || (s1 == 1 && s2 == 0) || (s1 == 2 && s2 != 1))
						{
							//nxt[j + k][s1] += tmp[j][s1] * dp[y][k][s2];//这里不能用nxt更新nxt，会出现循环覆盖（像背包那样）
							nxt[j + k][s1] += dp[c][j][s1] * dp[y][k][s2];
							nxt[j + k][s1] %= MOD;
						}
					}
				}

			}
		}
		memcpy(dp[c],nxt, sizeof(dp[c]));

	}


	return 0;
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	for (size_t i = 0; i < n-1; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	cin >> k >> x;
	dfs(0,-1);
	LL ans = 0;
	for (size_t i = 0; i <=x; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			ans += dp[0][i][j];
			ans %= MOD;
		}
	}
	cout << ans << endl;

	return 0;
}