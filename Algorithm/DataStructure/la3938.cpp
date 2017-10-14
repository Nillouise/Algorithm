#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef pair<int, int> interval;
const int maxn = 100000;
typedef long long LL;
int gL, gR;
LL prefix_sum[maxn];
LL sum(int L, int R)
{
	return prefix_sum[R] - prefix_sum[L - 1];
}

LL sum(interval a)
{
	return sum(a.first, a.second);
}

interval better(interval a1, interval a2)
{
	if (sum(a1) > sum(a2))return a1;
	else if (sum(a1) < sum(a2))return a2;
	else return a1 < a2 ? a1 : a2;
}

struct Btree
{
	interval maxsub[maxn];
	int prefix[maxn];
	int suffix[maxn];

	void build(int o, int L, int R)
	{
		int lc = o * 2, rc = o * 2 + 1;
		int M = L + (R - L) / 2;

		if (L == R)
		{
			maxsub[o] = make_pair(L, R);
			prefix[o] = L;
			suffix[o] = L;
		}
		else {
			build(lc, L, M);
			build(rc, M + 1, R);

			LL v1 = sum(L, prefix[lc]);
			LL v2 = sum(L, prefix[rc]);
			if (v1 == v2)
			{
				prefix[o] = prefix[lc];
			}
			else {
				prefix[o] = v1 > v2 ? prefix[lc] : prefix[rc];
			}

			v1 = sum(suffix[lc], R);
			v2 = sum(suffix[rc], R);
			if (v1 == v2)
			{
				suffix[o] = suffix[lc];
			}
			else {
				suffix[o] = v1 > v2 ? suffix[lc] : suffix[rc];
			}

			maxsub[o] = better(maxsub[lc], maxsub[rc]);// 完全在左子树或者右子树
			maxsub[o] = better(maxsub[o], make_pair(suffix[lc], prefix[rc]));// 跨越中线

		}

	}

	int queryPre(int o, int L, int R)
	{
		if (prefix[o] <= gR)return prefix[o];
		int M = L + (R - L) / 2;
		int lc = o * 2, rc = o * 2 + 1;
		if (gR <= M)return queryPre(lc, L, M);
		int maxl = queryPre(lc, L, M);
		int maxr = queryPre(rc, M + 1, R);

		return better(make_pair(L, maxl), make_pair(L, maxr)).second;
	}

	int querySuf(int o, int L, int R)
	{
		if (suffix[o] >= gL)return suffix[o];
		int rc = o * 2 + 1, lc = 0 * 2;
		int M = L + (R - L) / 2;
		if (gL > M)return querySuf(rc, M + 1, R);
		int maxl = querySuf(lc, L, M);
		int maxr = querySuf(rc, M + 1, R);

		return better(make_pair(maxl, R), make_pair(maxr, R)).first;
	}

	interval query(int o, int L, int R)
	{
		if (gL <= L&&gR >= R)
			return maxsub[o];
		int lc = o * 2, rc = o * 2 + 1;
		int M = L + (R - L) / 2;
		if (gR <= M)return query(lc, L, M);
		if (gL > M)return query(rc, M + 1, R);

		interval i1 = query(lc, L, M);
		interval i2 = query(rc, M + 1, R);
		interval i3;
		i3.first = querySuf(lc, L, M);
		i3.second = queryPre(rc, M + 1, R);

		interval r = better(i1, i2);
		r = better(r, i3);
		return r;
	}

};

Btree tree;

int main() {
	freopen("input.txt", "r", stdin);

	int n, q;
	for (int kase = 1;; kase++)
	{
		if (scanf("%d%d", &n, &q) != 2)break;
		prefix_sum[0] = 0;
		for (int i = 0; i < n; i++)
		{
			int c; scanf("%d", &c);
			prefix_sum[i + 1] = prefix_sum[i] + c;
		}
		tree.build(1, 1, n);
		printf("Case %d:\n", kase);
		while (q--)
		{
			scanf("%d%d", &gL, &gR);
			interval ans = tree.query(1, 1, n);
			printf("%d %d\n", ans.first, ans.second);
		}

	}

	return 0;
}
