#include<algorithm>
#include<iostream>
#include<cstring>
#include<stack>
#include<fstream>
#include<queue>
#include<vector>
using namespace std;
int n, m;
const int maxn = 500;
int order[maxn][maxn];
int vis[maxn];
int cnt = 0;
int path[maxn];
int topo(int x)
{
	if (vis[x] == 1)return 0;
	vis[x] = -1;
	for (size_t i = 1; i <= n; i++)//因为这里好像是从1算起的
	{
		if (order[x][i] == 1 && vis[i] != -1)
		{
			topo(i);
		}
	}
	path[cnt++] = x;
	vis[x] = 1;
	return 0;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while (cin >> n >> m && (!(n == 0 && m == 0)))//两个0时才会结束
	{
		memset(order, 0, sizeof(order));
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		memset(path, 0, sizeof(path));
		for (size_t i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			order[u][v] = 1;
		}
		for (size_t i = 1; i <= n; i++)
		{
			topo(i);
		}
		for (int i = cnt - 1; i >= 0; i--)
		{
			cout << path[i] << " ";
		}
		cout << endl;
	}
	return 0;

}