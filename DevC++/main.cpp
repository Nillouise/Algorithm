#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int dat[20000];
int tac[20000];
int dp[20000];


int main() {
	int T;cin>>T;
	while(T--)
	{
		int n;cin>>n;
		for(int i=0;i<n-1;i++)
		{
			cin>>dat[i+1];
		}
		for(int i=0;i<n-2;i++)
		{
			tac[i+1] = dat[i+2]-dat[1]; 
		}
		
		int top = n-2;
		memset(dp,-0x3f3f,sizeof(dp));
		dp[0] = 0;
		for(int i=1;i<=n-2;i++)
		{
			for(int j = top;j>=i;j--)
			{
				for(int k = 1;j-k*i>=0;k++)
				{
					dp[j] = max(dp[j],dp[j-k*i] +tac[i]*k);
				}
			}
		}
		
		cout<<dat[1]*n + dp[n-2]<<endl;
	}
}
