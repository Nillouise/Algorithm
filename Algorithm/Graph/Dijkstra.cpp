#include<iostream>
#include<vector>
#include<math.h>
#include<cmath>
#include<algorithm>
using namespace std;

//这个是 平方级的算法。

const int maxstate = 100;

int w[maxstate][maxstate];


const int INF = 10000;
int d[maxstate];
int done[maxstate];
int main()
{
	for (size_t i = 0; i < maxstate; i++)
		d[i] = (i==0?0: INF);
	d[0] = 0;
	int pc = 100;
	//for (size_t i = 0; i < pc; i++)
	//	cin >> u[i] >> v[i] >> w[i];
	//没写这个录入代码。
	for (size_t i = 0; i < pc; i++)
	{
		int cp = 0; int cpw = INF;
		for (size_t j = 0; j < pc; j++)
			if (d[j]<cpw && !done[j])
			{
				cpw = d[j];
				cp = j;
				//cpw = d[cp=j];
			}
		done[cp] = 1;
		for (size_t j = 0; j < pc; j++)
			d[j] = max(d[j], d[cp] + w[cp][j]);
	}

	return 0;
}

