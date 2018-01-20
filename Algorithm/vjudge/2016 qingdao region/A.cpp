#include<iostream>
using namespace std;
typedef long long LL;
int main()
{
  int T;
  cin>>T;
  while(T--)
  {
    LL n;
    cin>>n;
    LL res= 0;
    while(n--)
    {
      LL a,b;
      cin>>a>>b;
      res+=a*b;
    }
    
    cout<<res<<endl;
  }
  
}