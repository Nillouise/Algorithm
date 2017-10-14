#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int n, m, M;
int Tree[1048576 << 2], tree[1048576];


inline int gcd(int x, int y)
{
	x = x<0 ? -x : x;  y = y<0 ? -y : y;
	for (int r; y; r = x%y, x = y, y = r);
	return x;
}


int main()
{
	scanf("%d%d", &n, &m);
	for (M = 1; M <= n + 1; M <<= 1);
	while (m--)
	{
		int opt;
		scanf("%d", &opt);
		if (opt == 1)
		{
			int l, r, t;
			scanf("%d%d%d", &l, &r, &t);
			for (int x = l; x <= n; x += x&(-x))tree[x] += t;
			for (int x = r + 1; x <= n; x += x&(-x))tree[x] -= t;
			Tree[l += M] += t;
			for (int x = (l >> 1); x; x >>= 1)Tree[x] = gcd(Tree[x << 1], Tree[(x << 1) | 1]);
			Tree[r += M + 1] -= t;
			for (int x = (r >> 1); x; x >>= 1)Tree[x] = gcd(Tree[x << 1], Tree[(x << 1) | 1]);
		}
		else
		{
			int l, r;
			scanf("%d%d", &l, &r);
			int ret = 0, tmp = 0;
			for (int x = l + M, y = r + M + 1; x^y ^ 1; x >>= 1, y >>= 1)
			{
				if (!(x & 1))ret = gcd(ret, Tree[x ^ 1]);
				if (y & 1)ret = gcd(ret, Tree[y ^ 1]);
			}
			for (int x = l; x; x -= x&(-x))tmp += tree[x];
			ret = gcd(ret, tmp);
			printf("%d\n", ret);
		}
	}
}