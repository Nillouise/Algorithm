#include<iostream>
#include<vector>

using namespace std;
const int maxstate = 10;
vector<int> G[maxstate];
int tree[maxstate];
int dfs(int u,int fa)
{
	tree[u] = fa;
	for (size_t i = 0; i < G[u].size(); i++)
	{
		if (G[u][i] != fa)
		{
			dfs(G[u][i], u);
		}
	}
}
int  main()
{
	int n, m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(n, -1);
}