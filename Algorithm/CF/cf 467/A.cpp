#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int vis[700];


int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int n;
    cin>>n;
    vis[0]=1;
    int ans=0;
    for (int i = 0; i < n; i++) {
        int a;
        cin>>a;
        if(vis[a]==0)
        {
            ans++;
            vis[a]++;
        }
    }
    cout<<ans<<endl;
    
    
    return 0;
}
