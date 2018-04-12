#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    LL n,k;
    cin>>n>>k;
    
    LL ans = n*k;
    
    LL l=1,r=0;
    for(;l<=n;l=r+1)
    {
        if(k/l==0) 
            r = n;
        else 
            r = min(n,k/(k/l));
            
        ans -= (r+l)*(r-l+1)*(k/l)/2;
        // cout<<k/l<<endl;//
    }
    
    cout<<ans<<endl;
    
    
    
    
    
    
    return 0;
}