#include <iostream>
#include <cstdio>
#include <cstring>
#include<string>
#include <algorithm>
#include<sstream>
#include<cmath>//������log ����
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
	for (size_t i = 0; i < n - 1; i++)//���iֻ��ʾ�������ѣ�û�������κ����壬��Ϊ�Ѿ�����һ�����ˣ�����ֻ��Ҫ����n-1���㡣
	{
		int v = -1;
		double MIN = INF;
		for (size_t i = 0; i < n; i++)
		{
			if (dist[i] < MIN&&vis[i] == 0)//����ʾ��û���ŵģ����Ҿ�����С��
			{
				v = i;
				//				MIN = dist[0];//��������д�������
				MIN = dist[i];
			}
		}
		vis[v] = 1;
		sum += dist[v];

		for (size_t i = 0; i < n; i++)
		{
			if (G[v][i] < dist[i] && vis[i] == 0)//����ʾ ��û���ŵĵ㣬���������˵ĵ����С���루��Ϊֻ��Ҫ����V��ľ��룿��ΪV�����Ķ����±ߣ�֮ǰ�ı�ֻ�Ǿɱ߲���Ҫ��
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
		//		fill(&G[0][0], &G[maxn][maxn], INF);//ע�����fill��ά�����д�������ֶ�ά������ôд�����ллд����ĵط�ȥ
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
		printf("%.3lf\n", prim());//Ҫ��ӡ3λ����

	}


	return 0;
}