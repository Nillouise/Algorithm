#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int dp[30][2];
int vis[30][2];
int vec[30];
int dfs(int x,int pre,int limit)
{
    if(x==-1)return 1;
    if(limit==0&&vis[x][pre==6]){
        return dp[x][pre==6];
    }
    vis[x][pre==6]=true;
    
    int up = limit==1?vec[x]:9;
    int sum = 0;
    for (int i = 0; i <= up; i++) {
        if(i!=4 && (!(pre==6&&i==2)))
            sum +=dfs(x-1,i,limit&&(i==vec[x]));
        
    }
    if(limit==0)dp[x][pre==6]=sum;
    
    return sum;
}

int solve(LL x)
{
    int pos = 0;
    while(x){
        vec[pos++]=x%10;
        x/=10;
    }
    return dfs(pos-1,-1,1);
}


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int le,ri;
    while(cin>>le>>ri){
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        cout<<solve(ri)-solve(le-1)<<endl;
    }
    return 0;
}