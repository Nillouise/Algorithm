#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int dp[20000+100];
int dat[40];


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int V,n;
    cin>>V>>n;
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        for(int j=V;j>=x;j--)
        {
            if(dp[j-x])dp[j]=1;
        }
    }
    int ans =0;
    for(int i=0;i<V+1;i++)
    {
        if(dp[i])ans=i;
    }
    cout<<V-ans<<endl;
    
    
    return 0;
}