//这里用了一个每个数都暴力求因数的算法，导致超时，当然，本来思路就完全错了
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

map<LL, LL> prime(LL a)
{
	map<LL, LL> r;
	for (int i = 2; a != 1; i++)
	{
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
		for (auto a = r1.begin(); a != r1.end(); a++)
		{
			LL cnta = a->second;
			LL cntb = r2[a->first];

			if (cnta>cntb * 2 || cntb>cnta * 2)
			{
				cout << "NO" << endl;
				flag = 0;
				break;
			}
			//if(2*cnta-cntb%3)
			if ((2 * cnta - cntb) % 3)
			{
				cout << "NO" << endl;
				flag = 0;
				break;
			}
		}
		if (flag)
			cout << "YES" << endl;

	}

	return 0;
}