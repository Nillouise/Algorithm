#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL dat[2000];



int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
    {
        int n;cin>>n;
        for (int i = 0; i < n; i++) {
            cin>>dat[i];
        }
        LL ans = 0;
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                if(i==k)continue;
                for (int j = i+1; j < n; j++) {
                    if(j==k)continue;
                    LL cur = ((dat[i]+dat[j])^dat[k]);
                    if(ans<cur){
                        ans = cur;
                    }
                }
            }
        }
        cout<<ans<<endl;//
    }
    
    
    
    return 0;
}