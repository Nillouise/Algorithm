//贪心错误
//假设最小的一直归并到最大的，就会发现，并把最小的放回原来位置更省钱。
//原本想的，一种珍珠要么买，要么不买是正确的，但不买的时候，原来便宜的珍珠可以放回原来便宜的位置
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 100 + 5;
const double INF = 10000000;

int dp[maxn];
int A[maxn];
int P[maxn];
int n;

int main() {
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (size_t i = 0; i < n; i++)
		{
			cin >> A[i] >> P[i];
		}
		memcpy(dp, A, sizeof(A));

		for (size_t i = 0; i < n - 1; i++)
		{
			if (P[i] * 10 > dp[i] * (P[i + 1] - P[i]))
			{
				dp[i + 1] += dp[i];
				dp[i] = 0;
			}
		}
		int sum = 0;
		for (size_t i = 0; i < n; i++)
		{
			if (dp[i] != 0)//0时，就不用额外买10个了，0跟1很不同的
				sum += (dp[i] + 10)* P[i];
		}
		cout << sum << endl;

	}


	return 0;
}