#include<bits/stdc++.h>
using namespace std;

int n,m,e,x,y,ans;
bool vis[1005],flag[1005][1005];
int connect_x[1005],connect_y[1005];

bool dfs(int x)
{
    for (int y=1;y<=m;y++)
        if (flag[x][y]&&!vis[y])
            {
                vis[y]=true;
                if (connect_y[y]==-1||dfs(connect_y[y]))
                    {
                        connect_x[x]=y;
                        connect_y[y]=x;
                        return true;
                    }
            }
    return false;
}
int N;
vector<int> G[1000000+10];
pair<int,int> nodes[1000000+10];

void maxmatch()
{
    memset(connect_x,255,sizeof(connect_x));
    memset(connect_y,255,sizeof(connect_y));
    
    for(int i = 0;i<N;i++)
    {
        if(nodes[i].first==1||nodes[i].second==1)
        {
            memset(connect_x,0x3f3f3f,sizeof(connect_x));
            memset(connect_y,0x3f3f3f,sizeof(connect_y));  
            memset(vis,false,sizeof(vis));
            ans = max(ans,dfs(i));
        }
    }
    
    // for (int i=1;i<=n;i++)
    //     if (connect_x[i]==-1)
    //         {
    //             memset(vis,false,sizeof(vis));
    //             ans+=dfs(i);
    //         }
}

int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    cin>>N;
    for (int i = 0; i < N; i++) {
        int a,b;cin>>a>>b;
        G[a].push_back(i);
        G[b].push_back(i);
        nodes[i].first = a;
        nodes[i].second = b;
    }
    for (int i = 0; i < N; i++) {
        for(auto a:G[nodes[i].first+1])
        {
            flag[i][a] = true;
        }
        for(auto a:G[nodes[i].second+1])
        {
            flag[i][a] = true;
        }
    }
    
    
    
    
    return 0;
}