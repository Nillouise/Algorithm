//�����ص��Ƿ��������

//A Quailty and Playing Cards
//������Ϸֻ�����֣������������п��ܵ�״̬���в��ľ��߼��ɡ�
//��������Ҳ�ǿ����ģ�����Ϊ��������������quailty��д�����Ǽ�
//��Q������ΪA; B(A  B)��S������ΪC; D(C  D)��
//���ǿ���һ�������Q�϶����ȴ�B�ģ���Ϊ�����������Ƶġ�������
//�������ǶԵģ���������˼����
//1. ���B < C����ôһ����Sȫʤ��
//	2. ����C  B < D�����A < C����ôҲһ����Sȫʤ������C  A��
//	Ӧ����Q��Aʤ��S��Dʤ���������A = C�����Ƿ�������Qδ��
//	���ȳ�Bȥ��SӮ��һ�֣���Ϊ��������������S��һ��ҲӮ����ô��
//	ʱQ���ȳ�A������B = C��ʱ��Ҳ��Ҫ���۵ģ���Ϊ���ʱ��S����
//	��ȫʤ��
//	3. ���A < D  B����Q��Bʤ��S��Dʤ��
//	4. ʣ�µ��������Q��ȫʤ��
//	�������⵽���ﻹ��û�н�������ΪAce�����������ģ�����÷�
//	��1������������ʱ�����Ҫ�����Aceǿ������Ի�ø��ߵĵ÷֡����
//	��Ҫ����B��D����Ace��������������ǻ�Ҫ����AΪAce�������������
//	����������������ˡ�

#include <iostream>
#include <cstdio>
#include <cstring>
#include<string>
#include <algorithm>
#include<sstream>
#include<cmath>//������log ����
using namespace std;
const int maxn = 50000 + 5;
int L, N, M;
int dist[maxn];
string comp = "23456789TJQKA";
string score = "A23456789TJQK";
string conver(string poker)
{
	string r;
	r += poker[0];
	return r;
}

int cal(string Q1, string T1, string Q2, string T2)
{
	int r = 0;
	if ((int)comp.find(Q1) - (int)comp.find(T1) >= 0)
	{
		r += score.find(Q1) + 1;

		if ((int)comp.find(Q2) - (int)comp.find(T2) >= 0)
		{
			r += score.find(Q2) + 1;
		}
		else {
			r -= score.find(T2) + 1;
		}

	}
	else {
		r -= score.find(T1) + 1;
		if ((int)comp.find(Q2) - (int)comp.find(T2) > 0)
		{
			r += score.find(Q2) + 1;
		}
		else {
			r -= score.find(T2) + 1;
		}
	}
	return r;
}

int main() {
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	while (T--)
	{
		string Q1, Q2, T1, T2;
		cin >> Q1 >> Q2 >> T1 >> T2;
		Q1 = conver(Q1);
		Q2 = conver(Q2);
		T1 = conver(T1);
		T2 = conver(T2);

		int Tturn1 = cal(Q1, T1, Q2, T2);
		int Tturn2 = cal(Q1, T2, Q2, T1);

		int best1 = min(Tturn1, Tturn2);

		Tturn1 = cal(Q2, T1, Q1, T2);
		Tturn2 = cal(Q2, T2, Q1, T1);

		int best2 = min(Tturn1, Tturn2);

		cout << max(best1, best2) << endl;

	}

	return 0;
}