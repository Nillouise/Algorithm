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
vector<int> G[100000 * 2 + 5];
vector<int> tree;
//map<int, int> cntdivisor;//太慢了
int cntdivisor[100000 * 2 + 5];
int ans[100000 * 2 + 5][2];

vector<int> divisor[100000 * 2 + 5];
void init()
{
	for (int i = 1; i < 100000 * 2 + 1; i++)
	{
		for (int j = i; j < 100000 * 2 + 1; j += i)
		{
			divisor[j].push_back(i);
		}
	}
}


int dfs(int x, int p, int dep)
{
	//ans[x][1] = ans[p][1];//当要把当前节点变成0时
	ans[x][1] = ans[p][0];


	//vector<int>cd;
	//cd.clear();
	//for (int i = 1; i*i <= tree[x]; i++)
	//{
	//	if (tree[x] % i == 0)
	//	{
	//		cntdivisor[i]++;
	//		cd.push_back(i);
	//		//if (i*i != tree[x]);//多打了;号
	//		if (i*i != tree[x])
	//		{
	//			cntdivisor[tree[x] / i]++;
	//			cd.push_back(tree[x] / i);
	//		}
	//	}
	//}
	//for (auto a:divisor[tree[x]])
	for (auto &a : divisor[tree[x]])
	{
		cntdivisor[a]++;
	}


	//for (auto a:cd)
	//for(auto a: divisor[tree[x]])
	for (auto &a : divisor[tree[x]])
	{
		if (cntdivisor[a] == dep)
		{
			ans[x][0] = max(a, ans[x][0]);
		}
		if (cntdivisor[a] == dep - 1)
		{
			ans[x][1] = max(a, ans[x][1]);
		}
	}

	//这样做，因为整个路径的所有因数都要算一遍，太慢了
	//for (auto i = cntdivisor.begin(); i !=cntdivisor.end();)
	//{
	//	if (i->second == dep)
	//	{
	//		ans[x][0] = max(i->first, ans[x][0]);
	//	}
	//	if (i->second == dep - 1)
	//	{
	//		ans[x][1] = max(i->first, ans[x][1]);
	//	}
	//	//这是不行的，因为这里erase的话，那返回到上一层时，父节点的map就不对了。
	//	//if (i->second < dep - 1)
	//	//{
	//	//	i =cntdivisor.erase(i);
	//	//}
	//	//else {
	//	//	i++;
	//	//}

	//}
	for (size_t i = 0; i < G[x].size(); i++)
	{
		if (G[x][i] == p)continue;
		dfs(G[x][i], x, dep + 1);
	}

	//for (auto a : cd)
	//{
	//	cntdivisor[a]--;
	//}

	for (auto &a : divisor[tree[x]])
	{
		//cntdivisor[a]--;
		cntdivisor[a]--;
	}
	//for (int i = 1; i*i <= tree[x]; i++)
	//{
	//	//if (tree[x] % i == 0 &&cntdivisor.find(i)!=cntdivisor.end() )cntdivisor[i]--;
	//	 if (tree[x] % i == 0)cntdivisor[i]--;//这是错的，因为另一个因素没有减去
	//}
	return 0;
}


int main()
{
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	init();
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		tree.push_back(a);
	}

	for (size_t i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(0, 0, 1);

	for (size_t i = 0; i < n; i++)
	{
		cout << max(ans[i][0], ans[i][1]) << " ";
	}
	cout << endl;
	return 0;
}