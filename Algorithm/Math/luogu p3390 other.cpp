#include<iostream>
#include<cstring>
#define mod 1000000007
#define ll long long
using namespace std;
struct Mat{
    vector<vector<LL,200>,200 > m;
};//结构体存矩阵 
Mat a,e;//a是输入的矩阵，e是单位矩阵 
ll n,p;
Mat Mul(Mat x,Mat y) //矩阵乘 
{
    Mat c;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        c.m[i][j]=0;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        for(int k=1;k<=n;k++)
        {
            c.m[i][j]=c.m[i][j]%mod+x.m[i][k]*y.m[k][j]%mod;
          }
    return c; 
}
Mat pow(Mat x,ll y) //矩阵快速幂 
{
    Mat ans=e;
    while(y)
    {
        if(y&1)
         ans=Mul(ans,x);  
        x=Mul(x,x);
        y>>=1;
    }
    return ans;
}

int main()
{
    //输入 
    cin>>n>>p;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        cin>>a.m[i][j];
     //算法核心     
    for(int i=1;i<=n;i++)
        e.m[i][i]=1;    
    Mat ans=pow(a,p);
    //输出 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
          cout<<ans.m[i][j]%mod<<" ";
        cout<<endl;
    }  

    return 0;
}