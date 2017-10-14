#include <iostream>
#include <cstdio>
#include <cstring>
#include<string>
#include <algorithm>
#include<sstream>
#include<cmath>
#include<vector>
#include<stack>
using namespace std;
int N, P;

//这种思路的不对之处在于
//括号是有两种关系，互相包含和并列，当并列时，这个程序不能正确处理两个并列序列之间的那些非法括号
int solve(string s)
{
	stack<char> sta;
	int MAX = 0;
	int temp = 0;
	for (size_t i = 0; i < s.size(); i++)
	{

		if (s[i] == '(')
		{
			sta.push('(');
		}
		else {
			if (sta.size() >= 1)
			{
				sta.pop();
				temp += 2;
			}
			else {
				MAX = max(MAX, temp);
				temp = 0;
			}
		}
	}
	//最后一个字符要放在外面来，因为只有不合法时，才会更新MAX
	MAX = max(MAX, temp);
	return MAX;
}

int main() {
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--)
	{
		string s;
		cin >> s;
		cout << solve(s) << endl;
	}
	return 0;
}