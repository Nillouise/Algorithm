#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include <ctime>
#include <bitset>
using namespace std;
typedef long long LL;


int main()
{
	freopen("input.txt", "r", stdin);

	string s;
	while (cin >> s)
	{
		s = ' ' + s;
		vector<int> next(s.size(), -1);
		int cur = 0;
		int head = 0;
		int last = 0;
		int pre = 0;
		for (int i = 1; i<s.size(); i++)
		{
			if (s[i] == '[')
			{
				cur = 0;
			}
			else if (s[i] == ']')
			{
				cur = last;
			}
			else
			{
				//这里要想好
				if (cur == last)
				{
					last = i;
				}
				next[i] = next[cur];
				next[cur] = i;
				cur = i;


			}
		}
		int i = next[0];
		//这里会少打印出最后一个字符
		//		while(next[i]!=-1)
		while (i != -1)
		{
			cout << s[i];
			i = next[i];
		}
		cout << endl;
	}



	return 0;
}