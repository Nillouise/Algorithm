#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod = 100003;

LL pow(LL x,LL p)
{
    LL cur = x;
    LL res = 1;
    for (LL i = 0; i < 40; i++) {
        if((1LL<<i) & p )
        {
            res=(res*cur)%mod;
            cout<<"res"<<res<<endl;//
        }
        // cur= (cur*x)%mod;
        cur= (cur*cur)%mod;
    }
    cout<<res<<endl;//
    return res;
}




int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    // cout<<pow(2,3);
    
    LL M,N;cin>>M>>N;
    // LL n  =pow(M,N) - M*pow(M-1,N-1) + mod; //这里会导致溢出，知道为什么吗？
    LL n  =pow(M,N) - (M*pow(M-1,N-1))%mod + mod;
    
    cout<<n<<endl;//
    cout<<n%mod<<endl;//
    
    
    return 0;
}