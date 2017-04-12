
#include<iostream>
#include<cmath>
using namespace std;
typedef struct
{
	double l, r;
}in;
int cmp(const void *a, const void *b)
{
	return (*(in *)a).l >= (*(in *)b).l ? 1 : -1;
}
int main()
{
	int n, d, i, x, y, sw, re, count = 1;
	double pre;
	in p[1000];
	while (1)
	{
		cin >> n >> d;
		if (n == 0 && d == 0) break;
		sw = 1;
		for (i = 0; i<n; i++)
		{
			cin >> x >> y;
			if (d >= y&&sw == 1)
			{
				p[i].l = x - sqrt((double)d*d - (double)y*y);
				p[i].r = x + sqrt((double)d*d - (double)y*y);
			}
			else
			{
				sw = 0;
			}
		}
		if (sw == 0)
		{
			cout << "Case " << count++ << ": " << -1 << endl;
			continue;
		}
		qsort(p, n, sizeof(in), cmp);
		re = 1;
		pre = p[0].r;
		for (i = 1; i<n; i++)
		{
			if (p[i].l>pre)
			{
				re++;
				pre = p[i].r;
			}
			else
			{
				if (p[i].r<pre)
				{
					pre = p[i].r;
				}
			}
		}
		cout << "Case " << count++ << ": " << re << endl;
	}
	return 0;
}