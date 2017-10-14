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
	ios::sync_with_stdio(false);

	LL k;
	cin >> k;


	string s;
	cin >> s;

	vector<int> v;

	for (auto a : s)
		v.push_back(a - '0');
	sort(v.begin(), v.end());

	int cut = k;
	for (auto a : v)
		cut -= a;

	int cnt = 0;
	while (cut>0)
	{
		for (auto&a : v)
		{
			if (9 - a > 0)
			{
				cut -= 9 - a, a = 9;
				break;
			}
		}
		cnt++;
	}
	cout << cnt << endl;


	return 0;
}