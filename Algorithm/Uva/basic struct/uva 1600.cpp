//往bfs的图里，不同的状态记录不同的bfs长度。
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 1e9;
int way[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int G[25][25][25];
int maze[25][25];
struct Node
{
    int r,c,k,cnt;
};
int r,c;
int check(int r1,int c1)
{
    if(r1<0||r1>=r)return 0;
    if(c1<0||c1>=c)return 0;
    return 1;
}
int main()
{
//    freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);
    int KASE;
    cin>>KASE;
    for(int kase=0;kase<KASE;kase++)
    {
        //init
        for(int i=0;i<25;i++)for(int j=0;j<25;j++)for(int k=0;k<25;k++)G[i][j][k]=INF;

        cin>>r>>c;
        int k;
        cin>>k;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                cin>>maze[i][j];
        queue<Node >Q;
        G[0][0][0]=0;
        Q.push({0,0,0,0});
        while(!Q.empty())
        {
            Node node = Q.front();Q.pop();
//            if(maze[node.r][node.c]==0)
//            {
                for(int i=0;i<4;i++)
                {
                    int nr = node.r+way[i][0];
                    int nc = node.c+way[i][1];
                    if(check(nr,nc))
                    {
                        if(maze[nr][nc]==1)
                        {
                            if(k>=node.k+1)
                            {
                                if(G[nr][nc][node.k+1]>node.cnt+1)
                                {
                                    G[nr][nc][node.k+1]=node.cnt+1;
                                    Q.push({nr,nc,node.k+1,node.cnt+1});
                                }
                            }
                        }
                        else
                        {
                            if(G[nr][nc][0]>node.cnt+1)
                            {
                                G[nr][nc][0]=node.cnt+1;
                                Q.push({nr,nc,0,node.cnt+1});
                            }
                        }
                    }
                }
//            }else{
//
//            }
            if(G[r-1][c-1][0]<INF)
            {
                cout<<G[r-1][c-1][0]<<endl;
                break;
            }
        }
        if(G[r-1][c-1][0]==INF)
        {
            cout<<-1<<endl;
        }
    }

    return 0;
}
