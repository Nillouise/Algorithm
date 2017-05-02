#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include<iostream>
#define N 10
using namespace std;
int main()
{
	freopen("test.in", "w", stdout);
	int i, j, k;
	int n, m, p;
	int a, b, c;
	srand((unsigned)time(NULL));
	n = 30;
	for (i = 0; i < n; i++)
	{
		while ((rand() % 20))
		{
				if (rand() % 2)cout << "("; else cout << ")";

		}
		cout << endl;
	}
	return 0;
}