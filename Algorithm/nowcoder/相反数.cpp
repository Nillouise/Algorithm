#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int n;
    cin>>n;
    int t = n;
    int r = 0;
    while(t){
        r=r*10+t%10;
        t/=10;
    }
    cout<<r+n<<endl;
    
    
    return 0;
}
