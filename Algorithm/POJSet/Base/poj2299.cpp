//这题求逆序数，要用long long 保存

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
int n;
int a[500000 + 5];

long long merg_sort(int x, int y)
{
	long long cnt = 0;
	if (y - x > 1)
	{
		int m = x + (y - x) / 2;
		cnt += merg_sort(x, m);
		cnt += merg_sort(m, y);
		int p = x, q = m;
		vector<int> v;
		while (p<m || q<y)
		{
			if (q >= y || (p < m&&a[p] < a[q]))
			{
				//				cnt += (y - q);//这个不用加逆序数，只有后半段放到前半段才用加
				v.push_back(a[p]);
				p++;
			}
			else {
				cnt += (m - p);
				v.push_back(a[q]);
				q++;
			}
		}
		for (size_t i = 0; i < v.size(); i++)
		{
			a[x + i] = v[i];
		}
	}

	return cnt;
}

long long nixu()
{
	return merg_sort(0, n);
}

int main()
{
	freopen("input.txt", "r", stdin);

	while (cin >> n)
	{
		if (n == 0)break;
		for (size_t i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cout << nixu() << endl;
		//for (size_t i = 0; i < n; i++)
		//{
		//	cout << a[i];
		//}
	}

	return 0;
}