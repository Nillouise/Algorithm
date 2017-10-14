#include<iostream>

#include<cstring>

#include<cstdio>

#include<algorithm>

#include<vector>

using namespace std;

int n;

double x[5000 + 5];

double y[5000 + 5];

int vis[5000 + 5];

double dist[5000 + 5];



inline double cal(int i, int j)

{

	double r = 0;

	r += sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));

	r += abs(x[i] - x[j]) + abs(y[i] - y[j]);

	r += x[i] * x[j] + y[i] * y[j];

	return r / 3;

}

double prim(int start)

{

	memset(vis, 0, sizeof(vis));

	vis[start] = 1;

	dist[start] = 0;

	for (size_t i = 0; i < n; i++)

	{

		if (start == i)

			continue;

		dist[i] = cal(start, i);

	}

	double r = 0;

	for (size_t i = 0; i < n - 1; i++)

	{

		double MAX = -1000000000.0; int node = 0;

		for (int j = 0; j < n; j++)

		{

			if (vis[j] == 1)continue;

			if (dist[j] >MAX) { node = j; MAX = dist[j]; }

		}

		r += dist[node];

		vis[node] = 1;

		for (size_t j = 0; j < n; j++)

		{

			if (vis[j] == 1)continue;

			dist[j] = max(dist[j], cal(node, j));

		}

	}

	return r;

}



int main()

{
	freopen("input.txt", "r", stdin);
	while (cin >> n)

	{

		for (int i = 0; i < n; i++)

		{

			scanf("%lf %lf", &x[i], &y[i]);

		}

		printf("%.4f\n", prim(0));



	}

	return 0;



}