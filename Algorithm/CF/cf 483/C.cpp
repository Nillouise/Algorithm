#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    ios::sync_with_stdio(false);
    int T;cin>>T;
    while(T--)
    {
        LL p,q,b;
        cin>>p>>q>>b;
        if(p%q==0){
            cout<<"Finite"<<endl;
            continue;
        }
        
        LL down=q/__gcd(q,p%q);
        
        for(;;){
            LL x =__gcd(down,b);
            if(x==1)break;
            while(down%x==0)
            {
                down/=x;
            }
        }
        
        if(down==1){
            cout<<"Finite"<<endl;
        }else{
            cout<<"Infinite"<<endl;
        }
    }
    
    
    
    
    return 0;
}