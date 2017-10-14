
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

	LL N, S;
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
	pizza = (pizza + S - 1LL) / S;
	LL MAX = -1e18;

	//for (int i = 0; i <= pizza; i++)

	{
		LL ct = 0;
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
				tmp += -1LL * preh.back();
			}
			else if (precnt[pos] == piece)
			{
				tmp += -1LL * preh[pos];
			}
			else {
				//tmp += -1 * (piece - precnt[pos - 1])*(v[pos - 1].a - v[pos - 1].b);//可能b也会吃剩下。
				//int gap = pizza*S - precnt.back();//精度有问题
				LL gap = pizza*S - precnt.back();
				LL cut = piece - precnt[pos - 1];

				////这里是错的，因为他单纯比较了a和b的大小，但没有比较有可能a要吃多点，b可能只用吃少点
				////还有一个错误是，当要换pizza的类型时，可有有几个人要一起换
				//if (v[pos - 1].a < v[pos - 1].b)
				//{
				//	tmp += -1LL * (cut)*(v[pos - 1].a - v[pos - 1].b);
				//}
				//else
				//{
				//	LL remain = gap - cut > 0 ? 0 : cut - gap;
				//	tmp += -1LL * remain*(v[pos - 1].a - v[pos - 1].b);
				//}
				//下面这里没有考虑多个人要一起换
				//LL eata = -1LL * (cut)*(v[pos - 1].a - v[pos - 1].b);
				//LL remain = gap - cut > 0 ? 0 : cut - gap;
				//LL eatb = -1LL * remain*(v[pos - 1].a - v[pos - 1].b);
				//tmp += max(eata, eatb);


				//下面这里还在尝试，把多个人放在gap里（而不是一个人），但还是错的
				if (v[pos - 1].a < v[pos - 1].b)
				{
					tmp += -1LL * (cut)*(v[pos - 1].a - v[pos - 1].b);
					tmp += -1LL * preh[pos - 1];
				}
				else
				{
					if (gap - cut <= 0)
					{
						cut -= gap;
						tmp += -1LL * (cut)*(v[pos - 1].a - v[pos - 1].b);
						tmp += -1LL * preh[pos - 1];//这句要跟上面的pos配套
					}
					else {
						pos--;
						gap -= cut;
						while (v[pos - 1].a >= v[pos - 1].b)
						{
							if (gap > v[pos - 1].cnt)
							{
								gap -= v[pos - 1].cnt;
							}
							else {
								LL require = v[pos - 1].cnt - gap;
								tmp += -1LL * require*(v[pos - 1].a - v[pos - 1].b);
								break;
							}
							pos--;
							if (pos == -1)break;
						}
						tmp += -1LL * preh[pos - 1];//注意这里
					}



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
		floor += (LL)a.cnt*(LL)a.a;//这里精度不足，中间结果的精度不足
	}
	cout << floor + MAX << endl;


	return 0;
}