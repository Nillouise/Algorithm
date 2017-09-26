//����һ��ʼ��Ӧ��֪������״dp��������ʲô��ֵ���ѧ����
//һ��ʼ�Ϳ��Դֱ��ذ�״̬��Ϊ3��������������ʲô����û�г�ͻ�����п��ܣ���������valut������secure�ģ���Ȼ������״dp֮��

//��һ��ע����ǣ�����ı߽����ݵĶ��壬���а������͸���״̬�����˼·
//���о��ǣ�������һ������ǰ���ֵ���º����ֵ���ᵼ�¸����˺����ֵ�����ǡ���ѩ�򡱵ظ��������ǲ��еģ�

#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 5;//��˦������exponent����ֹ淶
const int MAXX = 10 + 5;
const LL MOD = 1e9 + 7;
vector<int> tree[MAXN];
LL n, m, k, x;
LL dp[MAXN][MAXX][3];
int dfs(int c, int fa)
{
	dp[c][0][0] = k - 1;
	dp[c][1][1] = 1;//ע��������д������ж��ٸ�vault���������root�ڵ�
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
			for (int s1 = 0; s1 < 3; s1++)//��������ѭ�����ɸ�״̬
			{
				//if (nxt[j][s1] == 0)continue;//�����ж�����޸ĵı���
				if (dp[c][j][s1] == 0)continue;//����״̬��0ʱ�������ܸ��º���ĸ�״̬
				for (int k = 0; k <= x; k++)
				{
					if (k + j > x) break;//�ӽڵ������+���ڵ�����������ܳ���������
					for (int s2 = 0; s2 < 3; s2++)//��������ѭ����������״̬
					{
						//if (nxt[k][s2] == 0)continue;
						if (dp[y][k][s2] == 0)continue;//����״̬��0ʱ�������ܸ��¸�״̬
						if (s1 == 0 || (s1 == 1 && s2 == 0) || (s1 == 2 && s2 != 1))
						{
							//nxt[j + k][s1] += tmp[j][s1] * dp[y][k][s2];//���ﲻ����nxt����nxt�������ѭ�����ǣ��񱳰�������
							nxt[j + k][s1] += dp[c][j][s1] * dp[y][k][s2];
							nxt[j + k][s1] %= MOD;
						}
					}
				}

			}
		}
		memcpy(dp[c], nxt, sizeof(dp[c]));

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
		u--, v--;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	cin >> k >> x;
	dfs(0, -1);
	LL ans = 0;
	for (size_t i = 0; i <= x; i++)
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