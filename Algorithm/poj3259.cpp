#include <iostream>
#include <cstdio>
#include <cstring>
#include<string>
#include <algorithm>
#include<sstream>
#include<cmath>
#include<queue>
using namespace std;
const int maxn = 2000;
const double INF = 1000000.0;
int N, M, W;
struct Edge
{
	int u, v, w;
	Edge(int u, int v, int w) :u(u), v(v), w(w) {}
};
vector<Edge> edges;
int state[maxn];
int BellMon()
{
	fill(state, state + maxn, INF);
	//	state[1] = 0;//������Ҫ��ʼֵ��ֻҪ�и�Ȧ
	//	for (int i = 0; i < N; i++)
	for (int i = 0; i < N - 1; i++)//һ���������N-1����������Ҳ����������N-1�Σ�ûȦ�Ļ���
	{
		int flag = 0;
		for (int j = 0; j < edges.size(); j++)
		{
			Edge &e = edges[j];
			if (state[e.u] + e.w < state[e.v])
			{
				flag = 1;
				state[e.v] = state[e.u] + e.w;
			}
		}
		if (!flag)break;
	}
	for (int j = 0; j < edges.size(); j++)
	{
		Edge &e = edges[j];
		if (state[e.u] + e.w < state[e.v])
		{
			return 1;
		}
	}
	return 0;
}


int main()
{
	freopen("input.txt", "r", stdin);

	int F;
	cin >> F;
	while (F--)
	{
		cin >> N >> M >> W;
		edges.clear();
		for (size_t i = 0; i < M; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;

			edges.push_back(Edge(u, v, w));
			edges.push_back(Edge(v, u, w));

		}
		for (size_t i = 0; i < W; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			edges.push_back(Edge(u, v, -w));
		}
		if (BellMon())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}