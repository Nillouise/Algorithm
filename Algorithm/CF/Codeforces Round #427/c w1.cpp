#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>//这个sqrt要用
#include<queue>
using namespace std;
typedef long long LL;
LL n, q, c;
struct star
{
	LL init;
	int x, y;

	bool operator <(star s2)const
	{
		return y < s2.y;
	}
};

LL getbright(star s, LL t)
{
	LL b = s.init + t;
	b %= c + 1;//光的亮度是0到c，所以c+1才是范围
	return b;
}
vector<star> v[200];
LL solve(int x1, int y1, int x2, int y2, LL t)
{
	LL cnt = 0;
	for (int i = x1; i <= x2; i++)
	{
		for (auto a : v[i])
		{
			if (a.y < y1)continue;
			if (a.y > y2)break;

			cnt += getbright(a, t);
		}
	}
	return cnt;
}





int main()
{
	ios::sync_with_stdio(false);

	cin >> n >> q >> c;

	for (size_t i = 0; i < n; i++)
	{
		star s;
		cin >> s.x >> s.y >> s.init;
		v[s.x].push_back(s);
	}
	for (int i = 0; i < 200; i++)
	{
		sort(v[i].begin(), v[i].end());
	}

	for (size_t i = 0; i < q; i++)
	{
		LL x1, y1, x2, y2, t;
		cin >> t >> x1 >> y1 >> x2 >> y2;
		cout << solve(x1, y1, x2, y2, t) << endl;
	}





	return 0;
}