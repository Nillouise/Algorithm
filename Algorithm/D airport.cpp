#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;
typedef long long LL;
const int maxn = 1e6 + 5;

int first;
int last;
int n, m, k;
int minc[100000 + 5];
struct F
{
	int d;
	int f;
	int t;
	int c;

	bool operator <(F f1) const
	{
		return d < f1.d;
	}
};
F col[maxn];

LL tom[maxn];
LL back[maxn];



int main()
{

	ios::sync_with_stdio(false);
	cin >> n >> m >> k;

	for (size_t i = 0; i < m; i++)//这里收取信息时，把去的飞机和回来的飞机分成两个数组会比较好。
	{
		F f;
		cin >> f.d >> f.f >> f.t >> f.c;
		col[i] = f;
	}
	sort(col, col + m);

	map<int, int> s;
	LL total = 0;
	for (size_t i = 0; i < m; i++)
	{
		if (col[i].t != 0)continue;

		if (s[col[i].f] == 0)
		{
			s[col[i].f] = col[i].c;
			total += col[i].c;
		}
		else {
			if (s[col[i].f] > col[i].c)
			{
				total -= s[col[i].f] - col[i].c;
				s[col[i].f] = col[i].c;
			}
		}
		if (s.size() >= n)
		{
			tom[col[i].d] = total;
		}
	}
	if (s.size() < n)
	{
		cout << -1 << endl;
		return 0;
	}
	s.clear();
	total = 0;
	for (int i = m - 1; i >= 0; i--)
	{
		if (col[i].f != 0)continue;
		if (s[col[i].t] == 0)
		{
			s[col[i].t] = col[i].c;
			total += col[i].c;
		}
		else {
			if (s[col[i].t] > col[i].c)
			{
				total -= s[col[i].t] - col[i].c;
				s[col[i].t] = col[i].c;
			}
		}
		if (s.size() >= n)
		{
			back[col[i].d] = total;
		}

	}
	if (s.size() < n)
	{
		cout << -1 << endl;
		return 0;
	}

	//延展
	for (int i = 1; i < maxn - k - 1; i++)
	{
		if (tom[i] == 0)
		{
			tom[i] = tom[i - 1];
		}
	}
	for (int i = maxn - k - 1 - 1; i >= 0; i--)
	{
		if (back[i] == 0)
		{
			back[i] = back[i + 1];
		}
	}


	LL MIN = 1e17;
	for (int i = 1; i < maxn - k - 1; i++)
	{
		if (tom[i] > 0 && back[i + k + 1])
		{
			if (MIN > tom[i] + back[i + k + 1])
				MIN = tom[i] + back[i + k + 1];
		}
	}
	if (MIN != 1e17)
	{
		cout << MIN << endl;
	}
	else {
		cout << -1 << endl;
	}


	return 0;
}