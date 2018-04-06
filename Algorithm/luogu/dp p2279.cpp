#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> dat[1000+10];
int dp[1000+10][3];

int min(int x,int y,int z)
{
    // cout<<"min "<<x<<y<<z<<endl;//
    return std::min(std::min(x,y),std::min(y,z));
}

int dfs(int x,int fire)
{
    if(dp[x][fire]!=-1)return dp[x][fire];
    if(dat[x].size()==0)
    {
        //一开始没有考虑边界。
        if(fire==0)return 1;
        if(fire==1)return 1;
        if(fire==2)return 1;
    }
    // cout<<x<<": ";
    // for(auto a:dat[x])
    // {
    //     cout<<a<<" ";
    // }
    // cout<<endl;
    
    int ans = 1;
    for(auto a:dat[x])
    {
        // cout<<x<<" "<<fire<<endl;//
        ans = ans+min(dfs(a,0),dfs(a,1),dfs(a,2));
    }
    //这思路考虑少了一个地方，就是当儿子是消防全的时候，另一个儿子完全可以不被覆盖！！！！
    int ans2 = 0;
    for(auto a:dat[x])
    {
        ans2 = ans2 +min(dfs(a,0),dfs(a,1),dfs(a,2));
    }
    ans2 = ans2-min(dfs(dat[x][0],1),dfs(dat[x][0],2),dfs(dat[x][0],0))+dfs(dat[x][0],0);
    for(int i=1;i<dat[x].size();i++)
    {
        if(ans2> ans2-min(dfs(dat[x][i],1),dfs(dat[x][i],2),dfs(dat[x][i],0))+dfs(dat[x][i],0))
        {
            ans2 = ans2-min(dfs(dat[x][i],1),dfs(dat[x][i],2),dfs(dat[x][i],0))+dfs(dat[x][i],0);
        }
    }
    
    int ans3 = 0;
    for(auto a:dat[x])
    {
        ans3 = ans3 + min(dfs(a,0),dfs(a,1),dfs(a,2));
    }
    ans3 = ans3 - min(dfs(dat[x][0],0),dfs(dat[x][0],1),dfs(dat[x][0],2))+dfs(dat[x][0],1);
    for(int i=1;i<dat[x].size();i++)
    {
        if(ans3>ans3-min(dfs(dat[x][i],0),dfs(dat[x][i],1),dfs(dat[x][i],2))+dfs(dat[x][i],1))
        {
            ans3 = ans3-min(dfs(dat[x][i],0),dfs(dat[x][i],1),dfs(dat[x][i],2))+dfs(dat[x][i],1);
        }
    }
    
    if(fire==0)
    {
        return dp[x][fire]=ans;    
    }else if(fire==1)
    {
        return dp[x][fire] = min(ans,ans2);
    }else
    {
        return dp[x][fire] = min(ans,ans2,ans3);
    }
}

int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int n;
    cin>>n;
    int x;
    for(int i=2;i<=n;i++)
    {
        cin>>x;
        dat[x-1].push_back(i-1);
    }
    memset(dp,-1,sizeof(dp));
    cout<<min(dfs(0,0),dfs(0,1),dfs(0,2))<<endl;
    
    
    
    return 0;
}