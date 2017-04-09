#include<iostream>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<algorithm>
#include<iterator>
#include<sstream>
#include <cstring>  
#include <cstdio>  
using namespace std;

//这题需要二维树状数组
int area[1024 + 1][1024 + 1];
int S;
int lowbit(int x)
{
	return x&(-x);
}

void add(int X, int Y, int d)
{
	while (X <= S)
	{
		area[Y][X] += d;
		X += lowbit(X);
	}
}

int sum(int Y, int T)
{
	int ret = 0;
	while (T>0)
	{
		ret += area[Y][T];
		T -= lowbit(T);
	}
	return ret;
}

int main()
{
	cin >> S >> S;
	int instruct;
	while (scanf("%d", &instruct) && instruct != 3)
	{
		if (instruct == 1)
		{
			int X, Y, A;
			cin >> X >> Y >> A;
			X++; Y++;
			add(X, Y, A);
		}
		else {
			int L, B, R, T;
			cin >> L >> B >> R >> T;
			L++; B++; R++; T++;
			int total = 0;
			for (size_t i = B; i <= T; i++)
			{
				total += sum(i, R) - sum(i, L - 1);//为什么要-1？因为 -1，才会算上 L这个格子
			}
			cout << total << endl;
		}
	}
	return 0;

}