


#include<iostream>
#include<fstream>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define LOCAL
int n;
int A[100000 + 5];
int leijia[100000 + 5];
int findV(int L, int R, int v)
{
	int gap = leijia[R - 1] - (L == 0 ? 0 : leijia[L - 1]);
	int v2 = gap - v;
	if (v2 == 0)return 1;
	if (v2 < 0)return 0;

	for (size_t i = L + 1; i < R; i++)
	{
		int t = v2 + (i == 0 ? 0 : leijia[i - 1]);
		int pos = lower_bound(leijia + i, leijia + R, t) - leijia;
		if (pos == R)return 0;
		if (leijia[pos] == t)return 1;

		for (size_t j = pos + 1; j <= R; j++)
		{
			if (findV(i, j, v2) == 1)
				return 1;
		}
	}
	v2 -= A[L];
	if (v2 == 0)return 1;
	if (v2 < 0)return 0;
	for (size_t i = L + 1; i < R; i++)
	{
		int t = v2 + (i == 0 ? 0 : leijia[i - 1]);
		int pos = lower_bound(leijia + i, leijia + R, t) - leijia;
		if (pos == R)return 0;
		if (leijia[pos] == t)return 1;

		for (size_t j = pos + 1; j <= R; j++)
		{
			if (findV(i, j, v2) == 1)
				return 1;
		}
	}


	return 0;
}


int main(void)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (size_t i = 0; i < n; i++)
		{
			scanf("%d", &A[i]);
		}
		sort(A, A + n);
		leijia[0] = A[0];
		for (size_t i = 1; i < n; i++)
		{
			leijia[i] = leijia[i - 1] + A[i];
		}
		long long i;
		for (i = 1; ; i++)
		{
			if (findV(0, n, i) == 0)
				break;
		}
		cout << i - 1 << endl;
	}


	return 0;
}