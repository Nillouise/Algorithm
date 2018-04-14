#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int N,K;

int dp[10000+200];
vector<pair<int,int>> G;
int dfs(int x)
{
    if(dp[x]!=0x3f3f3f3f)
    {
        // cout<<"ok"<<endl;//
        return dp[x];
    }
    // cout<<"first"<<G[x].first<<" "<<G[x].second<<endl;//
    int flag=0;
    for(int i=x+1;i<G.size();i++)
    {
        if(G[x].first+G[x].second-1< G[i].first)
        {
            for (int j = i; j < G.size(); j++) {
                if(G[j].first!=G[i].first)break;
                dp[x] = min(dp[x],dfs(j)+G[x].second);
                flag=1;
            }
            break;
        }
    }
    if(flag==0)
    {
        return dp[x] = G[x].second;
    }
    return dp[x];
}


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    cin>>N>>K;
    memset(dp,0x3f3f3f3f,sizeof(dp));
    for (int i = 0; i < K; i++) {
        int a,b;cin>>a>>b;
        G.push_back({a,b});
    }
    sort(G.begin(),G.end());
    int ans = 0x3f3f3f3f;
    
    for (int i = 0; i < K; i++) {
        if(G[i].first!=G[0].first)break;
        ans = min(ans,dfs(i));
        // ans = dfs(i);
        // cout<<ans<<endl;//
    }
    cout<<N-ans<<endl;//
    
    
    
    return 0;
}