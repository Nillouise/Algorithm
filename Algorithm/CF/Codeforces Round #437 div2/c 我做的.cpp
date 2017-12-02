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

struct Person
{
	LL s;
	LL a;
	LL b;

	bool operator< (Person p)const {
		return a - b < p.a - p.b;
	}
};


int main()
{
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	int N, S;
	cin >> N >> S;
	vector<Person> va, vb;
	//最多能有多少，减去被强迫吃另一种披萨的值
	LL MAXT = 0;
	for (size_t i = 0; i < N; i++)
	{
		LL s, a, b;
		cin >> s >> a >> b;
		//Person p{ s,a,b };
		if (a > b)
		{
			va.push_back({ s,a,b });//这里可以这么写，自动强制转换成p类型
			MAXT += s*a;
		}

		else
		{
			vb.push_back({ s,a,b });
			MAXT += s*b;
		}
	}
	//以a从小到大排序
	sort(va.begin(), va.end());
	//以b从小到负数排序
	sort(vb.begin(), vb.end());
	reverse(vb.begin(), vb.end());

	//算两边各自剩余多少
	LL arem = 0;
	for (auto a : va)
	{
		arem += a.s;
	}
	arem %= S;
	LL brem = 0;
	for (auto a : vb)
	{
		brem += a.s;
	}
	brem %= S;

	if (arem + brem > S)
	{
		cout << MAXT << endl;
		return 0;
	}

	//强迫人吃另一种pizza的折损
	LL ax = 0, bx = 0;

	for (auto a : va)
	{
		LL p = min(arem, a.s);
		ax += p*(a.a - a.b);
		arem -= p;
	}
	for (auto b : vb)
	{
		LL p = min(brem, b.s);
		bx += p*(b.b - b.a);
		brem -= p;
	}

	cout << MAXT - min(ax, bx) << endl;

	return 0;
}