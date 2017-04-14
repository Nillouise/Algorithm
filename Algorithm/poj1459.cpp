//#include<iostream>
//#include<queue>
//using namespace std;
//int g[205][205], pre[205];
//int dfs(int b, int n)
//{
//	int i, v;
//	queue<int>q;
//	int flow[205], visit[205];
//	memset(flow, -1, sizeof(flow));
//	memset(visit, 0, sizeof(visit));
//	while (!q.empty()) q.pop();
//	q.push(b); visit[b] = 1;
//	flow[0] = (1 << 30); pre[b] = b;
//	while (!q.empty())
//	{
//		v = q.front();
//		q.pop();
//		for (i = b; i <= n; i++)
//		{
//			if (!visit[i] && g[v][i])
//			{
//				visit[i] = 1;
//				flow[i] = flow[v]<g[v][i] ? flow[v] : g[v][i];
//				q.push(i);
//				pre[i] = v;
//			}
//		}
//	}
//	if (flow[n] != -1) return flow[n];
//	else return 0;
//}
//int getmaxflow(int b, int n)
//{
//	int _min, total = 0, np, pp;
//	while (_min = dfs(b, n))
//	{
//		np = n;
//		cout << "min " << _min <<" " <<n<<" ";
//		while (np != b)
//		{
//			pp = pre[np];
//			cout << pp << " ";
//			g[pp][np] -= _min;
//			g[np][pp] += _min;
//			np = pp;
//		}
//		cout << endl;
//		total += _min;
//	}
//	return total;
//}
//
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	int n, np, nc, m;
//	while (scanf("%d%d%d%d", &n, &np, &nc, &m) != EOF)
//	{
//		int i, j;
//		int a, b, c;
//		char ch;
//		memset(g, 0, sizeof(g));
//		for (i = 0; i<m; i++)
//		{
//			ch = getchar();
//			while (ch != '(')
//				ch = getchar();
//			scanf("%d,%d)%d", &a, &b, &c);
//			g[a + 1][b + 1] += c;
//		}
//		for (i = 0; i<np; i++)
//		{
//			ch = getchar();
//			while (ch != '(')
//				ch = getchar();
//			scanf("%d)%d", &a, &b);
//			g[0][a + 1] += b;
//		}
//		for (i = 0; i<nc; i++)
//		{
//			ch = getchar();
//			while (ch != '(')
//				ch = getchar();
//			scanf("%d)%d", &a, &b);
//			g[a + 1][n + 1] += b;
//		}
//		printf("%d\n", getmaxflow(0, n + 1));
//	}
//	system("pause");
//	return 0;
//}
//
//EK算法是每次都找最短（就是经过节点数最少，而不是权值最小）的路进行增广

#include<algorithm>
#include<iostream>
#include<cstring>
#include<stack>
#include<fstream>
#include<queue>
#include<vector>
using namespace std;
const int maxn = 1000;
const int INF = 1000000;
int n, np, nc, m;
int G[maxn][maxn];
int pa[maxn];
int bfs(int start, int end)
{
	int flow[maxn];
	memset(flow, 0, sizeof(flow));
	queue<int> q;
	q.push(start);
	flow[start] = INF;
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (size_t v = 0; v < n + 2; v++)//总共是n+2个点的
		{
			if (flow[v] == 0 && G[u][v]> 0)//这里原本写错了，要右边才能更新v点
			{
				flow[v] += min(G[u][v], flow[u]);//这里我把 u写成了v，没有思考变量的意义
				pa[v] = u;
				q.push(v);
				//if (v == end)
				//	return flow[v];
			}
		}
	}
	if (flow[end])
		return flow[end];
	return 0;
}

int EK(int start, int end)
{
	int flow = 0;//忘记初始化变量
	for (;;)
	{
		memset(pa, -1, sizeof(pa));
		int curFlow = bfs(start, end);
		if (curFlow == 0)
			return flow;
		else
		{
			flow += curFlow;
			int u = -1;
			int v = end;
			//			cout << "flow " << flow << " " << v << " ";
			for (;;)
			{
				u = pa[v];
				if (u == -1)break;
				//				cout << u << "　";
				G[u][v] -= curFlow;//这里老子又出了个bug ，这里是curflow才对，减也只是用来减 当前的流而已
				G[v][u] += curFlow;//写成flow，因为我又没有考虑变量的含义
				v = u;
			}
			//			cout << endl;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	while (cin >> n >> np >> nc >> m)
	{
		char ch;
		int x, y, z;
		memset(G, 0, sizeof(G));//没有初始化变量，但一出错就想到这个问题
		for (size_t i = 0; i < m; i++)
		{
			cin >> ch >> x >> ch >> y >> ch >> z;
			G[x + 1][y + 1] += z;
		}
		for (size_t i = 0; i < np; i++)
		{
			int a, cap;
			cin >> ch >> a >> ch >> cap;
			G[0][a + 1] += cap;//题目是0开始编号，但因为我这里赛了超级原点在0位置上，所以要+1；
							   //因为不保证边不重复，所以要+=
		}
		for (size_t i = 0; i < nc; i++)
		{
			int a, cap;
			cin >> ch >> a >> ch >> cap;
			G[a + 1][n + 1] += cap;//这里要n+1，因为 0点事超级原点，总共是有n+2个点的
		}
		cout << EK(0, n + 1) << endl;

	}


	return 0;

}