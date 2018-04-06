#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,dat[100][2],c;
int dp[1000][2][100][100];
const int INF=1e8;
// 因此设dp[i][j][0]表示在关完第i盏灯到第j盏灯后停在i处的最小耗电量，dp[i][j][1]表示在关完第i盏灯到第j盏灯后停在j处的最小耗电量，lamp[i].m为第i盏灯的距离，sum[i][j]表示在关完第i盏灯到第j盏灯后每s所耗电量,可得状态转移方程：
//这样就不需要考虑用t表示时间了！！！！
int dfs(int t,int side,int b,int e)
{
    if(t<0)return INF;
    if(b>c)return INF;
    if(e<c)return INF;
    if(b==e&&b==c)return 0;
    if(dp[t][side][b][e]!=INF)
    {
        return dp[t][side][b][e];
    }
    // printf("%d %d %d %d\n",t,side,b,e);
    
    
    int ans = INF;
    if(side==1)
        ans = min(ans,dfs(t-(dat[e][0]-dat[e-1][0]),1,b,e-1)+t*dat[e][1]);
    int path =0;
    path = dat[e][0]-dat[b][0];
    if(side==1)
    ans = min(ans,dfs(t-path,0,b,e-1)+t*dat[e][1] );
    if(side==0)
    ans = min(ans,dfs(t-(dat[b+1][0]- dat[b][0]),0,b+1,e)+t*dat[b][1]);
    if(side==0)
    ans = min(ans,dfs(t-path,1,b+1,e)+t*dat[b][1]);
    dp[t][side][b][e] = ans;
    return dp[t][side][b][e];
}


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    cin>>n>>c;
    c--;
    for (int i = 0; i < n; i++) {
        cin>>dat[i][0]>>dat[i][1];
    }
    for(int i=0;i<1000;i++)
    {
        for (int j = 0; j < 100; j++) {
            for (int k = 0; k < 100; k++) {
                dp[i][0][j][k]=INF;
                dp[i][1][j][k]=INF;
            }
        }
    }
    int ans = INF;
    // ans = min(ans,dfs(6,1,0,n-1));
    for(int i=0;i<100;i++)
    {
        ans = min(ans,dfs(i,0,0,n-1));
        ans = min(ans,dfs(i,1,0,n-1));
        // cout<<i<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
    
    
    return 0;
}