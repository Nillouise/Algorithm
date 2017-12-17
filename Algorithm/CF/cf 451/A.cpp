#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    freopen("I:\Project\acm\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int n;
    cin>>n;
    if(n%10 >5)
    {
            n/=10;
            n++;
    }else{
        n/=10;
    }
    cout<<n*10<<endl;
    
    
    return 0;
}