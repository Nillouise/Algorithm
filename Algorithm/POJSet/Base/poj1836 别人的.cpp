#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const double INF = 10000000;

double H[1005];
int n;

int max(int a, int b) {
	return a>b ? a : b;
}

int LIS(int a, int b) {
	double dp[1005];
	fill(dp, dp + n, INF);
	int ans = 0;
	if (a<b) {
		for (int i = a; i <= b; i++)
			*lower_bound(dp, dp + n, H[i]) = H[i];
		ans = lower_bound(dp, dp + n, INF) - dp;
	}
	else {
		for (int i = a; i >= b; i--)
			*lower_bound(dp, dp + n, H[i]) = H[i];
		ans = lower_bound(dp, dp + n, INF) - dp;
	}

	return ans;
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	memset(H, 0, sizeof(H));
	for (int i = 0; i<n; i++)
		scanf("%lf", &H[i]);

	//cout<<LIS(7,1)<<endl;
	int ans = 0;
	for (int i = 0; i<n; i++) {
		int res = 0;
		res = LIS(0, i) + LIS(n - 1, i) - 1;
		int res2 = 0;
		//int k = i + 1;
		//while (k <n && H[i] != H[k++]);
		//if (k != n)
		//	res2 = LIS(0, i) + LIS(n - 1, k - 1);
		res = max(res, res2);
		ans = max(ans, res);
	}

	printf("%d\n", n - ans);
	return 0;
}