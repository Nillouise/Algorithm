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

//const LL MAXN = 1e9+1;
const LL MAXN = 1e5 + 100;
vector<LL> pv;
vector<char> G(MAXN, 0);
int prime2()
{
	for (LL i = 2; i<MAXN; i++)
	{
		if (G[i] == 0)
		{
			for (LL j = i * 2; j<MAXN; j += i)
			{
				G[i] = 1;
			}
		}
	}

	for (LL i = 2; i<MAXN; i++)
	{
		if (G[i])pv.push_back(i);
	}
	return 0;
}


map<LL, LL> prime(LL a)
{
	map<LL, LL> r;
	for (auto i : pv)
	{
		if (a == 1)break;
		while (a%i == 0)
		{
			r[i]++;
			a /= i;
		}
	}
	return r;
}



int main()
{
	ios::sync_with_stdio(false);

	prime2();


	LL n, a, b;
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		cin >> a >> b;

		map<LL, LL> r1 = prime(a);
		map<LL, LL>r2 = prime(b);

		if (r1.size() != r2.size())
		{
			cout << "NO" << endl;
			continue;
		}

		int flag = 1;
		int flag2 = 1;
		for (auto a = r1.begin(); a != r1.end(); a++)
		{

			LL cnta = a->second;
			LL cntb = r2[a->first];
			flag = 1;
			if (cnta>cntb * 2 || cntb>cnta * 2)
			{
				flag = 0;
			}
			//if(2*cnta-cntb%3)
			if ((2 * cnta - cntb) % 3 || (2 * cntb - cnta) % 3)
			{
				flag = 0;
			}


			//这里意识到我的算法有问题，于是打了这个补丁，但这个补丁想得深一点就会知道，补丁也是错的。
			//因为他不能解决复杂的因数之间的关系（也就是一个因数有两种方法被消去，一个是消除这个因数，
			if (flag == 0)
			{
				cnta = a->first;
				cntb = r2[a->second];

				if (cnta>cntb * 2 || cntb>cnta * 2)
				{
					flag2 = 0;
				}
				//if(2*cnta-cntb%3)
				if ((2 * cnta - cntb) % 3 || (2 * cntb - cnta) % 3)
				{
					flag2 = 0;
				}
			}
			if (flag2 == 0)break;
		}
		if (flag2)
			cout << "YES" << endl;
		else
		{
			cout << "NO" << endl;
		}
	}



	return 0;
}