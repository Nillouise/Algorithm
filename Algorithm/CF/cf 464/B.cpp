#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    //freopen("D:\\Project\\Algorithm\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    LL n,k;
    cin>>n>>k;
    vector<LL> vec;
    LL mi = 0;
    LL m = 1e19;
    // cout<<m;
    LL cnt = 0;
    for(LL i=0;i<k;i++)
    {
        LL a;
        cin>>a;
        if(a>n)continue;
        LL l = n%a;
        if(l<m){
            m=l;
            mi = i+1;
            cnt = n/a;
        }
    }
    if(mi==0)
    {
        cout<<1<<" "<<0<<endl;
        return 0;
    }
    cout<<mi<<" "<<cnt<<endl;
    return 0;
}
