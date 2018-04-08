#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
int dat[200000+100];
int vis[200000+100];
int dep[200000+100];
int ans = 1e8;
int dfs(int x,int d)
{
    if(vis[x]==1)
    {
        return 0;
    }
    // cout<<x+1<<endl;//
    if(dep[x]!=-1)
    {
        ans=min(ans,d-dep[x]);
        vis[x]=1;
        dep[x] = d;
        return 0;
    }
    dep[x]=d;
    dfs(dat[x],d+1);
    vis[x]=1;
    return 0;
}


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    cin>>n;
    memset(dep,-1,sizeof(dep));
    for (int i = 0; i < n; i++) {
        cin>>dat[i];
        dat[i]--;
    }
    // dfs(0,0);
    for (int i = 0; i < n; i++) {
        dfs(i,0);
    }
    cout<<ans<<endl;
    
    
    return 0;
}