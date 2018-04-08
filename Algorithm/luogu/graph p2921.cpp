#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int cnt[100000+100];
int vis[100000+100];
int vis2[100000+100];
int dat[100000+100];
int N;
int dfs(int x,int dep)
{
    if(vis[x]==2)//记得这种用2表示节点正在递归的用法！！！！
    {
        return x;
    }else if(vis[x]==1)
    {
        return -1;
    }else if(vis[x]==-1)
    {
        vis[x]=2;
        int r = dfs(dat[x],dep+1);
        vis[x]=1;
        return r;
    }
    return 0;
}

int dfs2(int x,int dep)
{
    if(vis2[x]!=-1)
    {
        return cnt[x] = dep;
    }
    vis2[x]=1;
    return cnt[x] = dfs2(dat[x],dep+1);
}
int dfs3(int x)
{
    if(cnt[x]!=-1)return cnt[x];
    return cnt[x] = dfs3(dat[x])+1;
}

int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    cin>>N;
    for (int i = 0; i < N; i++) {
        cin>>dat[i];
        dat[i]--;
    }
    memset(vis,-1,sizeof(vis));
    memset(vis2,-1,sizeof(vis2));
    memset(cnt,-1,sizeof(cnt));
    for (int i = 0; i < N; i++) {
        if(vis[i]==-1)
        {
            int b = dfs(i,0);
            if(b==-1)continue;
            // int u=i;
            // while(u!=b)vis[u]=-1,u=dat[u];

            // cout<<"b="<<b<<endl;//
            if(vis2[b]==-1)
            dfs2(b,0);        
        }
    }
    // cout<<"begin"<<endl;
    // for (int i = 0; i < N; i++) {
    //     cout<<cnt[i]<<" ";
    // }
    // cout<<endl;//
    for (int i = 0; i < N; i++) {
        cout<<dfs3(i)<<endl;
    }
    
    
    
    return 0;
}