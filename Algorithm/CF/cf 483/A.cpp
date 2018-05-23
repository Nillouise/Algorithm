#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int n;cin>>n;
    vector<int> dat(n);
    for (int i = 0; i < n; i++) {
        cin>>dat[i];
    }
    sort(dat.begin(),dat.end());
    cout<<dat[(n-1)/2]<<endl;
    
    
    return 0;
}