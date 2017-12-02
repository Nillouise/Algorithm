#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
struct Token
{
    string op;
    int l,r;
};
Token dat[30];

void dfs(int dep,int pos)
{
    Token c = dat[pos];
    int judge = ((c.l!=-1||c.r!=-1)&&(dep!=0));
    if(judge)
    {
        cout<<"(";
    }
    if(c.l!=-1)dfs(dep+1,c.l);
    cout<<c.op;
    if(c.r!=-1)dfs(dep+1,c.r);
    if(judge)
    {
        cout<<")";
    }
}

int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    
    cin>>n;
    for (int i = 1; i <= n; i++) 
    {
        string op;
        int l,r;
        cin>>op>>l>>r;
        Token t;
        t.op = op;
        t.l=l;
        t.r=r;
        dat[i]=t;
    }
    
    vector<int> noroot(30,0);
    for (int i = 1; i <= n; i++) 
    {
        if(dat[i].l!=-1)noroot[dat[i].l]=1;
        if(dat[i].r!=-1)noroot[dat[i].r]=1;
    }
    int root = 0;
    for(int i=1;i<=n;i++)
    {
        if(noroot[i]==0)root = i;
    }
    
    dfs(0,root);
    cout<<endl;


    return 0;
}
