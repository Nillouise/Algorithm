#include <iostream>
#include <cstdio>
#include <cstring>
#include<string>
#include <algorithm>

using namespace std;

int C[27][27];

int init()
{
	memset(C, 0, sizeof(C));
	for (size_t i = 0; i < 27; i++)//0��ʼ����ΪC(0,0)���ǵ���1��0Ҳ���������
	{
		C[i][0] = 1;//��ֹ�����һ����ʱԽ��
		for (size_t j = 1; j <= i; j++)//j���Ҫ����i��������Դ�����ͼ�Ͽ�����
		{
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
	return 0;
}

int main() {
	freopen("input.txt", "r", stdin);

	string s;
	init();
	while (cin >> s)
	{
		int flag = 0;
		for (size_t i = 0; i < s.length(); i++)
		{
			if (s[i - 1] >= s[i])
			{
				cout << "0" << endl;
				flag = 1;
				break;
			}
		}
		if (flag)continue;

		int sum = 0;
		for (size_t i = 1; i < s.length(); i++)
		{
			sum += C[26][i];
		}

		for (int i = 0; i < s.length(); i++)
		{
			char m = (i - 1 < 0) ? -1 : (s[i - 1] - 'a');
			for (char j = s[i] - 'a' - 1; j>m; j--)
			{
				sum += C[26 - j - 1][s.length() - i - 1];
			}
		}
		cout << sum + 1 << endl;

	}

	return 0;
}