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

		cout <<rand()% 100000 <<" "<<rand()<< endl;
	}
	return 0;
}