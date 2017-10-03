////#include <iostream>
////#include<string>
////#include<cstring>
////#include<algorithm>
////#include<vector>
////#include<map>
////#include<set>
////#include<cmath>//这个sqrt要用
////#include<queue>
////using namespace std;
////typedef long long LL;
////LL n, q, c;
////struct star
////{
////	LL init;
////	int x, y;
////
////	bool operator <(star s2)const
////	{
////		return y < s2.y;
////	}
////};
////
////LL getbright(star s, LL t)
////{
////	LL b = s.init + t;
////	b %= c + 1;//光的亮度是0到c，所以c+1才是范围
////	return b;
////}
////vector<star> v[200];
////LL initG[200][200];
////LL G[200][200];
////LL icntG[200][200];
////LL cntG[200][200];
////
////LL solve(int x1, int y1, int x2, int y2, LL t)
////{
////	LL cnt = 0;
////	for (int i = x1; i <= x2; i++)
////	{
////		for (auto a : v[i])
////		{
////			if (a.y < y1)continue;
////			if (a.y > y2)break;
////
////			cnt += getbright(a, t);
////		}
////	}
////	return cnt;
////}
////
////
////LL solve2(int x1, int y1, int x2, int y2, LL t)
////{
////	LL init = G[x2][y2] - G[x1 - 1][y2] - G[x2][y1 - 1] + G[x1 - 1][y1 - 1];
////	LL num = cntG[x2][y2] - cntG[x1 - 1][y2] - cntG[x2][y1 - 1] + cntG[x1 - 1][y1 - 1];
////
////	LL b = (num*t + init) % (c*num + 1);
////
////	return b;
////}
////
////
////int main()
////{
////	freopen("input.txt", "r", stdin);
////	ios::sync_with_stdio(false);
////
////	cin >> n >> q >> c;
////
////	for (size_t i = 0; i < n; i++)
////	{
////		star s;
////		cin >> s.x >> s.y >> s.init;
////		initG[s.x + 1][s.y + 1] += s.init;
////		icntG[s.x + 1][s.y + 1]++;
////		v[s.x].push_back(s);
////	}
////
////	for (int i = 1; i < 100 + 1; i++)
////	{
////		for (int j = 1; j < 100 + 1; j++)
////		{
////			G[i][j] = initG[i][j] + G[i - 1][j] + G[i][j - 1] - G[i - 1][j - 1];
////			cntG[i][j] = icntG[i][j] + cntG[i - 1][j] + cntG[i][j - 1] - cntG[i - 1][j - 1];
////		}
////	}
////
////
////	for (size_t i = 0; i < q; i++)
////	{
////		LL x1, y1, x2, y2, t;
////		cin >> t >> x1 >> y1 >> x2 >> y2;
////		cout << solve2(x1 + 1, y1 + 1, x2 + 1, y2 + 1, t) << endl;
////	}
////
////
////
////
////
////	return 0;
////}
//
//
//
//
//
//
//
//#include <iostream>
//#include<string>
//#include<cstring>
//#include<algorithm>
//#include<vector>
//#include<map>
//#include<set>
//#include<cmath>//这个sqrt要用
//#include<queue>
//using namespace std;
//typedef long long LL;
//LL n, q, c;
//
//LL initG[105][105];
//LL icntG[200][200];
//LL cntG[200][200];
//
//LL GG[11][105][105];
//
//LL solve2(int x1, int y1, int x2, int y2, LL t)
//{
//	t %= c + 1;
//	LL init = GG[t][x2][y2] - GG[t][x1 - 1][y2] - GG[t][x2][y1 - 1] + GG[t][x1 - 1][y1 - 1];
//	LL num = cntG[x2][y2] - cntG[x1 - 1][y2] - cntG[x2][y1 - 1] + cntG[x1 - 1][y1 - 1];
//
//
//	return init;
//}
//
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	ios::sync_with_stdio(false);
//
//	cin >> n >> q >> c;
//
//	for (size_t i = 0; i < n; i++)
//	{
//		int x, y, init;
//		cin >> x >> y >> init;
//		//initG[x + 1][y + 1] += init;
//		//icntG[x + 1][y + 1]++;
//		initG[x][y] += init;
//		icntG[x][y]++;
//	}
//
//	//这里要加到102，因为原本是1开头
//	for (int i = 1; i < 100 + 1; i++)
//	{
//		for (int j = 1; j < 100 + 1; j++)
//		{
//			cntG[i][j] = icntG[i][j] + cntG[i - 1][j] + cntG[i][j - 1] - cntG[i - 1][j - 1];
//		}
//	}
//
//	for (int t = 0; t < 10 + 1; t++)
//	{
//		for (int i = 1; i < 100 + 1; i++)
//		{
//			for (int j = 1; j < 100 + 1; j++)
//			{
//				GG[t][i][j] = initG[i][j] + GG[t][i - 1][j] + GG[t][i][j - 1] - GG[t][i - 1][j - 1];
//			}
//		}
//		for (int i = 1; i < 100 + 1; i++)
//		{
//			for (int j = 1; j < 100 + 1; j++)
//			{
//				if (icntG[i][j] != 0)
//				{
//					initG[i][j]++;
//					initG[i][j] %= c + 1;
//				}
//			}
//		}
//	}
//
//
//	for (size_t i = 0; i < q; i++)
//	{
//		LL x1, y1, x2, y2, t;
//		cin >> t >> x1 >> y1 >> x2 >> y2;
//		cout << solve2(x1, y1, x2, y2, t) << endl;
//	}
//
//
//
//
//
//
//	return 0;
//}