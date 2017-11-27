//这题是我在校赛上没开的另一道难题，事后我猜出大概的解法，但还有一点错了，就是枚举的变量应该是从最大可行组合值+1到 目前最大面额才行。
#include<bits/stdc++.h>
using namespace std;
int DP[1000][15];
int tmp[1000][15];
int MAX=0;
vector<int> path(20);
vector<int> ans;
int n,k;
const int INF = 10000;
int dfs(int x,int dep,int pre)
{
 if(dep>k)return 0;
 
 memcpy(tmp,DP,sizeof(tmp));
 path[dep]=x;
 int cm = 0;
 int ci = 0;
 //这么更新应该会导致很慢，因为很多DP[dep-1]是INF，根本不需要算的。
 // for(int i=1000-1;i>=0;i--)
 // {
 //  for(int j=0;i-j*x>=0;j++)
 //  {
 //   if(DP[i-j*x][dep-1]+j<=n&& DP[i-j*x][dep-1]!=INF && DP[i][dep]>DP[i-j*x][dep-1]+j)
 //   {
 //    DP[i][dep] = DP[i-j*x][dep-1]+j;
 //   }
 //  }
 // }
 for (int i = 0; i < 1000; i++) 
 {
     if(DP[i][dep-1]<n)
     {
         for (int j = 0; i+j*x < 1000; j++) 
         {
             if(DP[i+j*x][dep]>DP[i][dep-1]+j)
             {
                 DP[i+j*x][dep]=DP[i][dep-1]+j;
             }
         }
     }
 }
 
 for(int i=1;i<1000;i++)
 {
  // if(DP[i][dep]>0&&DP[i][dep]!=INF)//这里<=n更符合要求
  if(DP[i][dep]>0&&DP[i][dep]<=n)
  {
   ci=i;
  }else{
   break;
  }
 }
 
 for(int i=1;i<1000;i++)
 {
  if(DP[i][dep]>0&&DP[i][dep]<n)cm = i;
  else break;
 }
 
 if(ci>MAX)
 {
  MAX=ci;
  ans=path;
 }
 
 for(int i=pre+1;i>x;i--)
 {
  dfs(i,dep+1,ci+1);
 }
 memcpy(DP,tmp,sizeof(tmp));
 return 0;
}

int main() 
{
    
 cin>>n>>k;
 
 for(int i=0;i<1000;i++)for(int j=0;j<15;j++)DP[i][j]=INF;
 for(int i=0;i<15;i++)DP[0][i]=0;
 //for(int i=1;i<=n;i++)DP[i][1]=i;
 dfs(1,1,n-1);
 
 for(int i=1;i<=k;i++)
 {
  cout<<ans[i]<<" ";
 }
 cout<<endl;
 cout<<MAX<<endl;

 return 0;
}

 
