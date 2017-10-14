#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 5001;
const double INF = 10000000;
char A[maxn];
char A2[maxn];
int dp[2][maxn];
int n;

int main() {
	freopen("input.txt", "r", stdin);
	while (cin >> n&&n != 0)
	{
		cin >> A;
		for (size_t i = 0; i < n; i++)
			A2[i] = A[n - i - 1];
		memset(dp, 0, sizeof(dp));
		//		dp[0][0] = (A[0] == A2[0] ? 1 : 0);
		for (size_t i = 0; i < n; i++)
		{
			dp[1][0] = (A[0] == A2[i] ? 1 : 0);//这句是精华
			for (size_t j = 1; j < n; j++)
			{
				//				if (A[i] == A[j]) //这里我又忘记变量的含义
				if (A2[i] == A[j])
				{
					dp[1][j] = dp[0][j - 1] + 1;
				}
				else {
					dp[1][j] = max(dp[0][j], dp[1][j - 1]);
				}
			}
			memcpy(dp, dp[1], sizeof(dp[1]));
		}
		cout << n - dp[1][n - 1] << endl;



	}

	return 0;
}