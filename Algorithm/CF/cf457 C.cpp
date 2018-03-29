#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


const int LPRIME = 100003;
const int LNUM = 1000000000;

int main()
{
  int n,m;
  cin>>n>>m;
  cout<<2;
  if(n==2)cout<<" "<<2<<endl;
  else
  cout<<" "<<100003<<endl;
  cout<<1<<" "<<n<<" "<<2<<endl;
  for(int i=2;i<=n-1;i++)
  {
    if(i==n-1)
      cout<<1<<" "<<n-1<<" "<<LPRIME-2-(n-3)<<endl;
    else
      cout<<1<<" "<<i<<" "<<1<<endl;
  }
  int cnt = n-1;
  for(int i=2;i<n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      if(cnt==m)break;
      cnt++;
      cout<<i<<" "<<j<<" "<<LNUM<<endl;
    }
  }
}