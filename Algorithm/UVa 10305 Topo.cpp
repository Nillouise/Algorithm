#include<algorithm>
#include<iostream>
#include<cstring>
#include<stack>
#include<fstream>
#include<queue>
#include<vector>
using namespace std;
int n, k;
const int maxn = 1000;
int chess[maxn][maxn];
int vis[maxn];
int match[maxn];
int dfs(int x)
{
	for (size_t i = 0; i < n; i++)
	{
		if (chess[x][i] == 1)
		{
			if (vis[i] == 1)continue;
			vis[i] = 1;//vis�������޸ģ���ʾȷȷʵʵ��������i���������ˣ���û�ɹ�����һ���¡�
			if (match[i] == -1|| dfs(match[i]))
			{
				match[i] = x;
//				vis[i] = 1;//vis ��Ӧ���������޸ĵģ���Ȼdfs�ͻ����޵ݹ� i�ˣ�
				return 1;
			}
		}
	}
	return 0;
}

int solve()
{
	int all = 0;
	for (size_t i = 0; i < n; i++)
	{
		memset(vis, 0, sizeof(vis));
		all += dfs(i);
	}
	return all;
}

int main()
{
	cin >> n >> k;
	memset(chess, 0, sizeof(chess));
	memset(vis, 0, sizeof(vis));
	memset(match, -1, sizeof(match));
	for (size_t i = 0; i < k; i++)
	{
		int R, C;
		cin >> R >> C; R--; C--;
		chess[R][C] = 1;
	}
	cout << solve() << endl;

	return 0;

}