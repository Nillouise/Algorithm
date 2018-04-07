#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int n;
    cin>>n;
    LL ans=n;
    for(int i=1;i<=n/2;i++)
    {
        ans+=n/i-1;
    }
    // ans++;
    // if(n%2==0)ans--;
    cout<<ans<<endl;
    
    return 0;
}