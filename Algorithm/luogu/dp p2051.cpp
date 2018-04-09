#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MAXN = 105;
const LL MOD = 9999973;
LL dp[MAXN][MAXN][MAXN];

LL N,M;
LL dat[200][200];
LL C(int x,int y)
{
    // cout<<"C"<<x<<y<<" "<<dat[x][y]<<endl;//
    return dat[x][y];
}

LL dfs(int a,int one,int two)
{
    if(a<0||one<0||two<0)return 0;
    if(dp[a][one][two]!=-1)
        return dp[a][one][two];
    
    LL res = 0;
    res = (res + dfs(a-1,one,two))%MOD;
    // res = (res + C(one,1)* dfs(a-1,one-1,two)%MOD)%MOD;//注意这里的选择组合是错的
    res = (res + C(M-one-two+1,1)* dfs(a-1,one-1,two)%MOD)%MOD;
    res = (res + C(one+1,1)*dfs(a-1,one+1,two-1)%MOD)%MOD;
    res = (res + C(M-one-two+1,1)*C(one,1)* dfs(a-1,one,two-1)%MOD)%MOD;
    res = (res + C(one+2,2)*dfs(a-1,one+2,two-2)%MOD)%MOD;
    res = (res + C(M-one-two+2,2)*dfs(a-1,one-2,two)%MOD)%MOD;
    dp[a][one][two] = res;
    // cout<<"dp"<<a<<one<<two<<" "<<dp[a][one][two]<<endl;//    
    
    return res;
}

int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    for (int i = 0; i < 120; i++) {
        dat[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            dat[i][j] = (dat[i-1][j-1]+dat[i-1][j])%MOD;
        }
    }
    
    
    cin>>N>>M;
    memset(dp,-1,sizeof(dp));
    for (int i = 0; i <= M; i++) {
        for (int j = 0; j+i <= M; j++) {
            dp[0][i][j]=0;
        }
    }
    dp[0][0][0]=1;
    dp[0][1][0]=M;
    dp[0][2][0] = C(M,2);
    LL ans = 0;
    for (int i = 0; i <= M; i++) {
        for (int j = 0; j+i <= M; j++) {
            ans = (ans+dfs(N-1,i,j))%MOD;
            // cout<<i<<j<<" "<<dfs(N-1,i,j)<<endl;//
        }
    }
    cout<<ans<<endl;
    // 
    // for(int k=0;k<N;k++)
    // {
    //     for (int i = 0; i <= M; i++) {
    //         for (int j = 0; j+i <= M; j++) {
    //             // ans = (ans+dfs(N-1,i,j))%MOD;
    //             // cout<<i<<j<<" "<<dfs(N-1,i,j)<<endl;//
    //             cout<<k<<i<<j<<" "<<dp[k][i][j]<<endl;//
    //         }
    //     }
    // }

    
    return 0;
}