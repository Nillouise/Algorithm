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
//EK�㷨��ÿ�ζ�����̣����Ǿ����ڵ������٣�������Ȩֵ��С����·��������

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
		for (size_t v = 0; v < n + 2; v++)//�ܹ���n+2�����
		{
			if (flow[v] == 0 && G[u][v]> 0)//����ԭ��д���ˣ�Ҫ�ұ߲��ܸ���v��
			{
				flow[v] += min(G[u][v], flow[u]);//�����Ұ� uд����v��û��˼������������
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
	int flow = 0;//���ǳ�ʼ������
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
				//				cout << u << "��";
				G[u][v] -= curFlow;//���������ֳ��˸�bug ��������curflow�Ŷԣ���Ҳֻ�������� ��ǰ��������
				G[v][u] += curFlow;//д��flow����Ϊ����û�п��Ǳ����ĺ���
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
		memset(G, 0, sizeof(G));//û�г�ʼ����������һ������뵽�������
		for (size_t i = 0; i < m; i++)
		{
			cin >> ch >> x >> ch >> y >> ch >> z;
			G[x + 1][y + 1] += z;
		}
		for (size_t i = 0; i < np; i++)
		{
			int a, cap;
			cin >> ch >> a >> ch >> cap;
			G[0][a + 1] += cap;//��Ŀ��0��ʼ��ţ�����Ϊ���������˳���ԭ����0λ���ϣ�����Ҫ+1��
							   //��Ϊ����֤�߲��ظ�������Ҫ+=
		}
		for (size_t i = 0; i < nc; i++)
		{
			int a, cap;
			cin >> ch >> a >> ch >> cap;
			G[a + 1][n + 1] += cap;//����Ҫn+1����Ϊ 0���³���ԭ�㣬�ܹ�����n+2�����
		}
		cout << EK(0, n + 1) << endl;

	}


	return 0;

}