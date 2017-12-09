#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m;
int pa[1000];
struct Edge
{
    int u,v,sp;
    bool operator<(const Edge&e)const
    {
        return sp<e.sp;
    }
};
vector<Edge> edges;
vector<int> G[1000];
void add(int u,int v,int sp)
{
    G[u].push_back(edges.size());
    edges.push_back({u,v,sp});
    // G[v].push_back(edges.size());
    // edges.push_back({v,u,sp});
}

void init()
{
    for (int i = 0; i < 1000; i++) 
    {
        pa[i]=i;
    }
}
int get(int x)
{
    if(pa[x]==x)return x;
    return pa[x]=get(pa[x]);
}

void merge(int x,int y)
{
    int px =get(x),py=get(y);
    // cout<<"x "<<x<<" y "<<y<<endl;//
    pa[px]=py;
}

int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    
    cin>>n>>m;
    for (int i = 0; i < m; i++) 
    {
        int u,v,sp;
        cin>>u>>v>>sp;
        add(u,v,sp);
    }
    sort(edges.begin(),edges.end());
    int s,t;
    cin>>s>>t;
    int impossible = 1;
    int up,la;
    double MIN = 1e9;
    for (int i = 0; i < m; i++) 
    {
        init();
        int flag=0;
        // cout<<"ok"<<endl;//
        
        for (int j = i; j < m; j++) 
        {
            merge(edges[j].u,edges[j].v);
            if(get(s)==get(t))
            {
                flag=1;
                // cout<<"get s"<<endl;//
                if(1.0*edges[j].sp/edges[i].sp <MIN)
                {
                    MIN =1.0* edges[j].sp/edges[i].sp;
                    la = edges[i].sp;
                    up = edges[j].sp;
                }
            }
        }
        // cout<<"flag "<<flag<<endl;//
        if(flag==0)
            break;
        else
            impossible = 0;
    }
    if(impossible)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        if(up%la == 0)
        {
            cout<<up/la<<endl;
        }else{
            int g = __gcd(up,la);
            cout<<up/g<<"/"<<la/g<<endl;
        }
    }
    
    
    


    return 0;
}
