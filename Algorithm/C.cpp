#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;
typedef long long LL;

int main()
{
	ios::sync_with_stdio(false);

	LL a, b, f, k;
	cin >> a >> b >> f >> k;

	LL cg = b;
	int end = 0;
	int cnt = 0;
	for (int i = 0; i < k; i++)
	{
		int cost;
		cost = end == 0 ? f : a - f;
		cg -= cost;
		if (cg < 0)
		{
			cout << -1 << endl;
			return 0;
		}

		//需要跑下一趟
		if (i != k - 1)
		{
			//可以开回加油站
			if (cg >= (a - cost) * 2)
			{

			}
			else {
				cg = b;
				cnt++;
			}
		}
		//不需要跑下一趟
		else {
			if (cg >= a - cost)
			{

			}
			else {
				cg = b;
				cnt++;
			}
		}
		cg -= a - cost;
		if (cg < 0)
		{
			cout << -1 << endl;
			return 0;
		}
		end = !end;
	}

	cout << cnt << endl;


	return 0;
}