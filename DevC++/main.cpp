#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 10000;

struct Edge {
    int u, v, dist;
    Edge(int u, int v, int d):u(u),v(v),dist(d) {}
};

vector<int> G[MAXN];
vector<int> Gs[MAXN];//�洢ÿ���ڵ�Ķ��ӽڵ�
vector<Edge> edges;
int dep[MAXN];//�ڵ�����

void addedge(int u,int v,int w)
{
    G[u].push_back(edges.size());
    edges.push_back({u,v,w});
}


int pa[MAXN][22];
int paw[MAXN][22];//����Ӧ��������ά����ǰ�ڵ㵽���Ƚڵ��һ����Ϣ��
void build(int x,int p,int depth){
    pa[x][0] = p;
    dep[x]=depth;
    for(auto a:G[x]){
//    	cout<<"x"<<x<<" "<<a<<endl;//
        Edge e = edges[a];
        if(e.v!=p){
        	//ע��������Gs 
            Gs[x].push_back(e.v);
            build(e.v,x,depth+1);
        }
    }
}


//LAC�ı���Ҫдһ��
//nΪ�ڵ����Ŀ
void build_beizeng(int n)
{
    for(int i=1;i<20;i++){
        for(int x=1;x<=n;x++)//ע�⣬��Ϊ������1-nΪ��ţ�������<=n 
        {
            if(dep[x]<(1<<i))
            {
                continue;
            }
            int cp = pa[x][i-1];//��·�ϵĸ��ڵ㡣
            pa[x][i] = pa[cp][i-1]; 
        }
    }
}


int LCA(int x,int y)
{
    if(dep[x]<dep[y]){
        swap(x,y);
    }
    //��x��ͬһ��
    for(int i=20;i>=0;i--){
        if(dep[x]-(1<<i)>=dep[y]){
//        	cout<<x<<" "<<pa[x][i]<<endl;//
            x = pa[x][i];
        }
    }
//    cout<<"x="<<x<<endl;
    //�����Ǳ����
    if(x==y){
        return x;
    }
    for(int i=20;i>=0;i--){
        //���������continue������ֱ�ӷ��أ���Ϊ�п���1<<20�ǳ������и���
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
    
    ios::sync_with_stdio(false);
    int n,m,s;
    cin>>n>>m>>s;
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        addedge(a,b,0);
        addedge(b,a,0);
    }

    
    build(s,0,0);
    build_beizeng(n);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        cout<<LCA(a,b)<<endl;
    }
    
    return 0;
}
