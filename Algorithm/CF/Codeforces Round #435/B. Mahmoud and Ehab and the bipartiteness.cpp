#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> tree[100000 + 5];
int vis[100000 + 5];
vector<int> vs1;
vector<int> vs2;

int dfs(int vs, int fa, int cur)
{
	if (vis[cur])return 0;
	vis[cur] = 1;
	if (vs == 1)
	{
		vs1.push_back(cur);
		for (size_t i = 0; i < tree[cur].size(); i++)
		{
			int child = tree[cur][i];
			dfs(2, cur, child);
		}
	}
	else {
		vs2.push_back(cur);
		for (size_t i = 0; i < tree[cur].size(); i++)
		{
			int child = tree[cur][i];
			dfs(1, cur, child);
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	int n;
	cin >> n;
	if (n == 1) { cout << 0 << endl; return 0; }
	int r = -1;
	//for (size_t i = 0; i < n-1; i++)
	for (size_t i = 0; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		r = u;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	dfs(1, -1, r);
	long long sub = n - 1;
	long long total = vs1.size()*vs2.size();//两个10万相乘要long long装，这里使我wa了三次
	long long gap = total - sub;
	//int gap = vs1.size()*vs2.size() - n+1;
	cout << gap << endl;

	return 0;
}