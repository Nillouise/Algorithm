//另一点注意的是，这题的边界数据的定义，还有把子树和父树状态分离的思路
//还有就是，跟背包一样，用前面的值更新后面的值，会导致覆盖了后面的值（就是“滚雪球”地更新数组是不行的）
// 为什么我这里有一大段注释做错了？可能是因为当字数为空的时候（ic==0），会导致DP[jc][0]+=DP[st][ic][0]*DP[x][jc-ic][0];滚雪球了。

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m;
vector<int> G[100000+10];
vector<int> tree[100000+10];
LL DP[100000+10][12][3];
int k,cnt;
const LL MOD = 1e9+7;
LL tmp[12][3];
void dfs(int x)//0 小于k,1等于k，2大于k 
{
    for(auto a:tree[x])
    {
        dfs(a);
    }
    // for (int i = 0; i <= m; i++) 
    // {
    //     DP[x][i][0]=k-1;
    //     DP[x][i][1]=1;
    //     DP[x][i][2]=m-k-1;
    // }
    DP[x][0][0]=k-1;
    DP[x][1][1]=1;
    DP[x][0][2]=m-k;
    
    for (int subtree = 0; subtree < (int)tree[x].size(); subtree++) 
    {
        int st = tree[x][subtree];
        memset(tmp,0,sizeof(tmp));
        for (int c1 = 0; c1 <= cnt ; c1++) 
        {
            for (int ty1 = 0; ty1 < 3; ty1++) 
            {
                for (int c2 = 0; c2 <= cnt; c2++) 
                {
                    if(c1+c2>cnt)continue;
                    for (int ty2 = 0; ty2 < 3; ty2++) 
                    {
                        if((ty1!=1&&ty2!=1)||(ty1==1&&ty2==0)||(ty2==1&&ty1==0))
                            tmp[c1+c2][ty2] += DP[x][c2][ty2] * DP[st][c1][ty1];
                        tmp[c1+c2][ty2]%=MOD;
                    }
                }
            }
        }
        memcpy(DP[x],tmp,sizeof(DP[x]));
        
    }
    
    
    //这可能用不存在的树去更新新树。
    // for (int i = 0; i < (int)tree[x].size(); i++) 
    // {
    //     int st = tree[x][i];
    //     for (int ic = 0; ic <= cnt; ic++) 
    //     {
    //         LL nozero = 0;//这可能用不存在的树去更新新树。
    //         for (int i = 0; i < 3; i++) 
    //         {
    //             nozero +=DP[st][ic][i];
    //         }
    //         if(!nozero)continue;
    //         // memcpy(tmp,DP[x],sizeof(tmp));
    // 
    //         memset(tmp,0,sizeof(tmp));
    //         for (int jc = cnt; jc >= ic; jc--) 
    //         {
    //             for (int ty = 0; ty < 3; ty++) 
    //             {
    //                 cout<<"tree "<<st<<" ic "<<ic<<" jc "<<jc<<" ty "<<ty<<"  :";
    //                 cout<<"( "<<tmp[jc][ty]<<" ";
    //                 if(ty==0)
    //                 {
    //                     tmp[jc][0]+=DP[st][ic][0]*DP[x][jc-ic][0];
    //                     tmp[jc][0]+=DP[st][ic][1]*DP[x][jc-ic][0];
    //                     tmp[jc][0]+=DP[st][ic][2]*DP[x][jc-ic][0];
    //                 }else if(ty==1&&jc-ic>0)
    //                 {
    //                     tmp[jc][1]+=DP[st][ic][0]*DP[x][jc-ic-1][1];
    //                 }else if(ty==2)
    //                 {
    //                     tmp[jc][2]+=DP[st][ic][0]*DP[x][jc-ic][2];
    //                     tmp[jc][2]+=DP[st][ic][2]*DP[x][jc-ic][2];
    //                 }
    //                 cout<<tmp[jc][ty]<<" )"<<endl;//
    //                 // DP[x][jc][ty]%=MOD;
    //                 tmp[jc][ty]%=MOD;
    //             }
    //         }
    //         memcpy(DP[x],tmp,sizeof(tmp));
    //     }
    // }
}

int init(int x,int fa)
{
    if(fa!=-1)tree[fa].push_back(x);
    for(auto a:G[x])
    {
        if(a!=fa)
        {
            init(a,x);
        }
    }
    return 0;
}

void prin(int x,int fa)
{
    for (int i = 0; i <= cnt; i++) 
    {
        cout<<"x "<<x<<" i :";
        for (int j = 0; j < 3; j++) 
        {
            cout<<DP[x][i][j]<<" ";
        }
        cout<<endl;
    }
    for(auto a:tree[x])
    {
        prin(a,x);
    }
}


int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    cin>>n>>m;
    for (int i = 0; i < n-1; i++) 
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cin>>k>>cnt;
//    cout<<"cnt "<<cnt;
    init(0,-1);
    // dfs()
    dfs(0);
    // prin(0,-1);
    LL sum = 0;
    for (int i = 0; i <= cnt; i++) 
    {
        for (int ty = 0; ty < 3; ty++) 
        {
            sum = (sum+DP[0][i][ty])%MOD;
        }
    }
    cout<<sum<<endl;
    
    return 0;
}
