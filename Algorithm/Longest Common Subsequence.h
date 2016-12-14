#pragma once
#include<iostream>
using namespace std;
class LCS
{
public:
	int d[100][100];
	string s1, s2;
	void run()
	{
		memset(d, 0, sizeof(d));
		for (int i = 0; i < s1.length; i++)
		{
			for (int j = 0; j < s2.length; j++)
			{
				if (s1[i] == s2[j])
					d[i][j] = i == 0 || j == 0 ? 1 : d[i - 1][j - 1] + 1;
			}
		}
		cout << "最长长度为：" << d[s1.length - 1][s2.length - 1]<<endl;


	}
};