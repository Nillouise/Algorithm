#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int Cmax,N,Sp,M;

vector<pair<int,int> > G[505];
int V[505];
int dist[505];
int MinCost=1e9; 
int MinTakeBack = 1e9;
vector<int> MinPath;

int dfs(int x,vector<int> curPath)
{
    if(x==Sp)
    {
        int cur=0;
        int MAX=0;
        for(auto a:curPath)
        {
            if(a==0)continue;
            cur-=Cmax/2-V[a];
            if(cur < 0)
            {
                MAX-=cur;
                cur = 0;
            }
        }
        if(MAX<MinCost)
        {
            MinPath = curPath;
            MinCost=MAX;
            MinTakeBack = cur;
        }else if(MAX ==MinCost &&MinTakeBack<cur){
            MinPath = curPath;
            MinCost = MAX;
            MinTakeBack = cur;
        }
        return 0;
    }
    for(auto a:G[x])
    {
        if(dist[a.first]==dist[x]-a.second)
        {    
            curPath.push_back(a.first);
            dfs(a.first,curPath);
            curPath.pop_back();
        }
    }
    
    return 0;
}

int main()
{
    freopen("input.txt","r",stdin);//
    cin>>Cmax>>N>>Sp>>M;
    for(int i=1;i<=N;i++)
    {
        cin>>V[i];
    }
    for(int i=0;i<M;i++)
    {
        int u,v,x;
        cin>>u>>v>>x;
        G[u].push_back({v,x});
        G[v].push_back({u,x});
    }
    queue<int> Q;
    memset(dist,0x3f,sizeof(dist));
    dist[Sp]=0;
    Q.push(Sp);
    while(!Q.empty())
    {
        int u = Q.front();Q.pop();
        for(auto a:G[u])
        {
            if(dist[a.first]>dist[u]+a.second)
            {
                dist[a.first]=dist[u]+a.second;
                Q.push(a.first);
            }
        }
        //if(dist[0]>=0)break;
    }
    for(int i=0;i<4;i++)cout<<dist[i]<<" ";
    
    vector<int> path;
    path.push_back(0);
    dfs(0,path);
    cout<<MinCost<<" ";
    
    for(int i=0;i<MinPath.size();i++)
    {
        if(i!=0)cout<<"->";
        cout<<MinPath[i];
    }
    cout<<" "<<MinTakeBack<<endl;
    
    
    
    return 0;
}
