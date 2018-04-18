#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL dp[30][20];
int vis[30][20];
int vec[30];


LL dfs(int x,int pre,int leadzero,int limit)
{
    if(x==-1)return 1;
    if(limit==0&&leadzero==0&&vis[x][pre]==1){
        return dp[x][pre];
    }
    if(limit==0&&leadzero==0){
        vis[x][pre] = 1;
    }
    int up = limit==0?9:vec[x];
    LL sum = 0;
    for (int i = 0; i <= up; i++) {
        if(leadzero==1||abs(i-pre)>=2)
        {
            sum += dfs(x-1,i,leadzero&&(i==0),limit&&(i==vec[x]) );
        }
    }
    
    
    if(limit==0&&leadzero==0)
    {
        dp[x][pre] = sum;
    }
    return sum;
}
LL solve(LL x)
{
    memset(vec,0,sizeof(vec));
    memset(vis,0,sizeof(vis));
    memset(dp,0,sizeof(dp));
    int pos = 0;
    while(x){
        vec[pos++]=x%10;
        x/=10;
    }
    return dfs(pos-1,-3,1,1);
}


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    LL a,b;cin>>a>>b;if(a>b)swap(a,b);
    cout<<solve(b)-solve(a-1)<<endl;//
    
    
    return 0;
}