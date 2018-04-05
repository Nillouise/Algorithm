#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


int T,M;
int w[10000+100],v[10000+100];
vector<int> dp[10000+100];


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    cin>>T>>M;
    for(int i=0;i<M;i++)
    {
        cin>>w[i]>>v[i];
        dp[i].resize(T+5);
    }

    for(int i=0;i<=T;i++)
    {
        if(i%w[0]==0)
        {
            dp[0][i]=v[0]*(i/w[0]);
        }
    }
    
    for(int i=0;i<M;i++)
    {
        for(int j=w[i];j<=T;j++)
        {
            dp[0][j] = max(dp[0][j],dp[0][j-w[i]]+v[i]);//这种题目是可以滚动的，月就是越滚越大。
        }
        
        // int pre=-1;
        // for(int j=0;j<=T;j++)
        // {
        //     if(dp[i][j]>pre)
        //     {
        //         pre=dp[i][j];
        //         for(int k=0;k*w[i+1]+j<=T;k++)
        //         {
        //             // cout<<k<<" "<<k*w[i+1]+j<<endl;//
        //             if(dp[i+1][j+k*w[i+1]]<dp[i][j]+k*v[i+1]) dp[i+1][j+k*w[i+1]] = dp[i][j]+k*v[i+1];
        //         }
        //     }
        // }
    }
    int ans=0;
    for(int i=T;i>0;i--)
    {
        // cout<<dp[M-1][i]<<endl;//
        if(dp[0][i]>ans)ans=dp[0][i];
    }
    cout<<ans<<endl;
    
    return 0;
}