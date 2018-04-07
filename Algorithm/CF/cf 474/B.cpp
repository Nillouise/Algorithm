#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int n,k1,k2,dat1[1000],dat2[1000];


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    cin>>n>>k1>>k2;
    for (int i = 0; i < n; i++) {
        cin>>dat1[i];
    }
    for (int i = 0; i < n; i++) {
        cin>>dat2[i];
    }
    priority_queue<int> gap;
    for (int i = 0; i < n; i++) {
        gap.push(abs(dat1[i]-dat2[i]));
    }
    int total = k1+k2;
    while(gap.top()!=0&&total!=0)
    {
        int a = gap.top();gap.pop();
        // cout<<a<<endl;//
        a--,total--;
        gap.push(a);
    }
    
    if(total>0)
    {
        // LL ans = 0;
        // int le = total/n;
        // int big = total%n;
        // for(int i=0;i<big;i++)
        // {
        //     ans+=(le+1)*(le+1);
        // }
        // for(int i=big;i<n;i++)
        // {
        //     ans+=le*le;
        // }
        if(total%2==1)
        {
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }
        
    }else{
        LL ans = 0;
        while(!gap.empty())
        {
            LL a = gap.top();gap.pop();
            ans+=a*a;
        }
        cout<<ans<<endl;
    }
    
    
    return 0;
}