#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL pre[200000+100];



int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    LL maxn = -1e8;
    for (int i = 0; i < n; i++) {
        cin>>pre[i+1];
        if(maxn<pre[i+1])maxn=pre[i+1];
        pre[i+1] = pre[i+1]+pre[i];
    }
    if(maxn<0)//这个逻辑是不必要的
    {
        cout<<maxn<<endl;
        return 0;
    }
    LL ans = 0;
    LL low=0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans,pre[i]-low);
        low=min(low,pre[i]);
    }
    cout<<ans<<endl;
    
    
    
    
    
    return 0;
}