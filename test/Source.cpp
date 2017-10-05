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

int clw(int b, int m, int e)
{
	//for(int i=b;i<=e;i++)
	for (int i = b; i != e; i++)
	{
		if (i>12) i = (i % 12) + 1;
		if (i == m)
		{
			return 0;
		}
	}
	return 1;
}


int clw2(int b, int m, int e)
{
	//for (int i = b; i <= e; i++)
	for (int i = b; i != e; i++)
	{
		i = (i % 60);
		if (i == m)
		{
			return 0;
		}
	}
	return 1;


}
int h, m, s, t1, t2;
//int clw3()
//{
//	for (int i=s;;i++)
//	{
//		if (i == 60)i == 0, m++;
//		if (m == 60)m == 0, h++;
//		if()
//	}
//}




int main()
{
	freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	set<int> s;
	for (int i = 0; i<n; i++)
	{
		int c = 0;
		for (int i = 0; i<k; i++)
		{
			int a;
			cin >> a;
			//c=(c << i) + a;
			c = (a << i) + c;
		}
		s.insert(c);
	}

	vector<int> v;
	for (auto i : s)
	{
		v.push_back(i);
	}

	int flag;
	for (int i = 0; i<v.size(); i++)
	{
		if (v[i] == 0)return cout << "YES" << endl, 0;

		for (int j = i + 1; j<v.size(); j++)
		{
			flag = 1;
			for (int o = 0; o<k; o++)
			{
				//if ((v[i] & (1 << o)>0) && (v[j] & (1 << o)>0)) //这里运算符号优先序不对
				if (((v[i] & (1 << o))>0) && ((v[j] & (1 << o))>0))
				{
					flag = 0;
					break;
				}
			}
			//i&&j&&(!(v[i]&v[j])) //这么判断最好

			if (flag == 1)
			{
				if (n == 10000)
				{
					for (auto a : v)
					{
						cout << a << " ";
					}
				}

				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;

	return 0;
}