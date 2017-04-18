#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<stack>
#include<set>
#include<functional>
#include<queue>
using namespace std;
const int maxn = 1000;
int C, G;
int hook[30];
int gram[30];
int d[30][15000];

int dfs(int g, int balance)
{
	if (g >= G)return 0;
	if (d[g][balance] != -1)return d[g][balance];
	int r = 0;
	for (size_t i = 0; i < C; i++)
	{
		//		r += dfs(g + 1, balance + hook[i] * gram[g]);//����������ʵ�����ǲ�����
		r += dfs(g + 1, balance - hook[i] * gram[g]);
	}
	d[g][balance] = r;
	return d[g][balance];
}


int main()
{

	freopen("input.txt", "r", stdin);
	while (cin >> C >> G&&C != 0 && G != 0)
	{
		for (size_t i = 0; i < C; i++)
			cin >> hook[i];
		for (int i = 0; i < G; i++)
			cin >> gram[i];
		memset(d, -1, sizeof(d));
		//���Ǳ߽�û�ж���
		for (size_t i = 0; i < C; i++)
		{
			d[G - 1][7500 + hook[i] * gram[G - 1]] = 1;
		}
		cout << dfs(0, 7500) << endl;
	}


	return 0;
}

//���Ǳ������ģ�˼·�ܺ�
int dp[30][15000];
int main()
{

	freopen("input.txt", "r", stdin);
	while (cin >> C >> G&&C != 0 && G != 0)
	{
		int hook[30];
		int gram[30];

		for (size_t i = 0; i < C; i++)
			cin >> hook[i];
		for (int i = 1; i <= G; i++)//���ﲻ��gram[0]����Ϊdp�������0��ʾû�ж���
			cin >> gram[i];
		memset(dp, 0, sizeof(dp));

		dp[0][7500] = 1;//0�����Ŷ������Ǿ�ȷʵ��ƽ��ģ�ƽ�����7500����Ϊ���и���

		for (size_t i = 1; i <= G; i++)
		{
			for (size_t j = 0; j < 15000; j++)
			{
				for (size_t k = 0; k < C; k++)
				{
					dp[i][j] += dp[i - 1][j - gram[i] * hook[k]];//�����и��õķ����������Ż��� k
				}
			}
		}


		cout << dp[G][7500] << endl;
	}


	return 0;
}