#include<cmath>
#include <cstring>
#include <algorithm>
#include<iostream>
using namespace std;
int N;
double A[1000 + 7];
double X[1000 + 7];



int tong(int b, int e, int *vis, int avoid, int paint, double &xie)
{
	int x = e - b;
	double y = A[e] - A[b];
	xie = y / (double)x;
	vis[b] = paint;
	for (int i = 0; e + i < N; i++)
	{
		int c = e + i;
		if (abs(A[b] + (e - b + i)*xie - A[c])<10e-10)
		{
			if (vis[c] == avoid)
			{
				return 0;
			}
			else {
				vis[c] = paint;
			}
		}
	}
	return 1;
}

int check(int*vis, int begin, int empty)
{
	for (size_t i = begin; i < N; i++)
	{
		if (vis[i] == empty)
			return 0;
	}
	return 1;
}

int firstempty(int *vis, int begin, int empty)
{
	for (size_t i = begin; i < N; i++)
	{
		if (vis[i] == empty)
		{
			return i;
		}
	}
	return -1;
}

int main()
{

	cin >> N;
	int maxI;
	double MAX = -10.0e9 - 100.0;
	int minI;
	double MIN = 10.0e9 + 100.0;
	for (size_t i = 0; i < N; i++)
	{
		cin >> A[i];
		if (i == 0)continue;
		double cur = (A[i] - A[0]) / (double)(i - 0);
		if (cur > MAX)
		{
			maxI = i;
			MAX = cur;
		}
		if (cur < MIN)
		{
			minI = i;
			MIN = cur;
		}
	}
	if (MIN == MAX)
	{
		cout << "No" << endl;
		return 0;
	}
	//第一点为独点
	int vis[1000 + 5];
	memset(vis, 0, sizeof(vis));
	double xxx;
	tong(1, 2, vis, 100, 1, xxx);
	if (check(vis, 1, 0) == 1)
	{
		cout << "Yes" << endl;
		return 0;
	}
	else {
		//第一点为组合点
		memset(vis, 0, sizeof(vis));
		double xie1;
		tong(0, maxI, vis, 100, 1, xie1);
		int y1 = firstempty(vis, 1, 0);
		int y2 = firstempty(vis, y1 + 1, 0);
		if (y2 == -1)
		{
			cout << "Yes" << endl;
			return 0;
		}
		double xie2;
		if (tong(y1, y2, vis, 1, 2, xie2) == 1 && check(vis, 1, 0) == 1)
		{
			if (abs(xie1 - xie2) < 10e-6)
			{
				cout << "Yes" << endl;
				return 0;
			}

		}
		memset(vis, 0, sizeof(vis));
		tong(0, minI, vis, 100, 1, xie1);
		y1 = firstempty(vis, 1, 0);
		y2 = firstempty(vis, y1 + 1, 0);
		if (y2 == -1)
		{
			cout << "Yes" << endl;
			return 0;
		}
		if (tong(y1, y2, vis, 1, 2, xie2) == 1 && check(vis, 1, 0) == 1)
		{
			if (abs(xie1 - xie2) < 10e-6)
			{
				cout << "Yes" << endl;
				return 0;
			}
		}

	}
	cout << "No" << endl;
	return 0;

}