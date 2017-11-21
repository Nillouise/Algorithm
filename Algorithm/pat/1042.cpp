//又看错题目（英文题目就是不想看），是从根节点到叶子节点的路径
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m,k;
vector<int> val;
vector<int> G[200];
int cvis[200];
int hvis[200];//head vis,用过头延展。
vector<int> cpath;
vector<vector<int>> ans;

int dfs(int x,int sum)
{
    if(sum>k)
    {
        return 0;
    }
    if(sum==k&&G[x].size()==1)
    {
        if(hvis[x]==1)return 0;
        vector<int> newp(cpath);
        ans.push_back(newp);
    }
    
    for(auto v:G[x])
    {
        if(cvis[v]==0&&val[v]+sum<=k)
        {
            cvis[v]=1;
            cpath.push_back(v);
            dfs(v,val[v]+sum);
            cpath.pop_back();
            cvis[v]=0;
        }
    }
    return 0;
}

bool cmp(vector<int> v1,vector<int> v2)
{
    int len = min(v1.size(),v2.size());
    for (int i = 0; i < len; i++) 
    {
        if(val[v1[i]]<val[v2[i]])return false;
        if(val[v1[i]]>val[v2[i]])return true;
    }
    return v1.size()>v2.size();
}

int main()
{
    freopen("input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    
    cin>>n>>m>>k;
    val.resize(n);
    for (int i = 0; i < n; i++) 
    {
        cin>>val[i];
    }
    for(int i=0;i<m;i++)
    {
        int p,cm;
        cin>>p>>cm;//这里是以p为其中一个端点而不是i;
        for(int j=0;j<cm;j++)
        {
            int v;
            cin>>v;
            G[p].push_back(v);
            G[v].push_back(p);
        }
    }
    for(int i=0;i<1;i++)
    {
        if(val[i]==k)
        {
            cpath.push_back(i);
            vector<int> newv(cpath);
            ans.push_back(newv);
            cpath.pop_back();
            continue;
        }
        
        hvis[i]=1;
        cpath.push_back(i);
        cvis[i]=1;
        // dfs(i,0);//这里弱智了，入口是有这个点的值的
        dfs(i,val[i]);
        cpath.pop_back();
        cvis[i]=0;
    }
    sort(ans.begin(),ans.end(),cmp);
    for(auto a:ans)
    {
        for(int i=0;i<a.size();i++)
        {
            cout<<val[a[i]];
            if(i!=a.size()-1)
                cout<<" ";
        }
        
        cout<<endl;
    }
    return 0;
}
