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
	LL cnt = 0;
	LL a = 0;
	LL b = 0;
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

	//for (int i = 0; i <= pizza; i++)
	LL begin = 0, end = pizza + 1;

	{
		LL ct = 0;
		int flag = 0;
		for (int i = 0; i<v.size(); i++)
		{
			if (v[i].a > v[i].b)
			{
				break;
			}
			ct += v[i].cnt;
		}


		LL index = ct / S;
		LL last = index + 3000 > pizza ? pizza : index + 3000;//这里试100次，其实并没有定论
															  //LL last = 0;
															  //for (LL i = 0; i <= pizza; i++)
		for (LL i = index; i <= last; i++)
		{
			LL piece = S*i;

			//int pos = lower_bound(precnt.begin(), precnt.end(), piece) - precnt.begin();
			int pos = lower_bound(precnt.begin(), precnt.end(), piece) - precnt.begin();
			LL tmp = 0;
			if (pos == precnt.size())
			{
				tmp += -1 * preh.back();
			}
			else if (precnt[pos] == piece)
			{
				tmp += -1 * preh[pos];
			}
			else {
				tmp += -1 * preh[pos - 1];
				//tmp += -1 * (piece - precnt[pos - 1])*(v[pos - 1].a - v[pos - 1].b);//可能b也会吃剩下。
				//int gap = pizza*S - precnt.back();//精度有问题
				LL gap = pizza*S - precnt.back();
				LL cut = piece - precnt[pos - 1];
				if (v[pos - 1].a < v[pos - 1].b)
				{
					tmp += -1 * (cut)*(v[pos - 1].a - v[pos - 1].b);
				}
				else
				{
					LL remain = gap - cut > 0 ? 0 : cut - gap;
					tmp += -1 * remain*(v[pos - 1].a - v[pos - 1].b);
				}
			}
			if (tmp > MAX)
			{
				MAX = tmp;
			}
			else {

			}
		}
	}




	LL floor = 0;
	for (auto a : v)
	{
		//floor += a.cnt*a.b;
		floor += (LL)a.cnt*a.a;//这里精度不足，中间结果的精度不足
	}
	cout << floor + MAX << endl;


	return 0;
}