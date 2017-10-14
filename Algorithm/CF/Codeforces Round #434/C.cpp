#include<cmath>
#include <string>
#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;

//这题我数量上犯了错误，对于一个连续的一段东西的判断，我把他当成单个东西判断了
bool iscon(char a)
{
	string s = "bcdfghjklmnpqrstvwxyz";
	return s.find(a) != string::npos;
}


//别人的解法
void solve()
{
	ios::sync_with_stdio(0);
	string s;
	cin >> s;
	//标记一段数字的开始
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