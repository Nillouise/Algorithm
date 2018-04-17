#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL dat[400][400];
LL cle[400][400];
LL key[400],val[400];
LL dp[400];
LL vis[400];
int n;

LL dfs(int x)
{
    if(x==n)return 0;
    if(vis[x])return dp[x];
    vis[x]=1;
    
    for (int i = x; i < n; i++) {
        if(cle[x][i]==1)
        {
            dp[x] =max(dat[x][i]+ dfs(i+1),dp[x]);
        }else{
            dp[x] = max(dfs(i+1),dp[x]);
        }
    }
    return dp[x];
}


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    int T;cin>>T;
    while(T--)
    {
        cin>>n;
        memset(cle,0,sizeof(cle));
        memset(dp,0,sizeof(dp));
        memset(dat,0,sizeof(dat));
        memset(vis,0,sizeof(vis));
        for (int i = 0; i < n; i++) {
            cin>>key[i];
        }
        for (int i = 0; i < n; i++) {
            cin>>val[i];
        }
        for (int i = 0; i < n; i++) {
            dat[i][i] = val[i];
            for (int j = i+1; j < n; j++) {
                dat[i][j]=dat[i][j-1]+val[j];
            }
        }
        
        for (int k = 1; k < n; k++) {
            for (int i = 0; i+k < n; i++) {
                if((k==1|| cle[i+1][i+k-1]==1)&&__gcd(key[i],key[i+k])!=1)
                {
                    cle[i][i+k]=1;
                    // cout<<"cle "<<i<<" "<<i+k<<endl;//
                }else{
                    //这里区间合并一开始漏了
                    for (int j = i+1; j < i+k; j++) {
                        if(cle[i][j]&&cle[j+1][i+k])
                        {
                            cle[i][i+k]=1;
                        }
                    }
                }
            }
        }
        cout<<dfs(0)<<endl;
        
        
    }
    
    
    
    return 0;
}