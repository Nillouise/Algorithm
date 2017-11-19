#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int strt[200][2];
int n;
int val[200];
int gtree[200];//生成树
int cnttree[200];

int dfs(int pos,int b,int e)
{
    if(pos==-1)return 0;
    if(b>=e)return 0;
    
    int vpos = b+(strt[pos][0]==-1?0:cnttree[strt[pos][0]]);
    gtree[pos]=val[vpos];
    dfs(strt[pos][0],b,vpos);
    dfs(strt[pos][1],vpos+1,e);
    return 0;
}
int init(int x)
{
    //int cnt =0;//这里是1才对，因为算上根节点
    int cnt=1;
    if(strt[x][0]!=-1)
        cnt+=init(strt[x][0]);
    if(strt[x][1]!=-1)
        cnt+=init(strt[x][1]);
    cnttree[x]=cnt;
    return cnt;
}

int main()
{
    freopen("input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    cin>>n;
    if(n==0){cout<<endl;return 0;}
    for(int i=0;i<n;i++)
    {
        cin>>strt[i][0]>>strt[i][1];
    }
    for (int i = 0; i < n; i++) 
    {
        cin>>val[i];
    }
    sort(val,val+n);
    init(0);
    dfs(0,0,n);
    
    vector<int> ans;
    queue<int> Q;
    Q.push(0);
    while(!Q.empty())
    {
        int u = Q.front();Q.pop();
        ans.push_back(u);
        if(strt[u][0]!=-1)
            Q.push(strt[u][0]);
        if(strt[u][1]!=-1)
            Q.push(strt[u][1]);
    }
    cout<<gtree[ans[0]];
    for(int i=1;i<n;i++)
        cout<<" "<<gtree[ans[i]];
    cout<<endl;
    

    return 0;
}
