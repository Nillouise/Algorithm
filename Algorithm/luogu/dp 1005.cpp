#include<bits/stdc++.h>
using namespace std;
typedef __int128 LL;// 注意这里,高精度

LL dp[100][100];
long long dat[100][100];
int n,m;
LL two[200];



// int dfs(int b,int e,int t)//一开始还写成这个屌样
LL dfs(int b,int e,int t)
{
    LL one =  1;
    if(dp[b][e]!=-1)
    {
        if(b==e)return dp[b][e]*two[t];
        return dp[b][e];
    }
    LL ans = two[t]*dp[b][b] + dfs(b+1,e,t+1);
    ans = max(ans, two[t]*dp[e][e] + dfs(b,e-1,t+1) );
    
    return dp[b][e] = ans;
}


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    two[0]=1;
    for (int i = 1; i < 200; i++) {
        two[i]=two[i-1]*2;
    }
    
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        for (int j = 0; j < m; j++) {
            cin>>dat[i][j];
        }
    }
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        memset(dp,-1,sizeof(dp));
        for(int j=0;j<m;j++)
        {
            dp[j][j] = dat[i][j];
        }
        ans+=dfs(0,m-1,1);
        // cout<<dfs(0,m-1,1)<<endl;
    }
    string s;
    while(ans)
    {
        s=to_string(int(ans%10))+s;
        ans/=10;
    }
    if(s.empty())cout<<"0"<<endl;
    else cout<<s<<endl;
    return 0;
}