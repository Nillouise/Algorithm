#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


LL check(LL x,LL &cnt)
{
    if(x<0)
    {
        return 0;
    }
    if(x%4==0)
    {
        cnt=x/4;
        return 1;
    }
    LL cnt2;
    if(x%2==1)
    {
        if(check(x-9,cnt2))
        {
            cnt=cnt2+1;
            return 1;
        }
        return 0;
    }
    
    
    if(check(x-6,cnt2))
    {
        cnt=cnt2+1;
        return 1;
    }

    
    
    
    return 0;
    
}

int main()
{
    freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    LL q;
    cin>>q;
    for (size_t kase = 0; kase < q; kase++) {
        LL val;
        cin>>val;
        LL cnt=0;
        if(check(val,cnt))
        {
            cout<<cnt<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
    
    
    return 0;
}
