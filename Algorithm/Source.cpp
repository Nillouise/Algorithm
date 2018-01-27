//测试一下sshkey

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int r,c,k;
int rs,cs,re,ce;
char G[1050][1050];
int dist[1050][1050];
set<int> R[1050];
set<int> C[1050];

void update(int cr,int cc)
{
    cout<<"update "<<cr<<" "<<cc<<endl;//
    R[cr].erase(cc);
    C[cc].erase(cr);
}

int main()
{
  double a = 0.25;
  double res = 1.0;
  for(int i=0;i<4;i++)
  res*=a;
  cout<<"res "<<res<<endl;
  double ans = 1.0;
  for(int i=0;i<7;i++){
    ans*=(1-res);
  }
  cout<<"res* 5 ="<<res*5<<endl;//
  cout<<"ans "<<ans<<endl;
  
    return 0;
}
