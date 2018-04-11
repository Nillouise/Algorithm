#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL dat[200000+100];


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    LL n, D;
    cin>>n>>D;
    string com;
    for(int i=0;i<=n;i++)dat[i] = -1e18;
    LL pre=0;
    int k = n;
    for (int i = 0; i < n; i++) {
        cin>>com;
        LL x;
        cin>>x;
        if(com=="A")
        {
            LL nxt = (pre+x)%D;
            // cout<<"nxt"<<nxt<<endl;//
            dat[k] = nxt;
            for (int j = k; j <= n; j+=(j&(-j))) {
                dat[j] = max(dat[j],nxt);
            }
            k--;
        }else{
            LL ans = -1e18;
            //注意这里，当求的段为空的时候，要特判
            if(x==0){
                cout<<0<<endl;
                pre=0;
                continue;
            }
            for(int j = min(k+x,n);j>0;j-=(j&(-j)) )
            {
                ans = max(ans,dat[j]); 
            }
            cout<<ans<<endl;
            pre = ans;
        }
    }
    
    
    
    
    return 0;
}