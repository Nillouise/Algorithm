#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int p = n;
    int cum = 0;
    
    int t = 0;
    while(true)
    {
        if(cum+t>=m)
            break;
        cum+=t;
        p--;
        t++;
    }
    for (int i = 1; i < p; i++) {
        cout<<i<<" ";
    }
    cout<<p+(m-cum)<<" ";
    for (int i = n; i >= p; i--) {
        if(i!=p+m-cum)
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;//
    
    
    return 0;
}