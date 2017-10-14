#include <iostream>
#include <cstdio>
#include <cstring>
#include<string>
#include <algorithm>

using namespace std;

int C[27][27];

int init()
{
	memset(C, 0, sizeof(C));
	for (size_t i = 0; i < 27; i++)//0开始，因为C(0,0)就是等于1，0也是有意义的
	{
		C[i][0] = 1;//防止在算第一个数时越界
		for (size_t j = 1; j <= i; j++)//j最后要等于i，这个可以从三角图上看出来
		{
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
	return 0;
}

int main() {
	freopen("input.txt", "r", stdin);

	string s;
	init();
	while (cin >> s)
	{
		int flag = 0;
		for (size_t i = 0; i < s.length(); i++)
		{
			if (s[i - 1] >= s[i])
			{
				cout << "0" << endl;
				flag = 1;
				break;
			}
		}
		if (flag)continue;

		int sum = 0;
		for (size_t i = 1; i < s.length(); i++)
		{
			sum += C[26][i];
		}

		for (int i = 0; i < s.length(); i++)
		{
			char m = (i - 1 < 0) ? -1 : (s[i - 1] - 'a');
			for (char j = s[i] - 'a' - 1; j>m; j--)
			{
				sum += C[26 - j - 1][s.length() - i - 1];
			}
		}
		cout << sum + 1 << endl;

	}

	return 0;
}