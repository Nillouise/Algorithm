//#include "FenZhiXianJie.h"
//#include<algorithm>
//#include<iostream>
//#include<queue>
//#include<set>
//using namespace std;
//
//
//
//
//
//class setToPredict
//{
//public:
//	int haveScore;
//	int predictScore;
//	int layerToBegin;
//	int PQ[100];
//
//	bool operator<(setToPredict&z)
//	{
//		if (predictScore == z.predictScore)
//		{
//			if (layerToBegin == z.layerToBegin)
//			{
//				int ok = 0;
//				int i=0;
//				for ( i = 0; i < 100; i++) 
//				{
//					if (PQ[i] != z.PQ[i])
//					{
//						ok = 1;
//						break;
//					}
//					i++;
//				}
//				if (ok==1)
//				{
//					return PQ[i - 1] < z.PQ[i - 1];
//				}
//				else {
//					return false;
//				}
//			}
//			else {
//				return layerToBegin < z.layerToBegin;
//			}
//		}
//		else {
//			return predictScore < z.predictScore;
//		}
//	}
//
//	void operator==(setToPredict&z)
//	{
//		for (int i = 0; i < 100; i++)
//		{
//			PQ[i] = z.PQ[i];
//		}
//		haveScore = z.haveScore;
//		predictScore = z.predictScore;
//		layerToBegin = z.layerToBegin;
//	}
//	setToPredict()
//	{
//		layerToBegin = 0;
//		haveScore = 0;
//		predictScore = 1 << 31 - 1;
//		memset(PQ, -1, sizeof(PQ));
//	}
//	void calScore()
//	{
//		for (int i = 0; i < Pshu; i++)
//		{
//			if (PQ[i] >= 0)
//			{
//				haveScore += P[PQ[i]][i] * Q[i][PQ[i]];
//			}
//		}
//		predictScore = haveScore;
//		for (size_t i = layerToBegin; i < Pshu; i++)
//		{
//			int maxXing = 0;
//			for (size_t j = 0; j < Pshu; j++)
//			{
//				if (PQ[j] < 0)
//				{
//					if (maxXing < P[i][j] * Q[j][i])
//						maxXing = P[i][j] * Q[j][i];
//				}
//			}
//			predictScore += maxXing;
//		}
//	}
//};
//int Pshu;
//int Qshu;
//int PQbfs()
//{
//	priority_queue<setToPredict> q;
//	for (int i = 0; i < Pshu; i++)
//	{
//		setToPredict s1; s1.PQ[i] = 0;
//		s1.layerToBegin++;
//		s1.calScore();
//		q.push(s1);
//	}
//	int havescoreMax = 0;
//	setToPredict maxzuhe;
//	while (!q.empty())
//	{
//		setToPredict s = q.top();
//		q.pop();
//		if (havescoreMax > s.predictScore)
//			continue;
//		else if (s.haveScore > havescoreMax)
//		{
//			havescoreMax = s.haveScore;
//			maxzuhe = s;
//		}
//		for (int i = 0; i < Pshu; i++)
//		{
//			if (s.PQ[i] == 0)
//			{
//				setToPredict s1; 
//				s1 = s;
//				s1.PQ[i] = s1.layerToBegin;
//				s1.layerToBegin++;
//				s1.calScore();
//				q.push(s1);
//			}
//		}
//
//
//	}
//	return maxzuhe.haveScore;
//
//}
//
//FenZhiXianJie::FenZhiXianJie()
//{
//}
//
//
//FenZhiXianJie::~FenZhiXianJie()
//{
//}
//
//int P[100][100];
//int Q[100][100];
//
//int FenZhiXianJie::run()
//{
//	int P[100][100];
//	int Q[100][100];
//
//
//	return 0;
//}
