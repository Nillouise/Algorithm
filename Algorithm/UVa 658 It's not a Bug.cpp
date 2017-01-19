#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n;
const int maxn = 20;
const int maxm = 100 + 5;
int dist[1 << maxn];
int mark[1 << maxn];
int m;
char before[maxm][maxn + 5], after[maxm][maxn + 5];
int t[maxm];
const int INF = 1000000000;
struct Node
{
	int dist, state;
	bool operator <(const Node t)const {
		return dist > t.dist;
	}
};

int solve()
{
	for (size_t i = 0; i < (1 << n); i++)
	{
		dist[i] = INF;
		mark[i] = 0;
	}
	priority_queue<Node> pq;
	Node start;

	start.dist = 0;
	start.state = (1 << n) - 1;
	pq.push(Node{ 0,(1 << n) - 1 });
	dist[start.state] = 0;

	while (!pq.empty())
	{
		Node current = pq.top(); pq.pop();
		if (current.state == 0)return current.dist;
		if (mark[current.state] == 1)continue;
		mark[current.state] = 1;

		for (size_t p = 0; p < m; p++)
		{
			bool patch = true;
			for (size_t i = 0; i < n; i++)
			{
				if (before[p][i] == '+' && !(current.state&(1 << i))) {
					patch = false;
					break;
				}
				if (before[p][i] == '-' && (current.state&(1 << i))) {
					patch = false;
					break;
				}
			}
			if (!patch)continue;

			Node nextnode;
			nextnode.dist = current.dist; nextnode.state = current.state;

			nextnode.dist += t[p];
			for (size_t i = 0; i < n; i++)
			{
				if (after[p][i] == '-')nextnode.state &= ~(1 << i);
				if (after[p][i] == '+') nextnode.state |= (1 << i);
			}
			if (dist[nextnode.state]< 0 || nextnode.dist < dist[nextnode.state])
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