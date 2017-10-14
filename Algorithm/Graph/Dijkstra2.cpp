#include<iostream>
#include<vector>
#include<queue>

using namespace std;
const int maxstate = 100;
const int  INF = 1000;

struct Edge
{
	int u, v, w;
	Edge(int u, int v, int w) :u(u), v(v), w(w) {}
};
struct Token
{
	int d, s;
	bool operator < (const Token& t)const
	{
		return d < t.d;
	}
};

struct Dijkstra
{
	int d[maxstate];
	int done[maxstate];
	vector<int> G[maxstate];
	vector<Edge> edges;
	void run(int s)
	{
		d[s] = 0;
		priority_queue<Token> pq;
		pq.push( Token{ 0, s });
		
		while ( !pq.empty())
		{
			Token cn = pq.top(); pq.pop();
			if (done[cn.s])continue;
			done[cn.s] = 1;

			for (size_t i = 0; i < G[cn.s].size(); i++)
			{
				int y = G[cn.s][i];
				if (d[edges[y].v] < d[cn.s] + edges[y].w)
				{
					d[edges[y].v] = d[cn.s] + edges[y].w;
					pq.push(Token{ d[edges[y].v],edges[y].v });
				}
			}
		}
	}
};
