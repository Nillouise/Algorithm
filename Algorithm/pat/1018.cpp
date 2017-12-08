//这题注意考虑道路的唯一性需要哪些条件（一开始我不愿意考虑清楚题目的唯一条件，wa了几次）
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int Cmax,N,Sp,M;
int dat[1000];
vector<int> G[1000];
struct Edge
{
    int u,v,d;
};
vector<Edge> edges;
void add(int u,int v,int d)
{
    G[u].push_back(edges.size());
    edges.push_back({u,v,d});
    G[v].push_back(edges.size());
    edges.push_back({v,u,d});
}
int minpath = 1e9;
int mincat = 1e9;
vector<int> anspath;
vector<int> curpath;
int takeback = 0;
int vis[1000];
int dfs(int x,int path,int cat,int need)
{
    if(path>minpath)return 0;
    if(path==minpath && need>mincat)return 0;
    vis[x]=1;
    curpath.push_back(x);
    if(x==Sp)
    {
        if(path<minpath)
        {
            anspath=curpath;
            minpath = path;
            mincat = need;
            takeback = cat;
        }else if(path==minpath&&need<mincat)
        {
            anspath=curpath;
            minpath = path;
            mincat = need;
            takeback = cat;
        }else if(path==minpath&&need==mincat&&cat<takeback)
        {
            anspath=curpath;
            minpath = path;
            mincat = need;
            takeback = cat;
        }
    }else 
    {
        for(auto a:G[x])
        {
                
            if(vis[edges[a].v]==0)
            {
                int nn,nc;
                if(cat < Cmax/2 - dat[edges[a].v])
                {
                    nn = need+ (Cmax/2 - dat[edges[a].v]-cat);
                    nc = 0;
                }else{
                    nc = cat - (Cmax/2 - dat[edges[a].v]);
                    nn=need;
                }
                dfs(edges[a].v,path+edges[a].d,nc,nn);
            }
        }
        
    }
    vis[x]=0;
    curpath.pop_back();
    
    
}
int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    cin>>Cmax>>N>>Sp>>M;
    for (int i = 0; i < N; i++) 
    {
        cin>>dat[i+1];
    }
    for (int i = 0; i < M; i++) 
    {
        int u,v,d;
        cin>>u>>v>>d;
        add(u,v,d);
    }
    vis[0]=1;
    dfs(0,0,0,0);
    cout<<mincat<<" ";
    for (int i = 0; i < anspath.size(); i++) 
    {
        cout<<anspath[i];
        if(i!=anspath.size()-1)
        {
            cout<<"->";
        }
    }
    cout<<" "<<takeback<<endl;
    
    return 0;
}
