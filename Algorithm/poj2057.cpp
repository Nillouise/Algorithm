//每个节点的叶子数并不是这个节点的子节点数目，我没有搞清楚这个概念
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N;
const int maxn = 1005;
vector<int> tree[maxn];
int worm[maxn];
int leaf[maxn];
double success[maxn];
double failure[maxn];
//comp两个子节点，就可以确定这两个子节点的相对顺序了（与其他无数个子节点是什么样的没有关系)
bool comp(int a, int b)
{
	double afirst = 0;
	double bfirst = 0;
	double total = leaf[a] + leaf[b];
	//这是错的，要是a子树没有奖励，可能根本就不需要走success[a]步
	//之前我以为a子树的成功期待步数不能乘以成功概率，这思路的问题在于我没能完全明白a子树成功（我以为成功的步数包含了一些在失败哪里）和失败的区别。
	//afirst +=1+ success[a] + leaf[b] / total*(failure[a] + 1 + 1 + success[b]);//失败之后回到原点 再到b探索需要+1+1;
	//bfirst +=1+ success[b] + leaf[a] / total*(failure[b] + 1 + 1 + success[a]);
	afirst += (leaf[a] / total)*(1 + success[a]) + leaf[b] / total*(failure[a] + 1 + 1 + 1 + success[b]);//失败之后回到原点 再到b探索需要+1+1;//这是理解错误
																										 //成功和失败是两种完全不同的状态，完全可以根据两者不同的步数乘以各自的概率，
																										 //所以失败那里是+1+1+1；进 出 再进另一个
	bfirst += (leaf[b] / total)*(1 + success[b]) + leaf[a] / total*(failure[b] + 1 + 1 + 1 + success[a]);


	return afirst < bfirst;
}

double DP(int d, int state)
{
	if (state == 0)
	{
		if (worm[d] == 1)
			return failure[d] = 0;
		if (failure[d] >= 0)return failure[d];
		if (tree[d].size() == 0)return failure[d] = 0;
		double sum = 0;
		for (size_t i = 0; i < tree[d].size(); i++)
		{
			sum += DP(tree[d][i], 0) + 2;
		}
		return failure[d] = sum;
	}
	else {
		if (success[d] >= 0)return success[d];
		if (tree[d].size() == 0)return success[d] = 0;
		//		for (size_t i = 0; i < tree[i].size(); i++)
		for (size_t i = 0; i < tree[d].size(); i++)
		{
			DP(tree[d][i], 0);
			DP(tree[d][i], 1);
		}
		sort(tree[d].begin(), tree[d].end(), comp);
		//		double sum =  leaf[d]/total * (success[tree[d][0]]+1);
		//		double cur = total - leaf[tree[d][0]];
		//		for (size_t i = 1; i < tree[d].size(); i++)
		//		{
		//			int num = tree[d][i];
		//			int pre = tree[d][i - 1];
		////			sum += cur / total *(failure[pre]+1+1 + success[num]);
		//			
		//			cur -= leaf[num];
		//		}
		double sum = success[tree[d][tree[d].size() - 1]] + 1;
		double total = leaf[tree[d][tree[d].size() - 1]];

		//		for (int i = tree[d].size()-1-1; i >0;i--)
		for (int i = tree[d].size() - 1 - 1; i >= 0; i--)
		{
			int num = tree[d][i];
			double cur = total + leaf[num];
			sum = leaf[num] / cur*(success[num] + 1) + total / cur*(1 + failure[num] + 1 + sum);
			total = cur;
		}

		return success[d] = sum;
	}
}
//这里不能正确处理一个叶子有两个父节点的那种树
int dfs(int x)
{
	if (leaf[x] >= 0)return leaf[x];
	int sum = 0;
	for (size_t i = 0; i < tree[x].size(); i++)
	{
		sum += dfs(tree[x][i]);
	}
	return leaf[x] = (tree[x].size() == 0 ? 1 : sum);
}


double solve()
{
	fill(success, success + maxn, -1.0);
	fill(failure, failure + maxn, -1.0);
	memset(leaf, -1, sizeof(leaf));

	for (size_t i = 0; i < N; i++)
	{
		dfs(i);
	}

	return DP(0, 1);


}

int main()
{
	freopen("input.txt", "r", stdin);
	while (cin >> N&&N != 0)
	{
		memset(worm, 0, sizeof(worm));
		for (size_t i = 0; i < maxn; i++)
		{
			tree[i].clear();
		}
		for (size_t i = 0; i < N; i++)
		{
			int f;
			char w;
			cin >> f >> w;
			if (f != -1)
			{
				f--;
				tree[f].push_back(i);
			}
			worm[i] = (w == 'Y' ? 1 : 0);
		}
		printf("%0.4f\n", solve());
	}

}