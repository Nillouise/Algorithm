#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAX_V = 1000;

int V; //顶点数应该是作为上界存在
vector<int> G[MAX_V];
int match[MAX_V]; // 所匹配的顶点
bool used[MAX_V]; //DFS中用到的访问标记

void add_edge(int u, int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}

bool dfs(int v)
{
    used[v] = true;
    for(int i=0;i<G[v].size();i++)
    {
        int u = G[v][i],w=match[u];
        if(w<0 || !used[w] && dfs(w))
        {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

int bipartite_matching()
{
    int res = 0;
    memset(match,-1,sizeof(match));
    //注意，这里可以用来调整匹配顺序，就是说要是按字典序最小来匹配的话，可以调转方向。当然，也要dfs来配合
    for (int v = 0; v < V; v++) {
        if(match[v]<0){
            memset(used,0,sizeof(used));
            if(dfs(v)){
                res++;
            }
        }
    }
    return res;
}

int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    
    
    
    return 0;
}