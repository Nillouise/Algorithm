//这题的图是用 i与i+j连起来这样生成的，最好直接用1开头的index开始算。
//这题因为特殊的图输入手段，一定要把所有的一切都从1开始数，因此要记得怎么从1开始数
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int maze[20];
int G[20][20];
vector<int> ans;
vector<int> cans;
int MAX=0;
int vis[17];
int dfs(int x,int num)
{
    num+=maze[x];
    vis[x]=1;
    cans.push_back(x);
    if(num>MAX)
    {
        MAX=num;
        ans=cans;
    }
    for(int i=1;i<13;i++)
    {
        if(G[x][i]&&(!vis[i]))
            dfs(i,num);
    }
    cans.erase(--cans.end());
    vis[x]=0;
    return 0;
}


int main()
{
    ios::sync_with_stdio(false);

	int N;
	cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>maze[i];
    }
    for(int i=1;i<N;i++)
    {
        for(int j=1;j<N-i+1;j++)
        {
            int connect;
            cin>>connect;
            if(connect)
            {
                G[i][i+j]=1;
                G[i+j][i]=1;
            }
        }
    }
    for(int i=1;i<=N;i++)dfs(i,0);
    cout<<ans[0];
    for(int i=1;i<ans.size();i++)
        cout<<"-"<<ans[i];
    cout<<endl;
    cout<<"MAX="<<MAX<<endl;
}
