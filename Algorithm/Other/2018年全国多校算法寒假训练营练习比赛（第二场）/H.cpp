//https://www.nowcoder.com/acm/contest/74/H

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL A[100] = {0,1,1,2};

int main()
{
   // freopen("D:\\Project\\Algorithm\\Algorithm\\Algorithm\\input.txt","r",stdin);
   
  for(int i=4;i<100;i++){
    A[i]=A[i-1]+A[i-2]+A[i-3];
  }
  
  int n;
  while( cin>>n)
  {
    cout<<A[n-1]<<endl;  
  }
   
}
