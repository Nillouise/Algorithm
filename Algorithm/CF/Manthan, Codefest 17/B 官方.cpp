#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)
#define ll long long
#define mod 1000000007
#define bitcount    __builtin_popcountll
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define pi pair<int,int>
int a[100005];
ll dp[100005][3];
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n, p, q, r, i;
	sd(n);
	sd(p);
	sd(q);
	sd(r);
	for (i = 0; i<n; i++)
		sd(a[i]);
	dp[0][0] = 1ll * p*a[0];
	//这里是把某个节点看做三个数字的结尾，这样就可以算这三个数字中的和的最大值了
	//逻辑形式跟把某个点看成中间的点，不一样
	for (i = 1; i<n; i++)
		dp[i][0] = max(dp[i - 1][0], 1ll * p*a[i]);
	dp[0][1] = dp[0][0] + 1ll * q*a[0];
	for (i = 1; i<n; i++)
		dp[i][1] = max(dp[i - 1][1], dp[i][0] + 1ll * q*a[i]);
	dp[0][2] = dp[0][1] + 1ll * r*a[0];
	for (i = 1; i<n; i++)
		dp[i][2] = max(dp[i - 1][2], dp[i][1] + 1ll * r*a[i]);
	printf("%lld\n", dp[n - 1][2]);
	return 0;
}