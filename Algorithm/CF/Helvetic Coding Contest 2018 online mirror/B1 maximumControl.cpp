#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int vis[100000];


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for (int i = 0; i < n-1; i++) {
        int a,b;cin>>a>>b;
        vis[a]++,vis[b]++;
    }
    int ans =0;
    for (int i = 1; i <= n; i++) {
        if(vis[i]==1)ans++;
    }
    
    cout<<ans<<endl;
    
    
    return 0;
}