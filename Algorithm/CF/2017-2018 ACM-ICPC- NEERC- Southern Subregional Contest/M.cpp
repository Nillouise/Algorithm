#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int x,y;
    int x2,y2;
    cin>>x>>y>>x2>>y2;
    int total=abs(x-x2)*2+abs(y-y2)*2;
    total+=4;
    if(x==x2)total+=2;
    if(y==y2)total+=2;
    cout<<total<<endl;
    
    
    return 0;
}
