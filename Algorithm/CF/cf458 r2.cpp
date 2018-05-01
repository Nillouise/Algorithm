#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
long long C[2000][2000];
long long mod = 1e9+7;
int dp[1400];

int cal(int x)
{
    int res = 0;
    while(x)
    {
        if(x&1)res++;
        x/=2;
    }
    return res;
}

int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    string n;int k;cin>>n>>k;
    //注意特判
    if(k==0)return cout<<1<<endl,0;//
    
    C[0][0] = 1;
    for (int i = 1; i < 1400; i++) {
        C[i][0] = 1;
        for (int j = 1; j < 1400; j++) {
            C[i][j] = (C[i-1][j] + C[i-1][j-1])%mod;
        }
    }
    //init 
    dp[1] = 0;
    for (int i = 2; i < 1400; i++) {
        dp[i] = dp[cal(i)] + 1; 
    }
    
    //可行解
    vector<int> dat;
    for (int i = 1; i < 1001; i++) {
        if(dp[i]==k-1)dat.push_back(i);
    }
    
    long long ans = 0;
    int one = 0;
    int len = n.size();
    for(int i=0;i<len;i++)
    {
        if(n[i]=='1')
        {
            for(auto a: dat)
            {
                //注意考虑越界，a-one>=0必不可少的
                if(a-one>=0 &&a-one<=len-1-i )
                {
                    ans = (ans + C[len - 1 - i ][a-one])%mod; 
                }
            }
            one++;
        }
    }
    
    int m = 0;
    for(auto a:n){
        if(a=='1')m++;
    }
    if(dp[m]==k-1)ans++;
    
    //特判，想想为什么
    if(k==1)ans=(ans-1+mod)%mod;
    cout<<ans%mod<<endl;
    
    
    
    
    
    
    return 0;
}