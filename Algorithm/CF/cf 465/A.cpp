#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<n;i++)
    {
        if(n%i==0)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    
    
    return 0;
}
