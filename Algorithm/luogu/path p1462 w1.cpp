#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m,b;
int f[10000+100];
vector<int> G[10000+100];
int e[10000+100];

struct Edge
{
    LL u,v,c;    
};

Edge edges[2*50000+100];

int cmp(int a,int b)
{
    return f[a]<f[b];
}


LL dij(int a,int b,LL cost)
{
    priority_queue<pair<LL,LL>,vector<pair<LL,LL> >, greater<pair<LL,LL>> > pq;
    vector<int> vis(n+10,0);
    vis[a]=1;
    pq.push({0,a});
    int flag = 1;
    while(!pq.empty())
    {
        pair<LL,LL> no = pq.top();pq.pop();
        if(no.second == b)
        {
            return no.first;
        }
        for(auto &a:G[no.second])
        {
            auto &e = edges[a]; 
            if(vis[e.v]==0 && f[e.v] <= cost)
            {
                vis[e.v]=1;
                pq.push({no.first + e.c, e.v});
            }
        }
    }
    return -1;
}


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    cin>>n>>m>>b;
    for (int i = 0; i < n; i++) {
        cin>>f[i];
    }
    for (int i = 0; i < m; i++) {
        int ai,bi,ci;
        cin>>ai>>bi>>ci;ai--,bi--;
        edges[2*i] = {ai,bi,ci};
        G[ai].push_back(2*i);
        edges[2*i+1] = {bi,ai,ci};
        G[bi].push_back(2*i+1);
    }
    for(int i=0;i<n;i++)e[i]=i;
    sort(e,e+n,cmp);
    int beg = 0,end = n;
    while(beg<end-1)
    {
        int mid = (beg+end)/2;
        int cc = e[mid];
        if(f[cc]<f[0]||f[cc]<f[n-1])
        {
            beg = mid+1;
            continue;
        }
        LL heal = dij(0,cc,f[cc]);
        if(heal==-1)
        {
            beg=mid+1;
            continue;
        }
        
        LL heal2 = dij(cc,n-1,f[cc]);//我这里用了两个dij，有点弱智呀，一个dij即可。
        if(heal2==-1)
        {
            beg = mid+1;
            continue;
        }
        if(heal+heal2<b)
        {
            end=mid+1;
            continue;
        }else{
            beg = mid+1;
        }
    } 
    if(beg == n)
    {
        cout<<"AFK"<<endl;
        return 0;
    }else{
        cout<<f[beg]<<endl;
    }
    return 0;
}