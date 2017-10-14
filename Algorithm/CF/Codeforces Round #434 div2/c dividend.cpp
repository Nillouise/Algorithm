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

struct P
{
	int cnt = 0;
	int a = 0;
	int b = 0;
	bool operator <(P n) const
	{
		return a - b < n.a - n.b;
	}
};



int main()
{
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);

	int n, s;
	cin >> n >> s;
	vector<P> v;
	LL pizza = 0;
	for (size_t i = 0; i < n; i++)
	{
		int p, a, b;
		cin >> p >> a >> b;

		P c;
		c.cnt = p;
		c.a = a;
		c.b = b;
		v.push_back(c);
		pizza += p;
	}
	pizza = (pizza - 1 + s) / s;

	sort(v.begin(), v.end());

	vector<LL> precnt;
	vector<LL> preh;
	//前缀和应该用0开头
	precnt.push_back(0);
	preh.push_back(0);
	for (int i = 0; i<v.size(); i++)
	{
		precnt.push_back(precnt.back() + v[i].cnt);
		preh.push_back(preh.back() + v[i].cnt*(v[i].a - v[i].b));
	}
	vector<LL> sufh(preh.size());
	sufh.back() = 0;
	for (int i = sufh.size() - 2; i >= 0; i--)
	{
		sufh[i] = sufh[i + 1] + v[i].cnt*(v[i].a - v[i].b);
	}
	sufh.push_back(0);

	LL MAX = -1e18;
	//模拟有多少块a披萨
	for (int i = 0; i <= pizza; i++)
	{
		int piece = i*s;
		int a = lower_bound(precnt.begin(), precnt.end(), piece) - precnt.begin();

		LL ch = 0;
		//刚好可以分开
		if (precnt[a] * s == piece)
		{
			ch += preh[a];
			ch += (-1 * sufh[a + 1]);
		}
		//其中一人要吃两种类型的pizza
		else {
			ch += preh[a - 1];
			ch += (-1 * sufh[a + 1]);
			//ch += (piece - precnt[a - 1] * s)*((v[a - 1].a - v[a - 1].b));//处理的是a
			//ch += (precnt[a + 1] * s - piece)*(-1)*((v[a - 1].a - v[a - 1].b));
			ch += (piece - precnt[a - 1] * s)*((v[a - 1].a - v[a - 1].b));//跟上面一样对的
			if (a + 1 != precnt.size())
				ch += (precnt[a + 1] * s - piece)*(-1)*((v[a - 1].a - v[a - 1].b));
		}
		if (MAX < ch)
		{
			MAX = ch;
		}
	}
	LL floor = 0;
	for (auto a : v)
	{
		floor += a.cnt*a.b;
	}
	cout << floor + MAX << endl;

	return 0;
}