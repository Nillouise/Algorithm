#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int tree[200];

int dfs(int pos)
{
    int val;
    cin>>val;
    if(val!=-1)
    {
        tree[pos]+=val;
        dfs(pos-1);
        dfs(pos+1);
    }else{
        return 0;
    }
}

int main()
{
    freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    //这个t用kase代表比较好
    for(int t=1;;t++)
    {
        memset(tree,0,sizeof(tree));
        dfs(100);
        int i=0;
        for(;i<200;i++)if(tree[i]!=0)break;
        if(i==200)break;
        //if(t!=1)cout<<endl;//空行居然要摆在这里//这是错的，看下面
        cout<<"Case "<<t<<":"<<endl;
        for(;tree[i]!=0;i++)
        {
            
            cout<<tree[i];
            if(tree[i+1]!=0)cout<<" ";
        }
        cout<<endl<<endl;//这里最后一个testcase居然可以有空行
    }
    
    return 0;
}
