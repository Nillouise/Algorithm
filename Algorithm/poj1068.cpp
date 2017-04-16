//字符数目变量忘记相减，没有牢记每个变量的含义和与题目的联系
//忘记Pn代表的含义是 P-sequence 的数目而不是真正构造出来的字符串 大小,这点在debug时居然没有第一时间反应出来，
//for循环提前退出，没有break掉，肯定就是因为边界条件写错了
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
const int maxstate = 10000;
int P[maxstate];


int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;

	while (T--)
	{
		int Pn;
		cin >> Pn;
		for (size_t i = 0; i < Pn; i++)
			cin >> P[i];
		string S;
		for (size_t i = 0; i < P[0]; i++)S += '(';
		S += ')';
		for (size_t i = 1; i < Pn; i++)
		{
			for (size_t j = 0; j < P[i] - P[i - 1]; j++)S += '(';
			S += ')';
		}
		//		cout << S;
		for (size_t i = 0; i < S.length(); i++)
		{
			if (S[i] == ')')
			{
				int rp = 0, balan = 0;
				for (int j = i; j >= 0; j--)
				{
					if (S[j] == ')') {
						balan++;
						rp++;
					}
					else
					{
						balan--;
					}
					if (balan == 0)
					{
						cout << rp << " ";
						break;
					}
				}
			}


		}
		cout << endl;

	}

	return 0;
}
