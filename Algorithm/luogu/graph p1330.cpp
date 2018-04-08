#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int N,M;
int vis[10000+100];
int col[10000+100];
vector<int> G[10000+100];
int flag = true;
int gcnt = 0;
int vis2[10000+100];
int col2[10000+100];
int flag2 = true;
int gcnt2 = 0;
int dfs(int x,int c)
{
    // cout<<x<<endl;//
    if(vis[x]==1)
    {
        if(col[x]!=c)
        {
            flag=false;
            return 0;
        }else{
            return 0;
        }
    }
    vis[x]=1;
    col[x]=c;
    if(c==1)
    {
        gcnt++;
    }
    for(auto a:G[x])
    {
        dfs(a,1-c);
    }
    return 0;
}

int dfs2(int x,int c)
{
    // cout<<x<<endl;//
    if(vis2[x]==1)
    {
        if(col2[x]!=c)
        {
            flag2=false;
            return 0;
        }else{
            return 0;
        }
    }
    vis2[x]=1;
    col2[x]=c;
    if(c==1)
    {
        gcnt2++;
    }
    for(auto a:G[x])
    {
        dfs2(a,1-c);
    }
    return 0;
}
int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    cin>>N>>M;
    for (int i = 0; i < M; i++) {
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=1;i<=N;i++)
    {
        if(vis[i]==0)
        {
            dfs(i,0);
        }
        if(vis2[i]==0)
        {
            dfs2(i,1);
        }
        if(flag==false&&flag2==false)
        {
            cout<<"Impossible"<<endl;
            return 0;
        }else if(flag==true&&flag==true){
            gcnt = min(gcnt,gcnt2);
            gcnt2 = gcnt;
        }else{
            if(flag==true)
            {
                gcnt2=gcnt;
            }else{
                gcnt=gcnt2;
            }
        }
    }
    cout<<gcnt<<endl;
    return 0;
}