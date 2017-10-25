#include<bits/stdc++.h>
using namespace std;
vector<int>ans;
const int maxn=1000+100;
int vis[maxn][maxn];
int abl[maxn];
int way[maxn][maxn][4];
    int r,c;
int k=0;
class Node
{
    int r,c,step;

    Node walk(int x)
    {
        if(x==0)
        return (Node){r-min(way[r][c][0],k),c,step+1};
        if(x==1)
        return (Node){r+min(way[r][c][1],k),c,step+1};
        if(x==2)
        return (Node){r,c-min(way[r][c][2],k),step+1};
        if(x==3)
        return (Node){r,c+min(k,way[r][c][3]),step+1};
        return Node();
    }
};


int main()
{
    ios::sync_with_stdio(false);
    cin>>k;

    cin>>r>>c;
    vector<string> m;
    for(int i=0;i<r;i++)
    {
        string s;
        cin>>s;
        m.push_back(s);
    }
    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    r1--,c1--,r2--,c2--;



    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(m[i][j]=='#')
            {
                way[i][j][0]=-1;
            }else if(i==0)
            {
                way[i][j][0]=0;
            }
            else {
                way[i][j][0]=way[i-1][j][0]+1;
            }
        }
    }

    for(int i=r-1;i>=0;i--)
    {
        for(int j=0;j<c;j++)
        {
            if(m[i][j]=='#')
            {
                way[i][j][1]=-1;
            }else if(i==r-1)
            {
                way[i][j][1]=0;
            }
            else {
                way[i][j][1]=way[i+1][j][1]+1;
            }
        }
    }

    for(int j=0;j<c;j++)
    {
        for(int i=0;i<r;i++)
        {
            if(m[i][j]=='#')
            {
                way[i][j][2]=-1;
            }else if(j==0)
            {
                way[i][j][2]=0;
            }else{
                way[i][j][2]=way[i][j-1][2]+1;
            }
        }
    }

    for(int j=c-1;j>=0;j--)
    {
        for(int i=0;i<r;i++)
        {
            if(m[i][j]=='#')
            {
                way[i][j][3]=-1;
            }else if(j==c-1)
            {
                way[i][j][3]=0;
            }else{
                way[i][j][3]=way[i][j+1][3]+1;
            }
        }
    }


    Node n = Node{r1,c1,0};

    queue<Node> Q;
    Q.push(n);
    memset(vis,-1,sizeof(vis));
    vis[n.r][n.c]=0;
    //测终点

    while(!Q.empty())
    {
                if(vis[r2][c2]!=-1)break;
        Node n=Q.front();
        Q.pop();
        if(m[n.r][n.c]=='#'||vis[n.r][n.c]!=-1)continue;
        for(int i=0;i<4;i++)
        {
            Node nn =n.walk(i);
            if(vis[nn.r][nn.c]==-1)
            {
                vis[nn.r][nn.c]=nn.step
                Q.push(nn);
            }
        }
    }


    cout<<vis[r2][c2]<<endl;

    return 0;
}
