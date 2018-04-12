#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int S,P;
pair<int,int> dat[800];
struct Edge
{
    int u,v;
    double dist;    
    bool operator<(const Edge &e){return dist<e.dist;}
};
vector<Edge> edges;
double getdist(int i,int j)
{
    return sqrt( pow((dat[i].first-dat[j].first),2.0)+pow(dat[i].second-dat[j].second,2.0));
}
int fa[200];

int find(int x)
{
    return x==fa[x] ?x:fa[x]=find(fa[x]);
}

int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    // ios::sync_with_stdio(false);
    cin>>S>>P;
    for (int i = 0; i < P; i++) {
        cin>>dat[i].first>>dat[i].second;
    }
    for (int i = 0; i < P; i++) {
        fa[i]=i;
    }
    
    
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < P; j++) {
            edges.push_back({i,j,getdist(i,j)});
        }
    }
    sort(edges.begin(),edges.end());
    
    double ans = 0;
    int ec = 0;
    for (int i = 0; i < edges.size(); i++) {
        if(ec>=P-S)
        {
            break;
        }
        int pa = find(edges[i].u);
        int pb = find(edges[i].v);
        if(pa!=pb)
        {
            fa[pa] = pb;
            ans = edges[i].dist;
            // cout<<ans<<endl;//
            ec++;
        }
    }
    
    // cout<<ans<<endl;
    printf("%0.2lf\n",ans);
    
    return 0;
}