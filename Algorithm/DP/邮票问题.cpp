你可以设置k种邮票的面值，一共用n张这些种类的邮票，要能组成1到ans 连续这么多种面值。
输出你组合的这k种邮票的面值，还有最大的ans

#include<bits/stdc++.h>
using namespace std;
int DP[1000][15];
int tmp[1000][15];
int MAX=0;
vector<int> path(20);
vector<int> ans;
int n,k;
const int INF = 10000;
void dfs(int x,int dep,int pre)
{
    // cout<<"x "<<x<<" dep "<<dep<<" pre "<<pre<<endl;//
 if(dep>k)return;
 
 memcpy(tmp,DP,sizeof(tmp));
 path[dep]=x;
 int cm = 0;
 int ci = 0;
 for(int i=1000-1;i>=0;i--)
 {
  for(int j=0;i-j*x>=0;j++)
  {
   if(DP[i-j*x][dep-1]+j<=n&& DP[i-j*x][dep-1]!=INF && DP[i][dep]>DP[i-j*x][dep-1]+j)
   {
    DP[i][dep] = DP[i-j*x][dep-1]+j;
   }
  }
 }
    //   cout<<"DP[i][dep] :";//
 for(int i=1;i<1000;i++)
 {
    //  cout<<DP[i][dep]<<" ";//
  if(DP[i][dep]>0&&DP[i][dep]!=INF)
  {
   ci=i;
  }else{
   break;
  }
 }
 // cout<<ci;
 // cout<<endl;//
 
 for(int i=1;i<1000;i++)
 {

  if(DP[i][dep]>0&&DP[i][dep]<n)cm = i;
  else break;
    //    cout<<DP[i][dep];//
 }
 // cout<<"cm"<<cm<<endl;//
 if(ci>MAX)
 {
  MAX=ci;
  ans=path;
 }
 
 for(int i=pre+1;i>x;i--)
 {
  dfs(i,dep+1,cm);
 }
 memcpy(DP,tmp,sizeof(tmp));
 
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
