#include <iostream>
#include <cstdio>
#include <cstring>
#include<string>
#include <algorithm>
#include<sstream>
#include<cmath>
using namespace std;

string s;
int init()
{
	stringstream ss;
	s = "";

	for (int j = 1; j <= 31268 + 4; j++) //这里写得不够大
	{
		ss << j;
	}
	ss >> s;

	return 0;
}

int main() {
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	init();

	while (T--)
	{
		int quest;
		cin >> quest;
		long long total = 0;
		long long cur = 0;
		for (int i = 1; ; i++)
		{
			cur += log10((double)i) + 1;//要转换类型，不然log10不知道要重载那个函数
			total += cur;
			if (total >= quest)
			{
				int index = quest - (total - cur);
				index--;//数量转坐标要--
				cout << s[index] << endl;
				break;
			}
		}

	}

	return 0;
}