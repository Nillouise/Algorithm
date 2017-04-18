#include<algorithm>
#include<iostream>
#include<string>
#include<stack>
#include<set>
#include<functional>
#include<queue>
using namespace std;
int N;
int g[30][30];
//这代码是错的，而且表示集合，也不要用 vector这种笨重的东西，会不断复制元素
int dfs(int calindex, vector<int> a1, vector<int> b2, int ans)
{
	int reans = ans;
	for (size_t k = calindex; k < a1.size(); k++)
	{
		vector<int> a(a1); vector<int> b(b2);
		int newans = 0;
		for (size_t i = calindex; i < a.size(); i++)
		{
			for (size_t j = 0; j < b.size(); j++)
			{
				//				if(i!=calindex)//这样又忘记了变量的含义，calindex是静态变量，而k才是尝试的、不断改变的变量
				if (i != k)
					newans += g[a[i]][b[j]];
			}
		}
		for (size_t i = 0; i < a.size(); i++)
		{
			newans += g[a[k]][a[i]];//因为i到i的距离是0,所以可以这样忽略 a[k]
		}

		if (newans >= ans)
		{
			b.push_back(a[calindex]);
			a.erase(a.begin() + k);
			reans = max(max(dfs(k, a, b, newans), newans), reans);
		}
	}
	return reans;

}

int subset[25];
int n, G[25][25];
int ans;//这个是全局变量，记录最大的答案
		//这代码跟搜不定数量的元素加起来等于某个数那种搜索没什么不同，只不过要记录搜过那个位置，转换的时候要用到这些位置（subset）
void dfs2(int id, int sum)
{
	int co = sum;
	subset[id] = 1;
	for (int i = 0; i < n; i++)
		if (subset[i])
			sum -= G[id][i];
		else
			sum += G[id][i];
	if (sum > ans)
		ans = sum;
	if (sum < co)return;//这里可以剪枝，因为把这个id元素拿到另一组，变小就不可能是最优解
	for (int i = id + 1; i < n; i++)
	{
		dfs2(i, sum);
		subset[i] = 0;
	}
}
int main()
{
	freopen("input.txt", "r", stdin);

	cin >> N;
	n == N;
	memset(g, 0, sizeof(N));
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			cin >> g[i][j];
			G[i][j] == g[i][j];
		}
	}
	vector<int> a;
	for (size_t i = 0; i < N; i++)
	{
		a.push_back(i);
	}
	cout << dfs(0, a, vector<int>(), 0) << endl;

	return 0;
}