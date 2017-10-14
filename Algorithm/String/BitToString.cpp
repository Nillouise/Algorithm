#include<iostream>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<algorithm>
#include<iterator>
#include<sstream>
using namespace std;


string tran(char c)
{
	string s;
	do
	{
		s += c % 2 ? '1' : '0';
	} while (c /= 2);

	reverse(s.begin(), s.end());//翻转字符串，需要Algorithms
	return s;
}

char tran2(string s)
{
	char c = 0;
	for (size_t i = 0; i < s.length(); i++)
	{
		c <<= 1;
		c += s[i] == '0' ? 0 : 1;
	}
	return c;
}

string printS(int num)
{
	stringstream ss;
	ss << num;
	string s;
	ss >> s;
	return s;
}


int main()
{
	cout << tran(2);

	cout << printS(23);

	system("pause");
	return 0;
}