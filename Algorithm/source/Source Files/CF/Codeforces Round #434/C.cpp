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
	char pre2 = 'e';//һ��ʼ���ǿ������
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
		pre2 = pre;//һ��ʼ˳��û���
		pre = s[i];
		//pre = s[i];
		//pre2 = pre;//һ��ʼ˳��û���
	}
	cout << endl;
	return 0;
}