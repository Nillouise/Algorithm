#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1000000+100;
const int MOD = 100003;
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
vector<Edge> edges;
vector<int> G[maxn];
bool done[maxn]; //是否已永久标号
int d[maxn]; //s到各个点的距离，这样的好处是，s离所有点的距离都可以记录下来，调用者要直接查这个d函数。
int p[maxn]; //最短路中的上一条弧
LL cnt[maxn];
int N,M;
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
    void dij(int s) {
        priority_queue<HeapNode> Q;
        for(int i = 0; i < n; i++) 
            d[i] = 0x3f3f3f;//这里设置一个极大值
        d[s] = 0;
        memset(done, 0, sizeof(done));
        Q.push((HeapNode){0, s});
        cnt[s] = 1;
        while(!Q.empty()) {
            HeapNode x = Q.top(); Q.pop();
            int u = x.u;
            if(done[u]) continue;
            done[u] = true;//这程序把done在这里记录
            for(int i = 0; i < G[u].size(); i++) {
                Edge& e = edges[G[u][i]];
                if(d[e.to] > d[u] + e.dist) {//注意这里的加点操作。
                    d[e.to] = d[u] + e.dist;
                    p[e.to] = G[u][i];
                    cnt[e.to] = cnt[u]%MOD;
                    Q.push((HeapNode){d[e.to], e.to});
                }else if(d[e.to] == d[u] + e.dist)
                {
                    cnt[e.to] = (cnt[e.to]+ cnt[u])%MOD;
                }
            }
        }
    }
    
};


int main()
{
    
    ios::sync_with_stdio(false);
    
    cin>>N>>M;
    Dij dij;
    dij.init(N);
    for (int i = 0; i < M; i++) {
        int a,b;
        cin>>a>>b;
        dij.AddEdge(a-1,b-1,1);
        dij.AddEdge(b-1,a-1,1);
    }
    dij.dij(0);
    for(int i=0;i<N;i++)
    {
        cout<<cnt[i]<<endl;//
    }
    
    return 0;
}