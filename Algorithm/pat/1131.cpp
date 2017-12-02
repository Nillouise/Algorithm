#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int> G[10000+100];
int sta[10000+100];// 站台的颜色，0代表中转站
int n;
vector<int> line[200];
int dist[10000+100];
int dist2[10000+100];

vector<int> anscol(10000+10);
vector< pair<int,int> > path(10000+10);
vector< pair<int,int> > anspath;
vector<int> anstra;
vector<int> colpath;
vector<int> trapath;
map<pair<int,int>,int> COL;
int MIN = 1e9;
//错的，错的，不能用dfs呀。。。，直接在bfs哪里记录需要转几趟车就行了。//还是错的？
int u,dest;
int dfs(int x,int sum,int dep)
{
    // cout<<"x "<<x<<endl;
    if(x==dest)
    {
        if(sum<MIN)
        {
            anspath = path;
            MIN = sum;
        }
        return 0;
    }
    for(auto a:G[x])
    {
        if(dist[x]==dist[a]+1)
        {
            int nsum=sum;
            // if(path.size()>0&&COL[{x,a}]!=COL[path[dep]])//这个dep 没减1真的脑残。。
            if(path.size()>0&&COL[{x,a}]!=COL[path[dep-1]])
                nsum++;
            path[dep] = {x,a};
            dfs(a,nsum,dep+1);
        }
    }
    return 0;
}

int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    // ios::sync_with_stdio(false);
    // memset(sta,-1,sizeof(sta));
    scanf("%d",&n);
    for (int i = 0; i < n; i++) 
    {
        int m;;
        scanf("%d",&m);
        for (int j = 0; j < m; j++) 
        {
            int a;
            scanf("%d",&a);
            line[i+1].push_back(a);
        }
    }
    
    for (int i = 1; i <=n; i++) 
    {
        for (int j = 0; j < line[i].size()-1; j++) 
        {
            if(line[i].size()==3&&line[i][0]==line[i].back())continue;//解决一种罕见情况
            G[line[i][j]].push_back(line[i][j+1]);
            COL[make_pair(line[i][j],line[i][j+1])]=i;
        }
        for (int j = line[i].size()-1; j > 0; j--) 
        {
            G[line[i][j]].push_back(line[i][j-1]);
            COL[make_pair(line[i][j],line[i][j-1])]=i;
        }
        // for(auto a:line[i])
        // {
        //     if(sta[a]==-1)
        //         sta[a] = i;
        //     else
        //         sta[a]=0;
        // }
    }
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&u,&dest);
        memset(dist,0x3f3f,sizeof(dist));
        MIN = 1e9;
        // memset(dist2,0x3f3f,sizeof(dist2));
        dist[dest]=0;
        
        queue<int> Q;
        Q.push(dest);
        while(!Q.empty())
        {
            int v=Q.front();Q.pop();
            // if(v==u)break;
            for(auto a:G[v])
            {
                // if(dist[a]>dist[v]+1||(dist[a]==dist[v]&&dist2[a]>dist2[v]))
                if(dist[a]>dist[v]+1)
                {
                    Q.push(a);
                    dist[a]=dist[v]+1;
                }
            }
        }
        dfs(u,0,0);
        printf("%d\n",dist[u]);
        // for(auto a:anspath)
        // {
        //         cout<<a.first<<" "<<a.second<<endl;
        // }
        // 
        int cl,beg=u,end;
        
        //打印路径的思路错了
        // for(int i=1;i<dist[u];i++)
        // {
        //     // cout<<i<<"i "<<endl;
        //     cout<<" c "<<COL[anspath[i]];//
        //     if(COL[anspath[i]]!=COL[anspath[i-1]]|| i==dist[u]-1)
        //     {
        //         if(i==dist[u]-1)
        //             printf("Take Line%d from %04d to %04d\n",COL[anspath[i-1]],beg,anspath[i].second);
        //         else
        //             printf("Take Line%d from %04d to %04d\n",COL[anspath[i-1]],beg,anspath[i].first);
        //         beg = anspath[i].first;
        //     }
        // }
        for (int i = 0; i < dist[u]; i++) 
        {
            if(i<dist[u]-1&&COL[anspath[i]]!=COL[anspath[i+1]])
            {
                printf("Take Line#%d from %04d to %04d.\n",COL[anspath[i]],beg,anspath[i].second);
                beg = anspath[i].second;
            }else if(i==dist[u]-1)
            {
                printf("Take Line#%d from %04d to %04d.\n",COL[anspath[i]],beg,anspath[i].second);
            }
        }
        
    }
    
    


    return 0;
}
