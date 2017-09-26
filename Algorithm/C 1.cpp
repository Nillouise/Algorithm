#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;
typedef long long LL;
const int MAXN = 10e5 + 5;
const int MAXX = 10 + 5;
const LL MOD = 10e9 + 7;
vector<int> tree[MAXN];
LL n, m, k, x;
LL dp[MAXN][MAXX][3];
int dfs(int c, int fa)
{
	dp[c][0][0] = k - 1;
	dp[c][1][1] = 1;
	dp[c][0][2] = m - k;

	for (int i = 0; i < tree[c].size(); i++)
	{
		int y = tree[c][i];
		if (y == fa)continue;
		dfs(y, c);
		static LL tmp[MAXX][3];
		memcpy(tmp, dp[c], sizeof(tmp));

		//�������Ҫ�����ǣ�Ӧ�ðѸ�״̬[����][״̬]����״̬[����][״̬]����������ȥ���¸�״̬����һ��״̬
		for (int j = 0; j <= x; j++)//������vault������
		{
			for (int k = 0; k <= x; k++)//���е�vault������
			{
				if (j + k > x)continue;
				for (int l = 0; l < 3; l++)//�ӽڵ������
				{
					if (dp[y][k][l] == 0)continue;//�����ӽڵ�ĳ��״̬�ǲ����ڵ�

					if (l == 0)
					{
						tmp[k + j][0] += tmp[j][0] * dp[y][k][0];
						tmp[k + j][1] += tmp[j][1] * dp[y][k][0];
						tmp[k + j][2] += tmp[j][2] * dp[y][k][0];
					}
					if (l == 1)
					{
						tmp[k + j][0] += tmp[j][0] * dp[y][k][1];
					}
					if (l == 2)
					{
						tmp[k + j][2] += tmp[j][2] * dp[y][k][2];
						tmp[k + j][0] += tmp[j][0] * dp[y][k][2];
					}
					//����֮�����tmp������Ҫmodһ��
					tmp[k + j][0] %= MOD;
					tmp[k + j][1] %= MOD;
					tmp[k + j][2] %= MOD;
				}
			}
		}
		memcpy(dp[c], tmp, sizeof(tmp));
	}


	return 0;
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (size_t i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	cin >> k >> x;



	return 0;
}