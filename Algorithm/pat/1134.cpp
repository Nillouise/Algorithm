#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m;
vector<int> G[10000];
// vector<int> G[1500];//这里看错数据范围写错一次，10^4是4个0

int idx = 0;
void addedge(int u,int v)
{
    G[u].push_back(idx);
    G[v].push_back(idx);
    idx++;
}



int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    cin>>n>>m;
    
    for (int i = 0; i < m; i++) 
    {
        int u,v;
        cin>>u>>v;
        addedge(u,v);
    }
    int k;
    cin>>k;
    while(k--)
    {
        int nv;
        cin>>nv;
        set<int> but;
        for (int i = 0; i < nv; i++) 
        {
            int a;
            cin>>a;
            but.insert(G[a].begin(),G[a].end());
        }
        if(but.size()<idx)
        {
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }
    }


    return 0;
}
