#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


vector<pair<LL,int>> vec;
int vis[100];


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    
    for (int i = 0; i < K; i++) {
        int x;cin>>x;
        for (int j = 0; j < x; j++) {
            LL y;cin>>y;
            vec.push_back({y,i});       
        }
    }
    sort(vec.begin(),vec.end());
    queue<pair<LL,int>> q;
    LL ans = 1e18;
    int sum = 0;
    for(auto &a:vec)
    {
        q.push(a);
        if(vis[a.second]==0)sum++;
        vis[a.second]++;
        
        while(sum>=K)
        {
            pair<LL,int> u = q.front();q.pop();
            ans = min(ans,a.first- u.first);
            vis[u.second]--;
            if(vis[u.second]==0){
                sum--;
            }
            
        }
        
    }
    cout<<ans<<endl;//
    
    
    
    
    return 0;
}