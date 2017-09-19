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
//这个num是错误的设计，因为一颗子树你只会访问一次
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
//		//这里只要用总数做大循环，j做子树的结点数木，就不需要tt来做中转了。
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
	dp[x][1] = 0;//这是假设x子树是叶子，没有子节点时，只需要剪0条边(其他状态当然是INF了）


	for (size_t i = 0; i < sub.size(); i++)
	{
		DP(sub[i]);
	}

	for (int i = 0; i < sub.size(); i++)
	{
		for (int j = P; j >= 0; j--)//从后面退起避免变量被修改后又被使用了
		{
			int temp = dp[x][j] + 1;//这是不要当前子树，需要剪一条边。
			for (int k = 0; j - k >= 0; k++)
			{
				//这是在考虑要当前子树的某个数目
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
		//这里只有N-1行，看清输入要求
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