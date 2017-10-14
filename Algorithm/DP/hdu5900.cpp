#include<iostream>
#include<list>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>

using namespace std;

//这么写是错的，因为我把DP[i][j]设为i到j都要能消除才有价值，那么之后就要处理这种不连续的能被消去的区间
const int maxn = 500;
long long k[maxn];
long long v[maxn];

long long DP[maxn][maxn];
long long gcd2(long long a, long long b)
{
	if (a == 0)return b;
	return gcd2(b%a, a);
}
long long gcd(long long a, long long b)
{
	return gcd2(a, b)>1 ? 1 : 0;
}
int main()
{
#ifdef LOCAL 
	cout << "fdsfsd" << endl;
#endif 
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;
		for (int i = 0; i<N; i++)scanf("%lld", &k[i]);
		for (int i = 0; i<N; i++)scanf("%lld", &v[i]);
		//		memset(DP,0,sizeof(0));
		memset(DP, 0, sizeof(DP));
		//		for(int i=0;i<N;i++)DP[i][i]=v[i];
		long long MAX = 0;
		//		for(int len = 1;len<N;len++)
		for (int len = 1; len<N; len += 2)
		{
			for (int i = 0; i + len<N; i++)
			{
				int j = len + i;
				//				if(gcd(k[i],k[j])&&(DP[i+1][j-1]>0 ) )
				if (gcd(k[i], k[j]) && (DP[i + 1][j - 1]>0 || i + 1 >= j - 1))
				{
					DP[i][j] = max(DP[i][j], DP[i + 1][j - 1] + v[i] + v[j]);
				}
				else {
					for (int e = i + 1; e<j; e++)
					{
						//						if(gcd(k[i],k[e])&&gcd(k[e+1],k[j])&&DP[i][e]>0&&DP[e+1][j]>0)
						if (DP[i][e]>0 && DP[e + 1][j]>0)
						{
							DP[i][j] = max(DP[i][j], DP[i][e] + DP[e + 1][j]);
						}
					}
				}
				MAX = max(MAX, DP[i][j]);
			}
		}
		cout << MAX << endl;
	}

	return 0;
}


#include<iostream>
#include<list>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 500;
long long k[maxn];
long long v[maxn];
long long sum[maxn];
long long DP[maxn][maxn];
long long gcd2(long long a, long long b)
{
	if (a == 0)return b;
	return gcd2(b%a, a);
}
long long gcd(long long a, long long b)
{
	return gcd2(a, b)>1 ? 1 : 0;
}
int main()
{
#ifdef LOCAL 
	cout << "fdsfsd" << endl;
#endif 
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;
		sum[0] = 0;
		for (int i = 1; i <= N; i++)scanf("%lld", &k[i]);
		for (int i = 1; i <= N; i++) {
			scanf("%lld", &v[i]);
			sum[i] = sum[i - 1] + v[i];
		}
		//		memset(DP,0,sizeof(0));
		memset(DP, 0, sizeof(DP));
		//		for(int i=0;i<N;i++)DP[i][i]=v[i];
		long long MAX = 0;
		//		for(int len = 1;len<N;len++)
		//		for(int len = 1;len<N;len+=2)
		for (int len = 1; len<N; len++)//这里的len必须只加1 
		{
			for (int i = 1; i + len <= N; i++)
			{
				int j = len + i;
				//				if(gcd(k[i],k[j])&&(DP[i+1][j-1]>0 ) )
				//				if(gcd(k[i],k[j])&&(DP[i+1][j-1]>0||i+1>=j-1 ) )
				if (gcd(k[i], k[j]) && DP[i + 1][j - 1] == sum[j - 1] - sum[i])
				{
					DP[i][j] = max(DP[i][j], DP[i + 1][j - 1] + v[i] + v[j]);
				}
				else {
					//这里是枚举分界，分界的两边 可能有一边不是能消除的区间，只是单个数 
					//这里这么写，j就可能是单个数了 
					for (int e = i + 1; e<j; e++)
						//					for(int e=i;e<j;e++)
					{
						//						if(gcd(k[i],k[e])&&gcd(k[e+1],k[j])&&DP[i][e]>0&&DP[e+1][j]>0)
						//						if(DP[i][e]==sum[e]-sum[i-1]&&DP[e+1][j])
						{
							DP[i][j] = max(DP[i][j], DP[i][e] + DP[e + 1][j]);
						}
					}
				}
				MAX = max(MAX, DP[i][j]);
			}
		}
		cout << MAX << endl;
	}

	return 0;
}