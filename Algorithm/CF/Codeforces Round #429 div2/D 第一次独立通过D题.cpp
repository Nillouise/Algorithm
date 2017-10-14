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
vector<int> G[3 * 100000 + 10];
vector<int> index[3 * 100000 + 10];
LL cntv[3 * 100000 + 10];
vector<int> p[3 * 100000 + 10];
vector<int> D;


vector<int> noone;
int vistree[3 * 100000 + 10];
int dfs(int x, int fa)
{
	vistree[x] = 1;//这是图，要防止互为子节点，这里互为子节点会导致内存爆掉

	for (int i = 0; i < G[x].size(); i++)
	{
		if (vistree[G[x][i]] == 0)
		{
			dfs(G[x][i], x);
		}
	}
	if (cntv[x] % 2 != D[x])
	{
		cntv[fa]++;
		for (int i = 0; i < G[x].size(); i++)
		{
			if (G[x][i] == fa)
			{
				noone.push_back(index[x][i]);
				return 0;
			}
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);


	int n, m;
	cin >> n >> m;
	for (size_t i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		D.push_back(a);
	}

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
		index[u].push_back(i);
		index[v].push_back(i);
	}
	vector<set<int>> v;
	vector<int> init;
	//for (int i = 0; i < n; i++)init.push_back(0);
	for (int i = 0; i < n; i++)init.push_back(i);
	set<int> tot(init.begin(), init.end());
	set<int> s;

	set<int> tot2;
	for (int i = 0; i < n; i++)
	{
		if (D[i] == -1)
		{
			s.insert(i);
			tot.erase(i);
			tot2.insert(i);
		}
	}
	v.push_back(s);
	//if (n == 150000 && m == 300000) { cout << -1 << endl; return 0; }
	if (s.size() == 0)
	{
		for (int i = 0; i < min(100, n - 1); i++)
		{
			dfs(i, 3 * 100000 + 2);
			if (cntv[3 * 100000 + 2] != 0)
			{
				memset(vistree, 0, sizeof(vistree));
			}
			else {
				cout << noone.size() << endl;
				for (size_t i = 0; i < noone.size(); i++)
				{
					cout << noone[i] + 1 << " ";
				}
				cout << endl;
				return 0;
			}
		}

		cout << -1 << endl;
		return 0;

	}


	//if (n == 150000 && m == 300000) { cout << -1 << endl; return 0; }
	while (!tot.empty())
	{
		set<int> s;
		s.clear();//不clear，可能导致超内存，因为没清内存
		int solution = 0;
		//vector<int> cv;
		for (auto a = tot.begin(); a != tot.end();)
		{
			//看这个节点有没有连在之前消去的节点上
			int flag = false;
			for (int i = 0; i < G[*a].size(); i++)
			{
				if (tot2.find(G[*a][i]) != tot2.end())//优化
				{
					flag = true;
					p[*a].push_back(G[*a][i]);
					solution = 1;
					break;
				}
			}
			if (flag)
			{
				s.insert(*a);
				//cv.push_back(*a);
				a = tot.erase(a);
			}
			else {
				a++;
			}
		}
		//if (solution == 0)
		//{
		//	//也有可能并没有树状结构（由-1诞生的一棵树，但有种情况是没有-1）

		//	dfs(0, 3 * 100000+2);
		//	if (cntT[3 * 100000 + 2]!=0)
		//	{
		//		cout << -1 << endl;
		//		return 0;
		//	}

		//	cout << noone.size() << endl;
		//	for (size_t i = 0; i < noone.size(); i++)
		//	{
		//		cout << noone[i] << " ";
		//	}

		//	cout << endl;
		//	return 0;
		//}
		if (solution == 0)
		{
			cout << -1 << endl;
			return 0;
		}

		v.push_back(s);
		tot2.insert(s.begin(), s.end());
	}
	vector<int >res;
	LL cnt = 0;
	//已经层级堆叠了
	for (auto a = v.rbegin(); a != v.rend(); a++)
	{
		for (auto i : *a)
		{
			if (D[i] == -1)break;


			if (cntv[i] % 2 != D[i])
			{
				for (int j = 0; j < G[i].size(); j++)//在之前的位置放index，优化掉这步
				{
					if (G[i][j] == p[i][0])
					{
						cntv[p[i][0]]++;
						cnt++;
						res.push_back(index[i][j]);
						break;
					}
				}
			}
		}
	}


	cout << cnt << endl;
	for (auto a : res)
	{
		cout << a + 1 << " ";
	}
	cout << endl;

	return 0;
}