//这题重点是分情况讨论

//A Quailty and Playing Cards
//由于游戏只有两轮，所以搜索所有可能的状态进行博弈决策即可。
//分类讨论也是可做的，以下为控诉无良出题人quailty而写。我们假
//设Q的手牌为A; B(A  B)，S的手牌为C; D(C  D)。
//我们考虑一般情况下Q肯定是先打B的，因为先手是有优势的。我们先
//假设这是对的，继续往下思考。
//1. 如果B < C，那么一定是S全胜。
//	2. 考虑C  B < D，如果A < C，那么也一定是S全胜，否则C  A，
//	应该是Q的A胜，S的D胜。但是如果A = C，我们发现这会儿Q未必
//	会先出B去让S赢第一局，因为这样会送先手让S下一局也赢，那么此
//	时Q会先出A。所以B = C的时候也是要讨论的，因为这个时候S还是
//	会全胜。
//	3. 如果A < D  B，则Q的B胜，S的D胜。
//	4. 剩下的情况就是Q会全胜。
//	但是这题到这里还是没有结束。因为Ace这张牌是最大的，但其得分
//	是1，所以我们有时候可能要让这个Ace强行输掉以获得更高的得分。因此
//	还要讨论B和D都是Ace的情况，其中我们还要讨论A为Ace的情况。到这里
//	这题才终于讨论完了。

#include <iostream>
#include <cstdio>
#include <cstring>
#include<string>
#include <algorithm>
#include<sstream>
#include<cmath>//这里有log 函数
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