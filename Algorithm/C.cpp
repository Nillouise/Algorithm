#include<cmath>
#include <string>
#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;

bool iscon(char a)
{
	string s = "bcdfghjklmnpqrstvwxyz";
	return s.find(a) != string::npos;
}

int main()
{
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	int success = 0;
	char pre = 'a';
	char pre2 = 'e';//一开始忘记考虑这点
	for (int i = 0; i < s.length(); i++)
	{
		if (iscon(s[i]))
		{
			success++;
			if (success >= 3 && (s[i] != pre || s[i] != pre2))
			{
				cout << " ";
				success = 1;
			}
		}
		else {
			success = 0;
		}
		cout << s[i];
		pre2 = pre;//一开始顺序没搞好
		pre = s[i];
		//pre = s[i];
		//pre2 = pre;//一开始顺序没搞好
	}
	cout << endl;
	return 0;
}