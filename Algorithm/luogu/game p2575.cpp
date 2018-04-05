#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int dp[1<<22];
int sg(int x)
{
    while(x&1)x=x>>1;
    if(dp[x]!=-1)
        return dp[x];
    vector<int> nxt(300);
    for(int i=19;i>=0;i--)
    {
        if(x&(1<<i))
        {
            for(int j=i-1;j>=0;j--)
            {
                if((x&(1<<j))==0)
                {
                    int t = x^(1<<i)^(1<<j);
                    nxt[sg(t)]=1;
                    break;
                }
            }
        }
    }
    for(int i=0;i<300;i++)
    {
        if(nxt[i]==0)
        {
            dp[x] = i;
            return i;
        }
    }
    return 300;
}


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<=20;i++)
    {
        dp[(1<<i)-1] = 0;        
    }
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int nim = 0;
        for(int i=0;i<n;i++)
        {
            int line;
            cin>>line;
            int binary = 0;
            for (int j = 0; j < line; j++) {
                int x;cin>>x;
                binary = binary|(1<<(20-x));
            }
            nim = nim^binary;
        }
        if(nim)
        {
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    
    
    return 0;
}