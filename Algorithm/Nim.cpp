#include<iostream>
#include<fstream>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define LOCAL

int dist(int x1, int y1, int x2, int y2)
{
	return abs(x1 - x2) + abs(y1 - y2);
}

int main(void)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif // LOCAL
	int T;
	cin >> T;
	while (T--)
	{
		int N, x1, y1, x2, y2;
		cin >> N >> x1 >> y1 >> x2 >> y2;
		int d = dist(x1, y1, x2, y2);
		if (N < d)
		{
			if (N % 2 == 1)
				cout << 1;
			else
				cout << -1;
		}
		else if (N / 2 + N % 2 < d)
		{
			cout << (N % 2 == 0 ? -1 : 1);
		}
		else
		{
			if (N % 2 == 0)
			{
				cout << -1;
			}
			else {
				cout << 2;
			}

		}
		cout << endl;
	}

	return 0;
}