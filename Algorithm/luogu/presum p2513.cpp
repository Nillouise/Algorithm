#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int dp[1010][1010];


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    dp[0][0]=1;
    
    for (int i = 1; i <= n; i++) {
        LL sum = 0;
        for (int j = 0; j <= m; j++) {
            sum= (sum+dp[i-1][j])%10000;
            dp[i][j] = sum;
            if(j-i+1>=0)
            {
                sum = (sum-dp[i-1][j-i+1]+10000)%10000;
            }
            
            
            // for (int k = 0; k < i; k++) {
            //     if(j-k>=0) {
            //         dp[i][j] = (dp[i][j]+ dp[i-1][j-k])%10000;
            //     } 
            // }
        }
    }
    cout<<dp[n][m]<<endl;//
    
    return 0;
}