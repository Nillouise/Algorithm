#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int G[200][200];
int vis[200];
int t;
int n,m;
int path[200];
int dfs(int u)
{
    vis[u]=-1;
    //这里的i用v代替会比较好
    for (int i = 1; i <= n; i++) {
        if(G[u][i])
        {
            if(vis[i]==-1)return 0;
            if(vis[i]==0&&!dfs(i))return 0;
        }
    }
    vis[u]=1;
    path[--t]=u;
    return 1;
}


int main()
{
    freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    

    while(cin>>n>>m,!(n==0&&m==0))
    {
        memset(G,0,sizeof(G));
        memset(vis,0,sizeof(vis));
        memset(path,0,sizeof(path));
        for (int i = 0; i < m; i++) {
            int u,v;
            cin>>u>>v;
            G[u][v]=1;
        }
        t=n;
        for (int i = 1; i <=n; i++) 
        {
            //这里要在判断一下节点有没有被访问过
            if(vis[i]==0)
            if(!dfs(i))
            {
                
            }
        }
        for (int i = 0; i < n; i++) {
            cout<<path[i];
            if(i!=n-1)cout<<" ";
        }
        cout<<endl;
    }
    
    
    
    return 0;
}
