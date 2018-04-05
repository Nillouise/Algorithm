#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int vis[100];
int up=0,down=100;
bool dfs(int res,int cur,int tar,int pre)
{
    if(res ==0)return true;
    // int flag=0;
    // for(int i=down;i<=up;i++)
    // {
    //     if(vis[i])flag=1;
    // }
    // if(flag==0)return true;
    
    if(cur==tar)
    {
        return dfs(res-1,0,tar,up);
    }
    
    for(int i=pre;i>=down;i--)
    {
        if(i>tar-cur)continue;
        if(vis[i]>0)
        {
            vis[i]--;
            if(dfs(res,cur+i,tar,i))return true;
            vis[i]++;
            // if(cur+i==tar||cur==tar)return false;//cur+i==tar有可能是最后组成的木棍。//注意这里cur==tar是错的
            if(cur+i==tar||cur==0)return false;//cur+i==tar有可能是最后组成的木棍。
        }
    }
    //写在这里是错的，因为会跟上面冲突的
    // for(int i=down;i<=up;i++)
    // {
    //     if(vis[i]>0)return false;
    // }
    return false;
}

int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int N;
    int len =0;
    int n= 0;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int x;
        cin>>x;
        if(x<=50)
        {
            vis[x]++;
            n++;
            len+=x;
            if(up<x)up=x;
            if(down>x)down=x;
        }
    }
    for(int i=n;i>1;i--)
    {
        if(len%i==0)
        {
            if(dfs(i,0,len/i,up))
            {
                cout<<len/i<<endl;
                return 0;
            }
        }
    }
    cout<<len<<endl;
    
    
    return 0;
}