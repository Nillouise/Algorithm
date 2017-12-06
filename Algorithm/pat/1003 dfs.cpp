#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m,c1,c2;
int dat[600];
struct Edge
{
    int u,v,d;
};
vector<Edge> edges;
vector<int> G[600];
void add(int u,int v,int dist)
{
    G[u].push_back(edges.size());
    edges.push_back({u,v,dist});
    G[v].push_back(edges.size());
    edges.push_back({v,u,dist});
}


int vis[600];
int mindist = 1e9;
int maxre = 0;//maxrescue
int cnt=0;
int dfs(int x,int sum,int re)
{
    if(sum>mindist)//回溯
        return 0;
    vis[x]=1;
    if(x==c2)
    {
        if(sum<mindist)
        {
            cnt=1;
            mindist=sum;
            maxre = re;
        }else if(sum==mindist)
        {
            cnt++;
            if(re>maxre)maxre=re;
            mindist=sum;
        }
    }
    else for(auto a:G[x])
    {
        Edge e = edges[a];
        if(vis[e.v]==0)
        {
            dfs(e.v,sum+e.d,re+dat[e.v]);
        }
    }
    vis[x]=0;
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
        cin>>dat[i];
    }
    for (int i = 0; i < m; i++) 
    {
        int u,v,d;
        cin>>u>>v>>d;
        add(u,v,d);
    }
    dfs(c1,0,dat[c1]);
    cout<<cnt<<" "<<maxre<<endl;

    return 0;
}
