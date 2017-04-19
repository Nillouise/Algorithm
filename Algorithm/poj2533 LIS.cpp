#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 1000 + 5;
const double INF = 10000000;

int n;
int a[maxn];
int LIS()
{
	int dp[maxn];
	fill(dp, dp + maxn, INF);

	//	dp[0] = 0;//ò�Ʋ�����Ҫ��ʼ�����Ϊ0����Ϊ�������Զ����ڴ��ڵ��ڵĵط�

	for (size_t i = 0; i < n; i++)
	{
		*lower_bound(dp, dp + n, a[i]) = a[i];

	}
	return lower_bound(dp, dp + n, INF) - dp;

}

int main() {
	freopen("input.txt", "r", stdin);
	while (cin >> n)
	{
		for (size_t i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cout << LIS() << endl;
	}

	return 0;
}