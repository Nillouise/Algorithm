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
	bool operator < (const Node& t)
	{
		return d < t.d;
	}
};

struct Dijkstra
{
	int d[maxn];
	int done[maxn];
	vector<Edge> G[maxn];

	void run(int s)
	{
		d[s] = 0;
		priority_queue<Node> pq;
		pq.push( Node{ 0, s });
		{0, 1; };
	}
};
