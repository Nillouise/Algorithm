#include <iostream>
#include <cstdio>
#include <cstring>
#include<string>
#include <algorithm>
#include<sstream>
#include<cmath>
#include<vector>
using namespace std;
int N, P;
const int INF = 0x0fff;
const int maxn = 155;
vector<int> tree[maxn];

int dp[maxn][maxn];
//���num�Ǵ������ƣ���Ϊһ��������ֻ�����һ��
//int DP(int x, int num)
//{
//	if (dp[x][num] != INF)return dp[x][num];
//	
//	vector<int> &sub = tree[x];
//	dp[x][1] = sub.size();
//	dp[x][0] = INF;
//	int temp[150];
//	memcpy(temp, dp[x], sizeof(dp[x]));
//	for (int i = 0; i < sub.size(); i++)
//	{
//		int tt[150];
//		for (int j = 0; j <= num; j++)
//		{
//			tt[j] = temp[j] + 1;
//		}
//		//����ֻҪ����������ѭ����j�������Ľ����ľ���Ͳ���Ҫtt������ת�ˡ�
//		//for (int j = 0; j <= num; j++)
//		//{
//		//	for (int k = 0; k+j <= num; k++)
//		//	{
//		//		tt[j + k] = min(tt[j + k], temp[j] + DP(sub[i], k) );
//		//	}
//		//}
//		memcpy(temp, tt, sizeof(tt));
//	}
//	memcpy(dp[x], temp, sizeof(temp));
//	return dp[x][num];
//}

int DP(int x)
{
	fill(dp[x], dp[x] + maxn, INF);
	vector<int> &sub = tree[x];
	dp[x][1] = 0;//���Ǽ���x������Ҷ�ӣ�û���ӽڵ�ʱ��ֻ��Ҫ��0����(����״̬��Ȼ��INF�ˣ�


	for (size_t i = 0; i < sub.size(); i++)
	{
		DP(sub[i]);
	}

	for (int i = 0; i < sub.size(); i++)
	{
		for (int j = P; j >= 0; j--)//�Ӻ����������������޸ĺ��ֱ�ʹ����
		{
			int temp = dp[x][j] + 1;//���ǲ�Ҫ��ǰ��������Ҫ��һ���ߡ�
			for (int k = 0; j - k >= 0; k++)
			{
				//�����ڿ���Ҫ��ǰ������ĳ����Ŀ
				temp = min(temp, dp[x][j - k] + dp[sub[i]][k]);
			}
			dp[x][j] = temp;
		}

	}
	return 0;
}

int fa[maxn];
int solve()
{

	int root = 0;
	for (;;)
	{
		if (fa[root] != -1)
		{
			root = fa[root];
		}
		else {
			break;
		}
	}
	DP(root);
	int MIN = INF;
	for (size_t i = 0; i < N; i++)
	{
		MIN = min(MIN, dp[i][P] + (i != root ? 1 : 0));
	}
	return MIN;

}

int main() {
	freopen("input.txt", "r", stdin);

	while (cin >> N >> P&&N != 0 && P != 0)
	{
		for (size_t i = 0; i < maxn; i++)
		{
			tree[i].clear();
		}
		memset(fa, -1, sizeof(fa));
		//����ֻ��N-1�У���������Ҫ��
		for (size_t i = 0; i < N - 1; i++)
		{
			int I, J;
			cin >> I >> J;
			I--; J--;
			tree[I].push_back(J);
			fa[J] = I;
		}
		cout << solve() << endl;
	}
	return 0;
}