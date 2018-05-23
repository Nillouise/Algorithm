#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;
int ans = 0;
vector<int> G[100000+100];

int dfs(int x,int p)
{
    int cnt = 1;
    
    for(auto a:G[x]){
        if(a!=p){
            cnt+=dfs(a,x);
        }
    }
    if(cnt%2==0){
        if(p!=-1)
        ans++;
        return 0;
    }else{
        return cnt;
    }
}

int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    cin>>n;
    if(n%2){
        cout<<-1<<endl;
        return 0;
    }
    for (int i = 0; i < n-1; i++) {
        int u,v;cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,-1);
    cout<<ans<<endl;
    
    
    return 0;
}