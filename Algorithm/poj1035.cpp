#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
vector<string> dict;

int comp(string s1, string s2)
{
	if (s1.size() > s2.size())
	{
		string s = s1;
		s1 = s2;
		s2 = s;
	}
	if (s2.size() - s1.size() > 1)
		return 0;
	if (s1.size() == s2.size())
	{
		int cnt = 0;
		for (size_t i = 0; i < s1.size(); i++)
		{
			cnt += s1[i] == s2[i] ? 0 : 1;
		}
		if (cnt > 1)
			return 0;
		else
			return 1;
	}
	int j = 0;
	int flag = 0;
	for (size_t i = 0; i < s1.size(); i++, j++)
	{
		if (s1[i] != s2[j])
		{
			if (flag == 1)
			{
				return 0;
			}
			else {
				//	j++;//不是j++，这样这样 i就不再比较了
				i--;
				flag = 1;
			}
		}
	}
	return 1;

}

int assemble(string s)
{
	cout << s << ": ";
	for (size_t i = 0; i < dict.size(); i++)
	{
		if (comp(dict[i], s))
		{
			cout << dict[i] << " ";
		}
	}
	cout << endl;
	return 1;
}

int check(string s)
{
	int flag = 0;
	for (size_t i = 0; i < dict.size(); i++)
	{
		if (dict[i] == s)
		{
			flag = 1;
			break;
		}
	}
	if (flag)
	{
		cout << s << " is correct" << endl;
	}
	else {
		assemble(s);
	}
	return 0;
}

int main()
{
	freopen("input.txt", "r", stdin);
	string s;

	while (cin >> s&&s[0] != '#')
	{
		dict.push_back(s);
	}

	while (cin >> s&&s[0] != '#')
	{
		check(s);
	}

	return 0;
}