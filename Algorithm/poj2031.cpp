#include <iostream>
#include <cstdio>
#include <cstring>
#include<string>
#include <algorithm>
#include<sstream>
#include<cmath>//这里有log 函数
using namespace std;
const int maxn = 200;
const double INF = 1000000.0;
double G[maxn][maxn];
int n;

int cal(double *a, double *b, int i, int j)
{
	double r = pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2) + pow(a[2] - b[2], 2);
	r = sqrt(r) - a[3] - b[3];
	G[i][j] = r < 0 ? 0 : r;
	return 0;
}

double prim()
{
	int vis[maxn];
	double dist[maxn];
	fill(vis, vis + maxn, 0);
	for (size_t i = 0; i < n; i++) dist[i] = G[0][i];
	vis[0] = 1;
	double sum = 0;
	for (size_t i = 0; i < n - 1; i++)//这个i只表示次数而已，没有其他任何意义，因为已经入了一个点了，所以只需要再入n-1个点。
	{
		int v = -1;
		double MIN = INF;
		for (size_t i = 0; i < n; i++)
		{
			if (dist[i] < MIN&&vis[i] == 0)//这句表示还没入团的，并且距离最小的
			{
				v = i;
				//				MIN = dist[0];//这里我又写错变量了
				MIN = dist[i];
			}
		}
		vis[v] = 1;
		sum += dist[v];

		for (size_t i = 0; i < n; i++)
		{
			if (G[v][i] < dist[i] && vis[i] == 0)//这句表示 还没入团的点，距离入团了的点的最小距离（因为只需要更新V点的距离？因为V点连的都是新边，之前的边只是旧边不需要改
				dist[i] = G[v][i];
		}
	}
	return sum;

}

int main() {
	freopen("input.txt", "r", stdin);

	double coor[100 + 5][4];
	while (cin >> n&&n != 0)
	{
		//		fill(&G[0][0], &G[maxn][maxn], INF);//注意这个fill二维数组的写法，这种二维数组这么写会溢出谢谢写到别的地方去
		for (size_t i = 0; i < maxn; i++)for (size_t j = 0; j < n; j++)G[i][j] = INF;

		for (size_t i = 0; i < n; i++)
		{
			cin >> coor[i][0] >> coor[i][1] >> coor[i][2] >> coor[i][3];
		}
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				cal(coor[i], coor[j], i, j);
			}
		}
		printf("%.3lf\n", prim());//要打印3位精度

	}


	return 0;
}