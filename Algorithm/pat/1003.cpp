#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int n,m,c1,c2;
int dist[700];
struct Edge
{
    int u,v,dist;
};
vector<Edge> edges;
vector<int> G[700];
int pathcnt= 0;
void addedge(int u,int v,int d)
{
    G[u].push_back(edges.size());
    edges.push_back({u,v,d});
    G[v].push_back(edges.size());
    edges.push_back({v,u,d});
}

int vectex[700];
int MAX = 0;
int dfs(int x,int sum)
{
    if(x == c2)
    {
        if(sum>MAX)MAX=sum;
        pathcnt++;
        return 0;
    }
    for(auto a:G[x])
    {
        Edge e = edges[a];
        if(dist[e.u]-e.dist == dist[e.v])
        {
            dfs(e.v,sum+vectex[e.v]);
        }
    }
    return 0;
}

int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    cin>>n>>m>>c1>>c2;
    for (int i = 0; i < n; i++) 
    {
        cin>>vectex[i];
    }
    for (int i = 0; i < m; i++) 
    {
        int u,v,d;
        cin>>u>>v>>d;
        addedge(u,v,d);
    }
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>> >pq;
    pq.push({0,c2});
    memset(dist,0x3f3f,sizeof(dist));
    // dist[c1]=0;
    while(!pq.empty())//一开始居然这里漏了！号，而我居然还要debug才能找出来
    {
        pair<int,int> c = pq.top();pq.pop();
        int u = c.second;
        dist[u] = c.first;
        // cout<<"u "<<u<<" v "<<" dist "<<c.first<<endl;//
        for(auto a:G[u])
        {
            Edge e = edges[a];
            if(dist[e.v]>dist[u]+e.dist)
            {
                pq.push({dist[u]+e.dist,e.v});
                dist[e.v]=dist[u]+e.dist;
            }
        }
    }
    // for(int i=0;i<n;i++)
    //     cout<<dist[i]<<" ";//
    dfs(c1,vectex[c1]);
    cout<<pathcnt<<" "<<MAX<<endl;
    return 0;
}
