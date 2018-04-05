#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int M,N;
int dat[10000];
int dp[10000];


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        cin>>dat[i];
    }
    dp[0]=1;
    for (int i = 0; i < N; i++) {
        for(int j=M;j>0;j--)
        {
            if(j>=dat[i])
            {
                dp[j] += dp[j-dat[i]]; 
            }
        }
    }
    cout<<dp[M]<<endl;
    
    return 0;
}