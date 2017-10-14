#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int dfs()
{
	int Wl, Dl, Wr, Dr;
	cin >> Wl >> Dl >> Wr >> Dr;
	if (Wl == 0)
	{
		Wl = dfs();
	}
	if (Wr == 0)
	{
		Wr = dfs();
	}
	if (Wl == -1 || Wr == -1)
	{
		return -1;
	}
	if (Wl*Dl == Wr*Dr)
	{
		return Wl + Wr;
	}
	else {
		return -1;
	}

}

int main()
{
	freopen("input.txt", "r", stdin);//

	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--)
	{
		if (dfs() == -1)
		{
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
		if (T != 0)
			cout << endl;
	}



	return 0;
}
