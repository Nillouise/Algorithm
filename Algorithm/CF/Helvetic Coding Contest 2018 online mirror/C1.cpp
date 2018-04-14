#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    int n,p;cin>>n>>p;
    vector<int> dat(n+1);
    vector<LL> pre(n+1,0);
    for (int i = 1; i <= n; i++) {
        cin>>dat[i];
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i-1]+dat[i];
    }
    LL ans = 0;
    for (int i = 1; i < n ; i++) {
        ans = max(ans, pre[i]%p+(pre[n]-pre[i])%p);
    }
    cout<<ans<<endl;
    
    
    
    
    
    return 0;
}