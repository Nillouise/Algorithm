#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int G[200][200];
int vis[200][200];
char path[3000];
int n;
int pos=0;
int dfs(char x)
{
    // cout<<x<<" ";
    
    for(int i=0;i<200;i++)
    {
        if(G[x][i]==1&&vis[x][i]==0)
        {
            vis[x][i]=1;
            vis[i][x]=1;
            // if(dfs(i,dep+1))return 1;
            // vis[x][i]=0;
            // vis[i][x]=0;
            dfs(i);
        }
    }
    path[pos++]=x;//注意这种路径记录必须要摆在递归结束后！！！！想一想8字形的图，顺序应该是按照碰壁的先后才是准确的，而不是探索的先后
    return 0;
}

int du[200];

int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    cin>>n;    
    string s;
    int b;
    for (int i = 0; i < n; i++) {
        cin>>s;
        G[s[0]][s[1]]=1;
        G[s[1]][s[0]]=1;
        du[s[0]]++;//这么做很有必要，这样才可以cover s[0]==s[1]的情况
        du[s[1]]++;
    }
    memset(vis,0,sizeof(vis));
    
    int odd=0;
    for(int i=0;i<200;i++)
    {
        // for (int j = i+1; j < 200; j++) {//窒息的操作//一个点连了几条边，而不是算其他的东西！！！
        // for(int j=0;j<200;j++){
        //     if(G[i][j]==1)
        //         cnt++;
        // }
        if(du[i]%2==1)
        {
            odd++;
        }
    }
    if(odd!=0&&odd!=2)
    {
        cout<<"No Solution"<<endl;
        return 0;
    }
    b = 0;
    if(odd==0)
    {
        for(int i=0;i<200;i++)
        {
            for(int j=0;j<200;j++)
            {
                if(G[i][j]){
                    b=i;
                    goto forbreak;
                }
            }
        }
    }else{
        for(int i=0;i<200;i++)
        {
            if(du[i]%2)
            {
                b=i;
                break;
            }
        }
    }
forbreak:
    dfs(b);
    // for (int i = 0; i < n+1; i++) {
    //     cout<<path[i];
    // }
    for(int i=n;i>=0;i--)cout<<path[i];
    cout<<endl;
    
    
    
    return 0;
}