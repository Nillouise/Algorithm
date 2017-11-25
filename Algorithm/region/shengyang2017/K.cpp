#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    freopen("I:\\Project\\acm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
    {
        // cout<<"T"<<T<<endl; //
        
        
        unsigned long long a[4];
        unsigned long long ans=0;
        unsigned long long pre=0;
        unsigned long long high=0;
        cin>>a[0]>>a[1]>>a[2]>>a[3];
        unsigned long long one = 1;
        // 
        // for (int i = 0; i < 4; i++) {
        //     a[i]=one<<62;
        // }
        // cout<<(one<<62)<<endl;//
        ans = a[0];
        pre = ans;
        for (int i = 1; i < 4; i++) {
            ans+=a[i];
            if(pre>ans)high++;
            pre = ans;
            // cout<<"ans"<<ans<<endl;//
        }
        // if(high)cout<<high;
                if(high)
                {
                    // cout<<high<<endl;
                    cout<<"18446744073709551616"<<endl;
                    // printf("%")
                }else{
                    cout<<ans<<endl;
                }
        // cout<<ans<<endl;
    }
    
    
    
    return 0;
}
