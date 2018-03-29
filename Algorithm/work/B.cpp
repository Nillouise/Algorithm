#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL sol[4];
LL num[4];
LL ans=0;

LL rem[4];

LL DP[35][35][35][35];

LL dfs(int a,int b,int c,int d)
{
    if(DP[a][b][c][d]!=-1)
    {
        // cout<<a<<b<<c<<d<<" "<<DP[a][b][c][d]<<endl;
        return DP[a][b][c][d];
    }else{
        LL tol = a*sol[0]+b*sol[1]+c*sol[2]+d*sol[3];
        // cout<<tol<<endl;//
        if(a>0)
        {
            DP[a][b][c][d] =  dfs(a-1,b,c,d)+ ((tol-sol[0])%10) * sol[0];
        }
        if(b>0)
        {
            DP[a][b][c][d] = max(DP[a][b][c][d],dfs(a,b-1,c,d)+ ((tol-sol[1])%10) * sol[1]);
        }
        if(c>0)
        {
            DP[a][b][c][d] =  max(DP[a][b][c][d],dfs(a,b,c-1,d)+((tol-sol[2])%10) * sol[2]);
        }
        if(d>0)
        {
            // cout<<"tol "<<((tol-d)%10)<<endl;
            DP[a][b][c][d] =  max(DP[a][b][c][d],dfs(a,b,c,d-1)+ ((tol-sol[3])%10) * sol[3]);
        }
        return DP[a][b][c][d];
    }
    
}



int main()
{
    //freopen("I:\\Project\\acm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    for(int i=0;i<4;i++)
    {
        cin>>num[i];
    }
    memcpy(rem,num,sizeof(num));
    memset(DP,-1,sizeof(DP));
    DP[0][0][0][0] = 0;
    for(int i=0;i<4;i++)
    {
        cin>>sol[i];
    }
    
    
    cout<<dfs(num[0],num[1],num[2],num[3])<<endl;
    
    return 0;
}