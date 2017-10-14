/*
vec[0].substr(i, j - i);substr 是从 a位置开始，选出 b个元素。
*/

#include<iostream>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;


int main()
{

	int n;
	cin >> n;
	while (n--)
	{
		int m;
		cin >> m;
		vector<string> vec;
		while (m--)
		{
			string t;
			cin >> t;
			vec.push_back(t);
		}
		string common;
		for (size_t i = 0; i <= 60; i++)
		{
			for (size_t j = i + 1; j <= 60; j++)
			{
				if (j - i < common.length())continue;
				string cur = vec[0].substr(i, j - i);
				if (cur.length() == common.length() && cur > common)continue;//确保是最小的字典序。
				int ok = 1;
				for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++)//这里使用auto 关键字，并不能通过 oj的系统
				{
					if (it->find(cur) == cur.npos) {//找不到，就会返回npos 作为标记
						ok = 0;
						break;
					}
				}
				if (ok == 1)
				{
					common = cur;
				}
			}
		}
		if (common.length() < 3)cout << "no significant commonalities" << endl;
		else cout << common << endl;
	}

	return 0;
}