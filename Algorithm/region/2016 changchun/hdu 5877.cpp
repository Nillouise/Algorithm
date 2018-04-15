#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL N,K;
vector<int> G[100000+100];
LL val[100000+100];
int pre[100000*10000];
map<LL,int> tree;
LL ans = 0;
int query(LL x)
{
    int res = 0;
    for (int i = 1e9; i>0; i = i-(i&(-i))) {
        auto it = tree.find(i);
        if(it!=tree.end())
        {
            if(it->second==0){
                tree.erase(it);
            }else{
                res+=it->second;
            }
        }
    }
    // cout<<"x "<<x<<" res"<<res<<endl;//
    return res;
}

void add(LL x,int val)
{
        // cout<<"x "<<x<<" val"<<val<<endl;//
    for (int i = x; i <= 1e9 ; i=i +(i&(-i))) {
        tree[i]+=val;
        if(tree[i] == 0)
        {
            tree.erase(tree.find(i));
        }
    }
}


LL dfs(int x,int dep)
{
    LL need = K/val[x];
    // cout<<"x"<<x<<val[x]<<" need "<<need<<endl;//
    if(need<=1e9)
    {
        LL cnt = query(need);
        ans+=cnt;
    }
    for(auto a:G[x])
    {
        add(val[a],1);
        dfs(a,dep+1);
        add(val[a],-1);
    }
    return 0;
}


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int T;
    cin>>T;
    while(T--)
    {
        cin>>N>>K;
        tree.clear();
        for (int i = 0; i < N+1; i++) {
            G[i].clear();
        }
        for (int i = 0; i < N; i++) {
            cin>>val[i+1];
        }
        for (int i = 0; i < N-1; i++) {
            int a,b;cin>>a>>b;
            G[a].push_back(b);
        }
        ans = 0;
        dfs(1,0);
        cout<<ans<<endl;//
    }    
    
    return 0;
}