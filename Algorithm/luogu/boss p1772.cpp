#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


const int maxn = 1000;
int inv[30][100];
//此模板以0到n-1为下标，注意转换
struct Edge {
    int from, to, dist;
    Edge(int u, int v, int d):from(u),to(v),dist(d) {}
};

struct HeapNode {
    int d, u;//d是权值，u是点
    bool operator < (const HeapNode& rhs) const {
    return d > rhs.d;
    }
};

//数据必须放在全局变量里，不能会爆内存
vector<Edge> edges;
vector<int> G[maxn];
bool done[maxn]; //是否已永久标号
int d[maxn]; //s到各个点的距离，这样的好处是，s离所有点的距离都可以记录下来，调用者要直接查这个d函数。
int p[maxn]; //最短路中的上一条弧

struct Dij {
    int n, m;
    void init(int n) {
        this->n = n;
        for(int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }
    //这里addEdge 在无向图中需要多add一次。
    void AddEdge(int from, int to, int dist) {
        edges.push_back(Edge(from, to, dist));
        m = edges.size();
        G[from].push_back(m-1);
    }
    void dij(int s,int t1,int t2) {
        priority_queue<HeapNode> Q;
        for(int i = 0; i < n; i++) 
            d[i] = 0x3f3f3f;//这里设置一个极大值
        d[s] = 0;
        memset(done, 0, sizeof(done));
        Q.push((HeapNode){0, s});
        while(!Q.empty()) {
            HeapNode x = Q.top(); Q.pop();
            int u = x.u;
            if(done[u]) continue;
            done[u] = true;//这程序把done在这里记录
            for(int i = 0; i < G[u].size(); i++) {
                Edge& e = edges[G[u][i]];
                if(d[e.to] > d[u] + e.dist&&inv[e.to][t1-1]==inv[e.to][t2]) {//注意这里的加点操作。
                    d[e.to] = d[u] + e.dist;
                    p[e.to] = G[u][i];
                    Q.push((HeapNode){d[e.to], e.to});
                }
            }
        }
    }
};
LL cost[150][150];
LL dp[150];
int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    int n,m,K,e;
    cin>>n>>m>>K>>e;
    Dij dij;
    dij.init(m);
    for (int i = 0; i < e; i++) {
        int a,b,c;
        cin>>a>>b>>c;a--,b--;
        dij.AddEdge(a,b,c);
        dij.AddEdge(b,a,c);
    }
    int d;
    cin>>d;
    for (int i = 0; i < d; i++) {
        int p,a,b;
        cin>>p>>a>>b;p--;
        for (int j = a; j <= b; j++) {
            inv[p][j] = 1;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n ; j++) {
            inv[i][j] = inv[i][j-1]+inv[i][j];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            dij.dij(0,i,j);
            cost[i][j] = ::d[m-1]*(j-i+1);
            // cout<<cost[i][j]<<" ";
        }
    }
    memset(dp,0x3f3f3f,sizeof(dp));
    dp[0] = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j>0;j--)
        {
            dp[i] = min(dp[i], dp[j-1] +  cost[j][i] +K); 
        }
    }
    cout<<dp[n]-K<<endl;
    
    
    return 0;
}