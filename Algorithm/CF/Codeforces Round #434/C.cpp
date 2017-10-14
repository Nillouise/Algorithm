#include<cmath>
#include <string>
#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;

//�����������Ϸ��˴��󣬶���һ��������һ�ζ������жϣ��Ұ������ɵ��������ж���
bool iscon(char a)
{
	string s = "bcdfghjklmnpqrstvwxyz";
	return s.find(a) != string::npos;
}


//���˵Ľⷨ
void solve()
{
	ios::sync_with_stdio(0);
	string s;
	cin >> s;
	//���һ�����ֵĿ�ʼ
	int last = -1;
	int is = 0;
	for (int i = 0; i < s.length(); i++) {

		if (iscon(s[i]))
			is = 0, last = i, cout << s[i];
		else
			if (last == i - 1)
				cout << s[i];
			else {
				if (s[i] != s[i - 1])
					is = 1;
				if (i - last > 2 && is)
					cout << ' ' << s[i], is = 0, last = i - 1;
				else
					cout << s[i];
			}
	}
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