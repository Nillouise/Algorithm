#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL N,K;
vector<int> G[100000+100];
LL val[100000+100];
int tree[100000+100];
int disper[100000];
LL ans = 0;
int query(LL x)
{
    int res = 0;
    // for (int i = 1e5+10; i>0; i = i-(i&(-i))) {
    for (int i = x; i>0; i = i-(i&(-i))) {
        res +=tree[i];
    }
    // cout<<"x "<<x<<" res"<<res<<endl;//
    return res;
}

void add(LL x,int val)
{
        // cout<<"x "<<x<<" val"<<val<<endl;//
    for (int i = x; i <= 1e5+10 ; i=i +(i&(-i))) {
        tree[i]+=val;
        // cout<<i<<"add"<<endl;//
    }
}
LL act = 0;

LL dfs(int x,int dep)
{
    // cout<<"x"<<x<<dep<<endl;
    LL need = K/val[x];
    int pos = upper_bound(disper,disper+act,need)-disper;
    // pos++;
    int cur = lower_bound(disper,disper+act,val[x])-disper;
    cur++;
    LL cnt = query(pos);
    ans+=cnt;
    for(auto a:G[x])
    {
        add(cur,1);
        dfs(a,dep+1);
        add(cur,-1);
    }
    // cout<<"exit"<<endl;//
    return 0;
}
int in[100000+100];

int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int T;
    cin>>T;
    while(T--)
    {
        cin>>N>>K;
        for (int i = 0; i < N+10; i++) {
            G[i].clear();
        }
        memset(tree,0,sizeof(tree));
        memset(disper,0,sizeof(disper));
        memset(in,0,sizeof(in));
        for (int i = 0; i < N; i++) {
            cin>>val[i+1];
            disper[i] = val[i+1];
        }
        sort(disper,disper+N);
        act = unique(disper,disper+N)-disper;
        int root =0;
        for (int i = 0; i < N-1; i++) {
            int a,b;cin>>a>>b;
            G[a].push_back(b);
            in[b]++;
        }
        for (int i = 1; i <= N; i++) {
            if(in[i]==0){
                root=i;
                break;
            }
        }
        ans = 0;
        dfs(root,0);
        cout<<ans<<endl;//
    }    
    
    return 0;
}