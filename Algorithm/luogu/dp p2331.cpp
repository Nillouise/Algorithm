#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int n,m,k;
int dat[200][2];
int dp[200][8][15];
const int maxn=105;
const int maxk=11;
int f[maxn][maxk][5];
int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    // ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>dat[i][j];
        }
    }
    memset(dp,-0x3f3f3f,sizeof(dp));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][0][j] = 0;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            //不选矩形
            for (int t = 0; t < 8; t++) {
                dp[i][0][j] = max(dp[i][0][j], dp[i-1][t][j]);
            }
            //选左边
            dp[i][2][j] = max(dp[i][2][j] ,dp[i-1][0][j-1]+dat[i][1]);
            dp[i][2][j] = max(dp[i][2][j], dp[i-1][2][j]+dat[i][1]);
            dp[i][2][j] = max(dp[i][2][j], dp[i-1][1][j-1]+dat[i][1]);
            dp[i][2][j] = max(dp[i][2][j],  dp[i-1][3][j-1]+dat[i][1]);
            dp[i][2][j] = max(dp[i][2][j], dp[i-1][7][j]+dat[i][1]);
            
            //选右边
            dp[i][1][j] = max(dp[i][1][j],dp[i-1][0][j-1]+dat[i][0]);
            dp[i][1][j] = max(dp[i][1][j],dp[i-1][1][j] + dat[i][0]);
            dp[i][1][j] = max(dp[i][1][j],dp[i-1][2][j-1]+dat[i][0]);
            dp[i][1][j] = max(dp[i][1][j],dp[i-1][3][j-1]+dat[i][0]);
            dp[i][1][j] = max(dp[i][1][j],dp[i-1][7][j]+dat[i][0]);
            
            int shu = dat[i][0]+dat[i][1];
            //选左右
            dp[i][3][j] = max(dp[i][3][j],dp[i-1][0][j-1]+shu);
            dp[i][3][j] = max(dp[i][3][j],dp[i-1][1][j-1]+shu);
            dp[i][3][j] = max(dp[i][3][j],dp[i-1][2][j-1]+shu);
            dp[i][3][j] = max(dp[i][3][j],dp[i-1][3][j]+shu);
            dp[i][3][j] = max(dp[i][3][j],dp[i-1][7][j-1]+shu );
            
            //左右分开选
            if(j>=2)
            dp[i][7][j] = max(dp[i][7][j],dp[i-1][0][j-2]+shu);
            dp[i][7][j] = max(dp[i][7][j],dp[i-1][1][j-1]+shu);
            dp[i][7][j] = max(dp[i][7][j],dp[i-1][2][j-1]+shu);
            dp[i][7][j] = max(dp[i][7][j],dp[i-1][3][j-2]+shu);
            dp[i][7][j] = max(dp[i][7][j],dp[i-1][7][j]+shu);
        }
    }
    int ans = 0;
    for (int i = 0; i < 8; i++) {
        ans = max(ans,dp[n][i][k]);
    }
    cout<<ans<<endl;//
    
    
    return 0;
}