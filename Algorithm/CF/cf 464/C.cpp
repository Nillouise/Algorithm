#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    //freopen("D:\\Project\\Algorithm\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    LL n;
    cin>>n;
    vector<LL> vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    int s,f;
    cin>>s>>f;
    int num = f-s;
    for(int i=0;i<num-1;i++)
    {
        vec.push_back(vec[i]);
    }
    vector<LL> pre;
    pre.push_back(0LL);
    for(int i=0;i<vec.size();i++)
    {
        pre.push_back(pre.back()+vec[i]);
    }
    LL MAX = 0;
    LL MAXI = 0;
    for(int i=num;i<pre.size();i++)
    {
        if(MAX < pre[i]-pre[i-num])
        {
            MAX = pre[i]-pre[i-num];
            MAXI = i-num+1;
        }
    }
    int ei = MAXI+num-1;
    while(ei>n)ei-=n;
    
    LL ans = 1e9;
    if(s<MAXI)
    {
        cout<<
    }else
    {
        cout<<MAXI-s+1<<endl;
    }
    
    // for(int i=s;i<f;i++)
    // {
    //     int tmp = i+ n-MAXI+1;
    //     if(tmp>n)tmp-=n;
    //     // cout<<"MaxI "<<MAXI<<" tmp "<<tmp<<endl;//
    //     if(tmp<ans)
    //     {
    //         ans=tmp;
    //         cout<<ans;
    //         return 0;
    //     }    
    // }
    // cout<<ans<<endl;
    
    // for(int i= 1;i<=n;i++)
    // {
    //     LL ch = (i+MAXI-1);
    //     LL ce = (i+MAXI-1+num-1);
    //     // cout<<" ch "<<ch<<" ce "<<ce<<endl;//
    //     while(ch>n)ch-=n;
    //     while(ce>n)ce-=n;
    //     // cout <<" "<<ch<<endl;//
    //     // if(ch>=s&& ch+1<=f&& ce>=s&& ce+1<=f )
    //     if(ch==s)
    //     {
    //         cout<<i<<endl;
    //         return 0;
    //     }
    // }
    
    
    return 0;
}
