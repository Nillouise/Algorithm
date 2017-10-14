#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxstate = 100;
int u[maxstate], v[maxstate], w[maxstate];
int r[maxstate];
int father[maxstate];
int cmp(int i, int j) {
	return w[i] < w[j];
}
bool findRoot(int x)
{
	return father[x] == x ? x : findRoot(father[x]);
}

int Krushal(int n)//n是讲有几条边，这个算法应该不用知道有几个点——信息已经全部包含在边里了
{
	for (int i = 0; i < n; i++)r[i] = i;
	for (int i = 0; i < n; i++)father[i] = i;
	sort(r, r + n, cmp);
	vector<int> MinEdgesSet;
	for (size_t i = 0; i < n; i++)
	{
		int curEdge = r[i];
		int x1 = findRoot(u[curEdge]);
		int x2 = findRoot(v[curEdge]);
		if (x1 != x2)
		{
			MinEdgesSet.push_back(curEdge);
			father[x2] = father[x1];
		}
	}
	return 0;
}

int main()
{
	int n;
	n = 4;
	w[0] = 3; w[1] = 2; w[2] = 1; w[3] = 4;
	r[0] = 0; r[1] = 1; r[2] = 2; r[3] = 3;

	sort(r, r + n, cmp);
	r;
	return 0;
}