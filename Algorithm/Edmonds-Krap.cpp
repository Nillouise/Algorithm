#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;
const int maxstate = 20;
const int INF = 100000;
struct Edge
{
	int from, to, cap, flow;
	Edge(int u, int v, int c, int f) :from(u), to(v), cap(c), flow(f) {}
};

struct  EdmondsKarp
{
	int n, m;
	vector<Edge> edges;
	vector<int> G[maxstate];
	int a[maxstate];
	int p[maxstate];
	void init(int n) {
		for (size_t i = 0; i < n; i++)
			G[i].clear();
		edges.clear();
	}
	void addEdge(int from, int to, int cap)
	{
		edges.push_back(Edge(from, to, cap, 0));
		edges.push_back(Edge(to, from, 0, 0));
		m = edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);

	}

	int Maxflow(int s, int t)
	{
		int flow = 0;
		for (;;)
		{
			memset(a, 0, sizeof(a));
			queue<int> Q;
			Q.push(s);
			a[s] = INF;
			while (!Q.empty())
			{
				int curNode = Q.front(); Q.pop();

				for (size_t i = 0; i < G[curNode].size(); i++)
				{
					Edge& e = edges[G[curNode][i]];
					if (a[e.to] > 0)continue;
					if (e.cap <= e.flow)continue;// it represent that this point is had use(use >0 to signal)
					a[e.to] =  min(a[curNode], e.cap - e.flow);
					p[e.to] = G[curNode][i];
					Q.push(e.to);
				}
				if (a[t] > 0)break;
			}
			if (a[t] == 0)break;

			int r = p[t];
			while(true )
			{
				edges[r].flow += a[t];
				edges[r ^ 1].flow -= a[t];
				r = edges[r].from;
				if (edges[r].from == s)break;
			}
			flow += a[t];

		}
		return flow;

	}


};