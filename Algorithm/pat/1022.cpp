#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
vector<int> data;
int tree[2000];
int cnttree[2000];

int init(int x)
{
    int cnt =1;
    if(x*2<=n)
        cnt+=init(x*2);
    if(x*2+1<=n)
        cnt+=init(x*2+1);
    return cnttree[x]=cnt;
}

int dfs(int x,int b)
{
    int pos;
    if(x*2<=n)
        pos = b + cnttree[x*2];
    else
        pos = b;
    tree[x] = data[pos];
    if(x*2<=n)dfs(x*2,b);
    if(x*2+1<=n)dfs(x*2+1,pos+1);
    return 0;
}

int main()
{
    freopen("input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    
    cin>>n;
    data.resize(n);
    for (int i = 0; i < n; i++) 
    {
        cin>>data[i];
    }
    sort(data.begin(),data.end());
    init(1);
    dfs(1,0);
    for(int i=1;i<=n;i++)
    {
        cout<<tree[i];
        if(i!=n)cout<<" ";
    }
    cout<<endl;
    return 0;
}
