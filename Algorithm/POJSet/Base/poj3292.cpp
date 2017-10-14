//拓展一下艾氏筛法即可，如果一个数i是H - 素数，那么5i + 4i * x 一定是H - 素数，因为(5i + 4i * x) mod 4 = 5i mod 4 = (5 mod 4) * (i mod 4) = 1 * 1 = 1。

//别人的代码

#ifndef ONLINE_JUDGE
#pragma warning(disable : 4996)
#endif
#include <iostream>
#include <cstdio>
#include <cstring>
#include<string>
#include <algorithm>
#include<sstream>
#include<cmath>

using namespace std;
#define MAX_H 1000001 + 16
bool is_H_prime[MAX_H], is_H_semiprime[MAX_H];
int H_prime[MAX_H];
int accumulate[MAX_H];

///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	// 艾氏筛法
	int p = 0;
	for (int i = 5; i < MAX_H; i += 4)
	{
		if (is_H_prime[i])
		{
			continue;
		}
		H_prime[p++] = i;
		for (int j = i * 5; j < MAX_H; j += i * 4)
		{
			is_H_prime[j] = true;
		}
	}
	for (int i = 0; i < p; ++i)
	{
		for (int j = 0; j < i + 1; ++j)
		{
			unsigned long long composite = H_prime[i] * H_prime[j];
			if (composite > MAX_H)
			{
				break;
			}
			is_H_semiprime[composite] = true;
		}
	}
	for (int i = 1; i < MAX_H; ++i)
	{
		accumulate[i] = accumulate[i - 1] + is_H_semiprime[i];
	}

	int h;
	while (cin >> h && h)
	{
		cout << h << ' ' << accumulate[h] << endl;
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif
	return 0;
}