#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    LL K,P;
    cin>>K>>P;
    set<LL> but;
    for (LL i = 1; but.size() < 100000+10; i++) 
    {
        LL t = i;
        LL p = t;
        LL g = 0;
        while(t)
        {
            g=g*10+t%10;
            t/=10;
            p*=10;
        }
        // cout<<p+g<<endl;//
        // while(1);//
        but.insert(p+g);
    }
    
    LL ans = 0;
    int i= 0;
    for(auto a:but)
    {
        
        // cout<<a<<endl;//
        i++;
        if(i>K)break;
        ans+=a;
        ans%=P;
    }
    cout<<ans<<endl;

    return 0;
}
