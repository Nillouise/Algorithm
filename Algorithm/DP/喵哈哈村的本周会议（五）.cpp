#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
const int maxn = 200;
int n, k;
int A[maxn][maxn];
int B[maxn][maxn];
int C[maxn][maxn];
int dp[maxn][maxn][5000];
int main() {
	freopen("input.txt", "r", stdin);

	while (cin >> n >> k)
	{
		for (size_t i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				cin >> A[i][j];
			}
		}
		for (size_t i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				B[i][j] = A[n - 1 - j][i - j];
			}
		}

		C[0][0] = B[0][0];
		for (size_t i = 1; i < n; i++)
		{
			C[i][0] = B[i][0];
			int temp = B[i][0];
			for (size_t j = 1; j <= i; j++)
			{
				C[i][j] = B[i][j] + C[i - 1][j - 1] + temp;
				temp += B[i][j];
			}
		}
		//		memset(dp, -1, sizeof(dp));
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j >= 0; j--)
			{
				//				for (int k = (i+1+1)*(i*1)/2; k >= (j + 1 + 1)*(j * 1) / 2; k--)
				for (int k = (i + 1 + 1)*(i + 1) / 2; k >= (j + 1 + 1)*(j + 1) / 2; k--)
				{
					//这里忘记考虑 i=0时不能-1
					//dp[i][j][k] = max(dp[i][j + 1][k], dp[i - 1][j - 1][k - j - 1] - C[i - 1][j - 1] + C[i][j]);
					if ((!i || !j))
					{
						int ii = (i - 1) < 0 ? 0 : i - 1; int jj = (j - 1) < 0 ? 0 : j - 1;
						dp[i][j][k] = max(dp[i][j + 1][k], dp[ii][jj][k - j - 1] - C[ii][jj] + C[i][j]);
					}
					else {
						dp[i][j][k] = max(dp[i][j + 1][k], dp[i - 1][j - 1][k - j - 1] - C[i - 1][j - 1] + C[i][j]);
					}

				}
			}
		}
		cout << dp[n - 1][0][k] << endl;
	}

}