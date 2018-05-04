#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 500000+2;

struct Edge {
    int u, v, dist;
    Edge(int u, int v, int d):u(u),v(v),dist(d) {}
};

//注意，这个模板因为使用了vector，会导致在luogu tle，使用数组实现链表才能过。
vector<int> G[MAXN];
// vector<int> Gs[MAXN];//存储每个节点的儿子节点
vector<Edge> edges;
int dep[MAXN];//节点的深度

void addedge(int u,int v,int w)
{
    G[u].push_back(edges.size());
    edges.push_back({u,v,w});
}


int pa[MAXN][22];
// int paw[MAXN][22];//这里应该是用来维护当前节点到祖先节点的一点信息的
void build(int x,int p,int depth){
    pa[x][0] = p;
    dep[x]=depth;
    for(auto a:G[x]){
//    	cout<<"x"<<x<<" "<<a<<endl;//
        Edge &e = edges[a];
        if(e.v!=p){
        	//注意这里是Gs 
            // Gs[x].push_back(e.v);
            build(e.v,x,depth+1);
        }
    }
}


//LAC的倍增要写一下
//n为节点的数目
void build_beizeng(int n)
{
    for(int i=1;i<20;i++){
        for(int x=1;x<=n;x++)//注意，因为本题是1-n为标号，所以用<=n 
        {
            if(dep[x]<(1<<i))
            {
                continue;
            }
            int cp = pa[x][i-1];//半路上的父节点。
            pa[x][i] = pa[cp][i-1]; 
        }
    }
}


int LCA(int x,int y)
{
    if(dep[x]<dep[y]){
        swap(x,y);
    }
    //拔x到同一层
    for(int i=20;i>=0;i--){
        if(dep[x]-(1<<i)>=dep[y]){
//        	cout<<x<<" "<<pa[x][i]<<endl;//
            x = pa[x][i];
        }
    }
//    cout<<"x="<<x<<endl;
    //特判是必须的
    if(x==y){
        return x;
    }
    for(int i=20;i>=0;i--){
        //这里必须是continue，不能直接返回，因为有可能1<<20是超过所有根的
        if(pa[x][i] == pa[y][i]){
            continue;
        }else{
            x= pa[x][i],y=pa[y][i];
        }
    }
    return pa[x][0];
}



int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    // ios::sync_with_stdio(false);cin.tie(0);
    int n,m,s;
    // cin>>n>>m>>s;
    scanf("%d%d%d",&n,&m,&s);
    for(int i=0;i<n-1;i++){
        // int a,b;cin>>a>>b;
        int a,b;scanf("%d%d",&a,&b);
        addedge(a,b,0);
        addedge(b,a,0);
    }

    
    build(s,0,0);
    build_beizeng(n);
    for(int i=0;i<m;i++){
        // int a,b;cin>>a>>b;
        int a,b;scanf("%d%d",&a,&b);
        // cout<<LCA(a,b)<<endl;
         printf("%d\n",LCA(a,b));
    }
    
    return 0;
}