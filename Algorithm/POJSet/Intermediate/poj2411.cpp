//Flogֱ�ߵȲ����ȵ���(array),�ҳ��ȹ�����һ��Flog·��
//Memory 172K Time: 47 Ms
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n, m;
//int dp[2][2048];//����������ܴ𰸺ܴ�Ҫ��long long
long long dp[2][2048];
int update(int cur, int a, int b)
{
	if (b&(1 << m))
	{
		dp[cur][b ^ (1 << m)] += dp[1 - cur][a];
	}
	return 0;
}



int main()
{
	//	freopen("input.txt", "r", stdin);

	while (cin >> n >> m&&n != 0 && m != 0)
	{
		if (n < m)swap(n, m);
		memset(dp, 0, sizeof(dp));
		//������Ϊ��0,0���������ʱ��ֻ�ܲ���Ϊ1������״̬����0�����״̬������
		dp[1][(1 << m) - 1] = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				memcpy(dp, dp[1], sizeof(dp[1]));
				memset(dp[1], 0, sizeof(dp[1]));
				for (int k = 0; k < (1 << m); k++)
				{
					update(1, k, k << 1);
					//�����i����Ϊ��һ�в�������
					if (i && !(k&(1 << (m - 1))))update(1, k, (k << 1) | (1 << m) | 1);
					//�����j����Ϊ��һ�в��ܺ��
					if (j && !(k & 1))update(1, k, (k << 1) ^ 3);
				}
			}
		}
		cout << dp[1][(1 << m) - 1] << endl;

	}


}