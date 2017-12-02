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

	int N, S;
	cin >> N >> S;
	vector<P> v;
	for (size_t i = 0; i < N; i++)
	{
		P p;
		cin >> p.cnt >> p.a >> p.b;
		v.push_back(p);
	}
	sort(v.begin(), v.end());

	vector<LL> preh; //sufh(v.size()+2);//这里用reverse处理应该比较好
	vector<LL> sufh;
	preh.push_back(0);
	vector<LL> precnt;
	precnt.push_back(0);
	for (auto a : v)
	{
		preh.push_back(preh.back() + a.cnt*(a.a - a.b));
		precnt.push_back(precnt.back() + a.cnt);
	}
	precnt.push_back(precnt.back());
	preh.push_back(preh.back());
	sufh.push_back(0);
	for (int i = v.size() - 1; i >= 0; i--)
	{
		sufh.push_back(sufh.back() + v[i].cnt*(v[i].a - v[i].b));
	}
	sufh.push_back(sufh.back());
	reverse(sufh.begin(), sufh.end());



	LL pizza = 0;
	for (auto a : v)
	{
		pizza += a.cnt;
	}
	pizza = (pizza + S - 1) / S;
	LL MAX = -1e18;
	////这里是从前到后给a pizza，但应该从b pizza开始给才对。
	//for (int i = 0; i <= pizza; i++)
	//{
	//	LL tmp = 0;
	//	int piece = pizza*S;

	//	int pos = lower_bound(precnt.begin(), precnt.end(), piece) - precnt.begin();

	//	if (pos == precnt.size())
	//	{
	//		tmp += preh[pos - 1];
	//	}else  if (precnt[pos] == piece)
	//	{
	//		tmp += preh[pos];
	//		tmp += -1*sufh[pos + 1];
	//	}
	//	else
	//	{
	//		tmp += preh[pos - 1];
	//		tmp += -1*sufh[pos + 1];

	//		tmp += (precnt[pos] - piece)*(v[pos - 1].a - v[pos - 1].b);
	//		tmp += (piece - precnt[pos])*(v[pos - 1].a - v[pos].b)*(-1);
	//	}
	//	if (tmp > MAX)MAX = tmp;
	//}

	for (int i = 0; i <= pizza; i++)
	{
		LL tmp = 0;
		int piece = i*S;

		int pos = lower_bound(precnt.begin(), precnt.end(), piece) - precnt.begin();

		if (pos == precnt.size())
		{
			tmp += -preh[pos - 1];
		}
		else  if (precnt[pos] == piece)
		{
			tmp += -1 * preh[pos];
			tmp += sufh[pos + 1];
		}
		else
		{
			tmp += -1 * preh[pos - 1];
			tmp += sufh[pos + 1];

			tmp += (precnt[pos] - piece)*(v[pos - 1].a - v[pos - 1].b)*(-1);
			tmp += (piece - precnt[pos])*(v[pos - 1].a - v[pos].b);
		}
		if (tmp > MAX)MAX = tmp;
	}
	LL floor = 0;
	for (auto a : v)
	{
		//floor += a.cnt*a.b;
		floor += a.cnt*a.a;
	}
	cout << floor + MAX << endl;


	return 0;
}