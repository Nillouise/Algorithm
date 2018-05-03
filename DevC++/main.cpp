#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int maxn = 10010*30*10;
//��ģ����0��n-1Ϊ�±꣬ע��ת��
struct Edge {
    int from, to, dist;
    Edge(int u, int v, int d):from(u),to(v),dist(d) {}
};

struct HeapNode {
    int d, u;//d��Ȩֵ��u�ǵ�
    bool operator < (const HeapNode& rhs) const {
    return d > rhs.d;
    }
};

//���ݱ������ȫ�ֱ�������ܻᱬ�ڴ�
vector<Edge> edges;
vector<int> G[maxn];
bool done[maxn]; //�Ƿ������ñ��
LL d[maxn]; //s��������ľ��룬�����ĺô��ǣ�s�����е�ľ��붼���Լ�¼������������Ҫֱ�Ӳ����d������
int p[maxn]; //���·�е���һ����

struct Dij {
    int n, m;
    void init(int n) {
        this->n = n;
        for(int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }
    //����addEdge ������ͼ����Ҫ��addһ�Ρ�
    void AddEdge(int from, int to, int dist) {
        edges.push_back(Edge(from, to, dist));
        m = edges.size();
        G[from].push_back(m-1);
    }
    void dij(int s) {
        priority_queue<HeapNode> Q;
        for(int i = 0; i < n; i++) 
            d[i] = 0x3f3f3f;//��������һ������ֵ
        d[s] = 0;
        memset(done, 0, sizeof(done));
        Q.push((HeapNode){0, s});
        while(!Q.empty()) {
            HeapNode x = Q.top(); Q.pop();
            int u = x.u;
            if(done[u]) continue;
            done[u] = true;//������done�������¼
            for(int i = 0; i < G[u].size(); i++) {
                Edge& e = edges[G[u][i]];
                if(d[e.to] > d[u] + e.dist) {//ע������ļӵ������
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
