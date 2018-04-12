#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL x,y;
vector<LL> dat;
void gcd(LL a,LL b)
{
    if(a>b)swap(a,b);
    if(a==0)
    {
        dat.push_back(0);
    }else{
        dat.push_back(b/a);
        gcd(b%a,a);
    }
    
}



int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    
    // gcd(25,7);
    // for(auto a:dat)
    // {
    //     cout<<a<<" ";
    // }
    
    int T;
    cin>>T;
    while(T--)
    {
        dat.clear();
        cin>>x>>y;
        gcd(x,y);
        int i;
        for(i=0;i<dat.size();i++)
        {
            if(dat[i]>1)break;
        }
        if(i%2 == 0)
        {
            cout<<"Stan wins"<<endl;
        }else{
            cout<<"Ollie wins"<<endl;
        }
        
        
        
    }
    
    
    return 0;
}