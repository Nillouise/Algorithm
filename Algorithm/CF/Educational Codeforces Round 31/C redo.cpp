#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
int dat[100000+10];
int vis[100000+10];
int dfs(int x)
{
    vis[x]=1;
    if(vis[dat[x]]==0)
        return dfs(dat[x])+1;
    return 1;
}


int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    
    cin>>n;
    for (int i = 0; i < n; i++) 
    {
        cin>>dat[i+1];
    }
    vector<LL> g;
    for (int i = 1; i <= n; i++) 
    {
        if(vis[i]==0)
        {
            g.push_back(dfs(i));
        }
    }
    sort(g.begin(),g.end());
    reverse(g.begin(),g.end());
    if(g.size()==0)
    {
        cout<<"0"<<endl;
    }else if(g.size()==1)
    {
        cout<<g[0]*g[0]<<endl;
    }else
    {
        LL total = (g[0]+g[1])*(g[0]+g[1]);
        for (int i = 2; i < g.size(); i++) 
        {
            total+= g[i]*g[i];
        }
        cout<<total<<endl;
    }
    

    return 0;
}
