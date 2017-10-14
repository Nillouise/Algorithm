// 这题可以不用保存中间结果，这样就不用判断系数是大于0还是小于0，还简洁
#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;
typedef long long LL;
LL a[100000 + 1000];
//这里起名不好
//起  int minleft[100005],minright[100005],maxleft[100005]；
LL al[2][100000 + 1000];
LL ar[2][100000 + 1000];

int main()
{
	freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(false);
	LL n, p, q, r;
	cin >> n >> p >> q >> r;
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	LL MAX = -10e10, MIN = 10e10;
	for (size_t i = 0; i < n; i++)
	{
		if (a[i] > MAX)MAX = a[i];
		if (a[i] < MIN)MIN = a[i];

		al[0][i] = MAX;
		al[1][i] = MIN;
	}

	MAX = -10e10;
	MIN = 10e10;
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] > MAX)MAX = a[i];
		if (a[i] < MIN)MIN = a[i];
		ar[0][i] = MAX;
		ar[1][i] = MIN;
	}
	LL mt = -10e10;

	for (int i = 0; i < n; i++)
	{
		LL total = 0;

		if (p < 0)total += p*al[1][i];
		else total += p*al[0][i];

		if (q < 0)total += q*a[i];
		else total += q*a[i];

		if (r < 0)total += r*ar[1][i];
		else total += r*ar[0][i];

		if (total > mt)mt = total;
	}
	cout << mt << endl;




	return 0;
}