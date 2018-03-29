//坑点：涉及相乘，可能会爆掉int

#include<iostream>
using namespace std;
typedef long long LL;
LL get(LL len, LL ran)
{
	return (len - 1) / ran + 1;
}
int flag = 0;
LL sq(LL k, LL r, LL c)
{
	if (r == 0 || c == 0)return 0;
	if (k>r || k>c)flag = 1;
	return get(r, k)*get(c, k);
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		LL m, n, r, c, k;
		cin >> m >> n >> r >> c >> k;
		flag = 0;
		LL cnt = 0;
		cnt += sq(k, r - 1, c - 1);
		cnt += sq(k, m - r, c - 1);
		cnt += sq(k, r - 1, n - c);
		cnt += sq(k, m - r, n - c);
		if (flag == 1)cout << "-1" << endl;
		else
			cout << cnt << endl;
	}
}
