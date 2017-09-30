#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>//这个sqrt要用
#include<queue>
using namespace std;
typedef long long LL;
int n;
vector<int> tree;
vector<int> G[2 * 100000 + 55];
vector<int> dp1(2 * 100000 + 55, 0);
vector<int>dp2(2 * 100000 + 55, 0);

int gcd(int a, int b)
{
	if (a == 0)return b;
	return gcd(b%a, a);
}
vector<int> pregcd;
vector<int> path;
int dfs(int x, int fa)
{
	auto end = pregcd.end();
	end--;
	pregcd.push_back(gcd(tree[x], *end));
	path.push_back(tree[x]);

	int suf = 0;
	int MAX = -1;
	for (int i = path.size() - 1; i >0; i--)
	{
		//suf = gcd(path[i], suf);//这句是放在下面才对
		if (MAX < gcd(suf, pregcd[i - 1]))MAX = gcd(suf, pregcd[i - 1]);
		suf = gcd(path[i], suf);
	}
	dp1[x] = MAX;


	for (size_t i = 0; i < G[x].size(); i++)
	{
		if (G[x][i] == fa)
			continue;
		dfs(G[x][i], x);
	}
	pregcd.erase(--pregcd.end());
	path.erase(--path.end());
	return 0;
}




int main()
{
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);

	cin >> n;
	tree.push_back(0);
	for (size_t i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		tree.push_back(a);
	}
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	//pregcd.push_back(tree[1]);//这是不行的
	pregcd.push_back(0);
	path.push_back(0);
	dfs(1, 0);
	dp1[1] = tree[1];
	for (int i = 1; i <= n; i++)
	{
		cout << dp1[i] << " ";
	}
	cout << endl;

	return 0;
}