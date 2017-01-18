#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
using namespace std;
int n;
const int maxn = 20;
const int maxm = 100;
int dist[1 << maxn];
int mark[1 << maxn];
int m;
char before[maxm][20], after[maxm][20],t[maxm];
const int INF = 1 << 30;
struct Node
{
	int dist, state;
	bool operator <(const Node t )const {
		return dist < t.dist;
	}
};

int solve()
{
	priority_queue<Node> pq;
	pq.push(Node{ 0,(1 << n) - 1});
	dist[1 << n] = 0;
	for (size_t i = 0; i < 1<<maxn; i++)dist[i] = INF;
	memset(mark, 0, sizeof(mark));

	while (!pq.empty())
	{
		Node current = pq.top(); pq.pop();
		if (current.state == 0)return current.dist;
		if (mark[current.state] == 1)continue;
		mark[current.state] = 1;


		for (size_t p = 0; p < m; p++)
		{
			bool patch = true;
			for (size_t i = 0; i < m; i++)
				if (before[p][i] == '+' && !current.state&(1 << i)) {
					patch = false;
					break;
				}
			for (size_t i = 0; i < m; i++)
				if (before[p][i] == '-'&&current.state&(1 << i)) {
					patch = false;
					break;
			}
			if (!patch)continue;

			Node nextnode;
			nextnode.dist = current.dist; nextnode.state = current.state;

			nextnode.dist += t[p];
			for (size_t i = 0; i < m; i++)
				if (after[p][i] == '-')nextnode.state &= ~(1 << i);
			for (size_t i = 0; i < m; i++)
				if (after[p][i] == '+') nextnode.state |= (1 << i);
			if (nextnode.dist < current.dist)
			{
				dist[nextnode.state] = nextnode.dist;
				pq.push(nextnode);
			}
		}
	}
	return -1;

}


int main()
{
	int kase = 0;
	while (scanf("%d%d", &n, &m) == 2 && n) {
		for (int i = 0; i < m; i++) scanf("%d%s%s", &t[i], before[i], after[i]);
		int ans = solve();
		printf("Product %d\n", ++kase);
		if (ans < 0) printf("Bugs cannot be fixed.\n\n");
		else printf("Fastest sequence takes %d seconds.\n\n", ans);
	}
	return 0;
}