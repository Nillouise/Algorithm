#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
//    freopen("I:\Project\acm\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    LL n,a,b;
    cin>>n>>a>>b;
    set<LL> but;
    LL x=0,y=0;
    for(;;x++)
    {
        LL t = n-x*a;
        if(t<0)break;
        int re = t%b;
        if(but.find(re)!=but.end())break;
        if(re==0)
        {
            cout<<"YES"<<endl;
            cout<<x<<" "<< t/b<<endl;
            return 0;
        }
        but.insert(re);
    }
    
    cout<<"NO"<<endl;//
    
    return 0;
}