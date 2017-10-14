#include<cmath>
#include <cstring>
#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);

	int n, m;
	vector<int> floor[101];
	cin >> n >> m;
	for (size_t i = 0; i < m; i++)
	{
		int k, f;
		cin >> k >> f;
		floor[f].push_back(k);
	}

	vector<int> possible;

	for (int i = 1; i <= 100; i++)
	{
		bool conflict = false;

		for (int f = 1; f <= 100; f++)
		{
			for (vector<int>::iterator diban = floor[f].begin(); diban != floor[f].end(); diban++)
			{
				int d = *diban - 1;
				//int possiblefloor = d / i + (d%i > 0 ? 1 : 0)+1;
				int possiblefloor = d / i + 1;
				if (possiblefloor != f)
				{
					conflict = true;
					goto curpossible;
				}
			}
		}
	curpossible:
		if (!conflict)possible.push_back(i);
	}
	int flag = true;
	int pre = -1;
	for (vector<int>::iterator i = possible.begin(); i != possible.end(); i++)
	{
		int nf = (n - 1) / (*i) + 1;
		if (pre != -1)
		{
			if (nf != pre) { flag = false; break; }
		}
		pre = nf;
	}
	if (flag)cout << pre << endl;
	else cout << -1 << endl;

	return 0;
}