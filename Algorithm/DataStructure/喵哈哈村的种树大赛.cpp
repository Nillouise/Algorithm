#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int n, m, M;

int gcd(int a, int b)
{
	if (b == 0)return abs(a);
	return abs(gcd(b, a%b));
}

int p, v;
int gL, gR;
struct Interval
{
	int Tree[1048576 << 2], tree[1048576];

	Interval()
	{
		memset(Tree, 0, sizeof(Tree));
		memset(tree, 0, sizeof(tree));
	}

	void update(int o, int L, int R)
	{
		if (L == R) {
			Tree[o] += v;
		}
		else {
			int M = L + (R - L) / 2;

			if (p <= M)update(o * 2, L, M);
			else update(o * 2 + 1, M + 1, R);

			Tree[o] = gcd(Tree[o * 2], Tree[o * 2 + 1]);
		}
	}

	int query(int o, int L, int R)
	{
		if (gL <= L&&gR >= R)return Tree[o];
		int M = L + (R - L) / 2;
		int res = 0;
		if (gL <= M)res = gcd(res, query(o * 2, L, M));
		if (gR>M)res = gcd(res, query(o * 2 + 1, M + 1, R));
		return res;
	}

	void treeadd(int pos, int addv)
	{
		while (pos <= n)
		{
			tree[pos] += addv;
			pos += pos&(-pos);
		}
	}

	int treesum(int pos)
	{
		int sum = 0;
		while (pos>0)
		{
			sum += tree[pos];
			pos -= pos&(-pos);
		}
		return sum;
	}
};

Interval interval;
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 0; i<m; i++)
	{
		int ques;
		scanf("%d", &ques);
		if (ques == 1)
		{
			int addv;
			scanf("%d%d%d", &gL, &gR, &addv);
			v = addv;
			p = gL;
			interval.update(1, 1, n);
			p = gR + 1;
			v = -addv;
			interval.update(1, 1, n);
			interval.treeadd(gL, addv);
			interval.treeadd(gR + 1, -addv);
		}
		else
		{
			scanf("%d%d", &gL, &gR);
			gL++;
			int ans = interval.query(1, 1, n);
			ans = gcd(ans, interval.treesum(gL - 1));
			printf("%d\n", ans);
		}
	}
	return 0;
}