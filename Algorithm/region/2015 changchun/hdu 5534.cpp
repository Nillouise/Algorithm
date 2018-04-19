#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL dat[3000];

struct Token
{
    int cost;
    int val;
    bool operator<(const Token &t)const{
        return 1.0*val/cost > 1.0*t.val/t.cost;
    }
};
Token t[3000];




int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    int T;cin>>T;
    while(T--)
    {
        int n;cin>>n;
        for (int i = 0; i < n-1; i++) {
            cin>>dat[i+1];
            t[i].cost = i+1;
            t[i].val = dat[i+1];
        }
        
        LL ans = dat[1]*2+ dat[2]*(n-2);
        LL re = n-2;
        sort(t,t+n-1);
        
        for(int i=0;i<n;i++)
        {
            Token c = t[i];
            if(c.cost == 1)continue;
            if( re==0 || c.val - dat[1] < (c.cost-1)*(dat[2]-dat[1]) )
            {
                break;
            }
            if(re<c.cost-1)continue;
            int cnt = re/(c.cost-1);
            ans = ans - cnt* dat[1] + cnt * c.val - cnt *(c.cost-1)*(dat[2]-dat[1]); 
            re = re%(c.cost-1);
        }
        cout<<ans<<endl;
        
    }
    
    
    
    return 0;
}