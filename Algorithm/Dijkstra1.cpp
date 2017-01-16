#include<iostream>
#include<algorithm>
using namespace std;


//这个是用邻接矩阵做的

const int maxn = 100;
int u[maxn], v[maxn], w[maxn];
int nextEdge[maxn];
int pointFirstEdge[maxn];
int done[maxn];
int d[maxn];
const int INF = 1000;

int main()
{
	//Init
	int pointNumber;
	int edgeNumber;
	//init 
	memset(nextEdge, -1, sizeof(nextEdge));
	memset(pointFirstEdge, -1, sizeof(pointFirstEdge));
	for (size_t i = 0; i < maxn; i++)
	{
		d[i] = INF;
	}
	d[0] = 0;

	//input
	for (size_t e = 0; e < edgeNumber; e++)
	{
		cin >> u[e] >> v[e] >> w[e];
		nextEdge[e] = pointFirstEdge[u[e]];
		pointFirstEdge[u[e]] = e;
	}

	//cal
	for (size_t i = 0; i < pointNumber; i++)
	{
		int x = 0, pcw = INF;
		for (size_t y = 0; y < pointNumber; y++)
		{
			if(d[y]<pcw&&!done[y])
			pcw = d[x = y];
		}
		done[x] = 1;
		for (size_t y = pointFirstEdge[x]; nextEdge[y] != -1; y = nextEdge[y])
		{
			d[v[y]] = min(d[v[y]], d[x] + w[y]);
		}

	}





}
