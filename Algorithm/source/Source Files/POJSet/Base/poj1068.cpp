//�ַ���Ŀ�������������û���μ�ÿ�������ĺ��������Ŀ����ϵ
//����Pn����ĺ����� P-sequence ����Ŀ��������������������ַ��� ��С,�����debugʱ��Ȼû�е�һʱ�䷴Ӧ������
//forѭ����ǰ�˳���û��break�����϶�������Ϊ�߽�����д����
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
