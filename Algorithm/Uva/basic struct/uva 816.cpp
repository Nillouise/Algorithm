//这题的输出格式真他妈脑残，一行开始要有两空格，一行的结尾不能有空格
//多多注意这题的输出格式
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

//这四个开始和结束为止 用r0,c0,r1,c1,r2,c2代表比较好
int startr,startc,endr,endc;
char startdir;
int has_edge[12][12][4][4];

int dr[4]= {-1,0,1,0};
int dc[4] = {0,1,0,-1};

struct Node
{
    int r,c;
    int dir;
    Node walk(int turn)
    {
        Node n;
        if(turn == 1)turn=-1;
        if(turn ==2) turn =1;
        n.dir = (dir+turn+4)%4;
        n.c = c+dc[n.dir];
        n.r = r+dr[n.dir];
        return n;
    }
    
      Node(int r=0, int c=0, int dir=0):r(r),c(c),dir(dir) {}
};



int dirid(char x)
{
    string s = "NESW";
    return s.find(x);
}

int turnid(char x)
{
    string s = "FLR";
    return s.find(x);
}
Node par[12][12][4];
int vis[12][12][4];

void print_ans(Node u)
{
    vector<Node> nodes;
    for(;;)
    {
        nodes.push_back(u);
        if(vis[u.r][u.c][u.dir]==0)
        {
            break;
        }
        u = par[u.r][u.c][u.dir];
    }
    
    nodes.push_back(Node(startr, startc, dirid(startdir)));
    int cnt = 0;
    // for(int i=0;i<nodes.size();i++)
    for(int i= nodes.size()-1;i>=0;i--)
    {
        // if(i%10==0)cout<<"  "; //以为错误
        if(cnt%10==0)printf(" ");
        printf(" (%d,%d)",nodes[i].r,nodes[i].c);
        cnt++;
        if((cnt%10)==0)cout<<endl;
    }
    if(cnt%10!=0)cout<<endl;
}

int bfs()
{
    queue<Node> Q;
    // Node n=Node{startr,startc,dirid(startdir)};
    Node n=Node(startr,startc,dirid(startdir));
    
    Node n2 = n.walk(0);
    Q.push(n2);
    while(!Q.empty())
    {
        Node n =Q.front();
        Q.pop();
        if(n.r==endr&&n.c==endc){
            print_ans(n);
            return 0;
        }
        for (int i = 0; i < 3; i++) {
            if(has_edge[n.r][n.c][n.dir][i]==1)
            {
                
                //这里不要用nn，用u v这类代表边的两端的变量
                Node nn = n.walk(i);
                if(vis[nn.r][nn.c][nn.dir])continue;
                
                par[nn.r][nn.c][nn.dir] = n;
                vis[nn.r][nn.c][nn.dir] = 1;
                Q.push(nn);
                //这里检查是否是终点有一个问题，就是可能父节点（也就是n）并没有被检查
                // if(nn.r==endr&&nn.c==endc)
                // {
                //     print_ans(nn);
                //     return 1;
                // }
            }
        }
        
    }
    
    cout<<"  No Solution Possible"<<endl;
    
    return 0;
}

int read()
{
    memset(has_edge,0,sizeof(has_edge));
    memset(vis,0,sizeof(vis));
    
    
    string name;
    cin>>name;
    if(name=="END")
    {
        return 0;
    }
    cout<<name<<endl;
    cin>>startr>>startc>>startdir>>endr>>endc;
    
    int r,c;
    while(cin>>r,r!=0)
    {
        cin>>c;
        string noti;
        while(cin>>noti,noti!="*")
        {
            for (int i = 1; i < noti.size(); i++) {
                
                has_edge[r][c][dirid(noti[0])][turnid(noti[i])]=1;
            }
        }
    }

    return 1;
    
}


int main()
{
    freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    //这语句会导致cout和print混用会出现问题，单独用就没有问题
    // ios::sync_with_stdio(false);
    while(read())
    {
        bfs();
    }
    return 0;
}
