//return (bit&(1 << pos))>0;这句写错了，写成(bit&(1 << pos)) == 1，殊不知这种位运算产生的根本不是1，而是真而已
#include<algorithm>
#include<iostream>
#include<string>
#include<stack>
using namespace std;
int getVal(int bit, char wei)
{
	string s = "pqrst";
	int pos = s.find(wei);
	return (bit&(1 << pos))>0;
}
int isVal(char c)
{
	string s = "pqrst";
	if (s.find(c) != s.npos)
		return 1;
	return 0;
}

int solve(string exp)
{
	for (int bitSet = 0; bitSet < (1 << 5); bitSet++)
	{
		stack<int> sta;
		for (int i = exp.length() - 1; i >= 0; i--)//从后算起就是前缀式
		{
			if (isVal(exp[i]))sta.push(getVal(bitSet, exp[i]));
			else {
				if (exp[i] == 'K') {
					int a = sta.top(); sta.pop();
					int b = sta.top(); sta.pop();
					sta.push(a&&b);
				}
				else if (exp[i] == 'A') {
					int a = sta.top(); sta.pop();
					int b = sta.top(); sta.pop();
					sta.push(a || b);
				}
				else if (exp[i] == 'N') {
					int a = sta.top(); sta.pop();
					sta.push(!a);
				}
				else if (exp[i] == 'C') {
					int a = sta.top(); sta.pop();
					int b = sta.top(); sta.pop();
					sta.push((!a) || b);
				}
				else if (exp[i] == 'E') {
					int a = sta.top(); sta.pop();
					int b = sta.top(); sta.pop();
					sta.push(a == b);
				}
			}
		}
		if (sta.top() == 0)
			return 0;
	}

	return 1;

}


int main()
{
	string s;
	for (;;)
	{
		cin >> s;
		if (s[0] == '0')break;
		if (solve(s))cout << "tautology" << endl;
		else cout << "not" << endl;
	}
	return 0;

}