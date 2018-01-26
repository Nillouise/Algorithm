#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
int one(int x)
{
  int cnt = 0;
  while(x)
  {
    if(x&1)
      cnt++;
    x/=2;
  }
  return cnt;
}

int DP[1003];

int C[1010][1010];

void initC()
{
  for(int i=0;i<1010;i++)
    C[i][0]=1;
  
  for(int i=1;i<1010;i++)
  {
    for(int j=1;j<=i;j++)
    {
      C[i][j] = (C[i-1][j]+C[i-1][j-1])%MOD;
    }
  }
}

int main()
{
  string s;
  int k;
  
  cin>>s>>k;
  if(k==0){
    cout<<1<<endl;
    return 0 ;
  }
  // if(s=="1"&&k==1){
  //   cout<<0<<endl;
  //   return 0;
  // }
  long long res = 0;
  
  DP[1]=0;
  for(int i = 2;i<1002;i++){
    DP[i] = DP[one(i)]+1;
  }
  initC();
  int pre = 0;
  for (size_t i = 0; i < s.size(); i++) {
    if(s[i]=='0')continue;
    
    for(int j = max(1,pre);j<1001;j++)
    {
      if(DP[j]==k-1)
      {
        res = ( res + C[s.size() - i-1][j-pre])%MOD;
        if(i == 0 && k == 1)
{
  res = (res+MOD-1)%MOD;
}
// cout<<"res"<<res<<endl;//
      }
    }
    pre++;
  }
  int cnt = 0;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]=='1')cnt++;
  }
  if(DP[cnt]==k-1){
    res++;
    res%=MOD;
  }
  cout<<res<<endl;
  return 0;
  
}