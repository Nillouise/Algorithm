//̰�Ĵ���
//������С��һֱ�鲢�����ģ��ͻᷢ�֣�������С�ķŻ�ԭ��λ�ø�ʡǮ��
//ԭ����ģ�һ������Ҫô��Ҫô��������ȷ�ģ��������ʱ��ԭ�����˵�������ԷŻ�ԭ�����˵�λ��
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
			if (dp[i] != 0)//0ʱ���Ͳ��ö�����10���ˣ�0��1�ܲ�ͬ��
				sum += (dp[i] + 10)* P[i];
		}
		cout << sum << endl;

	}


	return 0;
}