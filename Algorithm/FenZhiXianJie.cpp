#include "FenZhiXianJie.h"
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
using namespace std;


int Pshu;
int Qshu;

int P[100][100];
int Q[100][100];

class setToPredict
{
public:
	int haveScore;
	int predictScore;
	int layerToBegin;
	int PQ[100];

	bool operator<(const  setToPredict&z)const
	{
		if (predictScore == z.predictScore)
		{
			if (layerToBegin == z.layerToBegin)
			{
				int ok = 0;
				int i = 0;
				for (i = 0; i < Pshu; i++)
				{
					if (PQ[i] != z.PQ[i])
					{
						ok = 1;
						break;
					}
				}
				if (ok == 1&&i!= Pshu)
				{
					return PQ[i ] < z.PQ[i ];
				}
				else {
					return false;
				}
			}
			else {
				return layerToBegin < z.layerToBegin;
			}
		}
		else {
			return predictScore < z.predictScore;
		}
	}

	setToPredict& operator=(setToPredict&z)
	{
		for (int i = 0; i < 100; i++)
		{
			PQ[i] = z.PQ[i];
		}
		haveScore = z.haveScore;
		predictScore = z.predictScore;
		layerToBegin = z.layerToBegin;
		return *this;
	}
	setToPredict()
	{
		layerToBegin = 0;
		haveScore = 0;
		predictScore = 1 << 31 - 1;
		memset(PQ, -1, sizeof(PQ));
	}
	void calScore()
	{
		haveScore = 0;
		for (int i = 0; i < Pshu; i++)
		{
			if (PQ[i] >= 0)
			{
				haveScore += P[i][PQ[i]] * Q[PQ[i]][i];
			}
		}
		predictScore = haveScore;
		for (size_t i = layerToBegin; i < Pshu; i++)
		{
			int maxXing = 0;
			for (size_t j = 0; j < Pshu; j++)
			{
				if (PQ[j] < 0)
				{
					if (maxXing < P[i][j] * Q[j][i])
						maxXing = P[i][j] * Q[j][i];
				}
			}
			predictScore += maxXing;
		}
	}
};

int PQbfs()
{
	priority_queue<setToPredict> q;
	for (int i = 0; i < Pshu; i++)
	{
		setToPredict s1; s1.PQ[i] = 0;
		s1.layerToBegin++;
		s1.calScore();
		q.push(s1);
	}
	int havescoreMax = 0;
	setToPredict maxzuhe;
	while (!q.empty())
	{
		setToPredict s = q.top();
		q.pop();
		if (havescoreMax > s.predictScore)
			continue;
		else if (s.haveScore > havescoreMax)
		{
			havescoreMax = s.haveScore;
			maxzuhe = s;
		}
		for (int i = 0; i < Pshu; i++)
		{
			if (s.PQ[i] == -1)
			{
				setToPredict s1;
				s1 = s;
				s1.PQ[i] = s1.layerToBegin;
				s1.layerToBegin++;
				s1.calScore();
				q.push(s1);
			}
		}
	}
	//for (int i = 0; i < Pshu; i++)
	//	cout << maxzuhe.PQ[i]<<" ";
	//cout << endl;
	return maxzuhe.haveScore;

}




int FenZhiXianJie::run()
{
	cout << "男运动员人数：";
	cin >> Pshu;
	cout << "女运动员人数：";
	cin >> Qshu;
	for (int i = 0; i < Pshu; i++)
		for (int j = 0; j < Qshu; j++)
			cin >> P[i][j];
	for (int i = 0; i < Qshu; i++)
		for (int j = 0; j < Pshu; j++)
			cin >> Q[i][j];
	int optimum = PQbfs();
	cout << optimum;

	return optimum;
}
