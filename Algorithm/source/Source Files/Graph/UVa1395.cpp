//对于求余数处理是否注意出现负数的情况；这点没有考虑
//坐标系变化不是很熟悉，变换错了一次
//getPos函数没有考虑好边界，这题是从1开始编号的
#include<algorithm>
#include<iostream>
#include<string>
#include<stack>
#include<fstream>
using namespace std;
int n, m;
const int INF = 1000000;
struct Edge
{
	int u, v, d;
	bool operator <(const Edge &t)
	{
		return d < t.d;
	}
	Edge(int u = 0, int v = 0, int d = 0) :u(u), v(v), d(d) {

	}
};
Edge edges[10000];
int p[1000];
int findset(int x)
{
	return p[x] == x ? x : p[x] = findset(p[x]);
}
int solve()
{
	//	for (size_t i = 0; i <= n; i++)p[i] = i; //错的，初始化的位置都放错了
	sort(edges, edges + m);
	int ans = INF;
	for (size_t b = 0; b < m; b++)
	{
		int cnt = 0;
		for (size_t i = 0; i <= n; i++)p[i] = i;
		for (size_t i = b; i < m; i++)
		{
			int u = findset(edges[i].u), v = findset(edges[i].v);
			if (u != v)
			{
				p[u] = v;
				cnt++;
			}
			if (cnt == n - 1)
			{
				int curd = edges[i].d - edges[b].d;
				if (curd < ans) {
					//					curd = ans;//这里居然写成了这样,导致ans 一直为INF
					ans = curd;
				}
				break;
			}

		}
	}
	if (ans == INF)
		return -1;
	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	for (;;)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)break;
		for (size_t i = 0; i < m; i++)
		{
			int a, b, d;
			cin >> a >> b >> d;
			Edge e(a, b, d);
			edges[i] = e;
		}
		cout << solve() << endl;

	}

	return 0;

}