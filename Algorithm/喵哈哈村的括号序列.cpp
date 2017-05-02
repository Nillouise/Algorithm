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

//����˼·�Ĳ���֮������
//�����������ֹ�ϵ����������Ͳ��У�������ʱ�������������ȷ����������������֮�����Щ�Ƿ�����
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
	//���һ���ַ�Ҫ��������������Ϊֻ�в��Ϸ�ʱ���Ż����MAX
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