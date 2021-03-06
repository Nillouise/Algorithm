#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000+100;
struct Edge
{
    int u,v,col;
    int dist;//这里在后面dfs时才有用//后面也没用，这信息是存在点而不是存在边上的。
};
vector<Edge> G[maxn];
//这个数组只有储存路径长度的功能。
int vis[maxn];
const int INF=1e9+1000;
int n,m;
//图的起始点和终结点最好用 v1 和v2 表示吧
int v1,v2;
int bfs()
{
    vector<bool> has_visited(maxn,false);
    queue<int> Q;
    Q.push(v2);
    has_visited[v2]=true;
    vis[v2]=0;
    while(!Q.empty())
    {
        int cn = Q.front();Q.pop();
        for(auto a:G[cn])
        {
            int v = a.v;
            if(has_visited[v]==false&&vis[v]>vis[cn]+1)
            {
                has_visited[v]=true;
                vis[v]=vis[cn]+1;
                Q.push(v);
            }
        }
        if(vis[v1]<INF)
        {
            break;
        }
    }
    return 0;
}





int main()
{
    freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);

    while(cin>>n>>m)
    {
        v1=1;
        v2=n;
        for(int i=0;i<maxn;i++)
        {
            G[i].clear();
        }
        fill(vis,vis+maxn,INF);

        for(int i=0;i<m;i++)
        {
            int u,v,c;
            cin>>u>>v>>c;
            G[u].push_back({u,v,c});
            G[v].push_back({v,u,c});
        }

        bfs();

        cout<<vis[v1]<<endl;

        //卧槽，想错了，dfs并不好处理字典序
        //stack<Edge>stk;
//        //for(auto a:G[v1])
//        {
//            int v= a.v;
//            if(vis[v]==vis[v1]-1)
//            //这里用edge的col表示距离
//            stk.push({v1,v,a.col,vis[v1]});
//        }
//        vector<int> vc(n+100,INF);
//        while(!stk.empty())
//        {
//            Edge v = stk.top();stk.pop();
//            if(vc[v.dist]<v.col)
//            {
//                vc.dist
//            }
//
//        }





//        //好蠢，这里不用边遍历，用点遍历
//        vector<Edge> Q;
//        int MINC = INF;
//        for(auto a:G[v1])
//        {
//            if(vis[a.v]==vis[a.u]-1)
//            {
//                if(a.col<MINC)
//                {
//                    MINC = a.col;
//                }
//            }
//        }
//        for(auto a:G[v1])
//        {
//            if(dist[a.v]==dist[a.u]-1)
//            {
//                if(a.col==MINC)
//                {
//                    Q.push_back(a);
//
//                }
//            }
//        }
//
//
//
//
//        vector<int> vc(n+100,INF);
//        //这里正向应该用dfs才行的吧？？//不行，字典序用bfs才好处理。
//        while(Q.size()>0)
//        {
//            int MINC = INF;
//            for(int i=0;i<Q.size();i++)
//            {
//                Edge &e = Q[i];
//                for(auto a:G[e.u])
//                {
//                    if(dist[a.v]==dist[a.u]-1)
//                    {
//                        if(a.col<MINC)
//                        {
//                            MINC = a.col;
//                        }
//                    }
//                }
//            }
//
//            cout<<" "<<MINC;
//
//            vector<Edge> vq;
//            for(int i=0;i<Q.size();i++)
//            {
//                Edge e = Q[i];
//                for(auto a:G[e.u])
//                {
//                    if(dist[a.v]==dist[a.u]-1)
//                    {
//                        if(a.col==MINC)
//                        {
//                            vq.push_back(e);
//                        }
//                    }
//                }
//            }
//
//            if(u!=v1)cout<<" ";
//            cout<<MINC;
//            u=v;
//        }


        vector<int> Q;
        //bfs每个点只用遍历一次，但bfs的图，可能一个点有两个以上入边，这里的has_visited可以防止这种情况。
        vector<bool> has_visited(maxn,false);
        Q.push_back(v1);
        has_visited[v1]=true;
 //       cout<<v1;
        for(int path=0;path<vis[v1];path++)
        {
            int MINC = INF;
            for(auto a:Q)
            {
                for(auto b:G[a])
                {
                    if(b.col<MINC&&(vis[a]==vis[b.v]+1)&&has_visited[b.v]==false )MINC = b.col;
                }
            }
            if(path!=0)cout<<" ";
            cout<<MINC;
            vector<int> nq;
            for(auto a:Q)
            {
                for(auto b:G[a])
                {
                 //   if(b.col==MINC&&(vis[a]==vis[b.v]+1))//这里错了，因为一个点只用遍历一次，按这里的话，就可能多入了重复的点。
                    if(b.col==MINC&&vis[a]==vis[b.v]+1&&has_visited[b.v]==false)
                    {
                        has_visited[b.v]=true;
                        nq.push_back(b.v);
                    }
                }
            }
            Q = nq;//应该是这个操作太费时了//错了，就是这么做的

        }

        cout<<endl;
    }

    return 0;
}
