#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int N,M;
int G[3000][3000];
int dp[3000][3000];
int tmp[3000][3000];
// 奇偶性在这题里很重要的
int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    cin>>N>>M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin>>G[i][j];
        }
    }
    
    for (int i = 0; i < M; i++) {
        dp[i][i] = 1;
        for (int j = i+1; j < M; j++) {
            if(G[0][j]!=G[0][j-1])
            {
                dp[i][j] = 1;
            }else{
                break;
            }
        }
    }
    // for (int i = 0; i < M; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;//
    // }
    
    int squ = 0;
    int ran = 0;
    
    for (int t = 1; t < N; t++) {
        int i,j;
        memcpy(tmp,dp,sizeof(dp));
        for (i = 0; i < M; i++) {
            int flag=0;
            for (j = i; j < M; j++) {
                if((i!=j && (G[t][j]==G[t][j-1]))) { break;}
                dp[i][j] = 1;
                
                if(G[t][j] == G[t-1][j])
                {
                    flag=1;
                }else if(flag==0)
                {
                    dp[i][j] = max(tmp[i][j]+1,dp[i][j]);
                }
                
                
                squ = max(squ,min(j-i+1,dp[i][j]));
                ran = max(ran,dp[i][j]*(j-i+1));
            }
            // for (int k = i; k < j; k++) {
            //     dp[k][j-flag] = max(dp[k][j-flag],dp[i][j-flag]);
            // }
        }
        // memcpy(dp,tmp,sizeof(dp));//这里写了句弱智东西坑自己
    }
    // for (int i = 0; i < M; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;//
    // }
    

    // for (int i = 0; i < M; i++) {
    //     for (int j = i; j < M; j++) {
    //         squ = max(squ,min((j-i+1),dp[i][j]));
    //         ran = max(ran,(j-i+1)*dp[i][j]);
    //     }
    // }
    
    
    cout<<squ*squ<<endl;
    cout<<ran<<endl;
    
    
    return 0;
}