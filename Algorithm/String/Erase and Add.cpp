/*
��Ҫ��ע�ص�
while (scanf("%s", s), s[0] != '.')
scanf("%s%s", op, s2);���������ˣ�scanf�����ո����һ���ַ����Ľ�������ص㣬Ҳ����˵���ո���Ȼ����scanf�ķָ���
vector<string>::iterator it;��ס������ĸ�ʽ
for (it = m.begin(); it != m.end(); it++)
{
	if ((*it) == t)
	{
		m.erase(it);
		break;
	}
}ɾ�� vector�ڵ�Ԫ����vector.erase(iterator)


*/


#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
#include<time.h>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int i;
	char s[101], op[3], s2[101];

	while (scanf("%s", s), s[0] != '.')
	{
		scanf("%s%s", op, s2);
		vector<string> m;
		vector<string>::iterator it;
		string t;
		for (i = 0; s[i]; i++)
		{
			if (s[i] != '[')
			{
				if (s[i] == ',' || s[i] == ']')
				{
					if (t != "") m.push_back(t);
					t = "";
				}
				else t += s[i];
			}

		}
		for (i = 0; s2[i]; i++)
		{
			if (s2[i] != '[')
			{
				if (s2[i] == ',' || s2[i] == ']')
				{
					if (op[0] == '+')
					{
						if (t != "") m.push_back(t);
					}
					else
					{
						for (it = m.begin(); it != m.end(); it++)
						{
							if ((*it) == t)
							{
								m.erase(it);
								break;
							}
						}
					}
					t = "";
				}
				else t += s2[i];
			}
		}
		putchar('[');
		for (i = 0; i<m.size(); i++)
		{
			printf("%s%s", m[i].c_str(), i == m.size() - 1 ? "" : ",");
		}
		putchar(']');
		putchar(10);
	}
	return 0;
}
