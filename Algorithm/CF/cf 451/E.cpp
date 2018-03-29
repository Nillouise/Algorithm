#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL squ[100000];

void get(LL x,LL &a,LL &b)
{
    int pos =lower_bound(squ,squ+100000,x)-squ;
    a = squ[pos]-x;
    if(a==0)b=0;
    else b = x - squ[pos-1];
}



int main()
{
//    freopen("I:\Project\acm\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    for (LL i = 0; i < 100000; i++) {
        squ[i]=i*i;
    }
    LL n;
    cin>>n;
    vector<LL> vec(n);
    for (int i = 0; i < n; i++) {
        cin>>vec[i];
    }
    vector<LL> gap;
    LL scnt = 0;
    LL zcnt = 0;
    LL cnt = 0;
    for (int i = 0; i < n; i++) {
        LL a,b;
        get(vec[i],a,b);
        if(a==0)
        {
            if(vec[i]!=0)scnt++;
            else zcnt++;
            cnt++;
        }
        else{
            // cout<<vec[i]<<" min "<<min(a,b)<<" "<<endl;//
            gap.push_back(min(a,b));
        }
    }
    if(cnt>=n/2)
    {
        if(zcnt<=n/2)
        {
            cout<<cnt-n/2<<endl;
        }else{
            cout<<(zcnt-n/2)*2+scnt<<endl;
        }
        
    }else{
        sort(gap.begin(),gap.end());
        LL ans = 0;
        LL pos = 0;
        for (int i = cnt+1; i <= n/2; i++) {
            ans+=gap[pos++];
            // cout<<gap[i]<<" ";//
        }
        cout<<ans<<endl;
    }
    
    
    return 0;
}