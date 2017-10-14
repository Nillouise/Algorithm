//二分图有两个定理：最小覆盖数 = 最大匹配数、最大独立集 = 总数 - 最小覆盖集 。
//
//几个基本定义：
//最小覆盖：即在所有顶点中选择最少的顶点来覆盖所有的边。
//最大匹配：二分图左右两个点集中，选择有边相连的两个匹配成一对（每个点只能匹配一次），所能达到的最大匹配数。
//最大独立集：集合中的任何两个点都不直接相连。

#include<algorithm>
#include<iostream>
#include<cstring>
#include<stack>
#include<fstream>
#include<queue>
#include<vector>
using namespace std;
int n, k;
const int maxstate = 1000;
int chess[maxstate][maxstate];
int vis[maxstate];
int match[maxstate];
int dfs(int x)//匈牙利算法
{
	for (size_t i = 0; i < n; i++)
	{
		if (chess[x][i] == 1)
		{
			if (vis[i] == 1)continue;
			vis[i] = 1;//vis在这里修改，表示确确实实尝试了在i这里插入点了，成没成功是另一回事。
			if (match[i] == -1 || dfs(match[i]))
			{
				match[i] = x;
				//				vis[i] = 1;//vis 不应该在这里修改的，不然dfs就会无限递归 i了；
				return 1;
			}
		}
	}
	return 0;
}

int solve()
{
	int all = 0;
	for (size_t i = 0; i < n; i++)
	{
		memset(vis, 0, sizeof(vis));
		all += dfs(i) == 1 ? 1 : 0;
	}
	return all;
}

int main()
{
	cin >> n >> k;
	memset(chess, 0, sizeof(chess));
	memset(vis, 0, sizeof(vis));
	memset(match, -1, sizeof(match));
	for (size_t i = 0; i < k; i++)
	{
		int R, C;
		cin >> R >> C; R--; C--;
		chess[R][C] = 1;
	}
	cout << solve() << endl;

	return 0;

}