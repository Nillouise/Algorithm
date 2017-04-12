#include<iostream>
#include<memory.h>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<cmath>
using namespace std;
int island[10000][2];
int line[10000];
int n, d;
int dist(int i)
{
	return island[0][0] + sqrt(d*d - island[i][1] * island[i][1]);
}

int main()
{
	cin >> n >> d;
	for (int i = 0; i<n; i++)
	{
		cin >> island[i][0] >> island[i][1];
	}
	for (int i = 0; i<n; i++)
		line[i] = dist(i);
	sort(line, line + n);
	int curx = line[0];
	int curxi = 0;
	int cnt = 0;
	for (int i = 0; i<n; i++)
	{
		int x = curx - island[i][0];
		if (x*x + island[i][1] * island[i][1]>d*d)
		{
			for (int j = curxi; j<n; j++)
			{
				if (pow(line[j] - island[i][0], 2) + pow(island[i][j], 2) == d*d)
				{
					curxi = j;
					cnt++;
					curx = line[curxi];
				}
				break;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
