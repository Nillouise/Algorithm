
#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>//���sqrtҪ��
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

	vector<LL> preh; //sufh(v.size()+2);//������reverse����Ӧ�ñȽϺ�
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
		LL last = index + 3000 > pizza ? pizza : index + 3000;//������100�Σ���ʵ��û�ж���
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
				//tmp += -1 * (piece - precnt[pos - 1])*(v[pos - 1].a - v[pos - 1].b);//����bҲ���ʣ�¡�
				//int gap = pizza*S - precnt.back();//����������
				LL gap = pizza*S - precnt.back();
				LL cut = piece - precnt[pos - 1];

				////�����Ǵ�ģ���Ϊ�������Ƚ���a��b�Ĵ�С����û�бȽ��п���aҪ�Զ�㣬b����ֻ�ó��ٵ�
				////����һ�������ǣ���Ҫ��pizza������ʱ�������м�����Ҫһ��
				//if (v[pos - 1].a < v[pos - 1].b)
				//{
				//	tmp += -1LL * (cut)*(v[pos - 1].a - v[pos - 1].b);
				//}
				//else
				//{
				//	LL remain = gap - cut > 0 ? 0 : cut - gap;
				//	tmp += -1LL * remain*(v[pos - 1].a - v[pos - 1].b);
				//}
				//��������û�п��Ƕ����Ҫһ��
				//LL eata = -1LL * (cut)*(v[pos - 1].a - v[pos - 1].b);
				//LL remain = gap - cut > 0 ? 0 : cut - gap;
				//LL eatb = -1LL * remain*(v[pos - 1].a - v[pos - 1].b);
				//tmp += max(eata, eatb);


				//�������ﻹ�ڳ��ԣ��Ѷ���˷���gap�������һ���ˣ��������Ǵ��
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
						tmp += -1LL * preh[pos - 1];//���Ҫ�������pos����
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
						tmp += -1LL * preh[pos - 1];//ע������
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
		floor += (LL)a.cnt*(LL)a.a;//���ﾫ�Ȳ��㣬�м����ľ��Ȳ���
	}
	cout << floor + MAX << endl;


	return 0;
}