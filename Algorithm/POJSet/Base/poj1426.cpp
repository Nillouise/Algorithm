//这么做应该是最符合题目思路了，主要同余模定理，就是  11% m  == 10%m +1%m
//这题不是我做的，我没想到同余模定理，怎么做都是错的
//1426 Find The Multiple
#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
using namespace std;

//ifstream fin("input.in");
//#define cin fin

int n;
int vis[220];

int getmod(string &str, int m)
{
	int len = str.length();
	int ans = 0;
	for (int i = 0; i<len; i++)
		ans = (ans * 10 + str[i] - '0') % m;
	return ans;
}

void bfs()
{
	memset(vis, 0, sizeof(vis));
	if (n == 1) { printf("1\n"); return; }
	queue<string> q;
	string u = "1";
	q.push(u);
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		string v;
		int m;
		v = u + "0";
		m = getmod(v, n);
		if (!m)
		{
			cout << v << "\n";
			return;
		}
		if (!vis[m])
		{
			vis[m] = 1;
			q.push(v);
		}
		v = u + "1";
		m = getmod(v, n);
		if (!m)
		{
			cout << v << "\n";
			return;
		}
		if (!vis[m])//这里的作用只是剪枝
		{
			vis[m] = 1;
			q.push(v);
		}
	}
}

int main()
{
	//freopen("input.in","r",stdin);
	while (~scanf("%d", &n))
	{
		if (n == 0) break;
		bfs();
	}
	return 0;
}