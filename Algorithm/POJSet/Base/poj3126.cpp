#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<stack>
#include<set>
#include<functional>
#include<map>
#include<queue>
using namespace std;
const int maxn = 10000 + 10;//这里一定要贴近到10000，不然会加入奇怪、5位数的质数，导致错误（因为vis数组只开了10000，导致runtime error
const int INF = 10000000;
int p1[maxn];
int p2[maxn];
int pcnt = 0;
int prime1()
{
	for (size_t i = 2; i < maxn; i++)
	{
		if (p1[i] == 0)
			for (size_t j = i * 2; j < maxn; j += i)
			{
				p1[j] = 1;
			}
	}
	return 0;
}

int prime2()
{

	for (size_t i = 2; i < maxn; i++)
	{
		if (i>999)//之前没加这句，导致错误，因为那些4位数可能会匹配掉三位数的
			if (p1[i] == 0)p2[pcnt++] = i;
	}
	return 0;
}
int comp(int a, int b)
{
	int cnt = 0;
	while (a)
	{
		if (a % 10 != b % 10)
		{
			cnt++;
		}
		a /= 10;
		b /= 10;
	}

	return cnt == 1 ? 1 : 0;
}
int vis[10000];
int bfs(int start, int end)
{
	queue<int> q;
	memset(vis, -1, sizeof(vis));
	vis[start] = 1;
	q.push(start);
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (size_t i = 0; i < pcnt; i++)
		{
			if (vis[p2[i]] == -1)
				if (comp(cur, p2[i]))
				{
					vis[p2[i]] = vis[cur] + 1;
					q.push(p2[i]);
					if (p2[i] == end)return vis[p2[i]];
				}
		}
	}
	return vis[end];
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	prime1();
	prime2();

	while (T--)
	{
		int start, end;
		cin >> start >> end;
		cout << bfs(start, end) - 1 << endl;

	}

	return 0;
}