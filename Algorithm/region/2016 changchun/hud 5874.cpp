#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    LL M,N;
    while(cin>>M>>N)
    {
        if(M/2 *M/2>N)
        {
            cout<<"F"<<endl;
        }else{
            cout<<"T"<<endl;
        }
        
    }
    
    
    return 0;
}