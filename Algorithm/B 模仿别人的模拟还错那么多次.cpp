
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


int main()
{
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);

	LL n, k;
	cin >> n >> k;
	vector<LL> v(k);
	for (size_t i = 0; i < k; i++)
	{
		cin >> v[i];
	}

	vector<LL> have(10, 0);
	have[2] = n * 2;
	have[4] = n;

	for (auto&a : v)
	{
		while (a >= 3)
		{
			if (have[4] > 0)
				have[4]--, a -= 4;
			else if (have[2] > 0)
				have[2]--, a -= 2;
			else
				return cout << "NO" << endl, 0;
		}
	}

	for (auto&a : v)
	{
		if (a == 2)
		{
			if (have[2] > 0)a -= 2, have[2]--;
			else if (have[4] > 0)a -= 2, have[4]--, have[1]++;
			else
				//return cout << "NO" << endl, 0;
				have[1] -= 2;//分开
		}
	}
	LL cnt1 = 0;
	for (auto&a : v)
	{
		if (a == 1)
		{
			cnt1++;
		}
	}
	if (cnt1 > have[1] + have[2] + have[4] * 2)return cout << "NO" << endl, 0;
	cout << "YES" << endl;

	return 0;
}