#include<bits/stdc++.h>
using namespace std;
typedef int LL;

int n,m,k;
int dat[1000][1000];
// LL dp[1000][1000][20][20];//这样太大了
LL dp[801][801][20][2];
int MOD = 1000000007;

int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    cin>>n>>m>>k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>dat[i][j];
            dat[i][j]%=(k+1);
        }
    }
    for(int i=0;i<n;i++)
    {
        for (int j = 0; j < m; j++) {
            dp[i][j][dat[i][j]][0] = 1;
        }
    }
    
    
    for(int i=0;i<n;i++)
    {
        for (int j = 0; j < m; j++) {
            for (int o = 0; o <= k; o++) {
                for(int t = 0;t<2;t++)
                {
                    int cur = dp[i][j][o][t];
                    // cout<< i<<" "<<j<<" "<<" o="<<o<<" t="<<t<<" "<<cur<<" "<<endl;
                    int d = dat[i+1][j];
                    int d2 = dat[i][j+1];
                    LL *right,*down;
                    if(t==0)
                    {
                        right = &dp[i+1][j][(o - d + (k+1))%(k+1)][1];
                        down = &dp[i][j+1][(-d2+o+(k+1))%(k+1)][1];
                    }else{
                        right = &dp[i+1][j][(o + d+(k+1))%(k+1)][0];
                        down = &dp[i][j+1][(d2+o+(k+1))%(k+1)][0];
                    }
                    *right=(*right+ cur)%MOD;
                    *down = (*down+cur)%MOD;
                }
                // cout<<endl;
            }
        }
    }
    long long ans = 0;
    for(int i=0;i<n;i++){
        for (int j = 0; j < m; j++) {
            // cout<<dp[i][j][0][1]<<endl;//
                ans = (ans+dp[i][j][0][1])%MOD;    
        }
    }
    cout<<ans<<endl;
    
    return 0;
}