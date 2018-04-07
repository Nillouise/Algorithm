#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int N,M;

vector<pair<int,int>> G[4000];
int dp[4000][4000];
int tmp[4000];
int val[4000];
int human[4000];
int vis[4000];
int dfs(int x)
{
    if(vis[x])
    {
        return 0;
    }
    vis[x]=1;
    // cout<<"x="<<x<<endl;//
    if(G[x].size()==0)
    {
        // cout<<"node"<<x<<" "<<val[x]<<endl;
        return dp[x][1] = val[x];
    }
    

    for (int i = 0; i < G[x].size(); i++) {
                auto &e = G[x][i];
        //一开始我把memcpy写在这里，而tmp是全局变量，会被递归使用，导致错误!!!!
        // memcpy(tmp,dp[x],sizeof(tmp));
        dfs(e.first);
        
        memcpy(tmp,dp[x],sizeof(tmp));
        // cout<<"i="<<e.first<<"   ";
        // for(int o=0;o<=3;o++)cout<<"o "<<tmp[o]<<" ";
        // cout<<endl;
        for (int k = human[x]; k>0; k--) {
            int h = human[e.first];
            for(int j=1;j<=h;j++)
            {
                if(k<j)break;
                dp[x][k] = max(dp[x][k],tmp[k-j] +dp[e.first][j]-e.second);
                // cout<<"tmp[k-j]"<<tmp[k-j]<<" k="<<k<<" j="<<j<<endl;//
                // cout<<"dp[x][k]="<<x<<k<<" "<<dp[x][k]<<" cost"<<e.second<<endl;
            }
            // cout<<endl;//
        }
    }
    return 0;
}

int cal(int x)
{
    // cout<<"cal "<<x<<endl;
    if(G[x].size()==0)
    {
        human[x]=1;
        return 1;
    }
    int ans=0;
    for(auto a:G[x])
    {
        ans+=cal(a.first);
    }
    human[x]=ans;
    return ans;
}


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    cin>>N>>M;
    
    for(int i=0;i<N-M;i++)
    {
        int x;
        cin>>x;
        int a,b;
        for (int j = 0; j < x; j++) {
            cin>>a>>b;
            G[i].push_back({a-1,b});
        }
    }
    cal(0);
    for(int i=N-M;i<N;i++)
    {
        cin>>val[i];
    }
    // for(int i=0;i<N-M;i++)
    // {
    //     for(auto a:G[i])
    //     {
    //         cout<<a.first<<" ";
    //     }
    //     cout<<endl;//
    // }
    for(int i=0;i<4000;i++)for(int j=0;j<4000;j++)dp[i][j]=-1e8;
    for(int i=0;i<4000;i++)
    {
        dp[i][0]=0;
    }
    dfs(0);
    int ans=0;
    for(int i=0;i<=M;i++)
    {
        // cout<<dp[0][i]<<" ";
        if(dp[0][i]>=0)ans=i;
    }
    // cout<<"ans = "<<ans<<endl;
    cout<<ans<<endl;
    
    return 0;
}