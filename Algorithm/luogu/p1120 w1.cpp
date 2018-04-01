#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


bool dfs(vector<int> &vis,vector<int>&vec,int tar,int rem)
{
    if(rem<0)
    {
        return false;
    }
    if(rem==0)
    {
        int flag=0;
        for(int i=0;i<vis.size();i++)
        {
            if(vis[i]==0)
            {
                flag=1;
                vis[i]=1;
                if(dfs(vis,vec,tar,tar-vec[i]))
                    return true;
                vis[i]=0;
            }
        }
        if(flag==1)
            return false;
        else
            return true;
    }else{
        for(int i=0;i<vis.size();i++)
        {
            if(vis[i]==0)
            {
                vis[i]=1;
                if(dfs(vis,vec,tar,rem-vec[i]))
                    return true;
                vis[i]=0;
            }
        }
        return false;
    }
}


int main()
{
    //freopen("I:\\Project\\acm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    vector<int> vec;
    LL len = 0;
    for(int i=0;i<N;i++)
    {
        int x;
        cin>>x;
        if(x<=50)
        {
            vec.push_back(x);
            len+=x;
        }
    }
    
    sort(vec.begin(),vec.end());
    
    for(int i=N;i>0;i--)
    {
        if(len%i==0)
        {
            int tar = len/i;
            vector<int> vis(vec.size(),0);
            if(dfs(vis,vec,tar,0))
            {
                cout<<tar<<endl;
                return 0;
            }
        }
    }
    
    
    
    return 0;
}