#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
using namespace std;
namespace other
{
    struct p{
        int t,h,l;
    }c[101];
    int d,g;
    int ti[101];
    int f[101];
    bool cmp(p a,p b)
    {
        return a.t<b.t;
    }
    int other_man_main()
    {
        cin>>d>>g;
        for(int i=1;i<=g;i++)
          cin>>c[i].t>>c[i].l>>c[i].h;
        sort(c+1,c+1+g,cmp);
        f[0]=10;
        for(int i=1;i<=g;i++)
          for(int j=d;j>=0;j--)
            if(f[j]>=c[i].t)
            {
                if(j+c[i].h>=d)
                {
                    cout<<c[i].t;
                    return 0;
                }
                f[j+c[i].h]=max(f[j+c[i].h],f[j]);//f里面的是总生命值，这样就不用担心会刷新覆盖的了
                f[j]+=c[i].l;
            }
        cout<<f[0];
        return 0;
    }
}



int D,G;
int dp[3000+10][350];
int tmp[3000+10][350];
struct Token
{
    int t,f,h;
    bool operator<(Token &rhs){return t<rhs.t;}
};
Token token[110];

int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    // other::other_man_main();
    cin>>D>>G;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=10;i++)
    {
        dp[i][0]=1;
    }
    for (int i = 0; i < G; i++) {
        int t,f,h;
        cin>>t>>f>>h;
        token[i] = Token{t,f,h};
        // cout<<i<<" "<<t<<f<<h<<endl;//
    }
    sort(token,token+G);
    // for(auto a:token)
    // {
    //     cout<<" a "<<a.t<<a.f<<a.h<<endl;
    // }
    
    int MAX=10;
    for (int i = 0; i < G; i++) {
        memcpy(tmp,dp,sizeof(dp));
        Token t = token[i];

        for(int j=D;j>=0;j--)
        {
            for(int k=t.t;k<=MAX;k++)
            {
                if(dp[k][j]==1)
                {
                    // cout<<k<<" "<<j<<" "<<dp[k][j]<<'\t';
                    tmp[k+t.f][j]=1;//感觉应该是这里错了，因为t.f是离散的//并不是//确实有影响
                    for(int o=0;o<t.f;o++)
                    {
                        tmp[k+t.f-o][j]=1;
                    }
                    tmp[k][j+t.h]=1;
                }
            }
        }
                MAX+=t.f;
        memcpy(dp,tmp,sizeof(dp));
    }
    
    // for(int i=0;i<MAX;i++)
    // {
    //     for(int j=0;j<=D;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<D<<endl;
    for(int i=0;i<=MAX;i++)
    {
        // cout<<dp[i][D]<<" ";
        if(dp[i][D])
        {
            cout<<i<<endl;
            return 0;
        }
    }
    // cout<<"MAX ";
    // cout<<MAX<<endl;//可能这头牛活不到投最后一个垃圾的时候!!!，所以这是错的
    
    for(int i=0;i<=MAX+1;i++)//这里为啥要加1，你猜猜
    {
        if(dp[i][0]==0)
        {
            cout<<i-1<<endl;
            return 0;
        }
    }
    
    return 0;
}