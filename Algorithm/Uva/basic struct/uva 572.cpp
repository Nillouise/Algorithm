#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int m,n;
// int maze[300][300]; // 这里接受char，不能用int，因为cin要根据类型接受参数
char maze[300][300]; 
int vis[300][300];

int dfs(int r,int c,int id)
{
    if(r<0||r>=m||c<0||c>=n)
    {
        return 0;
    }
    if(vis[r][c]>0|| maze[r][c]=='*')
    {
        return 0;
    }
    
    vis[r][c]=id;
    
    for(int i=-1;i<2;i++)
    {
        for(int j=-1;j<2;j++)
        {
            if(i==0&&j==0)continue;
            dfs(r+i,j+c,id+1);
        }
    }
    return 1;
    
}


int main()
{
    freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    while(cin>>m>>n)
    {
        // cout<<m<<n; //
        if(m==0)break;
        
        memset(maze,0,sizeof(maze));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>maze[i][j];
            }
        }
        // for(int i=0;i<m;i++)   //
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<maze[i][j]<< ' ';
        //     }
        //     cout<<endl;
        // }
        
        
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cnt+=dfs(i,j,1);
                // cout<<cnt; // 
            }
        }
        cout<<cnt<<endl;
    }
    
    
    return 0;
}
