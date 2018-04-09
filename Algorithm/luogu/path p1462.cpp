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


LL dij(LL cost)
{
    if(f[0]>cost||f[n-1]>cost)return -1;
    priority_queue<pair<LL,LL>,vector<pair<LL,LL> >, greater<pair<LL,LL>> > pq;
    vector<int> vis(n+10,0);
    vis[0]=1;
    pq.push({0,0});
    while(!pq.empty())
    {
        pair<LL,LL> no = pq.top();pq.pop();
        if(no.second == n-1)
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
    // cout<<"cost"<<cost<<endl;//
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
    for(int i=0;i<n;i++)e[i]=i;//这种用了一个数组记录顺序的程序，要特别特别小心。//而且这题压根不需要这个，只要记录下那个费用就可以了
    sort(e,e+n,cmp);
    LL cost = dij(f[e[n-1]]);
    if(cost==-1||cost>b){
        cout<<"AFK"<<endl;
        return 0;
    }
    int beg = 0,end = n;
    while(beg<end)
    {
        int mid = (beg+end)/2;
        int cc = e[mid];
        LL cost = dij(f[cc]);
        if(cost==-1||cost>=b)
        {
            beg = mid+1;
        }else{
            end = mid;
            // cout<<mid<<endl;//
        }
    }
    
    // cout<<f[end]<<endl;//又写错这种弱智变量代表的含义
    
    cout<<f[e[end]]<<endl;
    
    return 0;
}