#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;

int len[20000];
vector<int> G[20000];
int t[20000];

int dfs(int x)
{
    if(t[x]!=-1)return t[x];
    
    int ans=0;
    for(auto a:G[x])
    {
        ans = max(ans,dfs(a));
    }
    return t[x] = ans+len[x];
}



int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    cin>>n;
    memset(t,-1,sizeof(t));
    for (int i = 0; i < n; i++) {
        int x,t,nxt;
        cin>>x>>t;
        len[x-1]=t;
        while(cin>>nxt&&nxt!=0)
        {
            G[x-1].push_back(nxt-1);
        }
    }
    for(int i=0;i<n;i++)dfs(i);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans,t[i]);
    }
    cout<<ans<<endl;//
    
    return 0;
}