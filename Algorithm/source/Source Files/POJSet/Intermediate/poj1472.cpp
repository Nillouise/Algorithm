#include <iostream>
#include <cstdio>
#include <cstring>
//输入begin,一开始这个string 跟for里面的重名了，stl的原因导致出bug
#include<string>
#include <algorithm>
#include<sstream>
#include<cmath>
using namespace std;
const int maxn = 200;
const double INF = 1000000.0;

int stringToInt(string s)
{
	stringstream ss;
	ss << s;
	int r;
	ss >> r;
	return r;
}

int dfs(int *cof)
{
	string n;
	cin >> n;
	for (;;)
	{
		string s;
		cin >> s;
		if (s == "OP")
		{
			string op;
			cin >> op;
			cof[0] += stringToInt(op);
		}
		else if (s == "LOOP")
		{
			int cof2[12];
			memset(cof2, 0, sizeof(cof2));
			int r = dfs(cof2);
			if (r == -1)
			{
				for (size_t i = 0; i < 11; i++)
					cof[i + 1] += cof2[i];
			}
			else {
				for (size_t i = 0; i < 12; i++)
					cof[i] += cof2[i] * r;
			}
		}
		else if (s == "END")
		{
			break;
		}
	}
	if (n[0] == 'n')return -1;
	return stringToInt(n);
}
int ans[12];
int start2()
{
	string be;
	cin >> be;//输入begin,一开始这个string 跟for里面的重名了，stl的原因导致出bug

	memset(ans, 0, sizeof(ans));
	for (;;)
	{
		string s;
		cin >> s;
		if (s == "OP")
		{
			string op;
			cin >> op;
			ans[0] += stringToInt(op);
		}
		else if (s == "LOOP")
		{
			int cof2[12];
			memset(cof2, 0, sizeof(cof2));
			int r = dfs(cof2);
			if (r == -1)
			{
				for (size_t i = 0; i < 11; i++)
					ans[i + 1] += cof2[i];
			}
			else {
				for (size_t i = 0; i < 12; i++)
					ans[i] += cof2[i] * r;
			}
		}
		else if (s == "END")
		{
			break;
		}
	}
	return 0;
}

int main()
{
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;
	//string s;
	//cin >> s;
	for (size_t t = 1; t <= T; t++)
	{
		start2();
		int plusFlag = 0;
		cout << "Program #" << t << endl;
		cout << "Runtime = ";
		for (int i = 11; i >= 0; i--)
		{

			if (ans[i] != 0)
			{
				if (plusFlag)cout << "+";
				plusFlag = 1;
				if (ans[i] > 1)//当系数是1，并且后面无n时，根本就不会输出了
							   //这么写挺不好的，应该把i=0的情况直接输出系数，其他的情况用一个括号概括
				{
					cout << ans[i];
					if (i >= 1)
						cout << "*";
				}
				else if (i == 0)
				{
					cout << ans[i];
				}
				if (i >= 2)
				{
					cout << "n^" << i;
				}
				if (i == 1)
					cout << "n";

			}
		}
		//		cout << endl<<endl;//注意输出格式，要多一个空行
		//因为没数的时候，就要直接输出0
		if (!plusFlag)
			cout << 0 << endl << endl;
		else
			cout << endl << endl;
	}
	return 0;
}