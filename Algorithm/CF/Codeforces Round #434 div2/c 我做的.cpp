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
	//������ж��٣���ȥ��ǿ�ȳ���һ��������ֵ
	LL MAXT = 0;
	for (size_t i = 0; i < N; i++)
	{
		LL s, a, b;
		cin >> s >> a >> b;
		//Person p{ s,a,b };
		if (a > b)
		{
			va.push_back({ s,a,b });//���������ôд���Զ�ǿ��ת����p����
			MAXT += s*a;
		}

		else
		{
			vb.push_back({ s,a,b });
			MAXT += s*b;
		}
	}
	//��a��С��������
	sort(va.begin(), va.end());
	//��b��С����������
	sort(vb.begin(), vb.end());
	reverse(vb.begin(), vb.end());

	//�����߸���ʣ�����
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

	//ǿ���˳���һ��pizza������
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