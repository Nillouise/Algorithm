#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,L;
vector<int> G[2000];
int vis[2000];
int cnt=0;

int dfs(int r,int dep)
{
    if(dep>L)return 0;
    if(vis[r]==0){cnt++;vis[r]=1;}
    for(auto a:G[r])
    {
        dfs(a,dep+1);
    }
    return 0;
}

int main()
{
    freopen("input.txt","r",stdin);//
    cin>>n>>L;
    for (int i = 1; i <= n; i++) {
        int m;
        cin>>m;
        for (int j = 0; j < m; j++) {
            int a;
            cin>>a;
            G[a].push_back(i);
        }
    }
    int k;
    cin>>k;
    for (int i = 0; i < k; i++) {
        int r;
        cin>>r;
        memset(vis,0,sizeof(vis));
        cnt=0;
        dfs(r,0);
        cout<<cnt-1<<endl;
    }
    
    

    return 0;
}
