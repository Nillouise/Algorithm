#include<iostream>
#include<vector>
#include<queue>

using namespace std;
const int maxn = 100;
const int  INF = 1000;

struct Edge
{
	int u, v, w;
	Edge(int u, int v, int w) :u(u), v(v), w(w) {}
};
struct Node
{
	int d, s;
	bool operator < (const Node& t)const
	{
		return d < t.d;
	}
};

struct Dijkstra
{
	int d[maxn];
	int done[maxn];
	vector<int> G[maxn];
	vector<Edge> edges;
	void run(int s)
	{
		d[s] = 0;
		priority_queue<Node> pq;
		pq.push( Node{ 0, s });
		
		while ( !pq.empty())
		{
			Node cn = pq.top(); pq.pop();
			if (done[cn.s])continue;
			done[cn.s] = 1;

			for (size_t i = 0; i < G[cn.s].size(); i++)
			{
				int y = G[cn.s][i];
				if (d[edges[y].v] < d[cn.s] + edges[y].w)
				{
					d[edges[y].v] = d[cn.s] + edges[y].w;
					pq.push(Node{ d[edges[y].v],edges[y].v });
				}
			}
		}
	}
};
