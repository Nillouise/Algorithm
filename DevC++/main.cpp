#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int maxn = 10010*30*10;
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
LL d[maxn]; //s到各个点的距离，这样的好处是，s离所有点的距离都可以记录下来，调用者要直接查这个d函数。
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
    void dij(int s) {
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
                if(d[e.to] > d[u] + e.dist) {//注意这里的加点操作。
                    d[e.to] = d[u] + e.dist;
                    p[e.to] = G[u][i];
                    Q.push((HeapNode){d[e.to], e.to});
                }
            }
        }
    }
}; 




int main()
{
	ios::sync_with_stdio(false);
	
	Dij dij;
	int n,m,k;
	cin>>n>>m>>k;
	k++;
	dij.init(n*k+100);
	for(int i=0;i<m;i++){
		int u,v,w;cin>>u>>v>>w;
		for(int j=0;j<k;j++){
			dij.AddEdge(u*k+j,v*k+j,w);
			dij.AddEdge(v*k+j,u*k+j,w);
			if(j!=k-1){
				dij.AddEdge(u*k+j,v*k+j+1,0);
				dij.AddEdge(v*k+j,u*k+j+1,0);
			}
		}
	}
	dij.dij(1*k);
	LL ans = 0x3f3f3f;
	for(int i=0;i<k;i++)
	{
		ans=min(ans,d[n*k+i]);
	}
	
	
	cout<<ans<<endl;
	

    return 0;
}
