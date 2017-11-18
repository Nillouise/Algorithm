#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int gr,gc,sli,thr;//slice,threshold
int G[60][1300][1300];
int vis[60][1300][1300];
int cnt=0;
int check(int r,int c,int z)
{
    if(r<0||r>=gr||c<0||c>=gc||z<0||z>=sli)
        return 0;
    if(vis[z][r][c]==1)return 0;
    if(G[z][r][c]==0)return 0;
    return 1;
}
int way[6][3]=
{
    {-1,0,0},
    {1,0,0},
    {0,-1,0},
    {0,1,0},
    {0,0,1},
    {0,0,-1}
};
int dfs(int r,int c,int z)
{
    cnt++;
    for(int i=0;i<6;i++)
    {
        int nr = r+way[i][0];
        int nc = c+way[i][1];
        int nz = z+way[i][2];
        if(check(nr,nc,nz))
        {
            vis[nz][nr][nc]=1;
            dfs(nr,nc,nz);    
        }
    }
    return 0;
}

int main()
{
 //   freopen("input.txt","r",stdin);//
    ios::sync_with_stdio(false);
    cin>>gr>>gc>>sli>>thr;
    for(int s=0;s<sli;s++)
    {
        for (int i = 0; i < gr; i++) {
            for (int j = 0; j < gc; j++) {
                cin>>G[s][i][j];  
            }
        }
    }
    int ans = 0;
    for(int s=0;s<sli;s++)
    {
        for (int i = 0; i < gr; i++) {
            for (int j = 0; j < gc; j++) {
                if(check(i,j,s)&&G[s][i][j]==1)
                {
                    vis[s][i][j]=1;//这里忘记写了，明明dfs函数内的入口点都有些这个，这里反而没有写
                    dfs(i,j,s);
                    if(cnt>=thr)
                    {
                        ans+=cnt;
             //           cout<<cnt<<" ";
                    }
                    
                    cnt=0; 
                    
                }
            }
        }
    }
    cout<<ans<<endl;
    
    return 0;
}
