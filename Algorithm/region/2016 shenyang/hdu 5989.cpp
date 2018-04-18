#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL dp[30][2][2];//pos，之前的数字是奇数还是偶数，之前的数量是奇数还是偶数。
int vis[30][2][2];
int vec[30];

int dfs(int x,int precnt,int preodd,int limit,int leadzero)
{
    if(x==-1)
    {
        if(precnt%2!=preodd||leadzero==1){
            return 1;
        }else{
            return 0;
        }
    }
    if(vis[x][precnt][preodd]==1&&limit==0&&leadzero)
    {
        return dp[x][precnt][preodd];
    }
    if(limit==0&&leadzero==0)
        vis[x][precnt][preodd]=1;
    
    
    int up = limit==0?9:vec[x];
    LL sum = 0;
    for (int i = 0; i <= up; i++) {
        
        if(i==0&&leadzero)
        {
            sum+=dfs(x-1,0,0,limit,1);
            continue;
        }
        if(i%2 != preodd||leadzero)
        {
            if(precnt%2 != preodd||leadzero)
                sum+=dfs(x-1,1,i%2,limit&&(i==vec[x]),0);
        }else{
            sum+=dfs(x-1,(precnt+1)%2,preodd,limit&&(i==vec[x]),0);
        }
    }
    if(limit==0&&leadzero==0)dp[x][precnt][preodd] = sum;
    return sum;
}

LL solve(LL x)
{
    memset(vis,0,sizeof(vis));
    memset(dp,0,sizeof(dp));
    memset(vec,0,sizeof(vec));
    int pos = 0;
    while(x){
        vec[pos++]=x%10;
        x/=10;
    }
    return dfs(pos-1,0,0,1,1);
}



int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    cout<<solve(10)<<endl;//
    int T;cin>>T;
    while(T--)
    {
        LL a,b;cin>>a>>b;
        
        cout<<solve(b)-solve(a-1)<<endl;
    }
    
    
    
    
    return 0;
}