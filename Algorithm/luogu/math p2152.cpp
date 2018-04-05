#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


LL gcd(LL a,LL b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}

int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    LL a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<endl;
    
    
    
    return 0;
}