#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL dat1[10000+100],dat2[10000+100];
pair<LL,LL> arr[10000+100];

//这题要先认识到，两个之间的交换是不会影响其他人的，然后推式子（一定要推式子才能出来的
int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int n;cin>>n;
    LL a,b;cin>>a>>b;
    for (int i = 0; i < n; i++) {
        cin>>dat1[i]>>dat2[i];
    }
    for (int i = 0; i < n; i++) {
        arr[i].first = dat1[i]*dat2[i];
        arr[i].second = i;
    }
    
    sort(arr,arr+n);
    LL ans = 0;
    LL total = a;
    for (int i = 0; i < n; i++) {
        ans = max(ans,total/ dat2[arr[i].second]);
        total*=dat1[arr[i].second];
    }
    cout<<ans<<endl;
    
    
    
    
    return 0;
}